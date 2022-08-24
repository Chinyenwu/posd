#ifndef TERMINAL
#define TERMINAL
#include <iostream>
#include <string>
#include <fstream>
#include "ellipse.h"
#include "triangle.h"
#include "rectangle.h"
#include <exception>
#include "two_dimensional_coordinate.h"
#include "sort.h"
#include <regex>
#include <iomanip>
#include <limits>

class Terminal
{
public:
    // you can use regular expression to get useful token from "Input string"
    Terminal(std::string input)
    {
        // Search for Shapes
        _stringForSearch = input;
        std::regex regexSearchAllShapes("(Ellipse |Rectangle )[\\s]{0,}\\([\\s]{0,}[0-9]{1,}\\.?[0-9]{0,}[\\s]{0,},[\\s]{0,}[0-9]{1,}\\.?[0-9]{0,}[\\s]{0,}\\)|"
                                        "(Triangle )[\\s]{0,}\\("
                                        "([[\\s]{0,}-?[0-9]{1,}\\.?[0-9]{0,}[\\s]{0,},[\\s]{0,}-?[0-9]{1,}\\.?[0-9]{0,}[\\s]{0,}],){2}"
                                        "[[\\s]{0,}-?[0-9]{1,}\\.?[0-9]{0,}[\\s]{0,},[\\s]{0,}-?[0-9]{1,}\\.?[0-9]{0,}[\\s]{0,}]\\)");
        std::smatch match;

        while (std::regex_search(_stringForSearch, match, regexSearchAllShapes))
        {
            _shapesStr.push_back(match[0]);
            _stringForSearch = match.suffix().str();

        }
        std::regex searchPositiveNumbers("[0-9]{1,}\\.?[0-9]{0,}");
        std::regex searchPosAndNegNumbers("-?[0-9]{1,}\\.?[0-9]{0,}");

        for (int i = 0; i < _shapesStr.size(); ++i)
        {
            if (std::regex_match(_shapesStr[i], std::regex("Ellipse.*")))
            {
                std::sregex_iterator it = std::sregex_iterator(_shapesStr[i].begin(), _shapesStr[i].end(), searchPositiveNumbers);
                std::smatch sm;
                sm = *it;
                double semiMajorAxes = std::stod(sm.str(0));
                it++;
                sm = *it;
                double semiMinorAxes = std::stod(sm.str(0));
                if(semiMajorAxes<=0||semiMinorAxes<=0){
                  continue;
                }
                if((semiMajorAxes-semiMinorAxes) < 0){
                  continue;
                }
                shapes.push_back(new Ellipse(semiMajorAxes, semiMinorAxes));
            }
            else if (std::regex_match(_shapesStr[i], std::regex("Triangle.*")))
            {
                std::vector<double> axis;
                for (std::sregex_iterator it = std::sregex_iterator(_shapesStr[i].begin(), _shapesStr[i].end(), searchPosAndNegNumbers);
                     it != std::sregex_iterator(); it++)
                {
                    std::smatch sm;
                    sm = *it;
                    axis.push_back(std::stod(sm.str(0)));
                }
                double x = sqrt((axis[0]-axis[2])*(axis[0]-axis[2])+(axis[1]-axis[3])*(axis[1]-axis[3]));
                double y = sqrt((axis[2]-axis[4])*(axis[2]-axis[4])+(axis[3]-axis[5])*(axis[3]-axis[5]));
                double z = sqrt((axis[4]-axis[0])*(axis[4]-axis[0])+(axis[5]-axis[1])*(axis[5]-axis[1]));
                if(x<=0||y<=0||z<=0){
                  continue;
                }
                if(x+y<z||y+z<x||z+x<y){
                  continue;
                }
                std::vector<TwoDimensionalCoordinate*> triangleVector;
                triangleVector.push_back(new TwoDimensionalCoordinate(axis[0], axis[1]));
                triangleVector.push_back(new TwoDimensionalCoordinate(axis[2], axis[3]));
                triangleVector.push_back(new TwoDimensionalCoordinate(axis[4], axis[5]));
                shapes.push_back(new Triangle(triangleVector));
            }
            else if (std::regex_match(_shapesStr[i], std::regex("Rectangle.*")))
            {
                std::sregex_iterator it = std::sregex_iterator(_shapesStr[i].begin(), _shapesStr[i].end(), searchPositiveNumbers);
                std::smatch sm;
                sm = *it;
                double length = std::stod(sm.str(0));
                it++;
                sm = *it;
                double width = std::stod(sm.str(0));
                if(length<=0||width<=0){
                  continue;
                }
                shapes.push_back(new Rectangle(length, width));
            }
        }
        std::smatch match1;
        // Search for feature
        std::regex searchFeature(".*(area|perimeter).*");
        if (!std::regex_search(_stringForSearch, match1, searchFeature))
        {
            //std::cout << "invalid input" << std::endl;
            throw std::string("invalid input");
        }
        // Search for order
        std::regex searchOrder(".*(inc|dec).*");
        if (!std::regex_search(_stringForSearch, match1, searchOrder))
        {
            //std::cout << "invalid input" << std::endl;
            throw std::string("invalid input");
        }
        if(shapes.size()==0)  throw std::string("invalid input");
        _stringForSearch = input;


    }

    std::string showResult()
    {
      if (_stringForSearch == "invalid input")
      {
          //std::cout << "invalid input" << std::endl;
          throw std::string("invalid input");
      }
      std::smatch match;
      // Search for feature
      std::regex searchFeature(".*(area|perimeter).*");
      if (!std::regex_search(_stringForSearch, match, searchFeature))
      {
          //std::cout << "invalid input" << std::endl;
          throw std::string("invalid input");
      }
      _feature = match[1];

      // Search for order
      std::regex searchOrder(".*(inc|dec).*");
      if (!std::regex_search(_stringForSearch, match, searchOrder))
      {
          //std::cout << "invalid input" << std::endl;
          throw std::string("invalid input");
      }
      _order = match[1];

      // Assign _shapes to _sortShapes
      // Contitions to identify which method to use.
      if (_feature == "area" && _order == "inc")
      {
          quickSort(shapes.begin(), shapes.end(), areaAscendingCompare);
      }
      else if (_feature == "area" && _order == "dec")
      {
          quickSort(shapes.begin(), shapes.end(), areaDescendingCompare);
      }
      else if (_feature == "perimeter" && _order == "inc")
      {
          quickSort(shapes.begin(), shapes.end(), perimeterAscendingCompare);
      }
      else if (_feature == "perimeter" && _order == "dec")
      {
          quickSort(shapes.begin(), shapes.end(), perimeterDescendingCompare);
      }

      std::vector<Shape *>::iterator shapePtr;
      shapePtr = shapes.begin();
      char str[100];
      std::string values = "",str2;
      std::ostringstream strs;
      if (_feature == "area")
      {
          for (int i = 0; i < shapes.size(); ++i)
          {
              Shape *temp = *(shapePtr + i);
              if (i != shapes.size() - 1)
              {
                sprintf(str, "%.3f",temp->area());
                str2 = str;
                values += str2 + "\n";
              }
              else
              {
                sprintf(str, "%.3f",temp->area());
                str2 = str;
                values += str2 + "";
              }
          }
          return values;
      }
      else if (_feature == "perimeter")
      {
          for (int i = 0; i < shapes.size(); ++i)
          {
              Shape *temp = *(shapePtr + i);
              if (i != shapes.size() - 1)
              {
                sprintf(str, "%.3f",temp->perimeter());
                str2 = str;
                values += str2 + "\n";
              }
              else
              {
                sprintf(str, "%.3f",temp->perimeter());
                str2 = str;
                values += str2 + "";
              }
          }
          return values;
      }
      else
          return "NULL";
    }
private:
    std::vector<std::string> _shapesStr;
    std::vector<Shape *> shapes;
    std::string _feature;
    std::string _order;
    std::string _stringForSearch;
};
#endif

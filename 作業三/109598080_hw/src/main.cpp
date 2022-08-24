#include <iostream>
#include <string>
#include <fstream>
#include "terminal.h"
int main(int argc, char **argv)
{
    //bin/geo input.txt output.txt [area perimeter  sumOfSquares]  [inc dec]
    if (argc < 5)
    {
        Terminal terminal("invalid input");
        terminal.showResult();
        return 0;
    }
    else
    {
        std::string inputLine;
        std::string inputLinetrue;
        std::string where(argv[0]);
        std::string inputPath(argv[1]);
        std::string outputPath(argv[2]);
        std::string featureArg(argv[3]);
        std::string orderingArg(argv[4]);
        std::ifstream file;
        std::ofstream wrFile;
        file.open(inputPath);
        while (std::getline(file, inputLine,'\n')) {
          inputLinetrue.append(inputLine+'\n');
        }

        wrFile.open(outputPath);
        //std::cout << inputLinetrue <<"\n";
        /*std::string str1("Hello World! ");
        std::string str2("GeeksforGeeks");
        std::cout << str1.append(str2) << "\n" ;*/
        Terminal test(inputLinetrue + " " + featureArg + " " + orderingArg);
        wrFile << test.showResult() << '\n';
        file.close();
        wrFile.close();
        return 0;
    }
}

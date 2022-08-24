#ifndef SCANNER
#define SCANNER
#include "string.h"
#include <deque>
class Scanner {
public:
    Scanner(std::string input) {
      std::string word = "";
      for (auto x : input)
      {
          if (x == ' ')
          {
              //std::cout << word << "\n";
              que.push_back(word);
              word = "";
          }
          else if(x == '('){
              //std::cout << "(" ;
              que.push_back("(");
              //std::cout << word << "\n";
              que.push_back(word);
              word = "";
          }
          else if(x == ')'){
              //std::cout << word << "\n";
              que.push_back(word);
              //std::cout << ")" << "\n";
              que.push_back(")");
              word = "";
          }
          else if(x == ','){
              //std::cout << word << "\n";
              que.push_back(word);
              //std::cout << ",";
              que.push_back(",");
              word = "";
          }
          else if(x == '{'){
              //std::cout << "(" ;
              que.push_back("{");
              //std::cout << word << "\n";
              que.push_back(word);
              word = "";
          }
          else if(x == '}'){
              //std::cout << word << "\n";
              que.push_back(word);
              //std::cout << ")" << "\n";
              que.push_back("}");
              word = "";
          }
          else {
              word = word + x;
          }
          //std::cout << x << "\n";
      }
      for(j=0;j<que.size();j++){
        if(que[j]==""){
          que.erase(que.begin()+j);
        }
      }
    }

    std::string nextToken() {
        // return next token.
        // throw exception std::string "next char doesn't exist." if next token not found.
        i=i+1;
        if(i>=que.size()){
            throw std::string("next char doesn't exist.");
        }
        else{
          return que[i];
        }

    }
  private:
    std::string _input;
    std::deque<std::string> que;
    int i=-1,j;
};
#endif

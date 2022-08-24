#ifndef NODE_SCANNER
#define NODE_SCANNER
#include "string.h"
#include <deque>
class NodeScanner {
public:
    NodeScanner(std::string input) {
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
              if(((int)x>=97&&(int)x<=122)||((int)x>=65&&(int)x<=90)||((int)x>=48&&(int)x<=57)||((int)x==46)&&x!='\0'){
                word = word + x;
              }
          }
          //std::cout << word << "\n";
      }
      for(j=0;j<que.size();j++){
        //std::cout << que[j] << "\n";
        if(que[j]=="\0"){
          que.erase(que.begin()+j);
        }
      }
    }

    std::string nextToken() {
        // return next token.
        // throw exception std::string "next char doesn't exist." if next token not found.
        i=i+1;
        if(i>=que.size()){
            throw std::string("next token doesn't exist.");
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

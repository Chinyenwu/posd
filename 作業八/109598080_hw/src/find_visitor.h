#ifndef FIND_VISITOR
#define FIND_VISITOR
#include "visitor.h"
#include <stack>
class FindVisitor : public Visitor {
public:
    FindVisitor(std::string name) {
        _info.append(name);
        _pushdown.push(_info);
        //_info = name;
    }

    void visitApp(App* app) {
        // find app when app's name matches given name,
        // add app's route as result.
        if(_info==app->route()){

        }
        else{
          _info.append(app->route());
          _pushdown.push(_info);
        }
        //_info = app->route();
    }

    void visitFolder(Folder* folder) {
        // find folder when folder's name matches given name,
        // add folder's route as result.
        // And find the tree structure bellow,
        // add the other match result with `\n`.
        Iterator * it = folder->createIterator();
        for(it->first();!it->isDone();it->next()){
          if(it->currentItem()->route()==_info){
            _info.append(folder->route());
            _pushdown.push(folder->route());
            //std::cout << _info << "\n";
          }
          try{
            Iterator * it2 = it->currentItem()->createIterator();
            for(it2->first();!it2->isDone();it2->next()){
              if(it2->currentItem()->route()==_info){
                _info.append(it->currentItem()->route());
                _pushdown.push(it->currentItem()->route());
                //std::cout << _info << "\n";
              }
            }
          }catch(std::string e){

          }

        }
        //_nodes.push_back(folder);

        /*Iterator * it = folder->createIterator();
        while(it->isDone()!=1){
          _info.append(it->currentItem()->route());
          it->next();
        }*/
    }

    std::string getResult() const {
        // return result.
        return _info;
    }

  private:
    std::string _info="/";
    std::stack<std::string> _pushdown;
    //double = size;
};

#endif

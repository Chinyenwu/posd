#ifndef APP
#define APP
#include "node.h"
class App : public Node {
public:
    App(std::string id, std::string name, double size) {
      this->_id = id;
      this->_name = name;
      this->_size = size;
    }

    void updatePath(std::string path){
      this->_path = path;
    }

    void accept(Visitor* visitor){
      visitor->visitApp(this);
    }
    // implement any functions inherit from Node that you think is suitable.
};
#endif

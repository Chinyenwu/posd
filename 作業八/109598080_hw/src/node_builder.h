#ifndef NODE_BUILDER
#define NODE_BUILDER
#include "node.h"
#include "folder.h"
#include <deque>
#include <stack>
class NodeBuilder {
public:
    void buildApp(std::string name, double size) {
        // build a app with an unique id and push in a std::stack.
    }

    void buildFolderBegin(std::string name) {
        // notify begin of folder.
    }

    void buildFolderEnd() {
        // notify end of folder.
    }

    std::deque<Node*> getResult() {
        // return result.
    }
};
std::stack<Shape *> _pushdown;
std::deque<Shape *> v;
std::deque<Shape *> begin;
int id = 0;

#endif

#ifndef NODE_PARSER
#define NODE_PARSER
#include "node_scanner.h"
#include "node_builder.h"
#include <deque>
#include <vector>
#include <string>
class NodeParser {
public:
    NodeParser(std::string input) {
        // initialize a scanner for handling input.
        // initialize a node builder for handling building node.
    }

    void parser() {
        // using NodeScanner::nextToken() to get all information to determine what to build,
        // and provide the argument the node needed.
        // use functions in NodeBuilder to build out the node.
        // the node with invalid argument should be ignored.
    }

    std::deque<Node*> getResult() {
        // return result.
    }
};
#endif
    //int i=0;

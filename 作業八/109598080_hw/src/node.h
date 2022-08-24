#ifndef SHAPE
#define SHAPE
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdexcept>
#include <limits>
#include <cmath>
#include <vector>
#include <list>
#include <fstream>
#include "iterator.h"
#include "visitor.h"
class Node {
public:

        Node();
        Node(std::string id, std::string name);
        Node(std::string id, std::string name, double size);

        std::string id() const;

        std::string name() const;

        virtual std::string route() const; // the "virtual" of this funtion is optional.

        virtual double size() const;

        virtual void updatePath(std::string path);

        virtual void addNode(Node* node);

        virtual Node* getNodeById(std::string id) const;

        virtual void deleteNodeById(std::string id);

        virtual Iterator* createIterator() const;

        virtual void addNodes(std::list<Node*> nodes);

        virtual void accept(Visitor* visitor) = 0;

        virtual ~Node();

protected:
        std::string _id,_name,_path="";
        double  _size;
};

#endif

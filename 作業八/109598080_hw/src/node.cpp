#include <iostream>
#include <string>
#include "node.h"
#include "null_iterator.h"
#include "node_iterator.h"

std::string Node::id() const{
  return this->_id;
};
std::string Node::name() const{
  return this->_name;
};
double Node::size() const{
  return this->_size;
};
std::string Node::route() const{
  std::string str1="";
  str1.append(this->_path);
  str1.append("/");
  str1.append(this->_name);
  return str1;
}
void Node::updatePath(std::string path){
  //this->_path = path;
}
void Node::addNode(Node *Node){
  throw std::string("only folder can add node.");
}
void Node::addNodes(std::list<Node*> nodes){
  throw std::string("only folder can add nodes.");
}
void Node::deleteNodeById(std::string id){
  throw std::string("only folder can delete node.");
};
Node* Node::getNodeById(std::string id) const{
  throw std::string("only folder can get node.");
};
Iterator* Node::createIterator() const{
  Iterator * nulliterator = new NullIterator();
  //NullIterator* nulliterator;
  return nulliterator;
};

Node::~Node(){};
Node::Node(){};
Node::Node(std::string id, std::string name){
  this->_id=id;
  this->_name=name;
};
Node::Node(std::string id, std::string name,double size){
  this->_id=id;
  this->_name=name;
  this->_size=size;
};

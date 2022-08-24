#ifndef FOLDER
#define FOLDER
#include "app.h"
#include "null_iterator.h"
#include "node_iterator.h"
class Folder : public Node {
public:
    Folder(std::string id, std::string name) {
      this->_id = id;
      this->_name = name;
    } // the default size of folder is zero.

    void addNode(Node* Node) {
    // add Node into compound Node.
      Iterator * it = Node->createIterator();
      try{
        it->first();
        Node->updatePath(this->route());
        for(it->first();!it->isDone();it->next()){//可能不用
          it->currentItem()->updatePath(Node->route());
          Iterator * it2 = it->currentItem()->createIterator();
          try{
            it2->first();
            for(it2->first();!it2->isDone();it2->next()){
              it2->currentItem()->updatePath(it->currentItem()->route());
            }
          }catch(std::string e){

          }//可能不用
        }
      }catch(std::string e){
          Node->updatePath(this->route());
      }
      _nodes.push_back(Node);
    }

    void addNodes(std::list<Node*> nodes){
      std::list<Node *>::iterator it = nodes.begin();
      std::list<Node *>::iterator it2 = nodes.end();
      while (it!=it2) {
        _nodes.push_back(*it);
        it++;
      }
    }
    /*
        void addNode(Node* node){
          Iterator * it = node->createIterator();
          try{
            it->first();
            //下面node 是個folder
            //std::cout << this->route() << std::endl;
            node->updatePath(this->route());
            for(it->first();!it->isDone();it->next()){
              //folder內的node做update
              it->currentItem()->updatePath(node->route());
              //要是這個node也是個folder在去對他底下的node做update
              try{
                Iterator * it2 = it->currentItem()->createIterator();
                it2->first();
                for(it2->first();!it2->isDone();it2->next()){
                  it2->currentItem()->updatePath(it->currentItem()->route());
                }
                //底下是個folder
              }catch(std::string){

              }
            }
          }catch(std::string e){
           //這邊是個node
           node->updatePath(this->route());
          }
          //node->updatePath(this->route());
          _nodes.push_back(node);
        }
        */
    void updatePath(std::string path){
      this->_path = path;
    }

    Iterator* createIterator() const {
        Iterator * Nodeiterator = new NodeIterator<std::list<Node *>::const_iterator>(_nodes.begin(), _nodes.end());
        return Nodeiterator;
    }

    double size() const {
    // return sum of all containing Nodes area.
      double a=0;
      std::list<Node *>::const_iterator it = _nodes.begin();
      std::list<Node *>::const_iterator it2 = _nodes.end();
      while (it!=it2) {
      a=a+(*it)->size();
      it++;
      }
    return a;
  }

    void deleteNodeById(std::string id) {
    // search and delete a Node through id,
    // search all the containing Nodes and the tree structure below,
    // if no match of id, throw std::string "Expected delete Node but Node not found"
    //std::cout<<"this is delete id:"<<id<<"\n";
      std::list<Node *>::iterator it = _nodes.begin();
      std::list<Node *>::iterator it2 = _nodes.end();
      int i=0,tag=0;
        while (it!=it2) {
          if((*it)->id()==id){
            _nodes.erase(it);
            tag=1;
            break;
          }
          else{
            try{
              return (*it)->deleteNodeById(id);
            }catch(std::string e){}
          }

          it++;
          i=i+1;
        }

        if(tag==0){
          throw std::string("Expected delete node but node not found.");
        }
      }

      Node * getNodeById(std::string id) const{
  // search and return a Node through id,
  // search all the containing Nodes and the tree structure below,
  // if no match of id, throw std::string "Expected get Node but Node not found"
    std::list<Node *>::const_iterator it = _nodes.begin();
    std::list<Node *>::const_iterator it2 = _nodes.end();
    int tag1=0;
    while (it!=it2) {
      if((*it)->id()==id){
        tag1=1;
        return (*it);
      }
      else{
        try {
          Node * mbox;
          mbox = (*it)->getNodeById(id);
          if(mbox->id()==id){
            tag1=1;
            return (mbox);
          }
          }catch(std::string e) {}
        }
        it++;
      }

      if(tag1==0){
        throw std::string("Expected get node but node not found.");
      }
    }
    // implement any functions inherit from Node that you think is suitable.
    void accept(Visitor* visitor){
      visitor->visitFolder(this);
    }

  private:
      std::list<Node*> _nodes;
};

#endif

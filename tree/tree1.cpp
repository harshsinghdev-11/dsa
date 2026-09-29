#include <iostream>
#include <vector>


class Node{
    public:
    int data;
    std::vector<Node*>children;
    Node(int x){
        data = x;
    }
};

void addChild(Node* parent,Node* child){
    parent->children.push_back(child);
}


#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H

// Yes, this is a very tiny node. Everything is accessibly publicly, without accessors or mutators

class node {
public:
    node *next, *prev;
    unsigned data;
    explicit node(unsigned int data) : data(data), next(nullptr), prev(nullptr) {}
};


#endif //UNTITLED1_NODE_H
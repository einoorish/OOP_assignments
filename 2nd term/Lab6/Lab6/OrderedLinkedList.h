#pragma once
#include "�oordinates.h"
#include <vector>

class OrderedLinkedList {

    struct Node {
        �oordinates coords;
        Node* prev;
        Node* next;
        Node(�oordinates coords, Node* prev, Node* next) :coords(coords), prev(prev), next(next) {};
    };


    Node* first = nullptr;
    Node* last = nullptr;

    int size;

public:
    OrderedLinkedList() : size(0) {}
    static OrderedLinkedList create_empty() { return OrderedLinkedList(); };
    void add(�oordinates coords);
    void remove(int index);
    int find(�oordinates coords);
    std::vector<�oordinates*> find(�oordinates begin, �oordinates end);
    void print();
    ~OrderedLinkedList();

};


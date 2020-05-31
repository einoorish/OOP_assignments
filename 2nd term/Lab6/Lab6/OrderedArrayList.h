#pragma once
#include "�oordinates.h"
#include <vector>

template <size_t capacity>
class OrderedArrayList {
private:

    �oordinates array[capacity];
    size_t size;

public:
    OrderedArrayList() : size(0) {for (size_t i = 0; i < capacity; i++) array[i] = �oordinates(0, 0, 0);}
    static OrderedArrayList create_empty() { return OrderedArrayList(); }
    void add(�oordinates value);
    void remove(unsigned index);
    int find(�oordinates value);
    std::vector<�oordinates*> find(�oordinates start, �oordinates end);
    void print();
};



template <size_t capacity>
void OrderedArrayList<capacity>::add(�oordinates value) {
    if (capacity == 0) return;

    if (size == 0) { array[size++] = value; return; }

    int i = 0;
    for (; i < size && array[i] > value; i++);
    for (size_t j = size; j > i; --j) {
        std::swap(array[j], array[j - 1]);
    }

    size++;
    array[i] = value;

    return;
}

template <size_t capacity>
void OrderedArrayList<capacity>::remove(unsigned indx) {
    for (int i = indx; i < size; ++i) {
        std::swap(array[i], array[i + 1]);
    }
    size--;
}

template <size_t capacity>
int OrderedArrayList<capacity>::find(�oordinates value) {
    for (size_t i = 0; i < size; ++i) { //TODO: binary search?
        if (array[i] == value) {
            return i;
        }
    }
    return -1;
}

template <size_t capacity>
std::vector<�oordinates*> OrderedArrayList<capacity>::find(�oordinates start, �oordinates end) {
    std::vector<�oordinates*> result;
    for (size_t i = 0; i < size; ++i) {
        if (array[i] > start && array[i] < end) {
            result.push_back(&array[i]);
        }
    }
    return result;
}

template <size_t capacity>
void OrderedArrayList<capacity>::print() {
    if (size == 0) { return; }
    for (size_t i = 0; i < size - 1; ++i) {
        std::cout << array[i] << ", ";
    }
    std::cout << array[size - 1] << "." << std::endl;
}
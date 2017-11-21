#include <list>
#include <ostream>
#include <iostream>
#include <algorithm>

// Searching functor
template <class T>
class Finder {
public:
    T data;

    Finder(const T& d) : data(d) {}

    bool operator()(const T& obj) {
        return obj.data == data;
    }
};

template <class T>
class Node {
public:
    T data;

    std::list<Node<T>*> adjacency;

    Node(T d) {
        data = d;
        adjacency = std::list<Node<T>*>();
    }

    void print();

    friend std::ostream& operator<<(std::ostream& os, const Node<T>& n) {
        os << n.data;
        return os;
    }
};

template <class T>
class Graph {
public:

    std::list<Node<T>> nodes;

    Graph() {
        nodes = std::list<Node<T>>();
    }

    void add_node(T);
    void bind(Node<T>, Node<T>);
    bool bind(T, T);
    void print();
};

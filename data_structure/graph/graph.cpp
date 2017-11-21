#include "graph.hpp"

template <class T>
void Graph<T>::add_node(T data) {
    auto n = Node<T>(data);
    nodes.push_back(n);
}

template <class T>
void Graph<T>::print() {
    for (auto const& node : nodes)
        std::cout << node << std::endl;
}

template <class T>
void Node<T>::print() {
    std::cout << "node: " << data << " adjacent nodes: ";
    for (auto const& adjacent_node : adjacency)
        std::cout << *adjacent_node;
    std::cout << std::endl;
}

template <class T>
bool Graph<T>::bind(T a, T b) {
    Node<T>* node_a = nullptr;
    Node<T>* node_b = nullptr;

    for (auto& elem : nodes) {
        if (elem.data == a) {
            node_a = &elem;
        }
        if (elem.data == b) {
            node_b = &elem;
        }
    }
    
    std::cout << node_a->data << std::endl;
    std::cout << node_b->data << std::endl;

    // Both are found, they can be binded together
    if (node_a != nullptr and node_b != nullptr) {
        node_a->adjacency.push_back(node_b);
        node_b->adjacency.push_back(node_a);
    } else {
        return false;
    }

    return true;
}

int main() {
    auto g = new Graph<int>();
    g->add_node(15);
    g->add_node(28);
    g->print();

    g->bind(15, 28);

    g->nodes.front().print();
}

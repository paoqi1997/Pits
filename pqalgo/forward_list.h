#ifndef PQALGO_FORWARD_LIST_H
#define PQALGO_FORWARD_LIST_H

#include <cstddef>

namespace pqalgo
{

template <typename T>
struct Node
{
    Node() : next(nullptr) {}
    Node(T _element) : next(nullptr), element(_element) {}
    Node *next;
    T element;
};

template <typename T>
class forward_list
{
public:
    forward_list() : head(new Node<T>()) {}
    ~forward_list();
    void insert(std::size_t index, T element);
    Node<T>* begin() { return head->next; }
    const Node<T>* begin() const { return head->next; }
private:
    Node<T> *head;
};

template <typename T>
forward_list<T>::~forward_list()
{
    auto p = head;
    while (p != nullptr) {
        auto q = p->next;
        delete p;
        p = q;
    }
    head = nullptr;
}

template <typename T>
void forward_list<T>::insert(std::size_t index, T element)
{
    auto p = head;
    // nextIdx是p的next指针所对应的索引
    std::size_t nextIdx = 0;

    while (p != nullptr && nextIdx++ != index) {
        p = p->next;
    }

    if (p != nullptr) {
        auto node = new Node<T>(element);
        auto q = p->next;
        p->next = node;
        node->next = q;
    }
}

} // namespace pqalgo

#endif // PQALGO_FORWARD_LIST_H

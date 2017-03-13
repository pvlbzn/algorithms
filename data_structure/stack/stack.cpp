// Stack datastructure implementation using singly linked list.
//
// Principal operations on Stack:
//      Push
//      Pop
//
// Stack is a basic abstract data type with two principal operations: push, pop.
// Dataflow is handled as LIFO (last in, first out). Additionally peek operation
// can be implemented to peek at the top of the stack. Stack is a linear data
// structure.
//
// Pavel Bazin 2017
#include "./stack.hpp"

#define NULL 0


node* node_factory(int data)
{
    node *n = new node;
    n->next = NULL;
    n->data = data;

    return n;
}


stack* stack_factory()
{
    stack *s = new stack;
    s->head = NULL;

    return s;
}


void push(stack *s, int data)
{
    if (s->head == NULL) s->head = node_factory(data);
    node *node = node_factory(data);
    node->next = s->head->next;
    s->head = node;
}


int pop(stack *s)
{
    if (s->head == NULL) return NULL;

    node *tmp = s->head;
    int res = tmp->data;
    
    s->head = tmp->next;

    delete tmp;
    return res;
}


int peek(stack *s)
{
    return s->head->data;
}

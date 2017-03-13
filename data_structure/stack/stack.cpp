#include "./stack.hpp"

#define NULL 0
// #pragma once


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

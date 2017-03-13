// Stack datastructure implementation
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



struct stack
{
    struct node* head;
};

struct node
{
    int data;
    struct node *next;
};


void push(stack *s, int data);
int  pop(stack *s);
int  peek(stack *s);

stack* stack_factory();

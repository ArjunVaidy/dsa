#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *top = NULL;

node *push();
node *pop();
node *peek();
node *display();

int main()
{
    int option;
    do
    {
        printf("\n\n *****Main Menu*****");
        printf("\n 1: Push element to the Stack");
        printf("\n 2: Pop element to the Stack");
        printf("\n 3: Peek the stack");
        printf("\n 4: Display the stack elements");
        printf("\n 5: Exit");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        }
    } while (option != 5);
    return 0;
}

node *push()
{
    int num;
    printf("\n Enter the integer element to push to the stack");
    scanf("%d", &num);
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->data = num;
    if (top == NULL)
    {
        new_node->next = NULL;
        top = new_node;
    }
    else
    {
        new_node->next = top;
        top = new_node;
    }
    return top;
}

node *pop()
{
    if (top == NULL)
    {
        printf("\nStack Underflow");
    }
    else if (top->next == NULL)
    {
        node *ptr;
        ptr = top;
        top = NULL;
        free(ptr);
    }
    else
    {
        node *ptr;
        ptr = top;
        top = top->next;
        free(ptr);
    }
    return top;
}

node *peek()
{
    if (top == NULL)
    {
        printf("\nStack Underflow");
    }
    else
    {
        printf("The top element in stack is %d", top->data);
    }
    return top;
}

node *display()
{
    if (top == NULL)
    {
        printf("\nStack Underflow");
    }
    else
    {
        node *ptr;
        ptr = top;
        while (ptr != NULL)
        {
            printf("\t %d", ptr->data);
            ptr = ptr->next;
        }
    }
    return top;
}
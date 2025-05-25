#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *start = NULL;

node *create_cll();
node *display();
node *insert_beg();
node *insert_end();
node *delete_beg();
node *delete_end();
node *delete_after();
node *delete_list();

int main()
{
    int option;
    do
    {
        printf("\n\n *****Main Menu*****");
        printf("\n 1: Create a Circular linked list");
        printf("\n 2: Display the Circular linked list");
        printf("\n 3: Add node at the beginning of the list");
        printf("\n 4: Add node at the end of the list");
        printf("\n 5: Delete node at the beginning of the list");
        printf("\n 6: Delete node at the end of the list");
        printf("\n 7: Delete a node after the given node");
        printf("\n 8: Delete the list");
        printf("\n 9: Exit");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            create_cll();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_beg();
            break;
        case 4:
            insert_end();
            break;
        case 5:
            delete_beg();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_after();
            break;
        case 8:
            delete_list();
            break;
        case 9:
            printf("\nExiting program...\n");
            break;
        }
    } while (option != 9);
    return 0;
}

node *create_cll()
{
    int num;
    printf("\n Enter the data between -1 to end: ");
    scanf("%d", &num);
    while (num != -1)
    {
        node *new_node, *ptr;
        new_node = (node *)malloc(sizeof(node));
        new_node->data = num;
        if (start == NULL)
        {
            new_node->next = new_node;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = start;
        }
        printf("\n Enter the data between -1 to end: ");
        scanf("%d", &num);
    }
    return start;
}

node *display()
{
    node *ptr;
    ptr = start;
    if (start == NULL)
    {
        printf("No data in the list, please add data and view the data");
        return start;
    }
    while (ptr->next != start)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\t %d", ptr->data);
    return start;
}

node *insert_beg()
{
    int num;
    node *ptr, *new_node;
    new_node = (node *)malloc(sizeof(node));
    printf("\nEnter the data between -1 and end: ");
    scanf("%d", &num);
    ptr = start;
    new_node->data = num;
    if (start == NULL)
    {
        new_node->next = new_node;
    }
    else
    {
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = start;
    }
    start = new_node;
    return start;
}

node *insert_end()
{
    int num;
    node *ptr, *new_node;
    new_node = (node *)malloc(sizeof(node));
    printf("\nEnter the data between -1 and end: ");
    scanf("%d", &num);
    ptr = start;
    new_node->data = num;
    if (start == NULL)
    {
        new_node->next = new_node;
        start = new_node;
    }
    else
    {
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = start;
    }
    return start;
}

node *delete_beg()
{
    node *ptr, *temp;
    ptr = start;
    temp = start;
    if (start == NULL)
    {
        printf("It is an empty list");
        return start;
    }
    else if (start->next == start)
    {
        free(start);
        start = NULL;
    }
    else
    {
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = start->next;
        start = start->next;
        free(temp);
    }
    return start;
}

node *delete_end()
{
    node *ptr, *prev_ptr;
    ptr = start;
    prev_ptr = NULL;
    if (start == NULL)
    {
        printf("It is an empty list");
        return start;
    }
    else if (start->next == start)
    {
        free(start);
        start = NULL;
        return start;
    }
    else
    {
        while (ptr->next != start)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = ptr->next;
        free(ptr);
    }
    return start;
}

node *delete_after()
{
    node *ptr, *prev_ptr;
    ptr = start;
    prev_ptr = ptr;
    int num;
    printf("Enter the node after which the node has to be deleted: ");
    scanf("%d", &num);
    if (start == NULL)
    {
        printf("It is an empty list");
        return start;
    }
    else if (start->next == start)
    {
        printf("List has only one value and hence can't be deleted the next node");
        return start;
    }
    else
    {
        while (prev_ptr->data != num)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = ptr->next;
        if (ptr == start)
        {
            start = start->next;
        }
        free(ptr);
    }
    return start;
}

node *delete_list()
{
    node *ptr;
    ptr = start;
    if (start == NULL)
    {
        printf("It is already an empty list");
    }
    else if (start->next == start)
    {
        delete_end();
        return start;
    }
    else
    {
        while (ptr->next != start)
        {
            delete_end();
            ptr = ptr->next;
        }
        free(start);
        start = NULL;
    }
    return start;
}
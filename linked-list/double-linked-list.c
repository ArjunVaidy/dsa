linked - list / test.c #include<stdio.h>
#include <stdlib.h>

                typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

node *start = NULL;
node *end = NULL;

node *create_dll();
node *display();
node *insert_beg();
node *insert_end();
node *insert_after();
node *insert_before();
node *delete_beg();
node *delete_end();
node *delete_after();
node *delete_before();
node *delete_list();

int main()
{
    int option;
    do
    {
        printf("\n\n *****Main Menu*****");
        printf("\n 1: Create a Double linked list");
        printf("\n 2: Display the Circular linked list");
        printf("\n 3: Add node at the beginning of the list");
        printf("\n 4: Add node at the end of the list");
        printf("\n 5: Insert node after the given node");
        printf("\n 6: Insert node before the given node");
        printf("\n 7: Delete the beginning node");
        printf("\n 8: Delete the end node");
        printf("\n 9: Delete a node after the given node");
        printf("\n 10: Delete a node before the given node");
        printf("\n 11: Delete the list");
        printf("\n 12: Exit");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            create_dll();
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
            insert_after();
            break;
        case 6:
            insert_before();
            break;
        case 7:
            delete_beg();
            break;
        case 8:
            delete_end();
            break;
        case 9:
            delete_after();
            break;
        case 10:
            delete_before();
            break;
        case 11:
            delete_list();
            break;
        case 12:
            printf("\nExiting program...\n");
            break;
        }
    } while (option != 12);
    return 0;
}

node *create_dll()
{
    int num;
    printf("\nEnter the data bewtween -1 to end: ");
    scanf("%d", &num);
    while (num != -1)
    {
        node *new_node, *ptr;
        new_node = (node *)malloc(sizeof(node));
        new_node->data = num;
        if (start == NULL)
        {
            new_node->prev = NULL;
            new_node->next = NULL;
            start = new_node;
            end = new_node;
        }
        else if (start->next == NULL)
        {
            new_node->next = NULL;
            new_node->prev = start;
            start->next = new_node;
            end = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            new_node->next = NULL;
            new_node->prev = end;
            end->next = new_node;
            end = new_node;
        }
        printf("\n Enter the data: ");
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
    while (ptr->next != NULL)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\t %d", ptr->data);
    printf("\n \t start-> %d", start->data);
    printf("\n \t end-> %d", end->data);
    return start;
}

node *insert_beg()
{
    int num;
    printf("\nEnter the data: ");
    scanf("%d", &num);
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->data = num;
    if (start == NULL)
    {
        new_node->prev = NULL;
        new_node->next = NULL;
        start = new_node;
        end = new_node;
        return start;
    }
    else
    {
        new_node->prev = NULL;
        new_node->next = start;
        start->prev = new_node;
        start = new_node;
    }
    return start;
}

node *insert_end()
{
    int num;
    printf("\nEnter the Data: ");
    scanf("%d", &num);
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->data = num;
    if (start == NULL)
    {
        new_node->prev = NULL;
        new_node->next = NULL;
        start = new_node;
        end = new_node;
    }
    else
    {
        new_node->next = NULL;
        new_node->prev = end;
        end->next = new_node;
        end = new_node;
    }
    return start;
}

node *insert_after()
{
    if (start == NULL)
    {
        printf("It is an empty list, please add some data");
        return start;
    }
    else
    {
        int num, value;
        printf("Enter the data: ");
        scanf("%d", &num);
        printf("Enter the value after we need to add the data: ");
        scanf("%d", &value);
        node *new_node, *ptr, *next_ptr;
        new_node = (node *)malloc(sizeof(node));
        new_node->data = num;
        if (end->data == value)
        {
            new_node->next = NULL;
            new_node->prev = end;
            end->next = new_node;
            end = new_node;
            return start;
        }
        else
        {
            ptr = start;
            while (ptr->data != value)
            {
                ptr = ptr->next;
            }
        }
        next_ptr = ptr->next;
        new_node->next = next_ptr;
        new_node->prev = ptr;
        ptr->next = new_node;
        next_ptr->prev = new_node;
    }
    return start;
}

node *insert_before()
{
    if (start == NULL)
    {
        printf("It is an empty list, please add some data");
        return start;
    }
    else
    {
        int num, value;
        printf("Enter the data: ");
        scanf("%d", &num);
        printf("Enter the value after we need to add the data: ");
        scanf("%d", &value);
        node *new_node, *ptr, *prev_ptr;
        new_node = (node *)malloc(sizeof(node));
        new_node->data = num;
        if (start->data == value)
        {
            new_node->prev = NULL;
            new_node->next = start;
            start->prev = new_node;
            start = new_node;
            return start;
        }
        else
        {
            ptr = start;
            while (ptr->data != value)
            {
                ptr = ptr->next;
            }
            prev_ptr = ptr->prev;
            new_node->prev = prev_ptr;
            prev_ptr->next = new_node;
            new_node->next = ptr;
            ptr->prev = new_node;
        }
    }
    return start;
}

node *delete_beg()
{
    node *ptr, *next_ptr;
    if (start == NULL)
    {
        printf("\nIt is an empty list");
        return start;
    }
    else if (start->next == NULL)
    {
        ptr = start;
        start = NULL;
        end = NULL;
        free(ptr);
    }
    else
    {
        ptr = start;
        next_ptr = start->next;
        next_ptr->prev = NULL;
        start = next_ptr;
        free(ptr);
    }
    return start;
}

node *delete_end()
{
    if (start == NULL || start->next == NULL)
    {
        delete_beg();
    }
    else
    {
        node *ptr, *prev_ptr;
        ptr = end;
        prev_ptr = end->prev;
        prev_ptr->next = NULL;
        end = prev_ptr;
        free(ptr);
    }
    return start;
}

node *delete_after()
{
    node *ptr, *delete_next, *next_ptr;
    int value;
    printf("\nEnter the value after which node has to be deleted: ");
    scanf("%d", &value);
    if (start == NULL || start->next == NULL)
    {
        printf("It is an empty list or it will have only one element");
        return start;
    }
    else if (end->data == value)
    {
        printf("The value you entered is at the end of the list.No elements to delete");
        return start;
    }
    else
    {
        ptr = start;
        while (ptr->data != value)
        {
            ptr = ptr->next;
        }
        delete_next = ptr->next;
        next_ptr = delete_next->next;
        ptr->next = next_ptr;
        if (next_ptr != NULL)
        {
            next_ptr->prev = ptr;
        }
        if (delete_next = end)
        {
            end = ptr;
        }
        free(delete_next);
    }
    return start;
}

node *delete_before()
{
    if (start == NULL || start->next == NULL)
    {
        printf("It is an empty list or it will have only one element");
        return start;
    }
    else
    {
        int value;
        printf("\nEnter the value before which node has to be deleted: ");
        scanf("%d", &value);
        node *ptr, *delete_ptr, *prev_ptr;
        ptr = start;
        while (ptr->data != value)
        {
            ptr = ptr->next;
        }
        delete_ptr = ptr->prev;
        if (delete_ptr == start)
        {
            ptr->prev = NULL;
            start = ptr;
            free(delete_ptr);
            return start;
        }
        prev_ptr = delete_ptr->prev;
        prev_ptr->next = ptr;
        ptr->prev = prev_ptr;
        free(delete_ptr);
    }
    return start;
}

node *delete_list()
{
    if (start == NULL)
    {
        printf("It is an empty list");
        return start;
    }
    else
    {
        node *ptr, *next_ptr;
        ptr = start;
        while (ptr != NULL)
        {
            next_ptr = ptr->next;
            free(ptr);
            ptr = next_ptr;
        }
        start = NULL;
        end = NULL;
    }
    return start;
}
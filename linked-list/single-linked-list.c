#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *start = NULL;
node *create_ll();
node *display();
node *insert_beg();
node *insert_end();
node *insert_before();
node *insert_after();
node *delete_beg();
node *delete_end();
node *delete_node();
node *delete_after();
node *delete_list();
node *reverse_list();

int main()
{
    int option;
    do
    {
        printf("\n\n *****Main Menu*****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add node at the beginning of the list");
        printf("\n 4: Add node at the end of the list");
        printf("\n 5: Add node before the given node");
        printf("\n 6: Add node after the given node");
        printf("\n 7: Delete node at the beginning of the list");
        printf("\n 8: Delete node at the end of the list");
        printf("\n 9: Delete a node");
        printf("\n 10: Delete a node after the given node");
        printf("\n 11: Delete the list");
        printf("\n 12: Reverse the list");
        printf("\n 13: Exit");
        printf("\n\n Enter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            create_ll();
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
            insert_before();
            break;
        case 6:
            insert_after();
            break;
        case 7:
            delete_beg();
            break;
        case 8:
            delete_end();
            break;
        case 9:
            delete_node();
            break;
        case 10:
            delete_after();
            break;
        case 11:
            delete_list();
            break;
        case 12:
            reverse_list();
            break;
        case 13:
            printf("\nExiting program...\n");
            break;
        }
    } while (option != 13);
    return 0;
}

node *create_ll()
{
    node *new_node, *ptr;
    int num;
    printf("\n Enter the value from -1 to end");
    printf("\n Enter the data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (node *)malloc(sizeof(node));
        new_node->data = num;
        new_node->next = NULL;
        if (start == NULL)
        {
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
        }
        printf("\n Enter the data: ");
        scanf("%d", &num);
    }
    return start;
};

node *display()
{
    node *ptr;
    ptr = start;
    if (ptr == NULL)
    {
        printf("List is empty");
    }
    while (ptr != NULL)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

node *insert_beg()
{
    int num;
    printf("Enter the data: ");
    scanf("%d", &num);
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->data = num;
    if (start == NULL)
    {
        new_node->next = NULL;
        start = new_node;
    }
    else
    {
        new_node->next = start;
        start = new_node;
    }
    return start;
}

node *insert_end()
{
    node *ptr, *new_node;
    int num;
    printf("Enter the data: ");
    scanf("%d", &num);
    new_node = (node *)malloc(sizeof(node));
    ptr = start;
    new_node->data = num;
    new_node->next = NULL;
    if (start == NULL)
    {
        new_node->next = NULL;
        start = new_node;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    return start;
}

// when traversing the linked list always track the previous node - best practice
node *insert_before()
{
    if (start == NULL)
    {
        printf("It is an empty list - Please add data ");
        return start;
    }
    else
    {
        int num, val;
        node *ptr, *prev_ptr, *new_node;
        new_node = (node *)malloc(sizeof(node));
        ptr = start;
        prev_ptr = ptr;
        printf("Enter the data: ");
        scanf("%d", &num);
        printf("Enter the value before we need to add the data: ");
        scanf("%d", &val);
        new_node->data = num;
        while (ptr->data != val)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        // @todo handle the case if the value is not found
        prev_ptr->next = new_node;
        new_node->next = ptr;
    }
    return start;
}

// when traversing the linked list always track the previous node - best practice
node *insert_after()
{
    if (start == NULL)
    {
        printf("It is an empty list - Please add data ");
        return start;
    }
    else
    {
        int num, val;
        node *new_node, *ptr, *prev_ptr;
        new_node = (node *)malloc(sizeof(node));
        printf("Enter the data: ");
        scanf("%d", &num);
        printf("Enter the value after we need to add the data: ");
        scanf("%d", &val);
        new_node->data = num;
        ptr = start;
        prev_ptr = ptr;
        while (prev_ptr->data != val)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        // @todo handle the case if the value is not found
        prev_ptr->next = new_node;
        new_node->next = ptr;
    }
    return start;
}

node *delete_beg()
{
    if (start == NULL)
    {
        printf("It is an empty list - Please add data ");
        return start;
    }
    else
    {
        node *ptr;
        ptr = start;
        start = start->next;
        free(ptr);
        printf("Deleted the first node succesfully");
    }
    return start;
}

node *delete_end()
{
    if (start == NULL)
    {
        printf("It is an empty list - Please add data ");
        return start;
    }
    else
    {
        node *ptr, *prev_ptr;
        ptr = start;
        prev_ptr = ptr;
        while (ptr->next != NULL)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = NULL;
        free(ptr);
    }
    return start;
}

node *delete_node()
{
    node *ptr, *prev_ptr;
    int num;
    printf("Enter the data for which node has to be deleted: ");
    scanf("%d", &num);
    if (start == NULL)
    {
        printf("It is an empty list - Please add data ");
        return start;
    }
    else
    {
        ptr = start;
        if (ptr->data == num)
        {
            delete_beg();
            return start;
        }
        prev_ptr = ptr;
        while (ptr->data != num)
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
    int num;
    node *ptr, *prev_ptr;
    printf("Enter the data after which node has to be deleted: ");
    scanf("%d", &num);
    ptr = start;
    prev_ptr = ptr;
    if (start == NULL)
    {
        printf("It is an empty list - Please add data ");
        return start;
    }
    else
    {
        while (prev_ptr->data != num)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        // at this time prev_ptr will contain the num and ptr will point to node to be deleted
        prev_ptr->next = ptr->next;
        free(ptr);
    }
    return start;
}

node *delete_list()
{
    node *ptr;
    if (start != NULL)
    {
        ptr = start;
        while (ptr != NULL)
        {
            printf("\n %d is to be deleted next", ptr->data);
            start = delete_beg();
            ptr = start;
        }
    }
    return start;
}

node *reverse_list()
{
    node *curr_ptr, *prev_ptr, *next_ptr;
    curr_ptr = start;
    if (start == NULL || start->next == NULL)
    {
        printf("It is an empty/only one item in the list ");
        return start;
    }
    else
    {
        curr_ptr = start;
        prev_ptr = NULL;
        while (curr_ptr != NULL)
        {
            next_ptr = curr_ptr->next; // stroing the reference
            curr_ptr->next = prev_ptr;
            prev_ptr = curr_ptr;
            curr_ptr = next_ptr; // assigning the stored reference
        }
    }
    start = prev_ptr; // now prev_ptr is last node
    return start;
}
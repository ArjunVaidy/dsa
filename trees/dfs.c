#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *new_node(int value)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void print_depth_first(TreeNode *root)
{
    // creating a array that holds pointer to node
    // pointer because --> we need to access left and right node as well its value
    TreeNode *process_stack[100];
    size_t process_stack_num = 0; // how mant elements in the stack

    // initialize with root node
    process_stack[0] = root;
    process_stack_num++;

    while (process_stack_num > 0)
    {
        TreeNode *current = process_stack[process_stack_num - 1];
        process_stack_num--;
        printf("%d", current->data);
        if (current->right != NULL)
        {
            process_stack[process_stack_num] = current->right;
            process_stack_num++;
        }
        if (current->left != NULL)
        {
            process_stack[process_stack_num] = current->left;
            process_stack_num++;
        }
    }
}

int main()
{
    TreeNode *root = new_node(0);
    root->left = new_node(1);
    root->right = new_node(2);
    root->left->left = new_node(3);
    root->left->right = new_node(4);
    root->right->left = new_node(5);
    root->right->right = new_node(6);
    print_depth_first(root);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *new_node(int data)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

void print_breadth_first(TreeNode *root)
{
    // create a queue
    TreeNode *process_queue[100];
    size_t process_stack_num = 0;

    // enqueue with root
    process_queue[0] = root;
    process_stack_num++;

    while (process_stack_num != 0)
    {
        TreeNode *current = process_queue[0];
        printf("%d ", current->data);
        // dequeue the current element
        int i;
        for (i = 0; i < process_stack_num - 1; i++)
        {
            process_queue[i] = process_queue[i + 1];
        }
        process_stack_num--;
        if (current->left != NULL)
        {
            process_queue[process_stack_num] = current->left;
            process_stack_num++;
        }
        if (current->right != NULL)
        {
            process_queue[process_stack_num] = current->right;
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
    print_breadth_first(root);
    return 0;
}
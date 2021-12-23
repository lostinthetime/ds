#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
} node;

void push(node **root, int data)
{
    if (*root == NULL)
    {
        node *temp = (node *)(malloc(sizeof(node)));
        temp->data = data;
        temp->right = temp->left = NULL;
        *root = temp;
    }
    else
    {
        if ((*root)->data > data)
        {
            push(&((*root)->left), data);
        }
        else
        {
            push(&((*root)->right), data);
        }
    }
}

node *minValueNode(node *root)
{
    node *current = root;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
node *deleteNode(node *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void traverse(node *root)
{

    if (root == NULL)
    {
        return;
    }
    printf("%d-> ", root->data);
    traverse(root->left);
    traverse(root->right);
}

int main()
{
    node *root = NULL;
    push(&root, 1);
    push(&root, 4);
    push(&root, 2);
    push(&root, 87);
    push(&root, 23);
    push(&root, 56);
    push(&root, 99);
    push(&root, 12);
    root = deleteNode(root, 23);
    traverse(root);
}
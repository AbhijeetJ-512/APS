#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newnode(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct Node *Insert_node(struct Node *node, int val)
{
    if (node == NULL)
    {
        return newnode(val);
    }
    if (val < node->data)
    {
        node->left = Insert_node(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = Insert_node(node->right, val);
    }
    return node;
}

struct Node *deleteNode(struct Node *root, int k)
{
    if (root == NULL)
        return root;

    if (root->data > k)
    {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k)
    {
        root->right = deleteNode(root->right, k);
        return root;
    }
    if (root->left == NULL)
    {
        struct Node *temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL)
    {
        struct Node *temp = root->left;
        free(root);
        return temp;
    }

    else
    {

        struct Node *succParent = root;

        struct Node *succ = root->right;
        while (succ->left != NULL)
        {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->data = succ->data;

        free(succ);
        return root;
    }
}
int main()
{
    int choice;
    struct Node *root = NULL;
    while (1)
    {
        printf("Enter \n1.Insert node\n2.display Tree(Pre order)\n3.Delete node\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int val;
            printf("Enter value to be added\n");
            scanf("%d", &val);
            root = Insert_node(root, val);
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Enter the value to be deleted\n");
            scanf("%d", &val);
            root = deleteNode(root, val);
            break;
        default:
            break;
        }
    }
}
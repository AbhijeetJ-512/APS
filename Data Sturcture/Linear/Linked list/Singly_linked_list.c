#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *nxt;
};

struct Node *newnode(int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    temp->nxt = NULL;
    return temp;
}

struct Node *Insert_end(struct Node *head, int val)
{
    struct Node *new_node = newnode(val);

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct Node *current = head;

        while (current->nxt != NULL)
        {
            current = current->nxt;
        }

        current->nxt = new_node;
    }
    return head;
}

void display(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d->", current->data);
        current = current->nxt;
    }
    printf("\n");
}

void search(struct Node *head, int val)
{
    if (head == NULL)
    {
        printf("EMPTY LIST\n");
    }
    else
    {
        struct Node *cur = head;
        while (cur != NULL)
        {
            if (cur->data == val)
            {
                printf("Searched successful\n");
                break;
            }
            else
            {
                cur = cur->nxt;
            }
        }
        if (cur == NULL)
        {
            printf("Search unsuccessful\n");
        }
    }
}

int main()
{
    int choice, val;
    struct Node *head = NULL;
    while (1)
    {
        printf("Enter choice\n1.insert end\n2.display\n3.Search\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value\n");
            scanf("%d", &val);
            head = Insert_end(head, val);
            break;
        case 2:
            display(head);
            break;
        case 3:
            printf("Enter the value to be searched\n");
            scanf("%d", &val);
            search(head, val);
            break;

        default:
            break;
        }
    }
}
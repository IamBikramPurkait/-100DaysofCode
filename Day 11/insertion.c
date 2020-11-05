// Day 11 : 5th November, 2020
// Author : Bikram Purkait

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    while (head != NULL)
    {
        printf("Element: %d\n", head->data);
        head = head->next;
    }
}

struct Node *insertAtBegining(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

struct Node *insertAtBetween(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;

    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;

    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    printf("LinkedList before insertion\n");
    linkedListTraversal(head);

    printf("LinkedList after insertion\n");
    // head = insertAtBegining(head, 50);
    // head = insertAtBetween(head, 50,1);
    // head = insertAtEnd(head, 50);
    head = insertAfterNode(head, third, 50);
    linkedListTraversal(head);

    return 0;
}
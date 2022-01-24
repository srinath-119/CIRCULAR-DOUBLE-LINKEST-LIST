#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next, *start;
};
//prototypes
void create(struct node *);
void display(struct node *);
struct node *insertAtBeginning(struct node *);
struct node *insertAtPosition(struct node *);
struct node *insertAtEnd(struct node *);
struct node *deleteFirstNode(struct node *);
struct node *deleteAtPosition(struct node *);
struct node *deleteLastNode(struct node *);
int nodeCount(struct node *);
//driver code
int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    int option;
    printf("Enter 1 to create a doubly circular linked list\n");
    printf("Enter 2 to display the List\n");
    printf("Enter 3 to insert a node at beginning\n");
    printf("Enter 4 to insert a node at gievn position\n");
    printf("Enter 5 to insert a node at last position\n");
    printf("Enter 6 to delete first node of the list\n");
    printf("Enter 7 to delete a node at given position\n");
    printf("Enter 8 to deletelast node of the list\n");
    printf("Enter 9 to get the count of nodes in the list\n");
    printf("Enter 10 to Exit\n");
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            create(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            head = insertAtBeginning(head);
            break;
        case 4:
            head = insertAtPosition(head);
            break;
        case 5:
            head = insertAtEnd(head);
            break;
        case 6:
            head = deleteFirstNode(head);
            break;
        case 7:
            head = deleteAtPosition(head);
            break;
        case 8:
            head = deleteLastNode(head);
            break;
        case 9:
            printf("The Node count is: %d\n", nodeCount(head));
            break;
        }
    } while (option != 10);

    return 0;
}
void create(struct node *head)
{
    struct node *newnode, *temp;
    int n, data;
    if (head == NULL)
    {
        printf("fail to allocate memory\n");
    }

    else
    {

        printf("Enter size of the linked list: ");
        scanf("%d", &n);

        printf("Enter the data for node 1: ");
        scanf("%d", &data);
        head->data = data;
        head->next = head;
        temp = head;
        for (int i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data for node %d: ", i);
            scanf("%d", &data);
            newnode->data = data;
            newnode->start = temp;
            newnode->next = head;
            temp->next = newnode;
            temp = temp->next;
        }
        head->start = temp;
    }
}
//display
void display(struct node *head)
{
    struct node *temp = head;
    printf("The Linked List is :\n");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
//insert beggining
struct node *insertAtBeginning(struct node *head)
{
    struct node *newnode;
    int data;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of noew node: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->start = head->start;
    newnode->next = head;
    head->start->next = newnode;
    head->start = newnode;
    return newnode;
}
//insert at given position
struct node *insertAtPosition(struct node *head)
{
    struct node *newnode, *temp = head;
    int data, pos, i = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the position to insert node: ");
    scanf("%d", &pos);
    printf("Enter the data of new node: ");
    scanf("%d", &data);

    while (i != pos - 1)
    {
        temp = temp->next;
        i++;
    }
    newnode->data = data;
    newnode->start = temp;
    newnode->next = temp->next;
    temp->next->start = newnode;
    temp->next = newnode;
    return head;
}
//insert at last
struct node *insertAtEnd(struct node *head)
{
    struct node *newnode, *temp = head;
    int data;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of noew node: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->start = head->start;
    newnode->next = head;
    head->start->next = newnode;
    head->start = newnode;

    return head;
}
//delete first
struct node *deleteFirstNode(struct node *head)
{
    struct node *temp = head;
    head->start->next = head->next;
    head->next->start = head->start;
    head = head->next;
    free(temp);
    return head;
}
// delete at gievn posistion
struct node *deleteAtPosition(struct node *head)
{
    struct node *temp = head, *ptr;
    int pos, i = 1;
    printf("Enter then node position to delete: ");
    scanf("%d", &pos);
    while (i != pos - 1)
    {
        temp = temp->next;
        i++;
    }
    ptr = temp->next;
    temp->next = ptr->next;
    ptr->start = temp;
    free(ptr);
    return head;
}
//delete last node
struct node *deleteLastNode(struct node *head)
{
    struct node *temp = head;
    temp = head->start;
    head->start->start->next = head;
    head->start = head->start->start;
    free(temp);
    return head;
}
int nodeCount(struct node *head)
{
    int i = 0;
    struct node *temp = head;
    do
    {
        i++;
        temp = temp->next;
    } while (temp != head);

    return i;
}
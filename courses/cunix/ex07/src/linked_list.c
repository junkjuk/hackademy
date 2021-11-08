#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct  node
{
    void *data;
    struct node *next;
} node_t;

node_t *list_create(void *data)
{
    node_t *newNode = malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void list_destroy(node_t **head, void (*fp)(void *data))
{
    
    if (*head == NULL)
    {
        return;
    }
    list_destroy(&(*head)->next, fp);
    (*fp)((*head)->data);
    free(*head);
    *head = NULL;
}

void list_push(node_t *head, void *data)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = list_create(data);
}

void list_unshift(node_t **head, void *data)
{
    node_t *headElement = *head;
    *head = list_create(data);
    (*head)->next = headElement;
}

void *list_pop(node_t **head)
{
    node_t *lastElement = *head;
    while (lastElement->next->next != NULL)
    {
        lastElement = lastElement->next;
    }
    node_t *returnedNode = lastElement->next;
    lastElement->next = NULL;
    return returnedNode;
}

void *list_shift(node_t **head)
{
    node_t *returnedNode = *head;
    *head = (*head)->next;
    return returnedNode;
}

void *list_remove_to_readmy(node_t **head, node_t *ptr)
{
    node_t *search_element = *head;
    while (search_element->next != NULL && search_element->next != ptr)
    {
        search_element = search_element->next;
    }
    search_element->next = search_element->next->next;
    return ptr;
}

void *list_remove(node_t **head, int position)
{
    node_t *search_element = *head;
    for (int i = 0; i < position - 1; i++)
    {
        search_element = (*head)->next;
    }
    node_t *returnedNode = search_element->next;
    search_element->next = search_element->next->next;
    return returnedNode;
}

void list_visitor(node_t *head, void (*fp)(void *data))
{
    while (head != NULL)
    {
        (*fp)(head->data);
        head = head->next;
    }
}

void list_print(node_t *head)
{
    list_visitor(head, my_puts);
}

// void test_destroy_noop(void *data)
// {
//   (void)data;
// }

// int main(){
//     node_t  *head;

//     head = list_create("test");
//     list_push(head, "second element");
//     list_print(head);
//     list_destroy(&head, &test_destroy_noop);
//     printf("Deleted\n");
//     list_print(head);
// }


int my_strlen(const char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        str++;
        len++;
    }
    return len;
}

void my_puts(void *s)
{
    write(STDOUT_FILENO, s, my_strlen(s));
    char emptyStr[] = "\n";
    write(STDOUT_FILENO, emptyStr, sizeof(emptyStr) - 1);
}
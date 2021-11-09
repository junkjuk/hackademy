#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int my_strcmp(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        str1++; 
        str2++;
        if (*str1 > *str2) 
        {
            return 1;
        }
        else if (*str1 < *str2)
        {
            return -1;
        }
    }
    return 0;
}

int my_strlen(char *str)
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


typedef struct node 
{
    void *data;
    char *key;
    struct node *left;
    struct node *right;
} node_t;

node_t *allocnode()
{
    node_t *node = malloc(sizeof(node_t));
    node->left = NULL;
    node->right = NULL;
    node->data = NULL;
    node->key = NULL;
    return node;
}

node_t *insert(node_t *root, char *key, void *data)
{
    if (root == NULL)
    {
        root = allocnode();
    }
    if(root->key == NULL)
    {
        root->data = data;
        root->key = key;
        return root;
    }

    if(my_strcmp(root->key, key) > 0)
    {
        if(root->left == NULL)
        {
            root->left = allocnode();
        }
        insert(root->left, key, data);
        return root;
    }
    else if(my_strcmp(root->key, key) < 0)
    {
        if(root->right == NULL)
        {
            root->right = allocnode();
        }
        insert(root->right, key, data);
        return root;
    }
    else
    {
        root->data = data;
        root->key = key;
        return root;
    }
}

void print_node(node_t *node)
{
    if(node !=  NULL)
    {
        my_puts(node->key);
        my_puts(node->data);
        return;
    }
    my_puts("None");
}

void visit_tree(node_t *node, void (*fp)(node_t *root))
{
    if(node == NULL)
    {
        return;
    }
    (*fp)(node);
    visit_tree(node->left, fp);
    visit_tree(node->right, fp);
}

void destroy_tree(node_t *node, void (*fp)(node_t *root))
{
    visit_tree(node, fp);
}



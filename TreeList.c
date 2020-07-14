/******************************************************************************
*                                                                             *
* Write a recursive function treeToList(Node root) that takes an ordered      *
* binary tree and rearranges it to make a circular doubly linked list out of  *
* the tree nodes. The list should be arranged so that the nodes are in        *
* increasing order. The function returns the head pointer to the new list.    *
*                                                                             *
* Note that treeInsert() function also needs code added.                      *
*                                                                             *
* Example                                                                     *
*   Given tree:                                                               *
*                                                                             *
*         4   <-root                                                          *
*        / \                                                                  *
*       2   5                                                                 *
*      / \                                                                    *
*     1   3                                                                   *
*                                                                             *
*   This program should convert it to:                                        *
*                                                                             *
*            ---<----------<----------<----------<---                         *
*           |  ___     ___     ___     ___     ___   |                        *
*           ->|   |-->|   |-->|   |-->|   |-->|   |-->                        *
*     HEAD--> | 1 |   | 2 |   | 3 |   | 4 |   | 5 |                           *
*          <--|___|<--|___|<--|___|<--|___|<--|___|<-                         *
*          |                                        |                         *
*           --->---------->---------->---------->---                          *
*                                                                             *
*   And the output should simply be:                                          *
*                                                                             *
*     1 2 3 4 5                                                               *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/* The node type from which both the tree and list are built */
struct node {
    int data;
    struct node* left;
    struct node* right;
};
typedef struct node* Node;


/*
 Given the root of an ordered binary tree, recursively change it into
 a circular doubly linked list.
*/
static Node treeToList(Node root) {
    /* ADD CODE HERE */
}


/* Helper function for treeInsert(): create a new node. */
static Node newNode(int data) {
    Node node = (Node) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}


/* Add a new node into a tree */
static void treeInsert(Node* rootRef, int data) {
    Node root = *rootRef;
    if (root == NULL)
        *rootRef = newNode(data);
    else {
        /* ADD CODE HERE */
        /* We already have a root node (i.e. value 4). What next? */
    }
}


static void printList(Node head) {
    Node current = head;

    while(current != NULL) {
        printf("%d ", current->data);
        current = current->right;
        if (current == head)
            break;
    }
    printf("\n");
}


/* Driver function to demo that the code works */
int main() {
    Node root = NULL;
    Node head;

    /* Build the ordered binary tree using below values */
    treeInsert(&root, 4);
    treeInsert(&root, 2);
    treeInsert(&root, 1);
    treeInsert(&root, 3);
    treeInsert(&root, 5);

    /* Convert the tree to a linked list */
    head = treeToList(root);

    /* head should point to the head node of the list */
    printList(head);    /* prints: 1 2 3 4 5  */

    return(0);
}

/******************************************************************************
*                                                                             *
* This program takes string arguments and puts only the strings that have     *
* more than two characters into a linked list. It prints out the strings at   *
* at the end by traversing the linked list.                                   *
*                                                                             *
* Need to make three changes to this program:                                 *
*                                                                             *
* 1) The output has null at the end. Use gdb to find the reason and fix it.   *
* 2) The output is in reverse order. Let's change it to be the same order as  *
*    the argument list. Hint: this can be done by changing insert() function. *
* 3) Remove duplicate strings. If there are repeating strings in the argument *
*    list, let's not show it in the final output.                             *
*                                                                             *
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
    char *str;
    struct Node* next;
};

void insert(struct Node** head_ref, char *new_str)
{
     
        struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
        new_node->str  = new_str;
        new_node->next = NULL;
        
        struct Node *lastNode = *head_ref;
        if (*head_ref == NULL) { 
            *head_ref = new_node; 
            return; 
        }
        else{ 
            if ( strcmp(lastNode->str,new_str)==0)
                    return;
            while (lastNode->next != NULL) { 
                lastNode = lastNode->next;   
                if ( strcmp(lastNode->str,new_str)==0)
                    return;            
            }       
        }    
        lastNode->next = new_node;   
                     
}

void printList(struct Node* n)
{
    while (n != NULL ) 
    { 
        printf("%s ", n->str);
        n = n->next;    
    }
}

int main(int argc, char *argv[])
{
    
    if (argc < 2)
    {
        printf("Please enter at least one string argument to continue!\n");
        return 0;
    }
    int i;
    struct Node* head = NULL;
    
    for (i = 1; i < argc; i++)
    {
        if (strlen(argv[i]) < 3)
            continue;
        insert(&head, argv[i]);
    }

    printList(head);
    printf("\n");
 
    return 0;
}


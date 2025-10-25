#include "list.h"
#include <stdlib.h>
// TODO: Include any necessary header files here

/**
 * Returns the head of the linked list.
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The head of the linked list. If the list is empty (NULL), returns NULL.
 */
struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

/**
 * Returns the tail of the linked list
 * 
 * @param head Pointer to the first node of the linked list.
 * @return The tail of the linked list
 */
struct ll_node *ll_tail(struct ll_node *head) {
    if (head == NULL){
        return NULL;
    }
    struct ll_node *node = head;
    
    while(node -> next != NULL){
        node = node -> next;
    }

    // Once node next is null, that is the last element of the list
    return node;
}

/**
 * Returns size of given linked list
 * 
 * @param head The head of LL
 * @return The size of LL
 */
int ll_size(struct ll_node *head) {
    if (head == NULL){
        return 0;
    }

    int size = 0;
    while(head != NULL) {
        head = head -> next;
        size++;
    }

    return size;
}

/**
 * Finds the location of a numer in LL
 * 
 * @param head the head of LL
 * @param value the value to find
 * 
 * @return the node of the given value
 */
struct ll_node *ll_find(struct ll_node *head, int value) {
    if (head == NULL){
        return NULL;
    }

    while(head != NULL){
        if(head->data == value){
            return head; // breaks loop if value matched
        }

        head = head -> next;
    }

    // if not found, return null
    return NULL;
}

/**
 * Creates an array based off of LL
 * 
 * @param head the start of LL
 * @return the array of
 */
int * ll_toarray(struct ll_node *head) {
    if (head == NULL){
        return NULL;
    }

    int size = (ll_size(head));
    int *array = malloc(size * sizeof(int));

    for(int i = 0; i < size; i++){
        array[i] = head -> data;
        head = head -> next;
    }

    return array;
}

/**
 * Creates a single node LL
 * 
 * @param data the data of the node
 * @return the head of the LL
 */
struct ll_node *ll_create(int data) {
    struct ll_node *head = malloc(sizeof(struct ll_node));
    if (head) *head = (struct ll_node){.data = data, .next = NULL};

    return head;
}

/**
 * Destroys ll
 * 
 * @param header first node in ll
 */
void ll_destroy(struct ll_node *head) {
    struct ll_node *temp;

    while(head != NULL){
        temp = head;
        head = head -> next;
        free(temp);
    }
}

/**
 * Add a node to the end of LL
 * 
 * @param head start of LL
 * @param data node data to add
 */
void ll_append(struct ll_node *head, int data) {
    struct ll_node *last = ll_tail(head);

    struct ll_node *new = malloc(sizeof(*new));
    
    if (new) *new = (struct ll_node){.data = data, .next = NULL};

    last -> next = new;
}

/**
 * Creates a linked list from an array
 * 
 * @param data pointer to array
 * @param len  length of array
 * 
 * @return linked list
 */
struct ll_node *ll_fromarray(int* data, int len) {
    struct ll_node *head = ll_create(data[0]);
    data++;
    struct ll_node *tail = head;

    for(int i = 0; i < len - 1; i++){
        struct ll_node *node = ll_create(data[i]);
        tail -> next = node;
        tail = node;
    }

    return head;
}

/**
 * Removes node from LL
 * 
 * @param head start of ll
 * @param value data of node to remove
 * @return head of edited list
 */
struct ll_node *ll_remove(struct ll_node *head, int value) {
    struct ll_node *prev = NULL;
    struct ll_node *curr = head;

    while (curr != NULL) {
        if (curr->data == value) {
            if (prev) {
                prev->next = curr->next;
            } else {
                head = curr->next;
            }
            free(curr);
            return head; // return updated head
        }
        prev = curr;
        curr = curr->next;
    }

    return head; // value not found
}



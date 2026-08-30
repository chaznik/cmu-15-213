/**
 * @file queue.c
 * @brief Implementation of a queue that supports FIFO and LIFO operations.
 *
 * This queue implementation uses a singly-linked list to represent the
 * queue elements. Each queue element stores a string value.
 *
 * Assignment for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Extended to store strings, 2018
 *
 * TODO: fill in your name and Andrew ID
 * @author XXX <chaznik>
 */

#include "queue.h"
#include "harness.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Allocates a new queue
 * @return The new queue, or NULL if memory allocation failed
 */
queue_t *queue_new(void) {
    queue_t *q = malloc(sizeof(queue_t));

    if (q == NULL) {
        printf("Failed to allocate new queue\n");
        return NULL;
    }

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
    return q;
}

/**
 * @brief Frees all memory used by a queue
 * @param[in] q The queue to free
 */
void queue_free(queue_t *q) {
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
    list_ele_t *temp_node;

    if (q == NULL) {
        return;
    }

    temp_node = q->head;

    while (temp_node != NULL) {
        temp_node = temp_node->next;
        free(q->head->value);
        free(q->head);
        q->head = temp_node;
    }
    free(q);
}

/**
 * @brief Attempts to insert an element at head of a queue
 *
 * This function explicitly allocates space to create a copy of `s`.
 * The inserted element points to a copy of `s`, instead of `s` itself.
 *
 * @param[in] q The queue to insert into
 * @param[in] s String to be copied and inserted into the queue
 *
 * @return true if insertion was successful
 * @return false if q is NULL, or memory allocation failed
 */
bool queue_insert_head(queue_t *q, const char *s) {
    list_ele_t *new_head;
    char *new_val;

    if (q == NULL) {
        return false;
    }

    new_head = malloc(sizeof(list_ele_t));
    new_val = malloc(sizeof(char) * (strlen(s) + 1));

    if (new_head == NULL || new_val == NULL) {
        printf("Failed to allocate memory for new head\n");
        free(new_val);
        free(new_head);
        return false;
    }

    if (q->size == 0) {
        q->tail = new_head;
    }

    strcpy(new_val, s);
    new_head->value = new_val;
    new_head->next = q->head;
    q->head = new_head;
    q->size += 1;
    return true;
}

/**
 * @brief Attempts to insert an element at tail of a queue
 *
 * This function explicitly allocates space to create a copy of `s`.
 * The inserted element points to a copy of `s`, instead of `s` itself.
 *
 * @param[in] q The queue to insert into
 * @param[in] s String to be copied and inserted into the queue
 *
 * @return true if insertion was successful
 * @return false if q is NULL, or memory allocation failed
 */
bool queue_insert_tail(queue_t *q, const char *s) {
    list_ele_t *new_tail;
    char *new_val;

    if (q == NULL) {
        return false;
    }

    new_tail = malloc(sizeof(list_ele_t));
    new_val = malloc(sizeof(char) * (strlen(s) + 1));

    if (new_tail == NULL || new_val == NULL) {
        printf("Failed to allocate memory for new tail\n");
        free(new_val);
        free(new_tail);
        return false;
    }

    strcpy(new_val, s);
    new_tail->value = new_val;
    new_tail->next = NULL;

    if (q->size == 0) {
        q->head = new_tail;
    } else {
        q->tail->next = new_tail;
    }

    q->tail = new_tail;
    q->size += 1;
    return true;
}

/**
 * @brief Attempts to remove an element from head of a queue
 *
 * If removal succeeds, this function frees all memory used by the
 * removed list element and its string value before returning.
 *
 * If removal succeeds and `buf` is non-NULL, this function copies up to
 * `bufsize - 1` characters from the removed string into `buf`, and writes
 * a null terminator '\0' after the copied string.
 *
 * @param[in]  q       The queue to remove from
 * @param[out] buf     Output buffer to write a string value into
 * @param[in]  bufsize Size of the buffer `buf` points to
 *
 * @return true if removal succeeded
 * @return false if q is NULL or empty
 */
bool queue_remove_head(queue_t *q, char *buf, size_t bufsize) {
    /* You need to fix up this code. */
    q->head = q->head->next;
    return true;
}

/**
 * @brief Returns the number of elements in a queue
 *
 * This function runs in O(1) time.
 *
 * @param[in] q The queue to examine
 *
 * @return the number of elements in the queue, or
 *         0 if q is NULL or empty
 */
size_t queue_size(queue_t *q) {
    if (q == NULL || q->size == 0) {
        return 0;
    }

    return q->size;
}

/**
 * @brief Reverse the elements in a queue
 *
 * This function does not allocate or free any list elements, i.e. it does
 * not call malloc or free, including inside helper functions. Instead, it
 * rearranges the existing elements of the queue.
 *
 * @param[in] q The queue to reverse
 */
void queue_reverse(queue_t *q) {
    /* You need to write the code for this function */
}

//
// Created by bolar on 2019. 02. 28..
//

#include "linked_list.h"
#include <malloc.h>
#include <stdio.h>

linked_list_t *linked_list_create()
{
    linked_list_t *linked_list = (linked_list_t *) malloc(sizeof(linked_list_t));

    linked_list->value = NULL;
    linked_list->next = NULL;

    return linked_list;
}

void linked_list_clear(linked_list_t *linked_list)
{
    linked_list_t *node_to_free = linked_list;

    while (node_to_free != NULL) {
        linked_list_t *next_node = node_to_free->next;
        free(node_to_free);
        node_to_free = next_node;
    }
    linked_list->value = NULL;
}

void linked_list_push_back(linked_list_t *linked_list, int value)
{

    if (linked_list->value == NULL) {
        linked_list->value = value;
    } else {

        // Allocate memory for a new node and initialize it
        linked_list_t *new_node = (linked_list_t *) malloc(sizeof(linked_list_t));
        new_node->value = value;
        new_node->next = NULL;

        // Iterate through the list to find the last element
        linked_list_t *it = linked_list;
        while (it->next != NULL) {
            it = it->next;
        }

        // Set the pointer of the last element to the new node
        it->next = new_node;

        // Alternative loop:
        //for (linked_list_node_t *it = linked_list; it->next != NULL; it = it->next)
    }
}

void linked_list_print(linked_list_t *linked_list)
{
    // Iterate through the list
    linked_list_t *it = linked_list;
    while (it != NULL) {
        printf("%d\n", it->value);
        it = it->next;
    }
}

void linked_list_push_front(linked_list_t *linked_list, int value)
{
    linked_list_t *new_node = (linked_list_t *) malloc(sizeof(linked_list_t));
    new_node->value = linked_list[0].value;
    new_node->next = linked_list[0].next;

    linked_list->value = value;
    linked_list->next = new_node;
}

int linked_list_push_after(linked_list_t *linked_list, int index, int value)
{
    linked_list_t *new_node = (linked_list_t *) malloc(sizeof(linked_list_t));
    new_node->value = value;

    int counter = 0;
    linked_list_t *it = linked_list;
    while (counter < index) {
        it = it->next;
        counter++;
    }
    new_node->next = it->next;
    it->next = new_node;

}

int linked_list_size(linked_list_t *linked_list)
{
    int counter = 0;
    linked_list_t *it = linked_list;
    while (it != NULL) {
        it = it->next;
        counter++;
    }
    return counter;
}

int linked_list_empty(linked_list_t *linked_list)
{
    if (linked_list->value == NULL)
        return 1;
    else
        return 0;
}

linked_list_t *linked_list_pop_front(linked_list_t *linked_list)
{
    if(linked_list_size(linked_list)== 1){
        linked_list_clear(linked_list);
    }else {

        linked_list_t *temp = linked_list->next;
        free(linked_list);
        return temp;
    }
}

int linked_list_delete_by_value(linked_list_t *linked_list, int value_to_delete)
{

    int delete_counter = 0;

    linked_list_t *it = linked_list->next;
    linked_list_t *last_before_it = linked_list;

    while (it->next != NULL) { // the first is a special case
        if (it->value == value_to_delete) {
            delete_counter++;
            linked_list_t *temp = it;
            last_before_it->next = it->next;
            it = it->next;
            free(temp);
        }
        last_before_it = it;
        it = it->next;
    }

    if (it->value == value_to_delete)
    {
        delete_counter++;
        last_before_it->next = NULL;
        free(it);
    }

    if(linked_list_size(linked_list) == 1 && linked_list->value == value_to_delete){
        linked_list_clear(linked_list);
    }else if (linked_list->value == value_to_delete) {
        delete_counter++;
        linked_list_t *temp = linked_list->next;
        linked_list->value = linked_list->next->value;
        linked_list->next = linked_list->next->next;
        free(temp);
    }

    return delete_counter;
}

linked_list_t *linked_list_search(linked_list_t *linked_list, int searching)
{
    linked_list_t *it = linked_list;
    while (it != NULL) {
        if (it->value == searching)
            return it;
        else
            it = it->next;
    }
    return NULL;
}

linked_list_t *linked_list_sort(linked_list_t *linked_list)
{

    int changes = 1;
    while (changes != 0) {
        linked_list_t *it = linked_list;
        changes = 0;
        while (it->next != NULL) {
            if (it->value > it->next->value) {
                int temp = it->value;
                it->value = it->next->value;
                it->next->value = temp;
                changes++;
            }
            it = it->next;
        }
    }
    return linked_list;
}

linked_list_t *linked_list_sort_insertion(linked_list_t *linked_list)
{

    int list_size = linked_list_size(linked_list);
    linked_list_t *list_array[list_size];
    int counter = 0;
    linked_list_t *it = linked_list;
    while (it != NULL) {
        list_array[counter]=it;
        it = it->next;
        counter++;
    }

    for (int i = 1; i < list_size; ++i) {
        for (int j = i - 1; j >= 0; j--) {
            if (list_array[i]->value >= list_array[j]->value) {
                break;
            } else {
                int temp = list_array[i]->value;
                list_array[i]->value = list_array[j]->value;
                list_array[j]->value = temp;
                i--;
            }

        }

    }
    return linked_list;
}

int linked_list_element_value(linked_list_t *linked_list, int index)
{
    int counter = 0;
    linked_list_t *it = linked_list;
    while (counter < index) {
        it = it->next;
        counter++;
    }
    return it->value;
}


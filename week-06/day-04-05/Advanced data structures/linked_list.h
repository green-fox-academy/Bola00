//
// Created by bolar on 2019. 02. 28..
//

#ifndef ADVANCED_DATA_STRUCTURES_LINKED_LIST_H
#define ADVANCED_DATA_STRUCTURES_LINKED_LIST_H

typedef struct linked_list
{
  int value;
  struct linked_list *next;
} linked_list_t;

linked_list_t *linked_list_create();

void linked_list_clear(linked_list_t *linked_list);

void linked_list_push_back(linked_list_t *linked_list, int value);

void linked_list_push_front(linked_list_t *linked_list, int value);

int linked_list_push_after(linked_list_t *linked_list, int index, int value);

void linked_list_print(linked_list_t *linked_list);

int linked_list_size(linked_list_t *linked_list);

int linked_list_empty(linked_list_t *linked_list);

linked_list_t* linked_list_pop_front(linked_list_t *linked_list);

int linked_list_delete_by_value(linked_list_t *linked_list, int value_to_delete);

linked_list_t* linked_list_search(linked_list_t *linked_list, int searching);

linked_list_t* linked_list_sort(linked_list_t *linked_list);

linked_list_t* linked_list_sort_insertion(linked_list_t *linked_list);

int linked_list_element_value (linked_list_t *linked_list, int index);

#endif //ADVANCED_DATA_STRUCTURES_LINKED_LIST_H

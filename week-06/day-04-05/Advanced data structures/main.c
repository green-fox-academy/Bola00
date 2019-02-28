#include <stdio.h>
#include "linked_list.h"

int main()
{
    linked_list_t *list = linked_list_create();

    printf("empty:%d\n", linked_list_empty(list));

    linked_list_push_back(list, 20);
    linked_list_push_back(list, 30);
    linked_list_push_front(list, 40);
    linked_list_push_back(list, 60);
    linked_list_push_back(list, 220);
    linked_list_push_back(list, 10);
    linked_list_push_back(list, 20);
    linked_list_sort_insertion(list);

    linked_list_print(list);

    linked_list_clear(list);
    printf("empty:%d\n", linked_list_empty(list));
    return 0;
}
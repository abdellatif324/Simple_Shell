#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct liststr
{
    char *str;
    struct liststr *next;
};

typedef struct liststr list_t;

int delete_node_at_index(list_t **head_ref, int index);
int get_node_index(list_t *head, list_t *node);
list_t *node_starts_with(list_t *head, char *str, int len);

#endif /* LINKED_LIST_H */


#endif /* LINKED_LIST_H */


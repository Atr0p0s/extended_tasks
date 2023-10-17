#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_list t_list;

struct s_list
{
    int 	data;
    t_list  *next;
};

int ascending(int a, int b)
{
    return (a <= b);
}

t_list* sort_list(t_list *lst, int (*cmp)(int, int))
{
    int swapped = true;
    while (swapped) {
        swapped = false;
        t_list *current = lst;
        t_list *next = lst->next;
        while (next) {
            if (!cmp(current->data, next->data)) {
                int tmp = current->data;
                current->data = next->data;
                next->data = tmp;
                swapped = true;
            }
            current = next;
            next = next->next;
        }
    }
}

int main(int argc, char **argv)
{
    t_list q, w, e, r, t, y;
    q.data = 23;
    q.next = &w;
    w.data = 56;
    w.next = &e;
    e.data = 2;
    e.next = &r;
    r.data = 7;
    r.next = &t;
    t.data = 4;
    t.next = &y;
    y.data = 1;
    y.next = NULL;

    t_list *node = &q;
    printf("Unsorted list: ");
    while (node) {
        printf("%d ", node->data);
        node = node->next;
    }
    puts("");

    sort_list(&q, ascending);
    node = &q;
    printf("Sorted list: ");
    while (node) {
        printf("%d ", node->data);
        node = node->next;
    }
    puts("");

    return 0;
}
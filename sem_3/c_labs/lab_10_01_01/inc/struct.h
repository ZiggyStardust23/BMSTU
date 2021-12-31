#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

#endif
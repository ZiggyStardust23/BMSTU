#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct node node_t;
typedef struct poly_elem poly_el;


struct poly_elem
{
    int coef;
    int pow;
};

struct node
{
    poly_el elem;
    node_t *next;
};

#endif
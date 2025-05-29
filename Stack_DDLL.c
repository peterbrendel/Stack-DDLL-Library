#include "Stack_DDLL_pri.h"

int stack(ppStack pp, int sizedata) {
    pStack stack = (Stack*) malloc(sizeof(Stack));
    if (!stack) return FAIL;

    if (cDDLL(&(stack->data), sizedata) == FAIL) {
        free(stack);
        return FAIL;
    }

    *pp = stack;
    return SUCCESS;
}

int unstack(ppStack pp) {
    if (pp == NULL || *pp == NULL) return FAIL;

    dDDLL(&((*pp)->data));
    free(*pp);

    return SUCCESS;
}

int push(pStack p, void *element) {
    if (p == NULL) return FAIL;

    return iBegin(p->data, element);
}

int pop(pStack p, void *element) {
    if (p == NULL) return FAIL;

    return rBegin(p->data, element);
}

int cleanStack(pStack p) {
    if (p == NULL) return FAIL;

    return cleanDDLL(p->data);
}

int top(pStack p, void *top) {
    if (p == NULL) return FAIL;

    return sBegin(p->data, top);
}

int emptyStack(pStack p) {
    if (p == NULL) return FAIL;

    return empty(p->data);
}

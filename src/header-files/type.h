#ifndef type_h
#define type_h

typedef struct card {
    unsigned int long number;
    struct card_t *next;
} card_t;

typedef struct list {
    card_t *front;
    card_t *back;
} list_t;

#endif
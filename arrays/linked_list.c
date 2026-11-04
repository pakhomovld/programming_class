#include <stdlib.h>
#include <stdio.h>

struct cell {
    int num;
    struct cell* next;
};



void iterate_over_linked_list(struct cell* a){
    while (a != NULL){
        printf("%d", a->num);
        a = a->next;
    }
}

void del_last_element(struct cell* a){
    if (a == NULL || a->next == NULL){
        return;
    }
    while (a->next->next != NULL){
        a = a->next;
    }
    a->next = NULL;
}

struct cell* concat(struct cell* a, struct cell* d){
    if (a == NULL) return d;
    if (d == NULL) return a;

    struct cell* current = a;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = d;
    return a;
}

int main(){
    struct cell a;
    struct cell b;
    struct cell c;
    
    struct cell d;
    struct cell e;

    a.num = 1;
    a.next = &b;

    b.num = 2;
    b.next = &c;

    c.num = 3;
    c.next = NULL;

    d.num = 4;
    d.next = &e;

    e.num = 5;
    e.next = NULL;


    // printf("%d\n", a.num);
    // printf("%d\n", a.next->num);
    // printf("%d", a.next->next->num);

    printf("Original list: \n");
    iterate_over_linked_list(&a); // Prints: 1 2 3

    printf("\nInput lists: \n");
    iterate_over_linked_list(&a);
    printf(" ");
    iterate_over_linked_list(&d);

    concat(&a,&d);

    printf("\nConcatenated: \n");
    iterate_over_linked_list(&a);

    del_last_element(&a);

    printf("\nAfter deleting last element: \n");
    iterate_over_linked_list(&a); // Prints: 1 2


    return 0;
}


// HW:
// 1. написать функцию которая удаляет последний элемент из списка
// 2. функция которая склеивает два списка(конкатенация)


// Haskell(functional, recursion thinking) -> Scala, Erlang (hybrid) - 

// Python

// C

// Assembler(machine code)
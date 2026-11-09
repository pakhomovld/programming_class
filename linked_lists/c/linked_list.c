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

void flush_list(struct cell* a){
    while (a != NULL){
        struct cell* tmp = a->next;
        free(a);
        a = tmp;
    }
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

struct cell* add_to_list(struct cell* a, int n){
    struct cell* ptr = malloc(sizeof(struct cell));
    ptr->next = a;
    ptr->num = n;

    return ptr;
}

struct cell* arr_to_list(int arr[], int arr_len){
    struct cell* result = NULL;

    for (int i = arr_len - 1; i >= 0; i--){
        result = add_to_list(result, arr[i]);
    }
    return result;
}

struct cell* quick_sort(struct cell* a){
    if (a == NULL || a->next == NULL){
        return a;
    }
    else {
        struct cell* list_before = NULL;
        struct cell* list_after = NULL;
        struct cell* ptr = NULL;
        struct cell* first = a;
        a = a->next;
        
        while (a != NULL){
            if (a->num < first->num){
                ptr = a->next;
                a->next = list_before;
                list_before = a;
                a = ptr;
            }
            else {
                ptr = a->next;
                a->next = list_after;
                list_after = a;
                a = ptr;
            }

        }
        first->next = quick_sort(list_after);
        return concat(quick_sort(list_before), first);
    }
}   

int main(){
    // struct cell a;
    // struct cell b;
    // struct cell c;
    
    // struct cell d;
    // struct cell e;

    int nums[] = {5, 3, 8, 2, 7, 1};

    // a.num = 1;
    // a.next = &b;

    // b.num = 2;
    // b.next = &c;

    // c.num = 3;
    // c.next = NULL;

    // d.num = 4;
    // d.next = &e;

    // e.num = 5;
    // e.next = NULL;


    // printf("%d\n", a.num);
    // printf("%d\n", a.next->num);
    // printf("%d", a.next->next->num);

    struct cell* a = arr_to_list(nums, 6);

    printf("Original list: \n");
    iterate_over_linked_list(a);

    // printf("\nInput lists: \n");
    // iterate_over_linked_list(a);
    // printf(" ");
    // iterate_over_linked_list(&d);

    // concat(a,&d);

//     printf("\nConcatenated: \n");
//     iterate_over_linked_list(a);

//     del_last_element(a);

//     printf("\nAfter deleting last element: \n");
//     iterate_over_linked_list(a); // Prints: 1 2

//     printf("\nAdding new element: \n");
//   //  struct cell* new = add_to_list(&a,7);
//     iterate_over_linked_list(add_to_list(a,7));

    
    //iterate_over_linked_list(a);

    printf("quick sort:\n");
    struct cell* sorted = quick_sort(a);
    iterate_over_linked_list(sorted);

    flush_list(a);
    return 0;
}


// HW:
// 1. написать функцию которая удаляет последний элемент из списка
// 2. функция которая склеивает два списка(конкатенация)


// Haskell(functional, recursion thinking) -> Scala, Erlang (hybrid) - 

// Python

// C

// Assembler(machine code)


// 05.11.2026

// heap: malloc -> free
// stack: input to func -> deleting on out of func

// HW: list
// 1. Написать функцию сортировки quick_sort для списка на С

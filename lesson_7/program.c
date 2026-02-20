#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int len(char* s); 

char* concat(char* a, char* b);

int main(){
    for (int i = 0; i < 10; i++){
        printf("Hello world\n");
    }

    printf("%d\n",factorial(5));
    printf("%d\n",len("hello world!"));

    char* a = "abc";
    char* b = "def";

    printf("%s\n",concat(a,b));

    return 0;
}

int factorial(int n){
    int result = 1;
    for (int i = 1; i <= n; i++){
        result = i * result;
    }
    return result;
}

// AND 
// true & true = true
// true & false = false

// false & true = false
// false & false = false

// \0

int len(char* s){
    int result = 0;

    while (s[result] != '\0')
        result++;
    return result;
}



char* concat(char* a, char* b){

    int len_a = len(a);
    int len_b = len(b);
    int str_len = len_a + len_b;
    char* result = malloc(str_len + 1);

    for (int i = 0; i < len_a; i++){
        result[i] = a[i];
    }
    for (int i = 0; i < len_b; i++){
        result[i+len_a] = b[i];
    }

    result[str_len] = '\0';

    return result;
}


// abc
// 012

// de
// 01

// abcde
// 01234
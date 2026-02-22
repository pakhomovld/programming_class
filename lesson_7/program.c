#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int factorial(int n);

int len(char* s); 

char* concat(char* a, char* b);

bool is_substring(char* a, char* b);
bool is_beginning(char* a, char* b);
bool is_palindrome(char* a);
bool is_lower_case(char* a);
bool is_identifier(char* a);

char* upcase(char* a);
char* swap_case(char* a);
char* reverse(char* a);
char* dup_string(char* a, int b);
char* appendl_char(char* a, char b);
char* appendr_char(char* a, char b);
char* del_symbol(char* a, int b);

int main(){
    for (int i = 0; i < 10; i++){
        printf("Hello world\n");
    }

    printf("%d\n",factorial(5));
    printf("%d\n",len("hello world!"));

    char* a = "abc";
    char* b = "def";

    printf("%s\n",concat(a,b));

    printf("%d\n",is_substring("abc", "qwabc42"));
    printf("%d\n",is_substring("abc", "abcdef"));
    printf("%d\n",is_palindrome("abcba"));
    printf("%d\n",is_lower_case("abcba"));
    printf("%d\n",is_identifier("a123"));

    printf("%s\n",upcase("abcD12"));
    printf("%s\n",swap_case("abcD12"));
    printf("%s\n",reverse("abc"));
    printf("%s\n",dup_string("abc", 3));
    printf("%s\n",appendl_char("abc", 'd'));
    printf("%s\n",appendr_char("abc", 'd'));
    printf("%s\n",del_symbol("abc", 2));

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


// 1. функция is_substring("abc","qwabc42") возвращает 1, если первая строка является подстрокой второго аргумента и 0, если не является.

bool is_substring(char* a, char* b){
    int len_a = len(a);
    int len_b = len(b);
    int j;

    for (int i = 0; i < len_b; i++){
        for (j = 0; j < len_a; j++){
            if (b[i+j] != a[j])
                break;
        }
        if (j == len_a)
        return true;   
    }
    return false;
}

// 2. функция is_beginning("abc","abcdef") возвращает 1, если первая строка является началом второй строки и 0 в противном случае

bool is_beginning(char* a, char* b){
    int len_a = len(a);

    for (int i = 0; i < len_a; i++){
        if (b[i] != a[i])
        return false;
    }
    return true;
}

// 3. функция is_palindrome("abcba") возвращает 1, если строка одинакова при прочтении слева направо и справо налево, т.е. является палиндромом.

bool is_palindrome(char* a){
    int len_a = len(a);

    for (int i = 0; i < len_a/2; i++){
        if (a[i] != a[len_a-i-1])
        return false;
    }
    return true;
}

// 4. функция is_lower_case("abc") возвращает 1, если строка состоит только из букв в нижнем регистре и 0 в противном случае. (см. таблицу ASCII)

bool is_lower_case(char* a){
    int len_a = len(a);

    for (int i = 0; i < len_a; i++){
        if (a[i] > 122 || a[i] < 97)
        return false;
    }
    return true;
}

// 5. функция is_identifier("a123") возвращает 1, если строка является идентификатором. т.е. начинается с буквы за которой идет послдовательность букв и цифр.

bool is_identifier(char* a){
    int len_a = len(a);
    if ((a[0] > 122 || a[0] < 97) && (a[0] > 90 || a[0] < 65))
    return false;

    for (int i = 1; i < len_a; i++){
        if ((a[i] > 122 || a[i] < 97) && (a[i] > 57 || a[i] < 48) && (a[i] > 90 || a[i] < 65))
        return false;
    }
    return true;
}

// 6. upcase("abcD12") -> "ABCD12", преобразует буквы в нижнем регистре в верхний регистр, цифры и буквы в верхнем регистре не трогает (см. таблицу ASCII)

char* upcase(char* a){
    int len_a = len(a);
    char* result = malloc(len_a + 1);

    for (int i = 0; i < len_a; i++){
        if (a[i] >= 97 && a[i] <= 122){
            result[i] = a[i] - 32;
        } else{
            result[i] = a[i];
        }
    }
    result[len_a] = '\0';
    return result;
}

// 7. swap_case("abcD12") -> "ABCd12", то же самое, но буквы в верхем регистре пребразует в нижний регистр (см. таблицу ASCII)

char* swap_case(char* a){
    int len_a = len(a);
    char* result = malloc(len_a + 1);

    for (int i = 0; i < len_a; i++){
        if (a[i] >= 97 && a[i] <= 122){
            result[i] = a[i] - 32;
        } else if (a[i] >= 65 && a[i] <= 90){
            result[i] = a[i] + 32;
            }
        else {
            result[i] = a[i];
        }
    }
    result[len_a] = '\0';
    return result;
}

// 8. reverse("abc") -> "cba", переворачивает строку

char* reverse(char* a){
    int len_a = len(a);
    char* result = malloc(len_a + 1);

    for (int i = 0; i < len_a; i++){
        result[i] = a[len_a-i-1];
    }
    result[len_a] = '\0';
    return result;
}

// 9. dup_string("abc",3) -> "abcabcabc", которая повторяет строку n-е кол-во раз, указанное во втором аргументе

char* dup_string(char* a, int b){
    int len_a = len(a);
    char* result = malloc(len_a * b + 1);

    for (int i = 0; i < b; i++){
        for (int j = 0; j < len_a; j++){
            result[i * len_a + j] = a[j];
        }

    }

    result[len_a * b] = '\0';
    return result;
}

// 10. appendl_char("abc",'d') -> "dabc", которая добавляет к строке один символ слева

char* appendl_char(char* a, char b){
    int len_a = len(a);
    char* result = malloc(len_a + 1 + 1);

    result[0] = b;

    for (int i = 1; i < len_a + 1; i++){
        result[i] = a[i-1];
    }

    result[len_a + 1] = '\0';
    return result;
}

// 11. appendr_char("abc",'d') -> "abcd", которая добавляет к строке один символ справа

char* appendr_char(char* a, char b){
    int len_a = len(a);
    char* result = malloc(len_a + 1 + 1);

    result[len_a] = b;

    for (int i = 0; i < len_a; i++){
        result[i] = a[i];
    }

    result[len_a + 1] = '\0';
    return result;
}

// 12. del_symbol("abcde",2) -> "abde", которая удаляет символ по номеру

char* del_symbol(char* a, int b){
    int len_a = len(a);
    char* result = malloc(len_a);

    for (int i = 0; i < len_a; i++){
        if (i < b){
            result[i] = a[i];
        } else if (i > b){
            result[i-1] = a[i];
        }
    }

    result[len_a - 1] = '\0';
    return result;
}

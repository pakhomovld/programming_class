#include <ctype.h>
#include <stdio.h>
#include <string.h>
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
char* int_to_char(int b);
char* title_case(char* s);
char* pad_left(char* s, int total_width, char pad);
char* pad_left_w_appendl(char* s, int total_width, char pad);
char* pad_right(char* s, int total_width, char pad);
char* pad_right_w_appendr(char* s, int total_width, char pad);
char* center(char* s, int total_width, char pad);
char* center_w_append_concat(char* s, int total_width, char pad);
char* comma_separated(int numbers[], int count);
char* array_to_string(int numbers[], int count, char* prefix, char* suffix);
char* join_strings(char* strings[], int count, char* separator);

int main(){
    // for (int i = 0; i < 10; i++){
    //     printf("Hello world\n");
    // }

    // printf("%d\n",factorial(5));
    // printf("%d\n",len("hello world!"));

    // char* a = "abc";
    // char* b = "def";

    // printf("%s\n",concat(a,b));

    // printf("%d\n",is_substring("abc", "qwabc42"));
    // printf("%d\n",is_substring("abc", "abcdef"));
    // printf("%d\n",is_palindrome("abcba"));
    // printf("%d\n",is_lower_case("abcba"));
    // printf("%d\n",is_identifier("a123"));

    // printf("%s\n",upcase("abcD12"));
    // printf("%s\n",swap_case("abcD12"));
    // printf("%s\n",reverse("abc"));
    // printf("%s\n",dup_string("abc", 3));
    // printf("%s\n",appendl_char("abc", 'd'));
    // printf("%s\n",appendr_char("abc", 'd'));
    // printf("%s\n",del_symbol("abc", 2));

    printf("%s\n",int_to_char(314));
    printf("%s\n",title_case("the c programming language"));
    printf("%s\n",pad_left("hello", 10, '-'));
    printf("%s\n",pad_left_w_appendl("hello", 10, '-'));
    printf("%s\n",pad_right("abc", 8, '.'));
    printf("%s\n",pad_right_w_appendr("abc", 8, '.'));
    printf("%s\n",center("Hi", 9, '='));
    printf("%s\n",center_w_append_concat("Hi", 9, '='));

    int a[] = {1, 100, 45, 8};
    printf("%s\n",comma_separated(a, 4));
    printf("%s\n",array_to_string(a, 4, "[", "]"));

    char* words[] = {"apple", "banana", "kiwi"};
    printf("%s\n",join_strings(words, 3, ", "));

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

// 314

// 314 % 10 = 4
// 314 /= 31

// 31 % 10 = 1
// 31 /= 3 

// 3 % 10 = 3
// 3 /= 0

char* int_to_char(int n){
    char* result = malloc(1);
    result[0] = '\0';

    while (n != 0){
        char* ptr = result;
        result = appendl_char(result, n % 10 + 48);
        free(ptr);

        n /= 10;
    }

    return result;
}



// clang -Wall -Wunreachable-code -g program.c && ./a.out
// leaks --atExit -- ./a.out



// 1. title_case(char* s) -> char*
// "the c programming language" -> "The C Programming Language"

char* title_case(char* s){
    int len_s = len(s);
    char* result = malloc(len_s + 1);
    int new_word = 1;

    for (int i = 0; i <= len_s; i++){
        if (isspace(s[i])) {
            result[i] = s[i];
            new_word = 1;
        } else if (new_word) {
            result[i] = toupper(s[i]);
            new_word = 0;
        } else {
            result[i] = tolower(s[i]);
        }
    }
    return result;
}

// 2.   pad_left(char* s, int total_width, char pad) -> char*
//      pad_left("42", 6, '0') -> "000042"
//      pad_left("hello", 10, '-') -> "-----hello"

char* pad_left(char* s, int total_width, char pad){
    char* result = malloc(total_width + 1);
    int pad_len = total_width - len(s);

    for (int i = 0; i < pad_len; i++){
        result[i] = pad;
    }

    for (int i = pad_len; i < total_width; i++){
        result[i] = s[i - pad_len];
    }

    result[total_width] = '\0';
    return result;
}

char* pad_left_w_appendl(char* s, int total_width, char pad) {
    char* result = malloc(1);
    result[0] = '\0';
    int pad_len = total_width - len(s);

    for (int i = 0; i < pad_len; i++){
        char* ptr = result;
        result = appendl_char(result, pad);
        free(ptr);
    }

    char* ptr = result;
    result = concat(result, s);
    free(ptr);

    return result;
}


// 3. pad_right(char* s, int total_width, char pad) -> char*
// pad_right("abc", 8, '.') -> "abc....."

char* pad_right(char* s, int total_width, char pad){
    char* result = malloc(total_width + 1);
    int len_s = len(s);

    for (int i = 0; i < len_s; i++){
        result[i] = s[i];
    }

    for (int i = len_s; i < total_width; i++){
        result[i] = pad;
    }

    result[total_width] = '\0';
    return result;

}

char* pad_right_w_appendr(char* s, int total_width, char pad){
    char* result = malloc(1);
    result[0] = '\0';
    int pad_len = total_width - len(s);

    for (int i = 0; i < pad_len; i++){
        char* ptr = result;
        result = appendr_char(result, pad);
        free(ptr);
    }

    result = concat(s, result);

    return result;
}


// 4. center(char* s, int total_width, char pad) -> char*
// center("Hi", 9, '=') -> "===Hi===="

char* center(char* s, int total_width, char pad){
    char* result = malloc(total_width + 1);
    int first_pad_len = (total_width - len(s)) / 2;
    int len_s_w_pad = len(s) + first_pad_len;

    for (int i = 0; i < first_pad_len; i++){
        result[i] = pad;
    }

    for (int i = first_pad_len; i < len_s_w_pad; i++){
        result[i] = s[i - first_pad_len];
    }

    for (int i = len_s_w_pad; i < total_width; i++){
        result[i] = pad;
    }

    result[total_width] = '\0';
    return result;
}

char* center_w_append_concat(char* s, int total_width, char pad){
    char* result = malloc(1);
    result[0] = '\0';
    int len_s = len(s);
    int lpad_len = (total_width - len_s) / 2;

    for (int i = 0; i < lpad_len; i++){
        char* ptr = result;
        result = appendl_char(result, pad);
        free(ptr);
    }

    result = concat(result, s);

    for (int i = lpad_len + len_s; i < total_width; i++){
        char* ptr = result;
        result = appendr_char(result, pad);
        free(ptr);
    }

    return result;
}


// 5. comma_separated(int numbers[], int count) -> char*
// int a[] = {1, 100, 45, 8}; -> "1, 100, 45, 8"

char* comma_separated(int numbers[], int count){
    char* result = malloc(1);
    result[0] = '\0';

    for (int i = 0; i < count; i++){
        char* ptr = result;
        char* ptr2 = int_to_char(numbers[i]);
        result = concat(result, ptr2);
        free(ptr);
        free(ptr2);

        if (i != count - 1){
        char* ptr = result;
        result = concat(result, ", ");
        free(ptr);
        }
    }
    return result;
}


// 6. array_to_string(int numbers[], int count, char* prefix, char* suffix) -> char*
// array_to_string(a, 4, "[", "]") -> "[1,100,45,8]"

char* array_to_string(int numbers[], int count, char* prefix, char* suffix){
    char* result = malloc(1);
    result[0] = '\0';

    char* ptr_start = result;
    result = concat(result, prefix);
    free(ptr_start);

    for (int i = 0; i < count; i++){
        char* ptr = result;
        char* ptr2 = int_to_char(numbers[i]);
        result = concat(result, ptr2);
        free(ptr);
        free(ptr2);

        if (i != count - 1){
        char* ptr = result;
        result = concat(result, ",");
        free(ptr);
        }
    }

    char* ptr_end = result;
    result = concat(result, suffix);
    free(ptr_end);

    return result;
}


// 7. join_strings(char* strings[], int count, char* separator) -> char*
// const char *words[] = {"apple", "banana", "kiwi"}; -> "apple, banana, kiwi" (or with different separator)

char* join_strings(char* strings[], int count, char* separator){
    char* result = malloc(1);
    result[0] = '\0';

    for (int i = 0; i < count; i++){
        char* ptr = result;
        result = concat(result, strings[i]);
        free(ptr);

        if (i != count - 1){
        char* ptr = result;
        result = concat(result, separator);
        free(ptr);
        }
    }

    return result;
}
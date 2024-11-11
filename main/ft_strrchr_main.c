#include "libft.h"

void test_ft_strrchr_found() {
    char *str = "Hello, world!";
    assert(ft_strrchr(str, ',') == &str[6]);
}

void test_ft_strrchr_not_found() {
    char *str = "Hello, world!";
    assert(ft_strrchr(str, 'x') == NULL);
}

void test_ft_strrchr_last_char() {
    char *str = "Hello, world!";
    assert(ft_strrchr(str, '!') == &str[12]);
}

void test_ft_strrchr_null_char() {
    char str[] = "foo\0bar";
    assert(ft_strrchr(str, '\0') == &str[3]);
}

void test_ft_strrchr_empty_string() {
    char *str = "";
    assert(ft_strrchr(str, 'x') == NULL);
}

void test_ft_strrchr_char_not_in_string() {
    char *str = "Hello, world!";
    assert(ft_strrchr(str, 'x') == NULL);
}

int main() {
    test_ft_strrchr_found();
    test_ft_strrchr_not_found();
    test_ft_strrchr_last_char();
    test_ft_strrchr_null_char();
    test_ft_strrchr_empty_string();
    test_ft_strrchr_char_not_in_string();
    printf("All tests passed!\n");
    return 0;
}

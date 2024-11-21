#include "../libft/libft.h"

void test_ft_strnstr_found() {
    char *haystack = "Hello, world!";
    char *needle = "world";
    assert(ft_strnstr(haystack, needle, 13) == &haystack[7]);
}

void test_ft_strnstr_not_found() {
    char *haystack = "Hello, world!";
    char *needle = "goodbye";
    assert(ft_strnstr(haystack, needle, 13) == NULL);
}

void test_ft_strnstr_empty_needle() {
    char *haystack = "Hello, world!";
    char *needle = "";
    assert(ft_strnstr(haystack, needle, 13) == haystack);
}

void test_ft_strnstr_empty_haystack() {
    char *haystack = "";
    char *needle = "world";
    assert(ft_strnstr(haystack, needle, 0) == NULL);
}

void test_ft_strnstr_needle_longer_than_haystack() {
    char *haystack = "Hello";
    char *needle = "Hello, world!";
    assert(ft_strnstr(haystack, needle, 5) == NULL);
}

void test_ft_strnstr_max_len_zero() {
    char *haystack = "Hello, world!";
    char *needle = "world";
    assert(ft_strnstr(haystack, needle, 0) == NULL);
}

int main() {
    test_ft_strnstr_found();
    test_ft_strnstr_not_found();
    test_ft_strnstr_empty_needle();
    test_ft_strnstr_empty_haystack();
    test_ft_strnstr_needle_longer_than_haystack();
    test_ft_strnstr_max_len_zero();
    printf("All tests passed!\n");
    return 0;
}

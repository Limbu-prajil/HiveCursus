#include "libft.h"

void test_ft_strncmp_equal_strings() {
    char *str1 = "hello";
    char *str2 = "hello";
    assert(ft_strncmp(str1, str2, 5) == 0);
}

void test_ft_strncmp_different_strings() {
    char *str1 = "hello";
    char *str2 = "world";
    assert(ft_strncmp(str1, str2, 5) < 0);
}

void test_ft_strncmp_prefix_match() {
    char *str1 = "hello";
    char *str2 = "hello world";
    assert(ft_strncmp(str1, str2, 5) == 0);
}

void test_ft_strncmp_different_length() {
    char *str1 = "hello";
    char *str2 = "hello world";
    assert(ft_strncmp(str1, str2, 5) == 0);
    assert(ft_strncmp(str1, str2, 11) < 0);
}

void test_ft_strncmp_null_bytes() {
    char str1[] = "foo\0bar";
    char str2[] = "foo\0baz";
    assert(ft_strncmp(str1, str2, 7) == 0);
    assert(ft_strncmp(str1, str2, 8) < 0);
}

void test_ft_strncmp_zero_length() {
    char *str1 = "hello";
    char *str2 = "world";
    assert(ft_strncmp(str1, str2, 0) == 0);
}

int main() {
    test_ft_strncmp_equal_strings();
    test_ft_strncmp_different_strings();
    test_ft_strncmp_prefix_match();
    test_ft_strncmp_different_length();
    test_ft_strncmp_null_bytes();
    test_ft_strncmp_zero_length();
    printf("All tests passed!\n");
    return 0;
}

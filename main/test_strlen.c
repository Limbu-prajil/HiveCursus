#include "../libft/libft.h"

void test_ft_strlen_empty_string() {
    char *empty_string = "";
    assert(ft_strlen(empty_string) == 0);
}

void test_ft_strlen_single_char_string() {
    char *single_char = "a";
    assert(ft_strlen(single_char) == 1);
}

void test_ft_strlen_multi_char_string() {
    char *multi_char = "hello, world!";
    assert(ft_strlen(multi_char) == 13);
}

void test_ft_strlen_string_with_null_char() {
    char string_with_null[] = "foo\0bar";
    assert(ft_strlen(string_with_null) == 3);
}

void test_ft_strlen_max_size_t() {
    size_t max_size_t = (size_t)-1;
    char *max_size_string = malloc(max_size_t + 1);
    memset(max_size_string, 'a', max_size_t);
    max_size_string[max_size_t] = '\0';
    assert(ft_strlen(max_size_string) == max_size_t);
    free(max_size_string);
}

int main() {
    test_ft_strlen_empty_string();
    test_ft_strlen_single_char_string();
    test_ft_strlen_multi_char_string();
    test_ft_strlen_string_with_null_char();
    test_ft_strlen_max_size_t();
    printf("All tests passed!\n");
    return 0;
}

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

// Helper function to print a hexadecimal number in lowercase
int ft_printf_hexlow(unsigned long long num)
{
    char *base = "0123456789abcdef";
    int count = 0;

    if (num >= 16)
    {
        count += ft_printf_hexlow(num / 16);
    }
    count += write(1, &base[num % 16], 1);
    return count;
}

// Helper function to print a pointer address
int ft_printf_pointer(void *ptr)
{
    unsigned long long address = (unsigned long long)ptr;
    int count = 0;

    count += write(1, "0x", 2); // Prefix for pointer addresses
    if (address == 0)
    {
        count += write(1, "(nil)", 5);
        return count;
    }
    count += ft_printf_hexlow(address); // Convert and print the pointer value in hex
    return count;
}

// Custom ft_printf function
int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1] == 'p') // Handle %p for pointers
        {
            void *ptr = va_arg(args, void *);
            count += ft_printf_pointer(ptr);
            i += 2;
        }
        else
        {
            count += write(1, &format[i], 1);
            i++;
        }
    }
    va_end(args);
    return count;
}
int main(void)
{
    printf("Test: Pointer Specifier\n");
    int x = 42;

    ft_printf("Custom print function - Pointer: %p\n", &x);
    printf("Standard print function - Pointer: %p\n", &x);

    return 0;
}

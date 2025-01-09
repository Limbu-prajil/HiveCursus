#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char *buf;
    struct Node *next;
} node;

void func4(node *****list)
{
  printf("%p\n", ****list);
}

void func3(node ****list)
{
  printf("%p\n", ***list);
  func4(&list);
}

void func2(node ***list)
{
  printf("%p\n", **list);
  func3(&list);
}

void func1(node **list)
{
  printf("%p\n", *list);
  func2(&list);
}

int main(void)
{
  node *list=0;
  func1(&list);
  return 0;
}

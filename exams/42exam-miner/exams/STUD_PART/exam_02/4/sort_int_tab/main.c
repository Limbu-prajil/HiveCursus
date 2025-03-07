#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size);

int main(){
	int tab[6] = {6, 50, 14, 23, 26, 9};
	sort_int_tab(tab, 6);
	for (int i = 0; i < 6; i++)
		printf("%d ", tab[i]);
	return 0;
}
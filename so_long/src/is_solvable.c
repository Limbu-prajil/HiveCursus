#include "so_long.h"

void flood_fill(int **tmpmap, int x, int y, int *coll, int *exit)
{
    /* int i = -1;
	while (++i < 5)
	{
		int j = -1;
		while (++j < 13)
			printf("%c ", tmpmap[i][j]);
		printf("\n");
	}
    printf("\n"); */
    if (tmpmap[x][y] == '1' || tmpmap[x][y] == 'F' )
        return ;
    if (tmpmap[x][y] == 'E')
        *exit = 1;
    if (tmpmap[x][y] == 'C')
        (*coll)--;
    tmpmap[x][y] = 'F';
    flood_fill(tmpmap, x + 1, y, coll, exit);
    flood_fill(tmpmap, x - 1, y, coll, exit);
    flood_fill(tmpmap, x, y + 1, coll, exit);
    flood_fill(tmpmap, x, y - 1, coll, exit);
}

static int count_coll(t_base *base, int **tmpmap)
{
    int i;
    int j;
    int count;

    i = -1;
    count = 0;
    while (++i < base->game->height)
    {
        j = -1;
        while (++j < base->game->width)
        {
            if (tmpmap[i][j] == 'C')
            {
                printf("coll: %d, %d\n", i, j);
                count++;
            }
        }
    }
    return (count);
}

int     is_solvable(t_base *base, int **tmpmap)
{
    int c;
    int e;
    
    printf("x: %d, y: %d\n", base->game->player.x, base->game->player.y);
    c = count_coll(base, tmpmap);
    //printf("c: %d\n", c);
    e = 0;
    flood_fill(tmpmap, base->game->player.y, base->game->player.x, &c, &e);
    /* int i = -1;
	while (++i < base->game->height)
	{
		int j = -1;
		while (++j < base->game->width)
			printf("%c ", tmpmap[i][j]);
		printf("\n");
	} */
    //printf("e: %d\n", e);
    //printf("c: %d\n", c);
    if (e == 1 && c == 0)
        return 1;
    return 0;
}

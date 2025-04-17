#include "so_long.h"

void flood_fill(int **tmpmap, int x, int y, int *coll, int *exit)
{
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
                count++;
        }
    }
    return (count);
}

int     is_solvable(t_base *base, int **tmpmap)
{
    int c;
    int e;
    
    c = count_coll(base, tmpmap);
    e = 0;
    flood_fill(tmpmap, base->game->player.x, base->game->player.y, &c, &e);
    printf("%d\n", e);
    printf("%d\n", c);
    if (e == 1 && c == 0)
        return 1;
    return 0;
}

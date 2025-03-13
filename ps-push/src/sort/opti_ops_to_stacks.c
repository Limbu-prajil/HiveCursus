#include "../../inc/push_swap.h"

void	critical_art_a(t_data *stacks, t_list *stb, int db, int ops)
{
	int		best_nbr;
	int		best_depth_b;

	best_nbr = -42;
	best_depth_b = -42;
	while (stb->next != stacks->b)
	{
		if (best_combo(stacks, best_depth_a(stacks->a, stb->nbr), db) < ops)
		{
			ops = best_combo(stacks, best_depth_a(stacks->a, stb->nbr), db);
			best_nbr = stb->nbr;
			best_depth_b = db;
		}
		db++;
		stb = stb->next;
	}
	if (best_combo(stacks, best_depth_a(stacks->a, stb->nbr), db) < ops)
	{
		ops = best_combo(stacks, best_depth_a(stacks->a, stb->nbr), db);
		best_nbr = stb->nbr;
		best_depth_b = db;
	}
	combo_exec(stacks, best_depth_a(stacks->a, best_nbr), best_depth_b);
}

void	critical_art_b(t_data *stacks, t_list *sta, int depth_a, int ops)
{
	int		best_nbr;
	int		best_depth_a;

	best_nbr = -42;
	best_depth_a = -42;
	while (sta->next != stacks->a)
	{
		if (best_combo(stacks, depth_a, best_depth_b(stacks->b, sta->nbr)) < ops)
		{
			ops = best_combo(stacks, depth_a, best_depth_b(stacks->b, sta->nbr));
			best_nbr = sta->nbr;
			best_depth_a = depth_a;
		}
		depth_a++;
		sta = sta->next;
	}
	if (best_combo(stacks, depth_a, best_depth_b(stacks->b, sta->nbr)) < ops)
	{
		ops = best_combo(stacks, depth_a, best_depth_b(stacks->b, sta->nbr));
		best_nbr = sta->nbr;
		best_depth_a = depth_a;
	}
	combo_exec(stacks, best_depth_a, best_depth_b(stacks->b, best_nbr));
}

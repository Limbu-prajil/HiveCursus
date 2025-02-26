#include <push_swap.h>

// Push chunks to B with minimal rotations
void push_chunks_to_b(t_stack **a, t_stack **b, int *pivots, int num_chunks, int chunk_size)
{
    if (!pivots || !(*a)) return;

    for (int i = 0; i < num_chunks; i++)
    {
        int moves = 0;
        int total_moves = stack_size(*a);

        while (moves < chunk_size && total_moves--)
        {
            if (!(*a)) break;  // Prevent accessing NULL
            if ((*a)->value <= pivots[i])
            {
                pb(a, b);
                moves++;
                if (*b && (*b)->next && (*b)->value < (*b)->next->value)
                    sb(b); // Immediate optimization
            }
            else if ((*a)->value > pivots[i])
                ra(a); // Only rotate if we see large numbers
        }
    }
}

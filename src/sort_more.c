/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:35:05 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/10 20:18:17 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "operations.h"
#include "libft.h"
#include "sort.h"

static void	sort_small(t_list **a, t_list **b)
{
	while ((*a)->next)
		push(a, b, PB);
	while (*b)
		insert_fastest_a(a, b);
}

static void	sort_big(t_list **a, t_list **b)
{
	int		i;
	t_chunk	chunk;

	i = 0;
	while ((*a)->next->next)
	{
		chunk = def_chunk(2, *a, ft_lstsize(*a));
		push_chunk_b(chunk.chunk[0], chunk.chunk[1], a, b);
		i++;
	}
	push_chunk_b(chunk.chunk[1], chunk.chunk[2], a, b);
	push(b, a, PA);
	while (*b)
		insert_fastest_a(a, b);
}

void	sort_more(t_list **a, t_list **b, size_t len)
{
	if (len > 100)
		sort_big(a, b);
	else
		sort_small(a, b);
	put_nb_top_a(a, find_min(*a));
}

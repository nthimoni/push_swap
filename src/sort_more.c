/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:35:05 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/03 05:41:41 by nthimoni         ###   ########.fr       */
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

static void sort_big(t_list **a, t_list **b, size_t len, int chunk_count)
{
	int		i;
	t_chunk	chunk;

	chunk = def_chunk(chunk_count, *a, len);
	i = 0;
	while (i < chunk.chunk_count)
	{
		push_chunk_b(chunk.chunk[i], chunk.chunk[i + 1], a, b);
		i++;
	}
	push(b, a, PA);
	while (*b)
		insert_fastest_a(a, b);
}


void	sort_more(t_list **a, t_list **b, size_t len)
{
	if (len >= 500)
		sort_big(a, b, len, 2);
	else if (len > 100)
		sort_big(a, b, len, 1);
	else
		sort_small(a, b);
	put_nb_top_a(a, find_min(*a));	
}

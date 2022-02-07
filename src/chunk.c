/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 01:08:32 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/07 18:25:49 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "operations.h"
#include "sort.h"
#include "buffer.h"

static int	get_sup_n(int val, int n, t_list *s)
{
	int	ret;

	ret = val;
	while (n--)
		ret = get_sup(s, ret);
	return (ret);
}

t_chunk	def_chunk(int chunk_count, t_list *a, size_t len)
{
	t_chunk	chunk;
	int		i;

	chunk.chunk_count = chunk_count;
	chunk.chunk = malloc(sizeof(int) * (chunk_count + 1));
	chunk.chunk[0] = find_min(a);
	chunk.chunk[chunk_count] = find_max(a);
	i = 1;
	while (i <= chunk_count - 1)
	{
		chunk.chunk[i] = get_sup_n(chunk.chunk[i - 1], len / chunk_count, a);
		i++;
	}
	return (chunk);
}

static int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static void	push_best(t_list *first, t_list *last, t_list **a, t_list **b)
{
	if (!first || !last)
		return ;
	if (ft_abs(count_put_on_top(*a, first->content))
		< ft_abs(count_put_on_top(*a, last->content)))
		put_nb_top_a(a, first->content);
	else
		put_nb_top_a(a, last->content);
	push(a, b, PB);
}

void	push_chunk_b(int min, int max, t_list **a, t_list **b)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*last;

	first = *a;
	last = NULL;
	while (first)
	{
		tmp = *a;
		first = NULL;
		while (tmp)
		{
			if (tmp->content >= min && tmp->content <= max)
			{
				if (!first)
					first = tmp;
				last = tmp;
			}
			tmp = tmp->next;
		}
		push_best(first, last, a, b);
	}
}

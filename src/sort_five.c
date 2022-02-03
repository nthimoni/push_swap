/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:45:34 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/01 16:50:32 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "buffer.h"
#include "libft.h"

static	void	put_largest_bottom(t_list **a)
{
	if ((*a)->content > (*a)->next->content 
		&& (*a)->content > (*a)->next->next->content)
		rotate(a, NULL, RA);
	else if ((*a)->content < (*a)->next->content 
		&& (*a)->next->content > (*a)->next->next->content)
		rev_rotate(a, NULL, RRA);
}

void	sort_five(t_list **a, t_list **b, size_t len)
{
	if (len > 3)
		push(a, b, PB);
	if (len > 4)
		push(a, b, PB);
	put_largest_bottom(a);
	if ((*a)->content > (*a)->next->content)
		swap((*a), NULL, SA);
	if (len > 3)
	{
		put_nb_top_a(a, get_sup(*a, (*b)->content));
		push(b, a, PA);
		if (len > 4)
		{
			put_nb_top_a(a, get_sup(*a, (*b)->content));
			push(b, a, PA);
		}
		put_nb_top_a(a, find_min(*a));
	}
}

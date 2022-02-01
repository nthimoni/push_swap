/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:45:34 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/01 02:25:09 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "libft.h"

static	void	put_largest_bottom(t_list **a)
{
	if ((*a)->content > (*a)->next->content 
		&& (*a)->content > (*a)->next->next->content)
		rotate(a, NULL, "ra");
	else if ((*a)->content < (*a)->next->content 
		&& (*a)->next->content > (*a)->next->next->content)
		rev_rotate(a, NULL, "rra");
}

void	sort_five(t_list **a, t_list **b, size_t len)
{
	if (len > 3)
		push(a, b, "pb");
	if (len > 4)
		push(a, b, "pb");
	put_largest_bottom(a);
	if ((*a)->content > (*a)->next->content)
		swap((*a), NULL, "sa");
	if (len > 3)
	{
		put_nb_top_a(a, get_sup(*a, (*b)->content));
		push(b, a, "pa");
		put_nb_top_a(a, get_sup(*a, (*b)->content));
		push(b, a, "pa");
		put_nb_top_a(a, find_min(*a));
	}
}

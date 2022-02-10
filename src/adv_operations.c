/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:53:21 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/10 20:14:01 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "operations.h"
#include "buffer.h"

int	find_max(t_list *s)
{
	int	max;

	max = s->content;
	while (s)
	{
		if (s->content > max)
			max = s->content;
		s = s->next;
	}
	return (max);
}

int	find_min(t_list *s)
{
	int	min;

	min = s->content;
	while (s)
	{
		if (s->content < min)
			min = s->content;
		s = s->next;
	}
	return (min);
}

void	put_nb_top_a(t_list **s, int a)
{
	int		ind;
	t_list	*tmp;
	int		len;

	ind = 1;
	tmp = *s;
	while (tmp->content != a)
	{
		tmp = tmp->next;
		ind++;
	}
	len = ft_lstsize(*s);
	if (ind <= (len / 2) + (len % 2))
		while ((*s)->content != a)
			rotate(s, NULL, RA);
	else
		while ((*s)->content != a)
			rev_rotate(s, NULL, RRA);
}

void	put_nb_top_b(t_list **s, int a)
{
	int		ind;
	t_list	*tmp;
	int		len;

	ind = 1;
	tmp = *s;
	while (tmp->content != a)
	{
		tmp = tmp->next;
		ind++;
	}
	len = ft_lstsize(*s);
	if (ind <= (len / 2) + (len % 2))
		while ((*s)->content != a)
			rotate(s, NULL, RB);
	else
		while ((*s)->content != a)
			rev_rotate(s, NULL, RRB);
}

int	get_sup(t_list *s, int a)
{
	int	sup;
	int	min;
	int	max;

	min = find_min(s);
	max = find_max(s);
	if (a > max || a < min)
		return (min);
	sup = max;
	while (s)
	{
		if (s->content > a && s->content < sup)
			sup = s->content;
		s = s->next;
	}
	return (sup);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_fastest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:57:03 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/03 04:03:31 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "buffer.h"
#include "operations.h"

int	count_put_on_top(t_list *s, int a)
{
	int		ind;
	t_list	*tmp;
	int		len;
	int		mid;

	ind = 1;
	tmp = s;
	while (tmp->content != a)
	{
		tmp = tmp->next;
		ind++;
	}
	len = ft_lstsize(s);
	mid = (len / 2) + (len % 2);
	if (ind <= mid)
		return (ind - 1);
	else
	{
		if (len % 2)
			return (-(mid - (ind - mid)));
		else
			return (-(mid - (ind - mid) + 1));
	}
}

t_rotbuf insert_move_count(t_list **from, t_list **to, int val)
{
	int			count_from;
	int			count_to;
	t_rotbuf	buffer;

	buffer = (t_rotbuf){0, 0, 0, 0};
	count_from = count_put_on_top(*from, val);
	count_to = count_put_on_top(*to, get_sup(*to, val));
	if (count_from > 0)
		buffer.r_from = count_from;
	else
		buffer.rr_from = -count_from;
	if (count_to > 0)
		buffer.r_to = count_to;
	else
		buffer.rr_to = -count_to;
	return (buffer);
}

int	nb_rot(t_rotbuf buffer)
{
	int	count;

	if (buffer.r_from > buffer.r_to)
		count = buffer.r_from;
	else
		count = buffer.r_to;
	if (buffer.rr_from > buffer.rr_to)
		count += buffer.rr_from;
	else
		count += buffer.rr_to;
	return (count);
}

void	rotate_buf(t_rotbuf buffer, t_list **b, t_list **a)
{
	while (buffer.r_from && buffer.r_to)
	{
		rotate(a, b, RR);
		buffer.r_from--;
		buffer.r_to--;
	}
	while (buffer.r_from--)
		rotate(b, NULL, RB);
	while (buffer.r_to--)
		rotate(a, NULL, RA);
	while (buffer.rr_from && buffer.rr_to)
	{
		rev_rotate(a, b, RRR);
		buffer.rr_from--;
		buffer.rr_to--;
	}
	while (buffer.rr_from--)
		rev_rotate(b, NULL, RRB);
	while (buffer.rr_to--)
		rev_rotate(a, NULL, RRA);
}

void	insert_fastest_a(t_list **a, t_list **b)
{
	t_rotbuf	buffer;
	t_rotbuf	tmp_buf;
	int			min;
	t_list		*tmp;

	tmp = *b;
	buffer = insert_move_count(b, a, tmp->content);
	min = nb_rot(buffer);
	while (tmp)
	{
		tmp_buf = insert_move_count(b, a, tmp->content);
		if (nb_rot(tmp_buf) < min)
		{
			min = nb_rot(tmp_buf);
			buffer = tmp_buf;
		}
		tmp = tmp->next;
	}
	rotate_buf(buffer, b, a);
	push(b, a, PA);
}

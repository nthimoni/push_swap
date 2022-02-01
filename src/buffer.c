/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 02:40:56 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/01 05:07:02 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "buffer.h"

static int	get_opti2(unsigned int sum)
{
	if (sum == RB + RRB)
		return (0);
	else if (sum == RB + RRR)
		return (RRA);
	else if (sum == RR + RRR)
		return (0);
	else if (sum == RR + RRA)
		return (RB);
	else if (sum == RR + RRB)
		return (RA);
	else if (sum == PA + PB)
		return (0);
	else if (sum == RRA + RRB)
		return (RRR);
	else
		return (-1);
}

static int	get_opti(unsigned int sum)
{
	if (sum == SA + SA)
		return (0);
	else if (sum == SA + SB)
		return (SS);
	else if (sum == SA + SS)
		return (SB);
	else if (sum == SB + SB)
		return (0);
	else if (sum == SB + SS)
		return (SA);
	else if (sum == SS + SS)
		return (0);
	else if (sum == RA + RRR)
		return (RRB);
	else if (sum == RA + RB)
		return (RR);
	else if (sum == RA + RRA)
		return (0);
	return (get_opti2(sum));
}

static void	print_op(unsigned int a)
{
	if (a == SA)
		ft_printf("sa\n");
	else if (a == SB)
		ft_printf("sb\n");
	else if (a == SS)
		ft_printf("ss\n");
	else if (a == RA)
		ft_printf("ra\n");
	else if (a == RB)
		ft_printf("rb\n");
	else if (a == RR)
		ft_printf("rr\n");
	else if (a == PA)
		ft_printf("pa\n");
	else if (a == PB)
		ft_printf("pb\n");
	else if (a == RRA)
		ft_printf("rra\n");
	else if (a == RRB)
		ft_printf("rrb\n");
	else if (a == RRR)
		ft_printf("rrr\n");
}

void	opti_buf(unsigned int *buffer)
{
	int	i;
	int opti;

	i = 0;
	while (i < SWAP_BUF_SIZE - 1 && buffer[i] && buffer[i + 1])
	{
		opti = get_opti(buffer[i] + buffer[i + 1]);
		if (opti > 0)
		{
			buffer[i] = opti;
			ft_memmove(buffer + i + 1, buffer + i + 2, (SWAP_BUF_SIZE - i - 2) * 4);
			buffer[SWAP_BUF_SIZE - 1] = 0;
			i -= 2;
		}
		else if (opti == 0)
		{
			ft_memmove(buffer + i, buffer + i + 2, (SWAP_BUF_SIZE - i - 2) * 4);
			ft_bzero(buffer + SWAP_BUF_SIZE - 2, 2 * 4);
			i -= 2;
		}
		i++;
		if (i < 0)
			i = 0;
	}
}

void	put_buff(unsigned int op)
{
	static unsigned int buffer[SWAP_BUF_SIZE];
	int					i;

	if ((int)op == FLUSH)
	{
		i = -1;
		opti_buf(buffer);
		while (buffer[++i])
			print_op(buffer[i]);
		return ;
	}
	i = 0;
	while (buffer[i])
		i++;
	buffer[i] = op;
	if (buffer[SWAP_BUF_SIZE - 1])
		opti_buf(buffer);
	else
		return ;/*
	if (opti > 0)
		buffer[0] = opti;
	else if (opti == 0)
		ft_bzero(buffer, sizeof(unsigned int) * SWAP_BUF_SIZE);*/
	if (buffer[SWAP_BUF_SIZE - 1])
	{
		print_op(buffer[0]);
		ft_memmove(buffer, buffer + 1, (SWAP_BUF_SIZE - 1) * 4);
		buffer[SWAP_BUF_SIZE - 1] = 0;
	}
}

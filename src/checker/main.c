/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <nthimoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 07:10:51 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/10 20:20:37 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "error.h"
#include "operations.h"
#include "sort.h"
#include "buffer.h"

void	print(int a)
{
	ft_printf("%d ", a);
}

void	print_st(t_list *a, t_list *b)
{
	ft_printf("a : ");
	ft_lstiter(a, print);
	ft_printf("\n");
	ft_printf("b : ");
	ft_lstiter(b, print);
	ft_printf("\n");
}

void	operation(char	*op, t_list **a, t_list **b)
{
	if (!ft_strncmp(op, "ra", 5) || !ft_strncmp(op, "rr", 5))
		rotate(a, NULL, -5);
	if (!ft_strncmp(op, "rb", 5) || !ft_strncmp(op, "rr", 5))
		rotate(b, NULL, -5);
	if (!ft_strncmp(op, "rra", 5) || !ft_strncmp(op, "rrr", 5))
		rev_rotate(a, NULL, -5);
	if (!ft_strncmp(op, "rrb", 5) || !ft_strncmp(op, "rrr", 5))
		rev_rotate(b, NULL, -5);
	if (!ft_strncmp(op, "sa", 5) || !ft_strncmp(op, "ss", 5))
		swap(*a, NULL, -5);
	if (!ft_strncmp(op, "sb", 5) || !ft_strncmp(op, "ss", 5))
		swap(*b, NULL, -5);
	if (!ft_strncmp(op, "pa", 5))
		push(b, a, -5);
	if (!ft_strncmp(op, "pb", 5))
		push(a, b, -5);
}

void	verdict(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b != NULL)
	{
		ft_printf("KO\n");
		return ;
	}
	tmp = *a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
		{
			ft_printf("KO\n");
			return ;
		}
		tmp = tmp->next;
	}
	ft_printf("OK\n");
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	char	*line;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	if (parse(&a, argc, argv) != 0)
		error_msg("Error", a, b);
	line = get_next_line(0);
	while (line)
	{
		line[ft_strlen(line) - 1] = 0;
		operation(line, &a, &b);
		free(line);
		line = get_next_line(0);
	}
	verdict(&a, &b);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
}

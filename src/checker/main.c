/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:35:20 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/08 19:54:15 by nthimoni         ###   ########.fr       */
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

void	operation(char	*op)
{
	
}

int main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (parse(&a, argc, argv) != 0)
		error_msg("Error", a, b);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);	
}

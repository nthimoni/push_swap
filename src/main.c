/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:35:20 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/27 22:42:17 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parse.h"
#include "error.h"


void	print(int a)
{
	ft_printf("%d\n", a);
}
int main(int argc, char *argv[])
{
	t_list	*a_stack;
	t_list	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (parse(&a_stack, argc, argv) != 0)
		error_msg("Error during parsing", a_stack, b_stack);
	ft_lstiter(a_stack, print);
	ft_lstclear(&a_stack, NULL);
	ft_lstclear(&b_stack, NULL);
}

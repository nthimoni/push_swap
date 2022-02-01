/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:19:13 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/01 03:53:26 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "libft.h"

void	swap(t_list *a, t_list *b, int op);
void	push(t_list **from, t_list **tpush, int op);
void	rotate(t_list **s1, t_list **s2, int op);
void	rev_rotate(t_list **s1, t_list **s2, int op);
int		find_min(t_list *s);
int		find_max(t_list *s);
void	put_nb_top_a(t_list **s, int a);
int		get_sup(t_list *s, int a);

#endif

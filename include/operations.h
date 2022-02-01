/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:19:13 by nthimoni          #+#    #+#             */
/*   Updated: 2022/02/01 01:39:37 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

#include "libft.h"

void	swap(t_list *a, t_list *b, char *msg);
void	push(t_list **from, t_list **tpush, char *msg);
void	rotate(t_list **s1, t_list **s2, char *msg);
void	rev_rotate(t_list **s1, t_list **s2, char *msg);
int		find_min(t_list *s);
int		find_max(t_list *s);
void	put_nb_top_a(t_list **s, int a);
int		get_sup(t_list *s, int a);

#endif

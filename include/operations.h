/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:19:13 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/29 00:26:03 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

void	swap(t_list *a, t_list *b, char *msg);
void	push(t_list **from, t_list **tpush, char *msg);
void	rotate(t_list **s1, t_list **s2, char *msg);

#endif

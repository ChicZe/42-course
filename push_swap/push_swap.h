/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:40:46 by ciusca            #+#    #+#             */
/*   Updated: 2024/01/23 16:20:49 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"

typedef struct c_list
{
	int				content;
	struct c_list	*next;
}				t_lst;

char	**matrix_join(char *string, char **mat);
int		matrix_len(char **mat);

/* stack operations */
void	sa(t_lst **stk_a);
void	ra(t_lst **stk_a);
void	rra(t_lst **stk_a);
void	sb(t_lst **stk_b);
void	rb(t_lst **stk_b);
void	rrb(t_lst **stk_b);
void	ss(t_lst **stk_a, t_lst **stk_b);
void	rr(t_lst **stk_a, t_lst **stk_b);
void	rrr(t_lst **stk_a, t_lst **stk_b);
void	pa(t_lst **stk_a, t_lst **stk_b);
void	pb(t_lst **stk_a, t_lst **stk_b);

/* list functions */
t_lst	*ft_newnode(int content);
void	ft_add_back(t_lst **alst, t_lst *new);
void	ft_add_front(t_lst **lst, t_lst *new);
int		ft_size(t_lst *lst);
t_lst	*remove_first(t_lst *stk_a);
t_lst	*create_stack(char **input);

/* lis algorithm */
void	get_arr(t_lst **stk_a);

#endif
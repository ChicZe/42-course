/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:35:14 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/21 11:51:16 by ciusca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"

typedef struct c_list
{
	int				content;
	struct c_list	*next;
}				t_lst;

typedef struct s_arr
{
	int	a_len;
	int	b_len;
}				t_arr;

/* check sorting */
void	init_check(char **input);

/* matrix functions */
int		matrix_len(char **mat);
void	free_matrix(char **mat);
char	**ft_matrix_dup(char **mat);

/* list functions */
t_lst	*ft_newnode(int content);
void	ft_add_back(t_lst **alst, t_lst *node);
void	ft_add_front(t_lst **lst, t_lst *node);
int		ft_size(t_lst *lst);
t_lst	*remove_first(t_lst *stk_a);
t_lst	*create_stack(char **input);
t_lst	*ft_last(t_lst *lst);
void	free_list(t_lst **list);

/* stack operations */
void	sa(t_lst **stk_a, int flag);
void	ra(t_lst **stk_a, int flag);
void	rra(t_lst **stk_a, int flag);
void	sb(t_lst **stk_b, int flag);
void	rb(t_lst **stk_b, int flag);
void	rrb(t_lst **stk_b, int flag);
void	ss(t_lst **stk_a, t_lst **stk_b);
void	rr(t_lst **stk_a, t_lst **stk_b);
void	rrr(t_lst **stk_a, t_lst **stk_b);
void	pa(t_lst **stk_a, t_lst **stk_b);
void	pb(t_lst **stk_a, t_lst **stk_b);

/* parsing */
int		check_sort(t_lst **sa);
void	check_invalid(char **input, int argc);

#endif
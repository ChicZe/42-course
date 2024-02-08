/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:40:46 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/01 18:40:20 by ciusca           ###   ########.fr       */
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

typedef struct s_arr
{
	int	a_len;
	int	b_len;
}				t_arr;

typedef struct s_lis
{
	int		*lis;
	int		n;
	int		end_index;
	int		max_length;
}				t_lis;

/* move cases*/
void	pos_pos(int **moves, int index, t_lst **sa, t_lst **sb);
void	neg_pos(int **moves, int index, t_lst **sa, t_lst **sb);
void	neg_neg(int **moves, int index, t_lst **sa, t_lst **sb);
void	restore_stack(t_lst **sa);

/* matrix functions */
char	**matrix_join(char *string, char **mat);
int		matrix_len(char **mat);

/* parsing */
void	check_duplicates(char **input, int argc);

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

/* list functions */
t_lst	*ft_newnode(int content);
void	ft_add_back(t_lst **alst, t_lst *new);
void	ft_add_front(t_lst **lst, t_lst *new);
int		ft_size(t_lst *lst);
t_lst	*remove_first(t_lst *stk_a);
t_lst	*create_stack(char **input);
void	print_list(t_lst *stack_a);
int		*list_to_array(t_lst *list);

/* utils */
int		*fill_arr(t_arr *stack, t_lst *stack_a, t_lst *stack_b);
int		ft_min(int a , int b);
int		ft_max(int a, int b);
int		find_smallest(int *arr, int n);

/* lis algorithm */
void	get_arr(t_lst **stk_a, t_lis *lis_arr);

/* sorting */
void	init_sort(char **input);

/* move count */
int		*count_b(t_lst *stack_b);
int		*count_a(t_arr *stack, int *sa, int *sb);

#endif
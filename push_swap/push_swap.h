/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciusca <ciusca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:40:46 by ciusca            #+#    #+#             */
/*   Updated: 2024/02/27 20:10:52 by ciusca           ###   ########.fr       */
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
void	free_matrix(char **mat);
char	**ft_matrix_dup(char **mat);

/* parsing */
void	check_invalid(char **input, int argc);
int		check_sort(t_lst **sa);
void	rev_one_sort(t_lst **sa, char **input);
void	check_rev(t_lst **sa, t_lst **sb);

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
t_lst	*ft_last(t_lst *lst);
void	free_list(t_lst **list);

/* utils */
int		*fill_arr(t_arr *stack, t_lst *stack_a, t_lst *stack_b);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		find_smallest(int *arr, int n);
int		find_bigger(int n, int *arr, int target);
int		find_min(int *arr, int n);
int		count_bigger(int target, int *arr, int n);
int		check_swap(t_lst **stk_a, t_lst **stk_b);
void	exit_function(char **input, char *str);

/* lis algorithm */
int		*get_arr(t_lst **stk_a, t_lis *lis_arr);

/* sorting */
void	init_sort(char **input);

/* move count */
int		*count_b(t_lst *stack_b);
int		*count_a(t_arr *stack, int *sa, int *sb);

#endif
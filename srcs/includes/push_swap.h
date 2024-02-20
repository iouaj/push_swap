/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:02:00 by iouajjou          #+#    #+#             */
/*   Updated: 2024/02/20 15:21:51 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"
# include "../srcs/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
	size_t			index;
	int				target;
	int				cost_a;
	int				cost_b;
}	t_stack;

//stack
t_stack	*newstack(int value);
void	addstack(t_stack **stack, t_stack *elem);
size_t	sizestack(t_stack *stack);
void	freestack(t_stack *stack);
void	setindex(t_stack **stack);

void	sort(t_stack **stack);
//Instruction
void	swap(t_stack **stack);
void	swap_both(t_stack **a, t_stack **b);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **stack);
void	rotate_both(t_stack **a, t_stack **b);
void	reverse(t_stack **stack);
void	reverse_both(t_stack **a, t_stack **b);
//utils
int		ft_abs(int nb);
int		is_sort(t_stack *stack);
t_stack	*min_after(t_stack *stack, t_stack *start);
t_stack	*min_stack(t_stack *stack);
void	do_simple(t_stack *minus, t_stack **stack, t_stack **bstack);
//repush
void	repush(t_stack **stack, t_stack **bstack);
//test
t_stack	*split_argv(int argc, char *argv[], t_stack *stack);
void	error(t_stack *stack);
//target
void	get_all_target(t_stack *stack, t_stack *bstack);
void	free_splitter(char **splitter);
#endif

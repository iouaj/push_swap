/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:06:55 by iouajjou          #+#    #+#             */
/*   Updated: 2024/02/20 13:40:16 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	t_stack	*get_stack_end(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

static	t_stack	*get_stack_before_end(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	reverse(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = get_stack_end(*stack);
	before_tail = get_stack_before_end(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	reverse_both(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	if (argc == 1)
		return (0);
	stack_a = split_argv(argc, argv, stack_a);
	setindex(&stack_a);
	if (!is_sort(stack_a))
		sort(&stack_a);
	freestack(stack_a);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:07:50 by iouajjou          #+#    #+#             */
/*   Updated: 2024/02/05 17:28:55 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*newstack(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = value;
	new->next = NULL;
	return (new);
}

void	setindex(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = *stack;
	*stack = min_stack(*stack);
	(*stack)->index = index;
	while (index++ < (int)sizestack(head) - 1)
	{
		*stack = min_after(head, *stack);
		(*stack)->index = index;
	}
	*stack = head;
}

void	addstack(t_stack **stack, t_stack *elem)
{
	t_stack	*temp;

	if (!elem)
	{
		freestack(*stack);
		stack = NULL;
		return ;
	}
	if (!stack || !(*stack))
	{
		*stack = elem;
		return ;
	}
	temp = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = elem;
	*stack = temp;
}

size_t	sizestack(t_stack *stack)
{
	size_t	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	freestack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

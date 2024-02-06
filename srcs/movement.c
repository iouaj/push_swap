/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:59:59 by iouajjou          #+#    #+#             */
/*   Updated: 2024/02/05 17:28:55 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	temp = (*src)->next;
	if (!(*dest))
	{
		*dest = *src;
		(*dest)->next = NULL;
	}
	else
		(*src)->next = *dest;
	*dest = *src;
	*src = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*head;

	if (sizestack(*stack) < (size_t)1)
		return ;
	temp = *stack;
	head = (*stack)->next;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = temp;
	if ((*stack)->next)
		(*stack)->next->next = NULL;
	*stack = head;
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}

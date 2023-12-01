/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:05:20 by iouajjou          #+#    #+#             */
/*   Updated: 2023/12/01 15:42:52 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_pile **pile)
{
	t_pile *temp;
	t_pile *temp_next;

	if (*pile && (*pile)->next)
	{
		temp = *pile;
		temp_next = (*pile)->next->next;
		*pile = (*pile)->next;
		(*pile)->next = temp;
		(*pile)->next->next = temp_next;
	}
}

void push(t_pile **src, t_pile **dest)
{
	t_pile *temp;

	if (*src)
	{
		temp = (*src)->next;
		addpile(dest, (*src));
		(*src) = temp;
	}
}

void rotate(t_pile **pile)
{
	t_pile	*temp;
	t_pile	*newhead;

	if (!(*pile) || !(*pile)->next)
		return ;

	temp = *pile;
	newhead = (*pile)->next;
	while ((*pile)->next)
		*pile = (*pile)->next;
	(*pile)->next = temp;
	(*pile)->next->next = NULL;
	*pile = newhead;
}

void reverse_rotate(t_pile **pile)
{
	t_pile	*temp;
	t_pile	*newhead;

	if (!(*pile) || !(*pile)->next)
		return ;
	temp = *pile;
	while ((*pile)->next->next)
		*pile = (*pile)->next;
	newhead = (*pile)->next;
	(*pile)->next = NULL;
	*pile = newhead;
	// ft_printf("==\n");
	// printpile(*pile);
	// ft_printf("===\n");
	// printpile(temp);
	(*pile)->next = temp;
}

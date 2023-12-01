/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:53:11 by iouajjou          #+#    #+#             */
/*   Updated: 2023/12/01 15:43:00 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libpush/libpush.h"

typedef struct s_pile
{
	int				head;
	struct s_pile	*next;
} t_pile;

int	testpile(t_pile *pile);

//pile.c
t_pile	*newpile(char *value);
size_t	pile_size(t_pile *pile);
void freepile(t_pile *pile);
int	addpile(t_pile **pile, t_pile *new);
//action.c
void swap(t_pile **pile);
void push(t_pile **src, t_pile **dest);
void rotate(t_pile **pile);
void reverse_rotate(t_pile **pile);

int	isnb(char *value);

void sortlower(t_pile **pile_a, t_pile **pile_b, size_t size);

int	ft_atoi(const char *nptr);
void printpile(t_pile *pile);

#endif
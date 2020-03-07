/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazani <hrazani@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:29:52 by hrazani           #+#    #+#             */
/*   Updated: 2020/03/03 18:34:47 by hrazani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void					init_stack(t_stack *head)
{
	head = NULL;
}

t_stack					*push(t_stack *head, int data)
{
	t_stack	*tmp;

	tmp = (t_stack*)malloc(sizeof(t_stack));
	if (tmp == NULL)
		exit(EXIT_FAILURE);
	tmp->data = data;
	tmp->next = head;
	head = tmp;
	return (head);
}

t_stack					*pop(t_stack *head, int *element)
{
	t_stack	*tmp;

	tmp = head;
	*element = head->data;
	head = head->next;
	free(tmp);
	return (head);
}

int						empty(t_stack *head)
{
	return (head == NULL ? 1 : 0);
}

int						stack_len(t_stack *path)
{
	int		len;

	len = 0;
	while (path)
	{
		++len;
		path = path->next;
	}
	return (len);
}

void		free_stack(t_stack *stack)
{
	t_stack *tmp;

	tmp = NULL;
	while (stack != NULL)
	{
		tmp = stack;
		(stack) = (stack)->next;
		free(tmp);
	}
	free(stack);
	stack = NULL;
}
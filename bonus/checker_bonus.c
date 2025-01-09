/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:05:32 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/09 20:27:02 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
int	op(t_stack **a,t_stack **b,char *line)
{ 
	if(ft_strncmp(line,"pa\n",4) == 0)
		return (pa(a,b,-1),1);
	else if(ft_strncmp(line,"pb\n",4) == 0)
		return(pb(a,b,-1),1);
	else if(ft_strncmp(line,"sa\n",4) == 0)
		return (s(a,-1),1);
	else if(ft_strncmp(line,"sb\n",4) == 0)
		return (s(b,-1),1);
	else if(ft_strncmp(line,"ss\n",4) == 0)
		return (ss(a,b),1);
	else if(ft_strncmp(line,"ra\n",4)== 0)
		return (r(a,-1),1);
	else if(ft_strncmp(line,"rb\n",4) == 0)
		return (r(b,-1),1);
	else if(ft_strncmp(line,"rr\n",4) == 0)
		return (rr(a,b),1);
	else if(ft_strncmp(line,"rra\n",5) == 0)
		return (rev_r(a,-1),1);
	else if(ft_strncmp(line,"rrb\n",5) == 0)
		return (rev_r(b,-1),1);
	else if(ft_strncmp(line,"rrr\n",5) == 0)
		return (rrr(a,b),1);
	else
		return (0);
}
int its_sorted(t_stack *a)
{

	t_stack *Next;
	if(a == NULL || a->next == NULL)
		return (1);
	Next = a->next;
	while (Next)
	{
		if(a->number > Next->number)
			return (0);
		a = a->next;
		Next = Next->next;
	}
	return (1);
}

int main (int argc , char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if(argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	parsing(argv,&stack_a);
	line = get_next_line(0);
	while (line)
	{
		if (op(&stack_a,&stack_b,line) == 0)
			(ft_putstr_fd("Erorr\n",2),free_stack(&stack_a),
				free_stack(&stack_b), free(line), exit(1));
		free(line);
		line = get_next_line(0);;
	}
	if(its_sorted(stack_a) == 1)
		ft_putstr_fd("OK\n",1);
	else 
		ft_putstr_fd("KO\n",1);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return(0);
}
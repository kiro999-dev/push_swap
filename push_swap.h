/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkhourba <zkhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:35:17 by zkhourba          #+#    #+#             */
/*   Updated: 2025/01/06 12:24:16 by zkhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

char	**ft_split(const char *s, char c);
void	ft_putstr_fd(char *s, int fd);
void	 ft_free(char **ptr);
long long	ft_atoi(const char *str);
typedef struct s_stack 
{
	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;


#endif 

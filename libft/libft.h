/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:15:57 by aalfahal          #+#    #+#             */
/*   Updated: 2023/02/09 22:59:52 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<stdlib.h>
# include<unistd.h>
# include <stdint.h>

/*********************************--Part One--*********************************/

int		ft_isalnum(char *s);
int		ft_isdgt(int s);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

/*********************************--Part Two--*********************************/

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**********************************--Bonus--***********************************/

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list (*new));
void	ft_lstadd_back(t_list **lst, t_list (*new));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_bfrlast(t_list *lst);

#endif

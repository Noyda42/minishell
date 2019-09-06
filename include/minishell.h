/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:36:32 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/06 16:55:21 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	MINISHELL_H
# define	MINISHELL_H
# include	"libft.h"
# include	"error.h"
# include	<stdio.h>
# define	TRUE	1
# define	FALSE	0
# define 	ECHO_OPT	"neE"

typedef	struct	s_option
{
	char 		*opt;
	char		opterr;
	int			optind;
}				t_option;

int			ft_getopt(int ac, char **av, const char *opt_ref, t_option *opt);
void    	manage_error(int error_code);
void		free_tab(char **tab);
char		**copy_tab(char **tab);
int			ft_echo(char **tab);
void		print_builtin_error(char *builtin_name, char *error_cause);


#endif
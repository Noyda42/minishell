/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:16:54 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/21 15:27:32 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	ERROR_H
# define 	ERROR_H

# define	EOLDPWDM    	1
# define	EMALLOC			2
# define	EINVOPT			3
# define	ENULLPARAM		4
# define	ECOMMANDNF		5
# define	EGNL			6
# define	EACCES			7
# define	EOPNDIR			8
# define	EBADF			9
# define	EHOMENS			10
# define	EDOLLEXP		11
void	print_error(char *func_name, char *error_cause);

#endif
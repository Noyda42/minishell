/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 19:16:54 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/09 20:55:45 by temehenn         ###   ########.fr       */
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


void	print_error(char *func_name, char *error_cause);

#endif
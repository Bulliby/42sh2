/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   term.h                                                                   */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/18 13:08:45 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/18 23:39:07 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_CONF_H
# define TERM_CONF_H

# include <termios.h>

typedef struct termios  t_termios;

typedef struct	        s_term
{
	int				    fd;
	t_termios		    termios;
}				    	t_term;

void		            exit_term(void);
void		            init_term(void);

#endif

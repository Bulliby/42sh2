/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.h                                                                   */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 20:23:27 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/17 20:27:15 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
 
# include <termios.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>



typedef struct termios	t_termios;

typedef struct		s_term
{
	int				fd;
	t_termios		termios;
}					t_term;

#endif

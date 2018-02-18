/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   move.h                                                                   */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 19:36:16 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/18 12:27:06 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# define k_UP "\x1B\x5B\x41"
# define k_DOWN "\x1B\x5B\x42"
# define k_LEFT "\x1B\x5B\x44"
# define k_RIGHT "\x1B\x5B\x43"
# define k_CTRL_RIGHT "\x1B\x5B\x31\x3B\x35\x43"
# define k_CTRL_LEFT "\x1B\x5B\x31\x3B\x35\x44"

typedef struct		s_input
{
	char			*cmd_line;
}					t_input;

typedef struct		s_cursor
{
	int				x;
	int				y;
}					t_cursor;

void				move_right(void);
void				move_left(void);

#endif

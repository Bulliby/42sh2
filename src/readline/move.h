/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   move.h                                                                   */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 19:36:16 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/07/31 19:59:13 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

typedef struct		s_input
{
	char			*cmd_line;
}					t_input;

//TODO: remove from move maybe main.h...
typedef struct		s_cursor
{
	int				x;
	int				y;
}					t_cursor;

void				move_right(void);
void				move_left(void);
void				move_down(void);
void				move_up(void);

void				putchar_move_cursor(void);
#endif

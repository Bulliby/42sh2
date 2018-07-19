/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   input.c                                                                  */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/24 20:36:12 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/07/19 21:13:31 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include "move.h"
#include "winsize.h"
#include "cap.h"
#include "libft.h"

extern t_cursor     g_cursor;
extern int			g_len_prompt;
extern char         *g_input;
extern char         *g_cmdln;
extern t_winsize    g_ws;

/**
 * The term is in insetion mode "im" and the last character of a line is 
 * loose after insetion. I use this fact in insert_rec() who 
 * recursively insert a new character on each full line who was the last 
 * char of the precedent line.
 */
void				insert_rec(int y, int rec)
{
	if (is_line_full(y))
	{
		use_ncap("do", rec);
		ft_putchar(g_cmdln[cursor_to_buffer(g_ws.ws_col, y)\
		- g_len_prompt]);
		use_ncap("up", rec);
		use_cap("cr");
		use_ncap("nd", g_cursor.x - 1);
		insert_rec(y + 1, rec + 1);
	}
}

char				*insert_at(char *buffer, char c)
{
	insert_rec(g_cursor.y, 0);
	g_cmdln = ft_strinsert_at(g_cmdln, c, cursor_to_buffer(g_cursor.x,\
	g_cursor.y) - g_len_prompt);
	ft_putchar(c);
	putchar_move_cursor();
}

/**
 * Compare cmdln with the max characters that can contain a text with a certain 
 * number of line (y).
 * Compare la taille de cmdln avec la taille maximal de characters que peut contenir
 * un text d'un certain nombre de ligne (y).
 */
int					is_line_full(int y)
{
    int cmdln_size = ft_strlen(g_cmdln);
    int max_size;

	max_size = g_ws.ws_col + y * (g_ws.ws_col + 1);
	max_size -= g_len_prompt;

    return (cmdln_size > max_size) ? 1 : 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   v_move.c                                                                 */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/07/31 21:18:24 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/08/15 12:56:29 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "v_move.h"
#include "winsize.h"
#include "cap.h"
#include "libft.h"
#include "move.h"

extern t_cursor         g_cursor;
extern int		        g_len_prompt;
extern char             *g_cmdln;
extern t_winsize        g_ws;

void        v_move_left(int pos)
{
    int     len;

    //Discard if we are at the start of command line
	if (g_cursor.x - 1 < g_len_prompt && g_cursor.y == 0)
		return ;
   
    len = cursor_to_buffer(g_cursor.x, g_cursor.y) - 1;

    if (pos < len)
        use_cap("se");
    else
        use_cap("so");

	ft_putchar(g_cmdln[cursor_to_buffer(g_cursor.x, g_cursor.y)\
     - g_len_prompt]);

	if (g_cursor.x - 1 < 0)
	{
		g_cursor.y--;
		g_cursor.x = g_ws.ws_col;
		use_cap("up");
		use_ncap("nd", g_ws.ws_col - 1);
	}
	else
	{
        /**
         * Like we have alreay write a character we need to go back from
         * 2 positions.
         */
		use_cap("le");
		if (g_cursor.x != g_ws.ws_col)
			use_cap("le");
		g_cursor.x--;
	}
}

void        v_move_right(int pos)
{
    int     len;

    //Discard if we are at the end of command line
	if (cursor_to_buffer(g_cursor.x + 1, g_cursor.y) > \
			(int)ft_strlen(g_cmdln) + g_len_prompt - 1)
		return ;

    len = cursor_to_buffer(g_cursor.x, g_cursor.y) + 1;

    if (pos < len)
        use_cap("so");
    else
        use_cap("se");

	ft_putchar(g_cmdln[cursor_to_buffer(g_cursor.x, \
				g_cursor.y) - g_len_prompt]);

	if (g_cursor.x + 1 <= g_ws.ws_col)
		g_cursor.x++;
	else
	{
		g_cursor.y++;
		g_cursor.x = 0;
		use_cap("cr");
		use_cap("do");
	}
}

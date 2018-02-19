/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   move.c                                                                   */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 20:15:19 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/19 22:15:41 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"
#include "winsize.h"
#include "cap.h"

static t_cursor     g_cursor;
static int			g_len_prompt;
extern t_winsize    g_ws;

void				move_left(void)
{
    //Block cursor at PROMPT
	if (g_cursor.x - 1 < g_len_prompt && g_cursor.y == 0)
		return ;

    //End of line
	if (g_cursor.x - 1 < 0)
	{
		g_cursor.y--;
		g_cursor.x = g_ws.ws_col;
		use_cap("up");
		use_ncap("nd", g_ws.ws_col);
        return;
	}
    //Else simply go left
	g_cursor.x--;
	use_cap("le");
}

void				move_right(void)
{
    //Simply go right
	if (g_cursor.x + 1 <= g_ws.ws_col)
	{
		g_cursor.x++;
		use_cap("nd");
        return;
	}
    //Else EOL so go one line below
    g_cursor.y++;
    g_cursor.x = 0;
    use_cap("cr");
    use_cap("do");
}

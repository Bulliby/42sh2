/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   v_move.c                                                                 */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/07/31 21:18:24 by bulliby            \     \_\ \     /     */
/*   Updated: 2019/02/28 21:10:38 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "v_move.h"
#include "winsize.h"
#include "cap.h"
#include "libft.h"
#include "move.h"

/**
 * t_pos            = position after move
 * pos              = postion when we initiate the copy paste function
 * t_pos (+|-) 1    = current position of the cursor
 * If the current position is equal to the copy past initiate position we do
 * nothing and got to the next character.
 */

extern t_cursor         g_cursor;
extern int		        g_len_prompt;
extern char             *g_cmdln;
extern t_winsize        g_ws;

void        v_move_left(int pos, t_cursor cp)
{
    int     t_pos;

    //Discard if we are at the start of command line
	if (g_cursor.x - 1 < g_len_prompt && g_cursor.y == 0)
		return ;
   
    t_pos = cursor_to_buffer(g_cursor.x, g_cursor.y) - 1;


    /**
     * Here the equal is necessary for 'uncolor' the last right char after pos
     * when we move to left. I brutforced this...
     */
    if (pos <= t_pos)
        use_cap("se");
    else
        use_cap("so");

    if (pos != t_pos + 1)
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
        if (pos != t_pos + 1)
		    use_cap("le");
		if (g_cursor.x != g_ws.ws_col)
			use_cap("le");
		g_cursor.x--;
	}
}

void        v_move_right(int pos, t_cursor cp)
{
    int     t_pos;

    //Discard if we are at the end of command line
	if (cursor_to_buffer(g_cursor.x + 1, g_cursor.y) > \
			(int)ft_strlen(g_cmdln) + g_len_prompt - 1)
		return ;

    t_pos = cursor_to_buffer(g_cursor.x, g_cursor.y) + 1;

    if (pos < t_pos)
        use_cap("so");
    else 
        use_cap("se");

    if (pos != t_pos - 1)
	    ft_putchar(g_cmdln[cursor_to_buffer(g_cursor.x, \
				g_cursor.y) - g_len_prompt]);
    else
        use_cap("nd");

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

/**
 * NOTE: 
 *
 * When we leave standout mode e.g going left from precedent moving 
 * right selection. It seems we move two step left the first time we do it. 
 * In fact, this is not the case. The terminal handle the cursor highlithing by
 * symply inversing standout mode of the current pos. 
 * So when we remove standout mode on the first char, after we are on a 
 * standout mode enabled postion who appear by the way reversed.
 */

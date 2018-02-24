/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   move.c                                                                   */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 20:15:19 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/24 23:18:20 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"
#include "winsize.h"
#include "cap.h"
#include "libft.h"

t_cursor            g_cursor;
int		            g_len_prompt;
extern t_winsize    g_ws;
extern char         *g_cmdln;

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

void                move_down(void)
{
    size_t          max_len;
    size_t          new_len;

    max_len = ft_strlen(g_cmdln) + g_len_prompt;
    new_len = cursor_to_buffer(g_cursor.x, g_cursor.y + 1); 

    //Move the cursor down if it is in the scope of the cmd_line
    if (new_len < max_len)
    {
        g_cursor.y++;
        use_cap("do");
		use_ncap("nd", g_cursor.x - 1);
    }
}

/**
 * Same as move_right without cursor's moves
 */
void        putchar_move_cursor(void)
{
	if (g_cursor.x + 1 <= g_ws.ws_col)
		g_cursor.x++;
	else
	{
		use_cap("do");
		use_cap("cr");
		g_cursor.x = 0;
		g_cursor.y++;
	}
}
/*
void				move_up(void)
{
	t_signal_var	*s;

	s = singleton();
	if (s->input->cursor->y - 1 >= 0)
	{
		use_cap("up");
		s->input->cursor->y--;
	}
	if (s->input->cursor->x <= s->input->sprompt && s->input->cursor->y == 0)
	{
		s->input->cursor->x = 0;
		use_cap("cr");
		use_ncap("nd", s->input->sprompt - 1);
		s->input->cursor->x = s->input->sprompt;
	}
}
*/

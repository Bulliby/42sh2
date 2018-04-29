/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   del.c                                                                    */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/03/03 11:23:33 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/04/29 18:40:52 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "cap.h"
#include "del.h"
#include "winsize.h"
#include "move.h"
#include "input.h"
#include "libft.h"
#include <unistd.h>

extern int			g_len_prompt;
extern t_cursor     g_cursor;
extern char         *g_cmdln;
extern t_winsize    g_ws;

/**
 * We delete the prev character "le" "dc"
 * We save the cursor Pos "sc", we go at first line full below "do"
 * We delete the character at start of the line "dc" we go one line up "up"
 * We put the last character deleted at the end of the line "nd"
 */
static void			del_rec(int y, int rec)
{
	int				len;

	len = ft_strlen(g_cmdln) + g_len_prompt;
	if (y < len / (g_ws.ws_col + 1))
	{
	    use_cap("sc");
		use_ncap("do", rec);
		use_cap("dc");
		use_cap("up");
		use_ncap("nd", g_ws.ws_col + 1);
		ft_putchar(g_cmdln[cursor_to_buffer(0, y + 1) - g_len_prompt - 1]);
		use_cap("rc");
		del_rec(y + 1, rec + 1);
	}
}


static void			del_end_of_line()
{
	g_cursor.y--;
	g_cursor.x = g_ws.ws_col;
	use_cap("up");
	use_ncap("nd", g_ws.ws_col - 1);
    use_cap("dc");
	use_ncap("nd", g_ws.ws_col - 1);

}

void				del(void)
{
	char			*new_cmd;

    //Supress char in BUFFER
    new_cmd = ft_strsupress_at(g_cmdln,\ 
    cursor_to_buffer(g_cursor.x, g_cursor.y) - g_len_prompt - 1);
    free(g_cmdln);
	g_cmdln = new_cmd;
    if (g_cursor.x - 1 < 0)
        del_end_of_line();
    else
    {
        g_cursor.x--;
        use_cap("le");
        use_cap("dc");
    }
	if (is_line_full(g_cursor.y))
		del_rec(g_cursor.y, 0);
}

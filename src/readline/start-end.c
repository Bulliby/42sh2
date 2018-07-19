/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   start.c                                                                  */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/07/19 21:03:26 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/07/19 21:37:33 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "start-end.h" 
#include "cap.h"
#include "winsize.h"
#include "libft.h"

extern t_cursor     g_cursor;
extern int			g_len_prompt;
extern char         *g_cmdln;

/**
 * Put the cursor at start of cli.
 */
void				start(void)
{
	use_ncap("up", g_cursor.y - 1);
	use_cap("cr");
	use_ncap("nd", g_len_prompt - 1);
	g_cursor.x = g_len_prompt;
	g_cursor.y = 0;
}

/**
 * Put the cursor at end of cli.
 */
void				end(void)
{
    t_cursor		new_cur;

	buffer_to_cursor(ft_strlen(g_cmdln)\
	+ g_len_prompt, &new_cur);
	use_cap("cr");
	use_ncap("do", new_cur.y - 1 - g_cursor.y);
	use_ncap("nd", new_cur.x - 1);
	g_cursor.x = new_cur.x;
	g_cursor.y = new_cur.y;

}

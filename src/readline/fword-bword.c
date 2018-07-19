/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fword-bword.c                                                            */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/07/19 21:48:30 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/07/19 22:21:54 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "fword-bword.h"
#include "start-end.h" 
#include "winsize.h"
#include "cap.h"
#include "libft.h"

extern t_cursor     g_cursor;
extern int			g_len_prompt;
extern char         *g_cmdln;

/**
 * Move the cursor
 */
static void			move_fword(t_cursor new_cur, t_cursor *cursor)
{
	use_cap("cr");
	use_ncap("do", new_cur.y - cursor->y - 1);
	use_ncap("nd", new_cur.x - 1);
	cursor->x = new_cur.x;
	cursor->y = new_cur.y;
}

/**
 * Move one word forward
 */
void				fword(void)
{
	char			*pos;
	char			*new_pos;
	int				len;
	t_cursor		new_cur;

	len = cursor_to_buffer(g_cursor.x, g_cursor.y)\
	- g_len_prompt;
	pos = &g_cmdln[len];

    /**
     * Check for the first occurence in param1 of one character
     * of param2.
     * TODO: Check the list of characters that determine a Word
     * it seems that all character that aren't letter delimit a Word
     */
	new_pos = ft_strpbrk(pos, "\t ");

	if (new_pos == NULL)//If there is no more Words go to the endof cli
	{
		end();
		return ;
	}
	while (*new_pos && (*new_pos == '\t' || *new_pos == ' '))
		new_pos++;
	len += new_pos - pos;
	buffer_to_cursor(len + g_len_prompt, &new_cur);
	move_fword(new_cur, &g_cursor);
}

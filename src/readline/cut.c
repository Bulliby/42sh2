/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cut.c                                                                    */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/10/21 13:01:33 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/10/21 19:04:51 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "cut.h"
#include "winsize.h"
#include "cap.h"
#include "copy.h"
#include "keys.h"
#include "libft.h"
#include "del.h"
#include <stdio.h>
#include <stdlib.h>

char                *g_cp_data;
extern t_cursor     g_cursor;
extern char         *g_cmdln;
extern char         *g_input;
extern int			g_len_prompt;

static void         move_to_right(int diff)
{
    diff = ft_abs(diff) + 1;

    while (diff != 0)
    {
        move_right();
        diff--;
    }
}

void        cut(int pos, t_cursor cp)
{
    int     pos_end;
    int     len;

    use_cap("se");
    g_cp_data = set_cp_data(pos);
    len = ft_strlen(g_cp_data);

    pos_end = cursor_to_buffer(g_cursor.x, g_cursor.y);
    if (pos_end < pos)
        move_to_right(pos_end - pos);
    else
        move_to_right(0);
        
    while (len)
    {
        del();
        len--;
    }

    use_cap("im");
}

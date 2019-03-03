/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cut.c                                                                    */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/10/21 13:01:33 by bulliby            \     \_\ \     /     */
/*   Updated: 2019/03/03 12:32:49 by bulliby             \________/\/\_/      */
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

    use_cap("se");//Escape from standout mode
    g_cp_data = set_cp_data(pos);
    len = ft_strlen(g_cp_data);

    pos_end = cursor_to_buffer(g_cursor.x, g_cursor.y);
    //Move the cursor for deleting the part of cmd line previousl selected.
    if (pos_end < pos)
        move_to_right(pos_end - pos);
    else
        move_to_right(0);
        
    while (len)
    {
        del();
        len--;
    }

    use_cap("im");//Go back in insert mode
}

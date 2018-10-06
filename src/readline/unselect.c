/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   unselect.c                                                               */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/10/13 19:24:24 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/10/13 19:24:33 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "unselect.h"
#include "winsize.h"
#include "libft.h"
#include "cap.h"

extern t_cursor     g_cursor;
extern char         *g_cmdln;
extern t_winsize    g_ws;
int		            g_len_prompt;

/**
 * This functions aim to unselect the portion of text selected.
 * They go at the left limit of the selected zone end rewrite the chars
 * without the standout mode. 
 */

static int          diff(t_cursor cp)
{
    return cursor_to_buffer(cp.x, cp.y) - cursor_to_buffer(g_cursor.x, g_cursor.y);
}

static void         move_to_left(int diff)
{
    diff = ft_abs(diff);

    while (diff != 0)
    {
        move_left();
        diff--;
    }
}

static void         unselect_left(t_cursor cp)
{
    int             length;

    length = diff(cp);

    //I only need to move if i'm at the right of the selected zone
    if (length < 0)
        move_to_left(length); 

    length = ft_abs(length);

    while (length != -1)
    {
        ft_putchar(g_cmdln[cursor_to_buffer(g_cursor.x, g_cursor.y) 
        - g_len_prompt]);
        putchar_move_cursor();
        length--;
    }
}


void                quit_visual(t_cursor cp)
{

    use_cap("se");
    unselect_left(cp);
    //Restor the cursor postion saved at initiate of copy
    use_cap("rc");
    g_cursor = cp;
    //Re-enter in insert mode
    use_cap("im");
}

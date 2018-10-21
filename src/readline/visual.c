/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   visual.c                                                                 */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/07/31 19:27:46 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/10/21 19:05:13 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include "visual_events.h"
#include "libft.h"
#include "winsize.h"
#include "move.h"
#include "../main.h"
#include "cap.h"
#include "unselect.h"

extern char         *g_cmdln;
extern t_cursor     g_cursor;
extern int			g_len_prompt;
extern char			*g_input;
char                *g_cp_data;

/**
 * Put the character who will act like a pivot for visual mode.
 */
static void         first_visual_char()
{
    int             pos;

    pos = cursor_to_buffer(g_cursor.x, g_cursor.y) - g_len_prompt;

    /**
     * If we are at the last column we go back one char because
     * this one is empty
     */
    if (pos == ft_strlen(g_cmdln))
        move_left(); 

    pos = cursor_to_buffer(g_cursor.x, g_cursor.y) - g_len_prompt;

    use_cap("sc");//Save the copy's cursor position
    use_cap("so");

	ft_putchar(g_cmdln[pos]);

    use_cap("se");
    use_cap("le");

}


/**
 * Execute a seconde infinite loop for intercept control key used in
 * copy/paste mode
 */
void                visual_mode()
{
    int             pos;
    char            **keys;
    int             event;
    t_func_events   *events;
    t_cursor        cp;

    //Nothing to do in visual mode if there is no txt.
    if (ft_strlen(g_cmdln) == 0)
        return ;

    events = v_ptr_events();
    keys = v_key_tab_events();
    pos = cursor_to_buffer(g_cursor.x, g_cursor.y);
    use_cap("ei");
    first_visual_char();

    //Save position before visaul moves
    cp.x = g_cursor.x;
    cp.y = g_cursor.y;

    while(42)
    {
        event = 0;
        getInput(); 
        while (event != VISUAL_EVENTS)
        {
            if(!ft_strcmp(g_input, keys[event]))
                events[event](pos, cp); 
            event++;
        }
        //When we CUT we also quit visual mode
        if (!ft_strcmp(g_input, k_CUT))
            break;
        if(!ft_strcmp(g_input, k_ESCAPE))
        {
            quit_visual(cp);
            break;
        }
    }
}

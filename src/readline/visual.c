/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   visual.c                                                                 */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/07/31 19:27:46 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/08/15 12:58:24 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include "visual_events.h"
#include "libft.h"
#include "winsize.h"
#include "move.h"
#include "../main.h"
#include "cap.h"

extern char         *g_cmdln;
extern t_cursor     g_cursor;
extern int			g_len_prompt;
extern char			*g_input;


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

    //Nothing to do in visual mode if there is no txt.
    if (ft_strlen(g_cmdln) == 0)
        return ;

    events = v_ptr_events();
    keys = v_key_tab_events();
    pos = cursor_to_buffer(g_cursor.x, g_cursor.y);
    use_cap("ei");
    while(42)
    {
        event = 0;
        getInput(); 
        while (event != VISUAL_EVENTS)
        {
            if(!ft_strcmp(g_input, keys[event]))
                events[event](pos); 
            event++;
        }
    }
}

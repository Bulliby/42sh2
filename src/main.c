/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/11 18:43:20 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/07/19 21:01:48 by bulliby             \________/\/\_/      */
/*                                                                            */

/* ************************************************************************** */
#include <unistd.h>
#include <signal.h>

#include "libft.h"
#include "readline/events.h"
#include "main.h"
#include "winsize.h"
#include "readline/move.h"
#include "readline/term_conf.h"
#include "cap.h"
#include "input.h"
#include "signal_conf.h"
#include "resize_screen.h"

char        *g_input;
char        *g_cmdln;

/**
 * This two global variable are the only one.
 *
 * _g_screen_size is a flag toggle when the screen size change
 * _g_ws is the size of the terminal window
 */
int         g_screen_size = 0;
t_winsize   g_ws;


void                getInput()
{
    g_input = ft_strnew(MAX_INPUT_READ);
	read(0, g_input, MAX_INPUT_READ);
    //printf("%X%X%X%X%X%X%X%X\n", g_input[0], g_input[1], g_input[2], g_input[3], g_input[4], g_input[5], g_input[6], g_input[7]);
}

void                events_while()
{
    t_func_events   *events;
    int             event;
    char            **keys;

    events = ptr_events();
    keys = key_tab_events();
    g_cmdln = ft_strnew(0);
    use_cap("im");
    init_resize_screen_thread();
    while(42)
    {
        event = 0;
        getInput(); 
        while (event != EVENTS)
        {
            if(!ft_strcmp(g_input, keys[event]))
                events[event](); 
            event++;
        }
        if (ft_isprint(g_input[0]))
            insert_at(g_cmdln, g_input[0]);
    }
}


int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    (void)env;
    init_term();
    block_signals();
    get_winsize(42);
    events_while();
    return (0);
}

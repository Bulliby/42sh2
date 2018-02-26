/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/11 18:43:20 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/26 13:30:43 by poledirec           \________/\/\_/      */
/*                                                                            */

/* ************************************************************************** */
#include <unistd.h>

#include "libft.h"
#include "readline/events.h"
#include "main.h"
#include "winsize.h"
#include "readline/move.h"
#include "readline/term_conf.h"
#include "cap.h"
#include "input.h"
#include "signal.h"

char        *g_input;
char        *g_cmdln;

void                getInput()
{
    g_input = ft_strnew(MAX_INPUT_READ);
	read(0, g_input, MAX_INPUT_READ);
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
    signal(SIGINT, sig_clear);
    init_term();
    get_winsize();
    events_while();
    return (0);
}

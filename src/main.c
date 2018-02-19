/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/11 18:43:20 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/19 23:48:50 by bulliby             \________/\/\_/      */
/*                                                                            */

/* ************************************************************************** */
#include <unistd.h>

#include "libft.h"
#include "readline/events.h"
#include "main.h"
#include "winsize.h"
#include "readline/move.h"
#include "readline/term_conf.h"

char        *getInput()
{

    char *buffer;

    buffer = ft_strnew(MAX_INPUT_READ);
	read(0, buffer, MAX_INPUT_READ);

	return (buffer);
}

void                events_while()
{
    t_func_events   *events;
    int             event;
    char            *buffer;
    char            **keys;

    events = ptr_events();
    keys = key_tab_events();
    while(42)
    {
        event = 0;
        buffer = getInput(buffer); 
        while (event != EVENTS)
        {
            if(!ft_strcmp(buffer, keys[event]))
                events[event](); 
            event++;
        }
    }
}

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    (void)env;
    init_term();
    get_winsize();
    events_while();
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/11 18:43:20 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/18 23:37:34 by bulliby             \________/\/\_/      */
/*                                                                            */

/* ************************************************************************** */
#include <unistd.h>

#include "libft.h"
#include "events.h"
#include "main.h"
#include "readline/move.h"
#include "term2.h"

char    *getInput()
{
    char *buffer;

    buffer = ft_memalloc_fail(8);
	read(0, buffer, 8);
	return (buffer);

}

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    (void)env;
    printf("%i\n", CTRL_LEFT);
    while(42)
    {
        init_term();
        getInput();
    }
}

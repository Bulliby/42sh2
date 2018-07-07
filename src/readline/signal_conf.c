/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   signal.c                                                                 */
/*                                                        ________            */
/*   By: poledirec <wellsguillaume+at+gmail.com>         /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/26 13:04:11 by poledirec          \     \_\ \     /     */
/*   Updated: 2018/07/07 20:25:22 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "signal_conf.h"
#include "move.h"
#include "winsize.h"
#include "libft.h"

extern char         *g_cmdln;
extern t_cursor     g_cursor;
extern int		    g_len_prompt;

void         block_signals(void)
{
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, sig_clear);
	signal(SIGTERM, SIG_IGN);
    signal(SIGWINCH, get_winsize);
}

void				sig_clear(int sig)
{
    t_cursor        current;

	buffer_to_cursor(ft_strlen(g_cmdln)\
	+ g_len_prompt, &current);
    //Jump any line that needed for be able to start a new empty line
	while (current.y - g_cursor.y >= 0)
	{
		ft_putchar('\n');
		current.y--;
	}
	g_cursor.x = g_len_prompt;
	g_cursor.y = 0;
	free(g_cmdln);
	g_cmdln = ft_strdup("");
}

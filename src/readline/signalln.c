/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   signal.c                                                                 */
/*                                                        ________            */
/*   By: poledirec <wellsguillaume+at+gmail.com>         /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/26 13:04:11 by poledirec          \     \_\ \     /     */
/*   Updated: 2018/02/26 13:44:26 by poledirec           \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "signalln.h"
#include "move.h"
#include "winsize.h"
#include "libft.h"

extern char         *g_cmdln;
extern t_cursor     g_cursor;
extern int		    g_len_prompt;

static void         block_signals(void)
{
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT,  SIG_IGN);
	signal(SIGTERM, SIG_IGN);
}

void				sig_clear(int sig)
{
    t_cursor        current;

	buffer_to_cursor(ft_strlen(g_cmdln)\
	+ g_len_prompt, &current);
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

/*void				sig_clear(int sig)
{
	t_signal_var	*s;
	t_cursor		tmp;

	(void)sig;
	s = singleton();
	buffer_to_cursor(ft_strlen(s->input->cmd_line)\
	+ s->input->sprompt, &tmp);
	while (tmp.y - s->input->cursor->y >= 0)
	{
		ft_putchar('\n');
		tmp.y--;
	}
	prompt(s->env);
	s->input->cursor->x = s->input->sprompt;
	s->input->cursor->y = 0;
	free(s->input->cmd_line);
	s->input->cmd_line = ft_strdup("");
}*/

/*
static void			sig_kill(int sig)
{
	int				singletone;

	singletone = *pid();
	if (singletone > 0)
	{
		ft_putendl("");
		kill(singletone, sig);
		exit_term();
	}
}
*/
/*
void				restore_signal(void)
{
	signal(SIGTSTP, SIG_DFL);
	signal(SIGINT, sig_kill);
}*/

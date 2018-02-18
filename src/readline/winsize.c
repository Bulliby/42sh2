/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   winsize.c                                                                */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/11 22:36:19 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/18 22:57:33 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "winsize.h"
#include "libft.h"
#include "term.h"
#include "../main.h"

t_winsize       g_ws;
extern t_term   g_term;

void				get_winsize(void)
{
	if (ioctl(g_term.fd, TIOCGWINSZ, &g_ws) == -1)
		ft_quit("get_winsize func()", 2, -1);
    //TODO: Why?
	g_ws.ws_col--;
	g_ws.ws_row--;
}

/**
 * Give the pos in the buffer for a given cursor pos
 */
int					cursor_to_sbuffer(int x, int y)
{
	return (x + y * (g_ws.ws_col + 1));
}

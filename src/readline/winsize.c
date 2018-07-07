/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   winsize.c                                                                */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/11 22:36:19 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/07/07 21:24:40 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "winsize.h"
#include "libft.h"
#include "term_conf.h"
#include "../main.h"
#include "move.h"

extern t_winsize g_ws;
extern int g_screen_size;
extern t_term   g_term;

/** 
 * This is the integer send when the purpose is to get 
 * the intial size of the terminal window.
 */ 
#define INIT 42

void				get_winsize(int signo)
{
	if (ioctl(g_term.fd, TIOCGWINSZ, &g_ws) == -1)
		ft_quit("get_winsize func()", 2, -1);

    //TODO: Why?
	g_ws.ws_col--;
	g_ws.ws_row--;

    if (signo != INIT)
        g_screen_size = 1;
}

/**
 * Detect change size of the window, assume that the event
 * is handled and restore the global flag in is orginal state.
 */
int                 screen_size_change()
{
    if (g_screen_size == 1) { g_screen_size = 0; return 1; }
    return 0;
}

/**
 * Give the pos in the buffer for a given cursor pos
 */
int					cursor_to_buffer(int x, int y)
{
	return (x + y * (g_ws.ws_col + 1));
}

/**
 * Give the cursor pos for a given place in the buffer
 */
void				buffer_to_cursor(int pos, t_cursor *cur)
{
	cur->y = pos / (g_ws.ws_col + 1);
	cur->x = pos % (g_ws.ws_col + 1);
}

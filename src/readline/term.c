/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   term.c                                                                   */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/18 13:07:52 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/18 23:39:36 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "term2.h"
#include "libft.h"

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <curses.h>
#include <term.h>

t_term  g_term;

void		exit_term(void)
{
    if (tcgetattr(g_term.fd, &g_term.termios) == -1)
        ft_quit("error: tcgetattr", 2, -1);
    g_term.termios.c_lflag |= (ICANON | ECHO);
    if (tcsetattr(g_term.fd, TCSANOW, &(g_term.termios)) == -1)
        ft_quit("error: tcsetattr", 2, -1);
    close(g_term.fd);
}

void		init_term(void)
{
    if (!isatty(0))
        ft_quit("error: isatty", 2, -1);
    if ((g_term.fd = open(ttyname(0), O_RDWR)) == -1)
        ft_quit("error: tyyname", 2, -1);
    if (tgetent(NULL, getenv("TERM")) < 1)
        ft_quit("error: tgetent", 2, -1);
    if (tcgetattr(g_term.fd, &(g_term.termios)) == -1)
        ft_quit("error: tcgetattr", 2, -1);

    g_term.termios.c_lflag &= ~(ICANON);
    g_term.termios.c_lflag &= ~(ECHO);
    g_term.termios.c_cc[VMIN] = 1;
    g_term.termios.c_cc[VTIME] = 0;
    if (tcsetattr(g_term.fd, TCSANOW, &(g_term.termios)) == -1)
        ft_quit("error: tcsetattr", 2, -1);
}

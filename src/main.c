/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/11 18:43:20 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/18 12:30:36 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "main.h"
#include <unistd.h>
#include "readline/move.h"

t_term  g_term;

char    *getInput()
{
    char *buffer;

    buffer = ft_memalloc_fail(8);
	read(0, buffer, 8);
    printf("[%X%X%X%X%X%X%X%X%X%X]\n", buffer[9], buffer[8], buffer[7], buffer[6], buffer[5], buffer[4], buffer[3], buffer[2], buffer[1], buffer[0]);
    if (ft_strcmp(buffer, k_CTRL_LEFT) == 0)
    {
        printf("TOTO\n");
    }
	return (buffer);

}

void		init_term_suite(void)
{
	g_term.termios.c_lflag &= ~(ICANON);
	g_term.termios.c_lflag &= ~(ECHO);
	g_term.termios.c_cc[VMIN] = 1;
	g_term.termios.c_cc[VTIME] = 0;
	if (tcsetattr(g_term.fd, TCSANOW, &(g_term.termios)) == -1)
		ft_quit("error: tcsetattr", 2, -1);
}

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
	init_term_suite();
}


int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    (void)env;

    while(42)
    {
        init_term();
        getInput();
    }
}

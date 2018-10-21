/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rewrite.c                                                                */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/07/07 20:10:28 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/07/08 16:22:24 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <pthread.h>

#include "cap.h"
#include "libft.h"
#include "term_conf.h"
#include "winsize.h"

extern char         *g_cmdln;
extern t_cursor     g_cursor;

/**
 * TODO: Atm the position after screen resize is set to the end
 * of the command line. We need to put it on his current position.
 *
 * TODO: We don't have to clear the whole terminal screen only from
 * it's start position.
 *
 * TODO: Protect global col li with mutex
 * 
 * TODO: Use less global variable
 */
static void         rewrite_screen()
{
    use_cap("cl");// clear the whole screen
    ft_putstr(g_cmdln);
    buffer_to_cursor(ft_strlen(g_cmdln), &g_cursor);
}

static void         *worker(void *arg)
{
    while(42)
    {
        if (screen_size_change())
            rewrite_screen();
        usleep(1000);
    }
    (void) arg;
}

void                init_resize_screen_thread(void)
{
    pthread_t       thread1;

    if(pthread_create(&thread1, NULL, worker, NULL) == -1) 
    {
	    perror("pthread_create");
        exit_term();
    }
}

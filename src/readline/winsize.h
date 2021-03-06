/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   winsize.h                                                                */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 19:47:23 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/07/07 20:27:14 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINSIZE_H
# define WINSIZE_H

#include <sys/ioctl.h>
#include "move.h"

typedef struct winsize	t_winsize;

int                     cursor_to_buffer(int x, int y);
void				    get_winsize(int signo);
void				    buffer_to_cursor(int pos, t_cursor *cur);
int                     screen_size_change();

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   winsize.h                                                                */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 19:47:23 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/24 19:06:02 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINSIZE_H
# define WINSIZE_H

#include <sys/ioctl.h>

typedef struct winsize	t_winsize;

int                     cursor_to_buffer(int x, int y);
void				    get_winsize(void);

#endif

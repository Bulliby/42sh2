/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   winsize.h                                                                */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 19:47:23 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/17 22:09:32 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINSIZE_H
# define WINSIZE_H

#include <sys/ioctl.h>

typedef struct winsize	t_winsize;

int                     cursor_to_sbuffer(int x, int y);
void				    get_winsize(void);

#endif

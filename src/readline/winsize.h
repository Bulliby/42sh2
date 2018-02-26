/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   winsize.h                                                                */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 19:47:23 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/26 13:35:31 by poledirec           \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINSIZE_H
# define WINSIZE_H

#include <sys/ioctl.h>
#include "move.h"

typedef struct winsize	t_winsize;

int                     cursor_to_buffer(int x, int y);
void				    get_winsize(void);
void				    buffer_to_cursor(int pos, t_cursor *cur);

#endif

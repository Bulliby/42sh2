/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   visual_events.h                                                          */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/18 23:43:05 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/08/15 12:53:30 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_EVENTS_H
# define VISUAL_EVENTS_H

# include "keys.h"

# define VISUAL_EVENTS 2
# define LEFT 0
# define RIGHT 1
# define CUT 2
# define COPY 3
# define PASTE 4

typedef void            (*t_func_events)(int pos);
char					**v_key_tab_events(void);
t_func_events           *v_ptr_events();

#endif

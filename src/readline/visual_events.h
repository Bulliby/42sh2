/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   visual_events.h                                                          */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/18 23:43:05 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/10/21 12:18:49 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_EVENTS_H
# define VISUAL_EVENTS_H

# include "keys.h"
# include "move.h"

# define VISUAL_EVENTS 3
# define LEFT 0
# define RIGHT 1
# define COPY 2
# define CUT 3
# define PASTE 4

/**
 * param cp, is not used in copy, cut.
 */
typedef void            (*t_func_events)(int pos, t_cursor cp);
char					**v_key_tab_events(void);
t_func_events           *v_ptr_events();
void                    copy(int pos, t_cursor cp);

#endif

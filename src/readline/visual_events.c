/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   visual_events.c                                                          */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/18 23:43:05 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/07/31 22:06:08 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "visual_events.h"
#include "v_move.h"
#include "libft.h"

//TODO: Check for a mean to find unused include
char					**v_key_tab_events(void)
{
    char                **keys;

    keys = ft_memalloc_fail(sizeof(char **) * VISUAL_EVENTS);
    keys[LEFT] = ft_strdup(k_LEFT);
    keys[RIGHT] = ft_strdup(k_RIGHT);
    /*
    keys[CUT] = ft_strdup(k_CUT);
    keys[COPY] = ft_strdup(k_COPY);
    keys[PASTE] = ft_strdup(k_PASTE);
    */
	return (keys);
}

t_func_events       *v_ptr_events()
{
    t_func_events *events;

    events = ft_memalloc_fail(sizeof(t_func_events) * VISUAL_EVENTS);
	events[LEFT] = &v_move_left;
	events[RIGHT] = &v_move_right;
    /*
	events[CUT] = &cut;
	events[COPY] = &copy;
	events[PAST] = &past;
    */
    return (events);
}

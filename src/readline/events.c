/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   events.c                                                                 */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/18 23:43:05 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/19 23:37:17 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "libft.h"
#include "move.h"
#include "../main.h"

char					**key_tab_events(void)
{
    char                **keys;

    keys = ft_memalloc_fail(sizeof(char **) * EVENTS);
    keys[0] = ft_strdup(k_UP);
    keys[1] = ft_strdup(k_DOWN);
	/*ret[2] = T_LEFT;
	ret[3] = T_RIGHT;
	ret[4] = T_DEL;
	ret[5] = T_HOME;
	ret[6] = T_END;
	ret[7] = T_FWORD;
	ret[8] = T_BWORD;
	ret[9] = T_VISUAL;
	ret[10] = T_SUP;
	ret[11] = T_PAST;
	ret[12] = T_HUP;
	ret[13] = T_HDOWN;*/
	return (keys);
}

t_func_events       *ptr_events()
{
    t_func_events *events;

    events = ft_memalloc_fail(sizeof(t_func_events) * EVENTS);
	events[UP] = &move_left;
	events[DOWN] = &move_right;
	/*ptrfunc[LEFT] = &move_left;
	ptrfunc[RIGHT] = &move_right;
	ptrfunc[DEL] = &del_at;
	ptrfunc[HOME] = &home;
	ptrfunc[END] = &end;
	ptrfunc[FWORD] = &fword;
	ptrfunc[BWORD] = &bword;
	ptrfunc[CP] = &select_c;
	ptrfunc[SUP] = &del;
	ptrfunc[PAST] = &past;
	ptrfunc[HISTORY_UP] = &history_up;
	ptrfunc[HISTORY_DOWN] = &history_down;*/
    return (events);
}

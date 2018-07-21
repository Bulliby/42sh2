/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   events.c                                                                 */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/18 23:43:05 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/07/21 21:57:11 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "libft.h"
#include "move.h"
#include "del.h"
#include "start-end.h"
#include "term_conf.h"
#include "../main.h"
#include "fword-bword.h"

char					**key_tab_events(void)
{
    char                **keys;

    keys = ft_memalloc_fail(sizeof(char **) * EVENTS);
    keys[LEFT] = ft_strdup(k_LEFT);
    keys[RIGHT] = ft_strdup(k_RIGHT);
	keys[DOWN] = ft_strdup(k_DOWN);
	keys[UP] = ft_strdup(k_UP);
	keys[DEL] = ft_strdup(k_DEL);
	keys[QUIT] = ft_strdup(k_QUIT);
    keys[START] = ft_strdup(k_START);
	keys[END] = ft_strdup(k_END);
	keys[FWORD] = ft_strdup(k_FWORD);
    keys[BWORD] = ft_strdup(k_BWORD);
    /*
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
	events[LEFT] = &move_left;
	events[RIGHT] = &move_right;
	events[DOWN] = &move_down;
	events[UP] = &move_up;
    events[DEL] = &del;
	events[QUIT] = &exit_term;
	events[START] = &start;
	events[END] = &end;
	events[FWORD] = &fword;
	events[BWORD] = &bword;
    /*
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

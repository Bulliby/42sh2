/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   events.c                                                                 */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/18 23:43:05 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/18 23:44:30 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

int					*key_tab_events(void)
{
	int	*ret;

	ret = ft_memalloc_fail(sizeof(int) * EVENTS);
	ret[0] = T_UP;
	ret[1] = T_DOWN;
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
	return (ret);
}

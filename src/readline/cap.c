/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cap.c                                                                    */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 22:15:09 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/18 23:14:17 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "cap.h"
#include "libft.h"

void				use_ncap(char *cap, int n)
{
	char			*res;
	int				i;

	i = 0;
	while (i <= n)
	{
		if ((res = tgetstr(cap, NULL)) == NULL)
			ft_quit("The cap doesn't exist\n", 2, -1);
		ft_putstr(res);
		i++;
	}
}

void				use_cap(char *cap)
{
	char			*res;

	if ((res = tgetstr(cap, NULL)) == NULL)
		ft_quit("The cap doesn't exist\n", 2, -1);
	ft_putstr(res);
}

char				*fetch_cap(char *cap)
{
	char			*ret;

	if ((ret = tgetstr(cap, NULL)) == NULL)
		ft_quit("The cap doesn't exist\n", 2, -1);
	return (ret);
}

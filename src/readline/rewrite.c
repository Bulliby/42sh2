/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rewrite.c                                                                */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/07/07 20:10:28 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/07/07 21:24:04 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "cap.h"
#include "libft.h"

extern char     *g_cmdln;

void        rewrite_screen()
{
    use_cap("cl");// clear the whole screen
    ft_putstr(g_cmdln);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   start.c                                                                  */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/07/19 21:03:26 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/07/19 21:19:03 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "start.h" 
#include "cap.h"
#include "winsize.h"

extern t_cursor     g_cursor;
extern int			g_len_prompt;

/**
 * Put the cursor at start of cli.
 */
void				start(void)
{
	use_ncap("up", g_cursor.y - 1);
	use_cap("cr");
	use_ncap("nd", g_len_prompt - 1);
	g_cursor.x = g_len_prompt;
	g_cursor.y = 0;
}


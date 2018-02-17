/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cap.h                                                                    */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 22:15:33 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/17 22:19:04 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>

void				use_ncap(char *cap, int n);
void				use_cap(char *cap);
char				*fetch_cap(char *cap);

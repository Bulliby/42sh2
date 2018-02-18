/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cap.h                                                                    */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 22:15:33 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/18 23:00:13 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAP_H
# define CAP_H

#include <curses.h>
#include <term.h>

void				use_ncap(char *cap, int n);
void				use_cap(char *cap);
char				*fetch_cap(char *cap);

#endif

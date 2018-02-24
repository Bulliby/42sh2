/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cap.h                                                                    */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 22:15:33 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/24 23:20:47 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAP_H
# define CAP_H

#include <curses.h>
#include <term.h>

//https://www.gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html
//http://www.delorie.com/gnu/docs/termcap/termcap_toc.html

/**
 * "do" go one line down and put the cursor at start of line
 * "nd" move the curosr to the right
 * "le" move the cursor to the left
 * "up" move the cursor up and stay at the colon position
 */

void				use_ncap(char *cap, int n);
void				use_cap(char *cap);
char				*fetch_cap(char *cap);

#endif

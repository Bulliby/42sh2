/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   cap.h                                                                    */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 22:15:33 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/03/03 11:05:01 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAP_H
# define CAP_H

#include <curses.h>
#include <term.h>

//https://www.gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html
//http://www.delorie.com/gnu/docs/termcap/termcap_toc.html

/**
 * This project don't aim to be compatible with pre historic term
 *
 * "do" go one line down and put the cursor at start of line
 * "nd" move the curosr to the right
 * "le" move the cursor to the left
 * "up" move the cursor up and stay at the colon position
 * "sc" save current position only if rc (but most have);
 * "dc" Delete one character at cursor position. If not present can't delete (vi)
 * "cr" Go at the start of the line, if not carriage return can make the triks
 * "rc" restore cursor position
 */

void				use_ncap(char *cap, int n);
void				use_cap(char *cap);
char				*fetch_cap(char *cap);

#endif

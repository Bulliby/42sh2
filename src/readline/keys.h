/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   keys.h                                                                   */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/17 19:47:23 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/10/21 15:47:32 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

/**
 * LINUX KEYS
 * TODO: handle all type of OS binding keys.
 * maybe use ./configure?
 *
 * TODO: Why we can't use metakey (e.g escape) + F in place of Ctrl-F
 * TODO: move keys in seperate file for be accessible in event and visual.
 */
# define k_UP "\x1B\x5B\x41"
# define k_DOWN "\x1B\x5B\x42"
# define k_LEFT "\x1B\x5B\x44"
# define k_RIGHT "\x1B\x5B\x43"
# define k_DEL "\x7F"  // Backspace
# define k_QUIT "\x04" // Ctrl-D
# define k_START "\x01" // Ctrl-A
# define k_END "\x05" // Ctrl-E
# define k_FWORD "\x06" // Ctrl-F
# define k_BWORD "\x02" // Ctrl-B
# define k_VISUAL "\x16" // Ctrl-V
# define k_COPY "\x19" // Ctrl-y
# define k_CUT "\x16" // Ctrl-V
# define k_PASTE "\x10" // Ctrl-V
# define k_ESCAPE "\x1B" // Ctrl-V

#endif

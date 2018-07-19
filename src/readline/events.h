/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   events.h                                                                 */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/18 13:15:13 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/07/19 21:20:14 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

/**
 * LINUX KEYS
 * TODO: handle all type of OS binding keys.
 * maybe use ./configure?
 */
# define k_UP "\x1B\x5B\x41"
# define k_DOWN "\x1B\x5B\x42"
# define k_LEFT "\x1B\x5B\x44"
# define k_RIGHT "\x1B\x5B\x43"
# define k_DEL "\x7F"  // Backspace
# define k_QUIT "\x04" // Ctrl-D
# define k_START "\x01" // Ctrl-A

# define EVENTS 7
# define LEFT 0
# define RIGHT 1
# define DOWN 2
# define UP 3
# define DEL 4
# define QUIT 5
# define START 6

typedef void        (*t_func_events)(void);
char				**key_tab_events(void);
t_func_events       *ptr_events();

#endif  

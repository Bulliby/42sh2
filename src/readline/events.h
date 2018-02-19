/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   events.h                                                                 */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/18 13:15:13 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/02/19 23:33:37 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# define k_UP "\x1B\x5B\x41"
# define k_DOWN "\x1B\x5B\x42"
# define k_LEFT "\x1B\x5B\x44"
# define k_RIGHT "\x1B\x5B\x43"
# define k_CTRL_UP "\x1B\x5B\x31\x3B\x35\x43"
# define k_CTRL_LEFT "\x1B\x5B\x31\x3B\x35\x44"

# define EVENTS 2
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define CTRL_UP 4
# define CTRL_LEFT 5

typedef void        (*t_func_events)(void);
char				**key_tab_events(void);
t_func_events       *ptr_events();

#endif  

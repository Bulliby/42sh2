/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   events.h                                                                 */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/18 13:15:13 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/03/05 23:04:07 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# define k_UP "\x1B\x5B\x41"
# define k_DOWN "\x1B\x5B\x42"
# define k_LEFT "\x1B\x5B\x44"
# define k_RIGHT "\x1B\x5B\x43"
# define k_DEL "\x7F"  // Backspace
# define k_QUIT "\x04" // Ctrl-D

# define EVENTS 6
# define LEFT 0
# define RIGHT 1
# define DOWN 2
# define UP 3
# define DEL 4
# define QUIT 5

typedef void        (*t_func_events)(void);
char				**key_tab_events(void);
t_func_events       *ptr_events();

#endif  

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   events.h                                                                 */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/02/18 13:15:13 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/10/21 15:43:46 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "keys.h"
 
# define EVENTS 12
# define LEFT 0
# define RIGHT 1
# define DOWN 2
# define UP 3
# define DEL 4
# define QUIT 5
# define START 6
# define END 7
# define FWORD 8
# define BWORD 9
# define VISUAL 10
# define PASTE 11

typedef void        (*t_func_events)(void);
char				**key_tab_events(void);
t_func_events       *ptr_events();

#endif  

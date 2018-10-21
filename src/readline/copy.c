/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   copy.c                                                                   */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/08/17 16:40:57 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/10/21 16:43:36 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "copy.h"
#include "move.h"
#include "libft.h" 
#include "keys.h"
#include "winsize.h"
#include "cap.h"

char                *g_cp_data;
extern t_cursor     g_cursor;
extern char         *g_cmdln;
extern char         *g_input;



char            *set_cp_data(int pos_begin)
{
    int         pos_end; 

    pos_end = cursor_to_buffer(g_cursor.x, g_cursor.y);
    if (pos_begin < pos_end)
        return ft_strsub(g_cmdln, pos_begin, pos_end - pos_begin + 1);    
    else
        return ft_strsub(g_cmdln, pos_end, pos_begin - pos_end + 1);    
}

void            copy(int pos, t_cursor cp)
{
    use_cap("se");
    g_cp_data = set_cp_data(pos);

    //Quit the visual mode and by the way unselect
    g_input = ft_strdup(k_ESCAPE);
}
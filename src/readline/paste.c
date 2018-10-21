/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   paste.c                                                                  */
/*                                                        ________            */
/*   By: bulliby <wellsguillaume+at+gmail.com>           /   ____/_  _  __    */
/*                                                      /    \  _\ \/ \/ /    */
/*   Created: 2018/10/21 15:33:59 by bulliby            \     \_\ \     /     */
/*   Updated: 2018/10/21 16:14:24 by bulliby             \________/\/\_/      */
/*                                                                            */
/* ************************************************************************** */

#include "paste.h"
#include "input.h" 
#include <stdio.h>

extern char     *g_cp_data;

void            paste()
{
    int         i;

    i = 0;
    while (g_cp_data[i])
    {
        insert_at(g_cp_data[i]);
        i++; 
    }
}

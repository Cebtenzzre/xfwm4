/*      $Id$
 
        This program is free software; you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation; either version 2, or (at your option)
        any later version.
 
        This program is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.
 
        You should have received a copy of the GNU General Public License
        along with this program; if not, write to the Free Software
        Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
        oroborus - (c) 2001 Ken Lynch
        xfwm4    - (c) 2002-2004 Olivier Fourdan
 
 */

#ifndef INC_MYWINDOW_H
#define INC_MYWINDOW_H

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <X11/Xlib.h>
#include <glib.h>
#include "mypixmap.h"
#include "screen.h"

#define MYWINDOW_XWINDOW(w) (w.window)

typedef struct _xfwmWindow xfwmWindow;
struct _xfwmWindow
{
    ScreenInfo *screen_info;
    Visual *visual;
    gint depth;
    Window window;
    gint x, y;
    gint width, height;
    gboolean map;
};

void xfwmWindowInit        (xfwmWindow *);
void xfwmWindowCreate      (ScreenInfo *,
                            Visual *,
                            gint, 
                            Window, 
                            xfwmWindow *, 
                            Cursor);
void xfwmWindowTemp        (ScreenInfo *, 
                            Visual *,
                            gint, 
                            Window, 
                            xfwmWindow *, 
                            int, 
                            int,
                            int,
                            int,
                            long); 
void xfwmWindowDelete      (xfwmWindow *);
void xfwmWindowShow        (xfwmWindow *, 
                            int, 
                            int, 
                            int, 
                            int, 
                            gboolean);
void xfwmWindowHide        (xfwmWindow *);
gboolean xfwmWindowVisible (xfwmWindow *);
gboolean xfwmWindowDeleted (xfwmWindow *);
void xfwmWindowSetBG       (xfwmWindow *, xfwmPixmap *);

#endif /* INC_MYWINDOW_H */

/*
 *  wmfs2 by Martin Duquesnoy <xorg62@gmail.com> { for(i = 2011; i < 2111; ++i) ©(i); }
 *  For license, see COPYING.
 */

#ifndef BARWIN_H
#define BARWIN_H

#include "wmfs.h"

#define BARWIN_MASK                                                  \
     (SubstructureRedirectMask | SubstructureNotifyMask              \
      | ButtonMask | MouseMask | ExposureMask | VisibilityChangeMask \
      | StructureNotifyMask | SubstructureRedirectMask)

#define BARWIN_ENTERMASK (EnterWindowMask | LeaveWindowMask | FocusChangeMask)
#define BARWIN_WINCW     (CWOverrideRedirect | CWBackPixmap | CWEventMask)

#define barwin_delete_subwin(b) XDestroySubwindows(W->dpy, b->win)
#define barwin_map_subwin(b)    XMapSubwindows(W->dpy, b->win)
#define barwin_unmap_subwin(b)  XUnmapSubwindows(W->dpy, b->win)
#define barwin_refresh(b)       XCopyArea(W->dpy, b->dr, b->win, W->gc, 0, 0, b->geo.w, b->geo.h, 0, 0)
#define barwin_map(b)           XMapWindow(W->dpy, b->win);
#define barwin_unmap(b)         XUnmapWindow(W->dpy, b->win);
#define barwin_move(b, x, y)    XMoveWindow(W->dpy, b->win, x, y);

struct barwin* barwin_new(Window parent, int x, int y, int w, int h, Color fg, Color bg, bool entermask);
void barwin_remove(struct barwin *b);
void barwin_resize(struct barwin *b, int w, int h);
void barwin_mousebind_new(struct barwin *b, unsigned int button, bool u, struct geo a, void (*func)(Uicb), Uicb cmd);
void barwin_refresh_color(struct barwin *b);

#endif /* BARWIN_H */

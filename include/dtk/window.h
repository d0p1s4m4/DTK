#ifndef DTK_WINDOW_H
# define DTK_WINDOW_H 1

# include <X11/Xlib.h>
# include <dtk/application.h>

typedef struct 
{
	Window win;
} DtkWindow;

DtkWindow *dtk_window_new(DtkApplication *app);

#endif /* !DTK_WINDOW_H */

#ifndef DTK_APPLICATION_H
# define DTK_APPLICATION_H 1

# include <X11/Xlib.h>

typedef struct
{
	Display *display;
} DtkApplication;

DtkApplication *dtk_application_new(int argc, char **argv);
void dtk_application_run(DtkApplication *app);
void dtk_application_destroy(DtkApplication *app);

#endif /* !DTK_APPLICATION_H */

#include "dtk/application.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/Xlib.h>

DtkApplication *
dtk_application_new(int argc, char **argv)
{
	DtkApplication *app;

	/* ignore for now */
	(void)argc;
	(void)argv;

	app = (DtkApplication *)malloc(sizeof(DtkApplication));
	if (app == NULL)
	{
		fprintf(stderr, "Can't allocate memory\n");
		return (NULL);
	}
	app->display = XOpenDisplay(NULL);
	if (app->display == NULL)
	{
		fprintf(stderr, "Can't open display\n");
		free(app);
		return (NULL);
	}

	return (app);
}

void
dtk_application_run(DtkApplication *app)
{
	(void)app;
}

void
dtk_application_destroy(DtkApplication *app)
{
	if (app->display != NULL)
	{
		XCloseDisplay(app->display);
	}

	free(app);
}

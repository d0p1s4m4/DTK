/*
 * Copyright (c) 2022, d0p1
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <X11/Xlib.h>
#include <dtk/application.h>

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
	XEvent evt;

	XMapWindow(app->display, app->windows->win); /* TODO: iterate over all windows */

	while (1)
	{
		XNextEvent(app->display, &evt);

		switch (evt.type)
		{
			default:
				printf("evt: %d\n", evt.type);
				break;
		}
	}
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

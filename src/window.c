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

#include "dtk/widget.h"
#include <X11/Xlib.h>
#include <stdlib.h>
#include <dtk/window.h>

DtkWidget *
dtk_window_new(DtkApplication *app)
{
	DtkWidget *window;
	int screen;
	unsigned int background;
	unsigned int border;

	window = (DtkWidget *)malloc(sizeof(DtkWidget));
	if (window == NULL)
	{
		/* TODO: logging system */
		return (NULL);
	}

	screen = DefaultScreen(app->display);
	background = BlackPixel(app->display, screen);
	border = WhitePixel(app->display, screen);
 
	window->handle = XCreateSimpleWindow(
		app->display, DefaultRootWindow(app->display), 0, 0, 640, 480, 2, 
		border, background);
	window->app = app;
	window->parent = NULL;

	dtk_widget_vector_push(&app->children, window);
    return (window);
}

DtkWidget *
dtk_window_new_with_title(DtkApplication *app, char const *title)
{
	DtkWidget *window;

	window = dtk_window_new(app);
	if (window == NULL)
	{
		return (NULL);
	}

	XStoreName(app->display, window->handle, title);

	return (window);
}

void
dtk_window_resize(DtkWidget *win, size_t width, size_t height)
{
	XResizeWindow(win->app->display, win->handle, width, height);
}

void
dtk_window_set_title(DtkWidget *win, char const *title)
{
	XStoreName(win->app->display, win->handle, title);
}

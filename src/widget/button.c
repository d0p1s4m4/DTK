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
#include <stdio.h>
#include <dtk/widget/button.h>
#include <dtk/application.h>

DtkWidget *
dtk_button_new(DtkWidget *parent)
{
	DtkButton *button;

	button = (DtkButton *)malloc(sizeof(DtkButton));
	if (button == NULL)
	{
		return (NULL);
	}

	button->widget.app = parent->app;
	button->widget.parent = parent->parent;

	button->widget.handle = XCreateSimpleWindow(
		parent->app->display, parent->handle, 10, 10, 100, 20, 2, 0, 120);
	if (!button->widget.handle)
	{
		fprintf(stderr, "Unable to create subwindows");
		return (NULL);
	}

	XMapWindow(parent->app->display, button->widget.handle); /* XXX: */

	return ((DtkWidget *)button);
}

DtkWidget *
dtk_button_new_with_label(DtkWidget *parent, char const *label)
{
	DtkButton *button;

	button = (DtkButton *)dtk_button_new(parent);
	if (button == NULL)
	{
		return (NULL);
	}

	(void)label;
	return ((DtkWidget *)button);
}

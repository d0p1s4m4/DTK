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

#include "dtk/application.h"
#include "dtk/widget/button.h"
#include <dtk/window.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
	DtkApplication *app;
	DtkWidget *main_window;
	DtkWidget *alt_window;

	app = dtk_application_new(argc, argv);
	if (app == NULL)
	{
		return (EXIT_FAILURE);
	}

	main_window = dtk_window_new_with_title(app, "Hello, DTK");
	if (main_window == NULL)
	{
		dtk_application_destroy(app);
		return (EXIT_FAILURE);
	}
	
	alt_window = dtk_window_new_with_title(app, "Hello, World");
	if (alt_window == NULL)
	{
		dtk_application_destroy(app);
		return (EXIT_FAILURE);
	}

	dtk_button_new(main_window);

	dtk_application_run(app);

	dtk_application_destroy(app);

	return (EXIT_SUCCESS);
}

AC_INIT([DTK],[0.1],[contact@d0p1.eu])

AM_INIT_AUTOMAKE([foreign])
AC_LANG(C)
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_RANLIB

AC_CHECK_INCLUDES_DEFAULT

AC_CHECK_HEADERS([X11/Xlib.h], [], [
    AC_MSG_ERROR([unable to find Xlib header])
])
AC_SEARCH_LIBS([XOpenDisplay], [X11], [], [
    AC_MSG_ERROR([unable to find XOpenDisplay()])
])

AC_CONFIG_FILES([Makefile
                 example/Makefile
                 src/Makefile])
AC_OUTPUT

AC_INIT([DTK],[0.1],[contact@d0p1.eu])

AM_INIT_AUTOMAKE([foreign subdir-objects])
AC_LANG(C)
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_RANLIB
AM_PROG_AR
AM_PROG_CC_C_O

AC_CHECK_INCLUDES_DEFAULT
AC_C_CONST
AC_CHECK_TYPE(size_t)

dnl +---------------------------+
dnl | Check xlib availability   |
dnl +---------------------------+

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

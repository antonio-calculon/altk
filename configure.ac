AC_INIT([altk], [0.0.0])
AM_INIT_AUTOMAKE

: ${CXXFLAGS:=-g -Wall}

AC_SUBST([pkgconfigdir], ['${libdir}/pkgconfig'])

AC_PROG_CXX
LT_INIT

PKG_CHECK_MODULES([AL5], [allegro-debug-5])

AC_CONFIG_FILES([ \
  Makefile \
  altk/Makefile \
])
AC_OUTPUT

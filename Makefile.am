#

SUBDIRS = altk

CONFIG_STATUS = $(top_builddir)/config.status

pkgconfig_DATA = altk.pc

altk.pc: altk.pc.in $(CONFIG_STATUS)
	$(CONFIG_STATUS) --file=$@:$<

.PHONY: listdirs

listdirs:
	@echo "prefix:     '$(prefix)'"
	@echo "datadir:    '$(datadir)'"
	@echo "pkgdatadir: '$(pkgdatadir)'"
	@echo "pkglibdir : '$(pkglibdir)'"

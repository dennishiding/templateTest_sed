
lib_LTLIBRARIES = libtemplateTest.la

libtemplateTest_la_SOURCES = templateTest.h

nodist_libtemplateTest_la_SOURCES = templateTest_u8.c \
                                    templateTest_u8.h \
                                    templateTest_f.c \
                                    templateTest_f.h

EXTRA_DIST = templateTest.c.template templateTest.h.template 

BUILT_SOURCES = ${nodist_libtemplateTest_la_SOURCES}

CLEAN_FILES = ${BUILT_SOURCES}

templateTest_u8.h : templateTest.h.template genTemplateSource.sh
	@${SHELL} ${srcdir}/genTemplateSource.sh \
                  ${srcdir}/templateTest.h.template $@ > $@

templateTest_f.h : templateTest.h.template genTemplateSource.sh
	@${SHELL} ${srcdir}/genTemplateSource.sh \
                  ${srcdir}/templateTest.h.template $@ > $@

templateTest_u8.c : templateTest.c.template genTemplateSource.sh \
                                            templateTest_u8.h
	@${SHELL} ${srcdir}/genTemplateSource.sh \
	          ${srcdir}/templateTest.c.template $@ > $@

templateTest_f.c : templateTest.c.template genTemplateSource.sh \
                                           templateTest_f.h
	@${SHELL} ${srcdir}/genTemplateSource.sh \
	          ${srcdir}/templateTest.c.template $@ > $@


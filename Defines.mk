MAKE += PREFIX=$(PREFIX) LIBEXEC_PREFIX=$(LIBEXEC_PREFIX) ETC_PREFIX=$(ETC_PREFIX)

define TEMPLATE_COMPILER =
sed $< >$@ \
		-e's#@PREFIX@#$(PREFIX)#' \
		-e's#@ETC_PREFIX@#$(ETC_PREFIX)#' \
		-e's#@LIBEXEC_PREFIX@#$(LIBEXEC_PREFIX)#'
endef

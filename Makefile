inclibs = util

src = $(wildcard $(srcdir)/*.c)
obj = $(addprefix $(bindir)/,$(notdir $(src:%.c=%.o)))
cflags += -fPIC $(addprefix -I,$(incdirs))
incdirs = $(addsuffix /include,$(addprefix $(libdir)/,$(inclibs)))
srcdir = $(realpath ./src)
libdir ?= $(realpath ./lib)
bindir ?= $(realpath ./bin)

$(bindir)/libutil.a: $(obj)
	$(AR) rcs $@ $(obj)

$(bindir)/%.o: $(srcdir)/%.c
	$(CC) -c $(cflags) -o $@ $^

.PHONY: clean
clean:
	rm -f $(bindir)/libutil.a $(obj)

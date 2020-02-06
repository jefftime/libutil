src = $(wildcard $(srcdir)/*.c)
obj = $(addprefix $(bindir)/,$(notdir $(src:%.c=%.o)))
cflags = -fPIC \
	-std=c90 \
	-pedantic-errors \
	-Wall \
	-Wconversion \
	$(include) \
	--no-standard-libraries
include = -I./include \
	-I$(libdir)/sized_types/include
srcdir = ./src
libdir ?= ./lib
bindir ?= ./bin

green = '\033[1;32m'
nocolor = '\033[0m'

$(bindir)/libutil.a: $(obj)
	@echo -e $(green)Link $(notdir $@)$(nocolor)
	@$(AR) rcs $@ $(obj)

$(bindir)/%.o: $(srcdir)/%.c
	@echo $(notdir $@)...
	@$(CC) -c $(cflags) -o $@ $^

.PHONY: clean
clean:
	rm -f $(bindir)/libutil.a $(obj)

SRCSF = main.c	\
		utils_mlx/init.c	\


# INCSF = cubed.h

ifndef $(OS)
OS := $(shell uname)
endif

$(info Compiling for OS:$(OS))

NAME = 3dgame

DIRSRC = src
DIROBJ = obj
DIRINC = inc
DIRLIB = lib

LIBFT = libft/libft.a

ifeq ($(OS),Linux)
LIBMLX = mlx-linux/libmlx.a
else
LIBMLX = mlx/libmlx.a
endif

LIBSF = $(LIBFT) $(LIBMLX)

# All relative to Makefile's folder
SRCS = $(patsubst %.c,$(DIRSRC)/%.c, $(SRCSF))
OBJS = $(SRCS:$(DIRSRC)/%.c=$(DIROBJ)/%.o)
LIBS = $(patsubst %.a,$(DIRLIB)/%.a, $(LIBSF)) 
INCS = $(patsubst %.h,$(DIRINC)/%.h, $(INCSF))
DEPS = $(OBJS:.o=.d)

LIB-I = $(patsubst %,-I%,$(dir $(LIBS))) -I$(DIRLIB)
LIB-l = $(subst lib,-l,$(basename $(notdir $(LIBSF))))
LIB-L = $(patsubst %,-L$(DIRLIB)/%, $(dir $(LIBSF)))

CC = cc

WFLAGS =#-Wall -Werror -Wextra
CPPFLAGS =-I$(DIRINC) $(LIB-I)  -MMD -MP
CFLAGS = $(OPFLAG) $(DFLAGS) $(XCFLAGS) $(WFLAGS)
LDFLAGS = $(OPFLAG) $(DFLAGS) $(XLDFLAGS) $(LIB-L) $(LIB-l) -lz -lm 
PGFLAGS = #-pg
OPFLAG = -O3

ifneq ($(OS),Linux) 
LDFLAGS += -framework OpenGL -framework AppKit 
else 
LDFLAGS += -lX11 -lXext
endif

# RULES
all: $(NAME)

# OBJ TO PROJECT
$(NAME): $(LIBS) $(OBJS)
	-@printf "${BLUE}"
	$(CC) $(PGFLAGS) $(OBJS) $(LDFLAGS) -o $@
	-@printf "${NC}"

# SOURCE TO OBJ
$(OBJS): $(DIROBJ)%.o : $(DIRSRC)%.c $(INCS) | $(DIROBJ)
	-@mkdir -p $(dir $@)
	-@printf "${GREEN}"
	-$(CC) $(PGFLAGS) $(CPPFLAGS) $(CFLAGS) -o $@ -c $<
	-@printf "${NC}"

# CLEANING
fclean: clean
	-@printf "${BRED}Cleaning executable!\n${RED}"
	-rm -f $(NAME)
	-@printf "${NC}"

clean:
	-@printf "${BYELLOW}Cleaning objects!\n${RED}"
	-rm -rf $(DIROBJ)
	-@printf "${NC}"

re: fclean all

# Dependencies
-include $(DEPS)

$(DIRLIB)/$(LIBFT):
	make -s -C $(dir $@) all bonus

$(DIRLIB)/$(LIBGNL):
	make -s -C $(dir $@) all

$(DIRLIB)/$(LIBMLX):
	make -s -C $(dir $@)

$(DIRLIB)/$(LIBMLX_SO): $(LIBMLX)
	cp $(DIRMLX)/libmlx.so ./libmlx.so

# Folders
$(DIROBJ):
	-@printf "${CYAN}"
	-mkdir -p $(DIROBJ)
	-@printf "${NC}"

.PHONY: all re fclean clean libclean

# COLORS
export BGREEN = \033[1;32m
export GREEN = \033[0;32m
export BRED = \033[1;31m
export RED = \033[0;31m
export BYELLOW = \033[1;33m
export YELLOW = \033[0;33m
export BBLUE = \033[1;34m
export BLUE = \033[0;34m
export BCYAN = \033[1;36m
export CYAN = \033[0;36m
export NC = \033[0m

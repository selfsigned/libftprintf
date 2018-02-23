# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 19:33:10 by xperrin           #+#    #+#              #
#    Updated: 2018/02/23 23:46:18 by xperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SONAME = $(NAME:.a=.so)
DNAME = $(NAME)
CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -g
INCDIR = includes
#PRINTFINC = printf.h printf_structs.h printf_helpers.h printf_conv.h
INCFILES = libft.h get_next_line.h #$(PRINTFINC)
INCFULL = $(addprefix $(INCDIR)/, $(INCFILES))
INC = $(addprefix -I, $(INCDIR))
SRCDIR = src

# Source Files
MEMDIR = $(SRCDIR)/memory
FT_MEM = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c

STRDIR = $(SRCDIR)/string
FT_STR = ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
	ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
	ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_islower.c ft_isupper.c \
	ft_strupcase.c ft_strlowcase.c ft_toupper.c ft_tolower.c \
	ft_strnew.c ft_strdel.c ft_strclr.c \
	ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c ft_itoa.c ft_itoa_base.c \
	ft_cntword.c ft_strrlen.c ft_strndup.c ft_strdeltab.c

DISPDIR = $(SRCDIR)/display
FT_DISP = ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

LSTDIR = $(SRCDIR)/list
FT_LST = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	ft_lstiter.c ft_lstmap.c

MATHDIR = $(SRCDIR)/math
FT_MATH = ft_cntdigit.c ft_pow.c ft_sqrt.c

GNLDIR = $(SRCDIR)/gnl
GNL = get_next_line.c

PRINTFP = $(SRCDIR)/printf
PRINTFDIR = $(PRINTFP)/function:$(PRINTFP)/parse $(PRINTFP)/conv
PRINTF_FUN = ft_printf.c ft_dprintf.c ft_vprintf.c ft_vdprintf.c
PRINTF_PARSE = readarg.c printarg.c
PRINTF_CONV = conv_char.c conv_string.c conv_int.c
PRINTF = $(PRINTF_FUN) $(PRINTF_PARSE) $(PRINTF_CONV)

OBJDIR = obj
VPATH = $(MEMDIR):$(STRDIR):$(DISPDIR):$(LSTDIR):$(MATHDIR):\
	$(GNLDIR):$(PRINTFDIR)
SRC = $(FT_MEM) $(FT_STR) $(FT_DISP) $(FT_LST) $(FT_MATH) $(GNL) $(PRINTF)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# Dude colors lmao
GOOD=\033[1;32m
AIGHT=\033[1;33m
WARN=\033[1;31m
NOCOLOR=\033[0m

.PHONY: all so clean fclean re test moulitest

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "$(GOOD)[$(DNAME)]Archived library updated.$(NOCOLOR)\n"

$(SONAME): CFLAGS += -fPIC
$(SONAME): DNAME = $(SONAME)
$(SONAME): $(OBJ)
	@$(CC) -shared -o $(SONAME) $(OBJ)
	@printf "$(GOOD)[$(DNAME)]Shared object updated.$(NOCOLOR)\n"

so: $(SONAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c $(INCFULL) | $(OBJDIR)
	@printf "$(GOOD)[$(DNAME)]$(AIGHT)[$(dir $<)]$(NOCOLOR)$(notdir $(@:.o=))\n"
	@$(CC) $(CFLAGS) -c -o $@ $< $(INC)

# Tests
MOULITEST_REPO = https://github.com/yyang42/moulitest
MOULITEST_TRACE = moulitrace.txt

test: moulitest_libft

moulitest_libft: $(NAME)
	if [ ! -d moulitest ]; then \
		git clone $(MOULITEST_REPO); fi
	echo 'LIBFT_PATH = $$PWD/../..' > moulitest/config.ini
	mv $(NAME) libft.a
	$(MAKE) --no-print-directory -C moulitest/ libft_bonus > $(MOULITEST_TRACE)
	@printf "$(GOOD)[MOULITEST]$(NOCOLOR)Tests finished, see $(MOULITEST_TRACE)\n"
	@if grep -qE "ABRT|SEGV|BUS\!|TIME|FAIL" $(MOULITEST_TRACE) ; then \
		printf "$(GOOD)[MOULITEST]$(WARN)Some tests failed$(NOCOLOR)\n"; \
		exit 1; \
	else \
		printf "$(GOOD)[MOULITEST]$(NOCOLOR)All tests passed\n"; \
	fi

# Cleanup
clean:
	@$(RM) -r $(OBJDIR)
	@printf "$(GOOD)[LIBFT]$(WARN)[CLEAN]$(NOCOLOR)Object directory removed\n"

fclean: clean
	@$(RM) $(NAME) $(SONAME)
	@printf "$(GOOD)[LIBFT]$(WARN)[CLEAN]$(NOCOLOR)Archive removed\n"

re: fclean all

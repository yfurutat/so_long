_SRCS_	:=	strlen \
			isalpha isdigit isalnum isprint isascii \
			tolower toupper \
			memset bzero \
			memcpy memmove \
			strlcpy strlcat \
			memchr strchr strrchr \
			memcmp strncmp strnstr \
			calloc atoi itoa \
			strdup substr strjoin \
			putchar_fd putstr_fd putendl_fd \
			putnbr_fd \
			split strtrim \
			striteri strmapi

UTIL	:=	isspace islower isupper strndup\

_BSRCS_	:=	lstnew \
			lstlast lstsize \
			lstadd_front lstadd_back \
			lstdelone lstclear \
			lstiter lstmap \

ifdef ADD_BONUS
_SRCS_	+=	$(_BSRCS_)
endif

SRCS	:=	$(addsuffix .c, $(addprefix ft_, $(_SRCS_) $(UTIL)))
BSRCS	:=	$(addsuffix .c, $(addprefix ft_, $(_BSRCS_)))

OBJS	:=	$(SRCS:.c=.o)
BOBJS	:=	$(BSRCS:.c=.o)

NAME	:=	libft.a
CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -g
RM		:=	rm -fr
AR		:=	ar -rcs
HFILE	:=	libft.h

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean	:
	$(RM) $(OBJS) $(BOBJS)
fclean	:	clean
	$(RM) $(NAME)
re		:	fclean all
bonus	:
	make all ADD_BONUS=42

sall	:
	@make -s all
sbonus	:
	@make -s bonus
aclean	:
	@$(RM) $(OBJS) $(BOBJS) $(NAME) a.out
reb		:	fclean bonus
resb	:
	@make -s fclean bonus

files	:
	@touch $(SRCS) $(HFILE)
filesb	:	
	@touch $(BSRCS)
norm	:
	@norminette $(HFILE) $(SRCS) $(BSRCS)
normd	:
	@norminette -R CheckDefine $(HFILE) $(SRCS) $(BSRCS)
normf	:
	@norminette -R CheckForbiddenSourceHeader $(HFILE) $(SRCS) $(BSRCS)
norma	:	norm normd normf

commit	:	aclean
			git add $(SRCS) $(BSRCS) $(HFILE) Makefile
			git commit -m "commit through Makefile"
			git log --numstat | grep -cE '^[0-9]+[[:space:]]+[0-9]+[[:space:]]+'
			git status

.PHONY	:	all clean fclean re bonus \
	aclean reb files filesb commit norm normd normf norma

# .DEFAULT_GOAL := fclean

#			git show
#			git diff
# 			time $(AR) $(NAME) $(OBJS)
# 			time $(RM) $(OBJS) $(BOBJS)
# 			time $(RM) $(NAME)
# 			@time make all ADD_BONUS=42
# 			@time norminette $(HFILE) $(SRCS) $(BSRCS)
# 			@time norminette -R CheckDefine $(HFILE) $(SRCS) $(BSRCS)
# 			@time norminette -R CheckForbiddenSourceHeader $(HFILE) $(SRCS) $(BSRCS)
# SRCS_	=	$(addprefix ft_, $(_SRCS_) $(UTIL))
# SRCS	=	$(addsuffix .c, $(SRCS_))
# BSRCS_	=	$(addprefix ft_, $(_BSRCS_))
# BSRCS	=	$(addsuffix .c, $(BSRCS_))
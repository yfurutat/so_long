NAME		=	so_long

CC			=	cc
# CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -Iincludes -Iminilibx-linux -Ilibft
CFLAGS		=	-Wall -Wextra -Werror -Iincludes -Iminilibx-linux -Ilibft
MLXFLAGS	=	-L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
MLXMAKE		=	$(MAKE) -C $(MLX_PATH)
LIBFTMAKE	=	$(MAKE) -C $(LIBFT_PATH)

RM			:=	rm -rf
HFILES		:=	includes/so_long.h includes/get_next_line.h
COM_MSG		:=	commit through Makefile

LIBFT_PATH	=	./libft/
MLX_PATH	=	./minilibx-linux/
SRCS_PATH	=	./srcs/
OBJS_PATH	=	./objs/

SRCS_FILES	=	error.c \
				get_next_line.c \
				get_next_line_utils.c \
				handle_hooks.c \
				init.c \
				parse_map.c \
				scan_map.c \
				check_path.c \
				main.c 

OBJS		=	$(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))

all: $(NAME)

$(NAME): mlx libft $(OBJS_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)libft.a $(MLXFLAGS) $(MLX_PATH)libmlx_Darwin.a -o $(NAME)

mlx:
	$(MLXMAKE)

libft:
	$(LIBFTMAKE)

$(OBJS_PATH):
	mkdir -p $@

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MLXMAKE) clean
	$(LIBFTMAKE) clean
	rm -rf $(OBJS_PATH)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX_PATH)/libmlx_Darwin.a
	$(RM) $(LIBFT_PATH)/libft.a

re: fclean all

norm	:
	@norminette $(HFILES) $(LIBFT_PATH)*.h $(LIBFT_PATH)*.c $(SRCS_PATH)*.c
normd	:
	@norminette -R CheckDefine $(HFILES) $(LIBFT_PATH)*.h $(LIBFT_PATH)*.c $(SRCS_PATH)*.c
normf	:
	@norminette -R CheckForbiddenSourceHeader $(HFILES) $(LIBFT_PATH)*.h $(LIBFT_PATH)*.c $(SRCS_PATH)*.c
norma	:	norm normd normf

commit	:
	@echo "\n"
	git status
	@echo "\n"
	git add $(SRCS_PATH)$(SRCS_FILES) $(HFILES) Makefile .gitignore
	@echo "\n"
	@git commit -m "$(COM_MSG)"
	@echo "\n"
	git status
	@echo "\n"
	@echo '[git push] to complete'
	@echo "\n"

.PHONY: libft mlx all clean fclean re \
	norm normd normf norma commit


# NAME := so_long
# SRC	:=	main.c

# CC			:=	gcc
# CFLAGS 		:= -Wall -Wextra -Werror -g -Iincludes -Iminilibx-linux
# OBJS_PATH	=	
# OBJS		= $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))
# all:

# clean: 
# fclean:
# re:
# .PHONY: all clean fclean re
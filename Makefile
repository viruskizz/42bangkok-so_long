NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= /bin/rm -f

LIBFT_DIR	= libft

INCLUDE_DIR	= ./includes
INCLUDES 	= -I $(INCLUDE_DIR) \
			  -I $(LIBFT_DIR) \
			  -I $(MLX_DIR) 
 
LIBS 		= -L$(LIBFT_DIR) -lft

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	MLX_DIR		= mlx_linux
	MLX_FLAGS	= -Lmlx_linux -lmlx_linux -lXext -lX11 -lm -lz -L/usr/local/lib
else # for MACOS(Darwin or Other)
	MLX_DIR		= mlx
	MLX_FLAGS	= -L$(MLX_DIR) -lmlx \
				  -framework OpenGL \
				  -framework AppKit
endif

BUILD_DIR	= build
SRC_DIR		= ./srcs
SRCS		= main.c \
			  game.c \
			  object.c \
			  sprite.c \
			keyhandler.c \
			utils/img_util.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

refast: cleanbuild $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

$(NAME): libs $(OBJS)
		$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(MLX_FLAGS) $(OBJS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libs:
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)	

bonus: all

re: fclean all

cleanbuild:
	-$(RM) -r $(BUILD_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(MLX_DIR)	
	$(RM) $(NAME)

.PHONY: all clean fclean re

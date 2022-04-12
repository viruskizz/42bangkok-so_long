NAME				= so_long
CC					= gcc
CFLAGS			= -Wall -Wextra -Werror
RM 					= /bin/rm -f

INCLUDE_DIR = ./includes
INCLUDES 		= -I $(INCLUDE_DIR) \
							-I $(LIBFT_DIR) \
							-I $(MLX_DIR)

MLX_DIR			= mlx
LIBFT_DIR		= libft
LIBS 				=	-L$(LIBFT_DIR) -lft \
							-L$(MLX_DIR) -lmlx \
							-framework OpenGL \
							-framework AppKit

BUILD_DIR		= build
SRC_DIR			= ./srcs
SRCS				= main.c

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT_DIR)
		@make -C $(MLX_DIR)
		$(CC) $(CFLAGS) $(LIBS) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: all

re: fclean all

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(MLX_DIR)	
	$(RM) $(NAME)

.PHONY: all clean fclean re

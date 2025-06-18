NAME		= fractol
CC			= cc
CFLAGS		= -Wall -Wextra -Werror


LIBFT_DIR	= libs/Libft
PRINTF_DIR	= libs/printf
MLX42_DIR	= libs/MLX42
SRCS_DIR	= srcs
OBJS_DIR	= objs
INCLUDE_DIR	= includes
LFLAGS = -lglfw -lGL -lX11 -lpthread -lXrandr -lXinerama -lXcursor -lm -ldl

SRCS		= srcs/main.c \
			  srcs/fractal.c \
			  srcs/rendering.c \
			  srcs/init.c \
			  srcs/parsing.c \
			  srcs/keyhook.c \
			  srcs/zoom.c

OBJS		= objs/main.o \
			  objs/fractal.o \
			  objs/rendering.o \
			  objs/parsing.o \
			  objs/init.o \
			  objs/zoom.o \
			  objs/keyhook.o

LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/ft_printf.a
MLX42		= $(MLX42_DIR)/build/libmlx42.a


INCLUDES	= -I$(LIBFT_DIR) -I$(PRINFT_DIR) -I$(MLX42_DIR)/include -I$(INCLUDE_DIR)

all: $(MLX42) $(PRINTF) $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX42) $(LFLAGS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(MLX42):
	@mkdir -p $(MLX42_DIR)/build
	@cd $(MLX42_DIR)/build && cmake .. && make

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@rm -rf $(MLX42_DIR)/build
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
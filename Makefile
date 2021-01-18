NAME = printf.a
SRC = src/print.c src/ft_printf.c src/put_format.c src/printf_aux.c
OBJ = $(SRC:.c=.o)
CCW = gcc -Wall -Wextra -Werror -g 
LIBFT = libft/
libft.a = $(LIBFT)libft.a
incl = -I include/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar rc $(NAME) */*.o
	$(CCW) main.c $(NAME) $(incl) -o printf
	@echo ;
	@./printf

%.o: %.c
	$(CCW) $(incl) -c $< -o $@

clean:
	@rm -rf src/*.o
	@make clean -C $(LIBFT)

$(LIBFT):
	@make -C libft

fclean: clean
	@make fclean -C	$(LIBFT) 
	@rm -rf $(NAME)

re: fclean all

ref: fclean f

.PHONY: b re clean clean $(LIBFT) $(NAME) all

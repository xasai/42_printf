NAME = libftprintf.a
SRC = src/print.c src/ft_printf.c src/put_format.c src/printf_aux.c
OBJ = $(SRC:.c=.o)
CCW = gcc -Wall -Wextra -Werror -g 
LIBFT = libft/
incl = -I include/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar rc $(NAME) */*.o

%.o: %.c
	$(CCW) $(incl) -g -c $< -o $@

test:
	$(CCW) test.c $(NAME) $(incl) -o test
	./test

clean:
	@rm -rf src/*.o
	@make clean -C $(LIBFT)

$(LIBFT):
	@make -C libft

fclean: clean
	@make fclean -C	$(LIBFT) 
	@rm -rf $(NAME) test

re: clean all

ref: fclean

.PHONY: test re clean $(LIBFT) $(NAME) all

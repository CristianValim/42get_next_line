# Nome do executável
NAME = get_next_line

# Compilador e flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Arquivos de origem e objetos
SRCS = get_next_line.c get_next_line_utils.c main.c
OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

# Regra padrão
all: $(NAME)

# Regra para criar o executável
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Regra para compilar arquivos .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

# Regra para limpar arquivos objeto
clean:
	rm -f $(OBJS) $(DEPS)

# Regra para limpar arquivos objeto e executável
fclean: clean
	rm -f $(NAME)

# Regra para recompilar tudo
re: fclean all

# Regra para rodar o teste
run: all
	./$(NAME)

.PHONY: all clean fclean re run
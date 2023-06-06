NAME = MyAwesomePhoneBook

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM		= rm -f
MD		= mkdir -p
CP		= cp -f
CC		= c++

PHONEBOOK_SRC	=	main.cpp \

SRCS	+= $(PHONEBOOK_SRC)
OBJS	= $(SRCS:.c=.o)
DEPS	= $(basename $(OBJS))

%.o: %.c Makefile
	@echo "	Compiling: $<"
	@$(CC)  $@ -MMD $(CPPFLAGS) -c $< -o $@

all: ${NAME}

${NAME}: $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "MyAwesomePhoneBook compiled."

clean:
	@$(RM) $(NAME)

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re 
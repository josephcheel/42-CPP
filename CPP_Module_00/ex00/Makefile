NAME = Megaphone

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
RM		= rm -f
MD		= mkdir -p
CP		= cp -f
CC		= c++

MEGAPHONE_SRC	=	megaphone.cpp \

SRCS	+= $(MEGAPHONE_SRC)
OBJS	= $(SRCS:.c=.o)
DEPS	= $(basename $(OBJS))

%.o: %.c Makefile
	@echo "	Compiling: $<"
	@$(CC) - $@ -MMD $(CPPFLAGS) -c $< -o $@

all: ${NAME}

${NAME}: $(OBJS)
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "Megaphone compiled."

clean:
	@$(RM) $(OBJS)

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re 

NAME = megaphone

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
AR		= ar -rcs
RM		= rm -fr
MD		= mkdir -p
CP		= cp -f
CC		= c++
DEPFLAGS			= -MMD -MP

MEGAPHONE_SRC	=	megaphone.cpp \

SRCS_DIR = 
OBJS_DIR = obj/

SRCS	+= $(MEGAPHONE_SRC)
OBJS	= ${addprefix ${OBJS_DIR}, ${SRCS:.cpp=.o}}
DEPS	= ${addprefix ${OBJS_DIR}, ${SRCS:.cpp=.d}}


$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp Makefile
	@$(MD) $(dir $@)
	@echo "	Compiling: $<"
	@$(CC) -c $(CPPFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@ 
#$@ -c

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(INCLUDE) -o $@ $^ $(LIBS)
	@echo "Megaphone compiled."

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re 

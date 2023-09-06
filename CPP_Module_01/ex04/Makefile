NAME = replacer.out

CPPFLAGS = -std=c++98 -Wall -Wextra -Werror
AR		= ar -rcs
RM		= rm -fr
MD		= mkdir -p
CP		= cp -f
CC		= c++
DEPFLAGS			= -MMD -MP

MAIN_SRC	=	main.cpp \

SRCS_DIR = 
OBJS_DIR = obj/

SRCS	+= $(MAIN_SRC)
OBJS	= ${addprefix ${OBJS_DIR}, ${SRCS:.cpp=.o}}
DEPS	= ${addprefix ${OBJS_DIR}, ${SRCS:.cpp=.d}}


$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp Makefile
	@$(MD) $(dir $@)
	@$(CC) -c $(CPPFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@ 
	@echo "$(WARN_COLOR)Compiling: $<$(NO_COLOR)"

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CPPFLAGS) $(INCLUDE) -o $@ $^ $(LIBS)
	@echo "$(OK_COLOR)$(NAME) compiled!$(NO_COLOR)"

clean:
	@$(RM) $(OBJS_DIR)
	@echo "$(ERROR_COLOR)Dependencies and objects removed$(NO_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(ERROR_COLOR)$(NAME) program removed$(NO_COLOR)"

re: fclean all

-include ${DEPS}

.PHONY: all clean fclean re 

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─COLOR──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

NO_COLOR		=	\x1b[0m
OK_COLOR		=	\x1b[32;01m
ERROR_COLOR		=	\x1b[31;01m
WARN_COLOR		=	\x1b[33;01m

OK_STRING		=	$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING	=	$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING		=	$(WARN_COLOR)[WARNINGS]$(NO_COLOR)
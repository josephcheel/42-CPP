NAME = templates

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow 
DEPFLAGS	= -MMD -MP
DEBFLAGS	= -fsanitize=address -pedantic -pedantic-errors
RM			= rm -f
MD			= mkdir -p
CP			= cp -f
CC			= c++

SRC	=	main.cpp


SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/

INCLUDE += -I $(INC_DIR)

SRCS	+= $(addprefix $(SRC_DIR), $(SRC))
OBJS	=	$(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))
DEPS	=	$(addprefix $(OBJ_DIR), $(SRCS:.cpp=.d))


$(OBJ_DIR)%.o: %.cpp Makefile
	@$(MD) $(dir $@)
	@$(CC) -c $(CPPFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@
	@echo "$(WARN_COLOR)Compiling: $<$(NO_COLOR)"

all: ${NAME}

${NAME}: $(OBJS)
	@$(CC) $(CFLAGS) $(DEBFLAGS) $(INCLUDE) -o $@ $^ $(LIBS)
	@echo "$(OK_COLOR)$(NAME) compiled!$(NO_COLOR)"

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo "$(ERROR_COLOR)Dependencies and objects removed$(NO_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(ERROR_COLOR)$(NAME) program removed$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re 

-include $(DEPS)
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

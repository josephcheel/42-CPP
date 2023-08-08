NAME = MyAwesomePhoneBook

CPPFLAGS	= -Wall -Wextra -Werror -std=c++98
DEPFLAGS	= -MMD -MP
RM			= rm -f
MD			= mkdir -p
CP			= cp -f
CC			= c++

PHONEBOOK_SRC	=	main.cpp PhoneBook.cpp \


SRC_DIR = src/
OBJ_DIR = obj/
INCLUDE = -I include

SRCS	+= $(addprefix $(SRC_DIR), $(PHONEBOOK_SRC))
OBJS	=	$(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))
DEPS	=	$(addprefix $(OBJ_DIR), $(SRCS:.cpp=.d))

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp 
	@$(MD) $(dir $@)
	@echo "	Compiling: $<"
	@$(CC) -c $(CPPFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@

all: ${NAME}

${NAME}: $(OBJS)
#@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^ $(LIBS)
	@echo "$@ compiled."

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re 
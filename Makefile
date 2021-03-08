##
## EPITECH PROJECT, 2021
## Project_2021
## File description:
## Project makefile
##

DSRC	=	./src/

SRC_FILES = 	main.c 				\
				nm.c				\
				nm_archi.c			\
				elf/load_file.c		\
				elf/elf_header.c	\
				elf/sym_type64.c	\
				elf/sym_type32.c	\
				sections/section_list.c		\
				sections/section_str.c		\
				sections/section_sym.c		\
				list/sym_list.c				\
				list/sort_list.c			\
				symbols/display_symbols.c	\
				symbols/save_symbols.c		\
				symbols/sort_symbols.c		\
#				archive.c			\

SRC	=	$(addprefix $(DSRC), $(SRC_FILES))

OBJ	=	$(SRC:.c=.o)

NAME	=	my_nm

CFLAGS	+= -W -Wall -Wextra $(INCLUDE) -g #-Werror

INCLUDE = -I./includes

all:  nm

nm: $(OBJ)
	@gcc -o $(NAME) $(OBJ) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

clean:
	rm -f  $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all

reall:	fclean all

#tests_run:
	#@gcc -o $(NAME) $(SRC_UT) -I./ -lcriterion --coverage && ./$(NAME)

.PHONY :        clean fclean re

ECHO	=	/bin/echo -e
DEFAULT	=	"\e[0m"
BOLD_T	=	"\e[1m"
DIM_T	=	"\e[2m"
UNDLN_T	=	"\e[4m"
BLACK_C	=	"\e[30m"
RED_C	=	"\e[31m"
GREEN_C	=	"\e[32m"
YELLO_C	=	"\e[33m"
BLUE_C	=	"\e[34m"
MAGEN_C	=	"\e[35m"
CYAN_C	=	"\e[36m"
WHITE_C	=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LINE_RETURN	=	$(ECHO) ""

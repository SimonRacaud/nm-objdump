##
## EPITECH PROJECT, 2021
## Project_2021
## File description:
## Project makefile
##

DSRC	=	./src/

SRC_FILES_NM = 	nm/main.c 					\
				nm/nm.c						\
				nm/nm_archi.c				\
				elf/load_file.c				\
				elf/elf_header.c			\
				elf/sym_type64.c			\
				elf/sym_type32.c			\
				sections/section_list.c		\
				sections/section_str.c		\
				sections/section_sym.c		\
				list/sym_list.c				\
				list/sort_list.c			\
				symbols/display_symbols.c	\
				symbols/save_symbols.c		\
				symbols/sort_symbols.c		\
				archive/archive.c					\
				archive/archive_section_generator.c	\
				archive/load_from_archive.c			\
				tools/my_str_to_word_array.c		\
				tools/str_to_number.c				

SRC_NM	=	$(addprefix $(DSRC), $(SRC_FILES_NM))
OBJ_NM	=	$(SRC_NM:.c=.o)
NAME_NM	=	my_nm

SRC_FILES_OBJD 	= 	objdump/main.c			\
					objdump/file_header.c	\
					objdump/objdump.c 		\
					objdump/objdumpArchi.c 	\
					objdump/show_sections.c	\
					objdump/print_section_content.c	\
					elf/load_file.c 		\
					elf/elf_header.c 		\
					sections/section_list.c \
					sections/section_str.c 	\

SRC_OBJD 		= $(addprefix $(DSRC), $(SRC_FILES_OBJD)) 
OBJ_OBJD		= $(SRC_OBJD:.c=.o)
NAME_OBJD 		= my_objdump	

CFLAGS	+= -W -Wall -Wextra $(INCLUDE) $(DEBUG) # -Werror
DEBUG 	= -g

INCLUDE = -I./includes

all:  nm objdump

nm: $(OBJ_NM)
	@gcc -o $(NAME_NM) $(OBJ_NM) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME_NM)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME_NM)\n"$(DEFAULT)

objdump:	$(OBJ_OBJD)
	@gcc -o $(NAME_OBJD) $(OBJ_OBJD) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME_OBJD)\n"$(DEFAULT) || \
		$(ECHO) $(BOLD_T)$(RED_C)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME_OBJD)\n"$(DEFAULT)

clean:
	rm -f  $(OBJ_NM) $(OBJ_OBJD)
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f $(NAME_NM) $(NAME_OBJD)

re:	fclean all

nm_re: fclean nm
obj_re: fclean objdump

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

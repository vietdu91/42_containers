	# Library Name #

NAME		=	ft_containers
STD_NAME	=	true_std_containers

	# Compilator #

COMPILER	=	c++

	# Variables #

SRCS		=		main.cpp \

INCLUDES	=		includes/std_functions/equal.hpp

	# Colors Foreground #

DEFAULT		=	\033[0;39m
BLACK		=	\033[0;30m
RED			=	\033[0;31m
RED_B		=	\033[1;31m
L_RED		=	\033[0;91m
GREEN		=	\033[0;32m
GREEN_B		=	\033[1;32m
L_GREEN		=	\033[0;92m
YELLOW		=	\033[0;33m
L_YELLOW	=	\033[0;93m
BLUE		=	\033[0;34m
BLUE_B		=	\033[1;34m
L_BLUE		=	\033[0;94m
PINK		=	\033[0;35m
L_PINK		=	\033[0;95m
SKY			=	\033[0;36m
SKY_B		=	\033[1;36m
L_SKY		=	\033[0;96m
GREY		=	\033[0;37m
D_GREY		=	\033[0;90m
WHITE		=	\033[0;97m
RESET		=	\e[0m

	# Colors Background #

NOIR		=	\033[0;40m
ROUGE		=	\033[0;41m
L_ROUGE		=	\033[0;101m
VERT		=	\033[0;42m
L_VERT		=	\033[0;102m
JAUNE		=	\033[0;43m
L_JAUNE		=	\033[0;103m
BLEU		=	\033[0;44m
L_BLEU		=	\033[0;104m
ROSE		=	\033[0;45m
L_ROSE		=	\033[0;105m
CYAN		=	\033[0;46m
L_CYAN		=	\033[0;106m
GRIS		=	\033[0;100m
BLANC		=	\033[0;107m

	# Objects #

OBJS	=	${SRCS:.cpp=.o}
OBJS	:=	$(addprefix objs/,${OBJS})
DEP		=	$(OBJS:.o=.d)

STD_OBJS	=	${SRCS:.cpp=.o}
STD_OBJS	:=	$(addprefix objs_std/,${STD_OBJS})
STD_DEP		=	$(STD_OBJS:.o=.d)

	# Flags #

FLAGS		=	-g3 -Wall -Wextra -Werror -std=c++98

	# Rules #
all:		${NAME} ${STD_NAME}
			@printf "$(L_PINK)<3 <3 $(RESET)"
			@printf "$(RED_B)vietdu91 le sang$(RESET)"
			@printf "$(L_PINK) <3 <3 \n$(RESET)"

ft:			${NAME}
			@printf "$(L_SKY)<3 <3 $(RESET)"
			@printf "$(BLUE_B)vietdu91 le sang$(RESET)"
			@printf "$(L_SKY) <3 <3 \n$(RESET)"

std:		${STD_NAME}
			@printf "$(L_PINK)<3 <3 $(RESET)"
			@printf "$(RED_B)vietdu91 le sang$(RESET)"
			@printf "$(L_PINK) <3 <3 \n$(RESET)"

$(NAME):	${OBJS} ${INCLUDES}
			${COMPILER} ${FLAGS} -I includes ${OBJS} -o $(NAME)
			@printf "\n\n$(SKY)████████████████  😊 😊 😊  PENSEE DU JOUR POUR TE FAIRE SOURIRE  😊 😊 😊  ████████████████$(RESET)"
			@printf "\n\n$(BLUE_B)Hell has a name : FT_CONTAINERS ☠🔥😈✡⛩️☠✝👹☄💀👿☦☠🔥😈✡⛩️☠✝👹☄💀👿☦ !!!  \n\n$(RESET)"
			@printf "$(YELLOW)============$(RESET)"
			@printf "\e[38;5;227m============$(RESET)"
			@printf "\e[38;5;228m============$(RESET)"
			@printf "\e[38;5;229m============$(RESET)"
			@printf "\e[38;5;230m============$(RESET)"
			@printf "\e[38;5;231m============\n$(RESET)"
			@printf "$(GREEN)La vie passe, la moulinette trepasse !\n\n$(RESET)"

$(STD_NAME):	${STD_OBJS} ${INCLUDES}
				${COMPILER} ${FLAGS} -I includes ${STD_OBJS} -o $(STD_NAME)

-include $(DEP)

objs/%.o:	srcs/%.cpp
			@mkdir -p $(dir $@)
			@${COMPILER} -MMD -MP ${FLAGS} -I includes -o $@ -c $<

objs_std/%.o:	srcs/%.cpp
				@mkdir -p $(dir $@)
				@${COMPILER} -MMD -MP ${FLAGS} -I includes -D STD -o $@ -c $<

diff :	${NAME} ${STD_NAME}
		@./$(NAME) > $(NAME).txt
		@./$(STD_NAME) > $(STD_NAME).txt
		@printf "\n\n$(PINK_B)"
		-@diff -s $(NAME).txt $(STD_NAME).txt
		@printf "$(RESET)"
		@rm $(NAME).txt $(STD_NAME).txt

clean:
			rm -f ${OBJS}
			rm -f ${STD_OBJS}
			rm -rf objs
			rm -rf objs_std
			@printf "$(YELLOW)\nAu fond, est-ce que ranger ça ne revient pas un peu à foutre le bordel dans son désordre ? \n$(RESET)"
			@printf "$(YELLOW)============$(RESET)"
			@printf "\e[38;5;227m============$(RESET)"
			@printf "\e[38;5;228m============$(RESET)"
			@printf "\e[38;5;229m============$(RESET)"
			@printf "\e[38;5;230m============$(RESET)"
			@printf "\e[38;5;231m============\n$(RESET)"
			@printf "$(GREEN)Que la paix regne sur ton foyer\n\n$(RESET)"

fclean:
			rm -f ${OBJS}
			rm -f ${STD_OBJS}
			rm -f ${NAME}
			rm -f ${STD_NAME}
			rm -rf objs
			rm -rf objs_std
			rm -rf diff
			@printf "$(YELLOW)\nAu fond, est-ce que ranger ça ne revient pas un peu à foutre le bordel dans son désordre ? \n$(RESET)"
			@printf "$(YELLOW)============$(RESET)"
			@printf "\e[38;5;227m============$(RESET)"
			@printf "\e[38;5;228m============$(RESET)"
			@printf "\e[38;5;229m============$(RESET)"
			@printf "\e[38;5;230m============$(RESET)"
			@printf "\e[38;5;231m============\n$(RESET)"
			@printf "$(GREEN)Que la paix regne sur ton foyer\n\n$(RESET)"

re:			fclean all
			@printf "$(YELLOW)\nAimer, désirer, c’est aussi souffrir, et être prêt à recommencer... \n$(RESET)"
			@printf "\e[38;5;227m============$(RESET)"
			@printf "\e[38;5;228m============$(RESET)"
			@printf "\e[38;5;229m============$(RESET)"
			@printf "\e[38;5;230m============$(RESET)"
			@printf "\e[38;5;231m============\n$(RESET)"

.PHONY:	all clean fclean re

##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard	sources/*.c)
LIBS	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system
PATHLIB	=	.
NAME	=	my_hunter

all:	libcomp	build

libcomp:
	$(MAKE)	-C	./lib/my

build:
	gcc $(SRC) -o $(NAME) -L$(PATHLIB) $(LIBS) -lmy -Iinclude/ -g3

clean:
	make -C lib/my clean

fclean:	clean
	rm	-fr	$(NAME)

re:	fclean	all

##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	$(wildcard	*.c)

OBJ	=	$(SRC:.c=.o)

NAMELIB	=	libmy.a

all:	cph	build	copylib	permlib

build:	$(OBJ)
	echo	${SRC}
	ar	rc	$(NAMELIB) *.o

copylib:
	cp	$(NAMELIB)	../../

permlib:
	chmod	777 $(NAMELIB)

cph:
	cp	my.h	../../include

clean:
	rm	-f	$(OBJ)

fclean:	clean
	rm	-f	$(NAMELIB)

re:	fclean	all

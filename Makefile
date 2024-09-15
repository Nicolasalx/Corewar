##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_ASM		=	asm
SRC_COREWAR	=	corewar

NAME_TESTS	=	unit_tests

$(MAKE):
	cd $(SRC_ASM) && $(MAKE)
	cd $(SRC_COREWAR) && $(MAKE)

all:
	cd $(SRC_ASM) && $(MAKE) all
	cd $(SRC_COREWAR) && $(MAKE) all

clean:
	cd $(SRC_ASM) && $(MAKE) clean
	cd $(SRC_COREWAR) && $(MAKE) clean

fclean:
	cd $(SRC_ASM) && $(MAKE) fclean
	cd $(SRC_COREWAR) && $(MAKE) fclean

re: fclean all

unit_tests:
	cd $(SRC_ASM) && $(MAKE) unit_tests
	cd $(SRC_COREWAR) && $(MAKE) unit_tests

tests_run:
	cd $(SRC_ASM) && $(MAKE) tests_run
	cd $(SRC_COREWAR) && $(MAKE) tests_run

gcovr:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY: all clean fclean re unit_tests tests_run gcovr

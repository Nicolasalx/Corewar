# Corewar
## Definition
The Corewar project is a game in which several programs called "Champions" will fight to stay the last one alive.
Corewar is actually a computer simulation in which processors will share memory to run on.
The project is based on a virtual machine in which the champions will fight for memory by all possible means in order to win, the last champion being able to signal that he is alive wins the game.
In other words, the last champion to execute the "live" instruction is declared winner.

## Description
The project is divided into three seperate parts:

__• Champions__

The champions are files written in an assembly language specific to our virtual machine. The file is
filled with instructions that the champion must follow, it’s his line of conduct. It is in this file that the
champion knows when he must attack, defend himself or announce that he is still alive.
Examples of champions are given in the attachments.

__• The Assembler__

The assembler is the first of the two binaries that you are asked to do. The purpose of this program,
like a program that your own computer would try to run, is to transcribe the champions (the .s files)
into a language that the virtual machine can understand. It will therefore be necessary to understand
the assembly language in order to translate it byte by byte.

__• The Virtual Machine__

In most cases, the second binary, the virtual machine, will come only after the development of the
assembly part because it will ask you to execute the instructions of each of the champions and thus. ..
to understand the machine language that you just translated! The virtual machine is thus a program
which will place at the disposal a memory zone so that the champions can share it and fight on it.
The importance of the machine is to correctly execute the instructions of each one by respecting an
order and a cycle of play in an allotted time or until there remains only one.

##  Compilation
The project can be compiled using the Makefile, with the following rules:

'__make__': compiles both the '__asm__' and '__corewar__' binaries

'__make re__': recompiles both binaries

'__make clean__': removes all object files

'__make fclean__': removes all object files and the binaries

The project should include all source files, except for binary, temp, and obj files. Any bonus files should be included in a directory named '__bonus__'.

## Usage
'__asm__' takes one parameter: The path to the file who will be transformed in .cor.

'__corewar__' takes multiple parameters: The path for all champions .cor to execute. 

## Lossless Compression

## Bonus
'__Website__'

The Website bonus allows with a front to select and edit champions and to be able to launch the Graphical Corewar afterwards.

![image](https://i.ibb.co/9gvRZz3/image-1.png)


'__Graphical Corewar__'

The bonus graphical corewar is an arena on a virtual machine which represents the memory of this one. Champions fight on this arena trying to write the fastest and furthest in memory.
This is represented in CSFML where each champion is defined with the percentage of control they hold over memory.
![image](https://i.ibb.co/8XbTLZq/Screenshot-2023-05-27-17-23-35.png)


'__Graphical CPP__'

The bonus of Graphical C++ which will allow you to take random champions in a folder and display them in CSFML and to be able to launch the simulation.

![image](https://i.ibb.co/8MvK6y2/cpp.png)


'__Champion Generator__'

The champion generator will generate a random champion thanks to the Chat GPT API.
The prompt is composed of two strings which form a request.
First we have a file in which we write all the information so that Chat GPT can understand what they have to generate.
Secondly we have the request of the user who uses it via a front in Python thanks to the lib tkinter.
These two strings make it possible to form an optimal query to generate the perfect champion.

![image](https://i.ibb.co/9bv2Lpv/gen.png)


'__Interpretor S++__'

The S++ bonus is an interpreter that will convert a file that is more understandable than an asm file into an .s file.

![image](https://i.ibb.co/rm7xsJM/Screenshot-2023-05-27-17-18-09.png)


'__Convertor__'

The Convertor bonus will convert hexadecimal, binary and decimal.
It is developed in python with a front-end thanks to the tkinter lib.

![image](https://i.ibb.co/n1WHsyW/conv.png)


## Authors
__Thibaud Cathala__

thibaud.cathala@epitech.eu

__Nicolas Alexandre__

nicolas1.alexandre@epitech.eu

__Jules Beauvais__

jules.beauvais@epitech.eu

__Natanel Cohen__

natanel.cohen@epitech.eu

## Acknowledgments

Epitech for providing the project guidelines

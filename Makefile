##
## Makefile for BSQ in /home/valeru_r/rendu/Prog_Elem/BSQ/CPE_2015_BSQ
## 
## Made by Reever Valerus
## Login   <valeru_r@epitech.net>
## 
## Started on  Mon May  9 19:48:05 2016 Reever Valerus
## Last update Mon May  9 19:49:26 2016 Reever Valerus
##

all	:
		make -C src

clean	:
		make -C src clean

fclean	:
		make -C src fclean

re	:	fclean all

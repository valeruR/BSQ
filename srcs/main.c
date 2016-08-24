/*
** main.c for Yeezy in /home/valeru_r/rendu/Prog_Elem/BSQ/CPE_2015_BSQ
** 
** Made by Reever Valerus
** Login   <valeru_r@epitech.net>
** 
** Started on  Wed Dec 16 09:37:24 2015 Reever Valerus
** Last update Mon May  9 19:52:59 2016 Reever Valerus
*/

#include <stdlib.h>
#include "BSQ.h"

int	main(int argc, char **argv)
{
  if (argc == 2)
    fonct_open_read(argv[1]);
  my_putchar('\n');
  return (0);
}

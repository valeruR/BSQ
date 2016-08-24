/*
** open_read.c for Yeezy in /home/valeru_r/rendu/Prog_Elem/BSQ/CPE_2015_BSQ
** 
** Made by Reever Valerus
** Login   <valeru_r@epitech.net>
** 
** Started on  Wed Dec 16 09:43:29 2015 Reever Valerus
** Last update Wed Jun  1 20:51:28 2016 Reever Valerus
*/

#include "BSQ.h"

static int	calc_file(char *str)
{
  int		cols;
  int		rowls;
  int		value;

  cols = calc_cols(str);
  rowls = calc_rowls(str);
  value = rowls * cols;
  return (value);
}

int	fonct_open_read(char *filepath)
{
  int	fd;
  int	r;
  int	j;
  char	buff[4096];
  char	**tab;
  int	cols;

  if ((fd = open(filepath, O_RDONLY)) == -1)
    return (-1);
  cols = my_getnbr(get_line(fd));
  if ((r = read(fd, buff, 4095)) == -1)
    return ;
  buff[r] = '\0';
  j = (calc_file(buff));
  tab = creat_tab(buff);
  if (buff[r] != filepath[my_strlen(filepath)])
    return ;
  close(fd);
}

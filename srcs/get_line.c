/*
** getline.c for BSQ in /home/valeru_r/rendu/Prog_Elem/BSQ/CPE_2015_BSQ/src
** 
** Made by Reever Valerus
** Login   <valeru_r@epitech.net>
** 
** Started on  Wed Jun  1 01:44:58 2016 Reever Valerus
** Last update Wed Jun  1 01:57:03 2016 Reever Valerus
*/

#include "BSQ.h"

static char	*my_realloc(char *line, char c, int *idx)
{
  char		*str;
  int		idx_str;

  if ((str = malloc(sizeof(char) * ((*idx) + 2))) == NULL)
    return (NULL);
  idx_str = 0;
  if (line != NULL)
    {
      while (idx_str < (*idx))
	{
	  str[idx_str] = line[idx_str];
	  idx_str++;
	}
      free(line);
    }
  str[idx_str] = c;
  idx_str++;
  str[idx_str] = 0;
  *idx = *idx + 1;
  return (str);
}

char		*get_line(const int fd)
{
  char		*line;
  int		idx;
  int		charac_read;
  char		charac;
  int		check;

  check = 1;
  idx = 0;
  line = NULL;
  while (check != 0)
    {
      if ((charac_read = read(fd, &charac, 1)) <= 0)
	return (line);
      if (idx == 0)
	if ((line = malloc(sizeof(char) * 2)) == NULL)
	  return (NULL);
      if (charac == '\n')
	check = 0;
      else
	line = my_realloc(line, charac, &idx);
    }
  line[idx] = 0;
  return (line);
}

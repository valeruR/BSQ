/*
** algo2.c for Yeezy in /home/valeru_r/rendu/Prog_Elem/BSQ/CPE_2015_BSQ
** 
** Made by Reever Valerus
** Login   <valeru_r@epitech.net>
** 
** Started on  Sun Dec 20 17:24:57 2015 Reever Valerus
** Last update Wed Jun  1 20:19:06 2016 Reever Valerus
*/

#include "BSQ.h"

void    algorithme(char **tab, int rowls, int cols, int **tab2)
{
  t_bsq my_algo;

  my_algo.index_rowl = rowls - 2;
  tab2 = tab_int_creat(tab, rowls, cols, tab2);
  my_algo.result = 1;
  while (my_algo.index_rowl >= 0)
    {
      my_algo.index_col = cols - 2;
      while (my_algo.index_col >= 0)
        {
          if (tab2[my_algo.index_rowl][my_algo.index_col] != 0)
            tab2[my_algo.index_rowl][my_algo.index_col] =
	      taille(tab2, my_algo.index_rowl, my_algo.index_col) + 1;
          my_algo.compare = tab2[my_algo.index_rowl][my_algo.index_col];
          if (my_algo.compare >= my_algo.result)
            my_algo.result = my_algo.compare;
          my_algo.index_col--;
        }
      my_algo.index_rowl--;
    }
  make_map_final(tab, tab2, rowls, cols, my_algo.result);
  print_map_final(tab, rowls, cols);
}

int     **tab_int_creat(char **tab, int rowls, int cols, int **tab2)
{
  int   i;
  int   j;

  i = 0;
  while (i != rowls)
    {
      j = 0;
      while (j != cols)
	{
          if (tab[i][j] == 'o')
            tab2[i][j] = 0;
          else
            tab2[i][j] = 1;
          j++;
        }
      i++;
    }
  return (tab2);
}

void    afficher_tab_int(int **tab, int rowls, int cols)
{
  int   i;
  int   j;

  i = 0;
  while (i != rowls)
    {
      j = 0;
      while (j != cols)
        {
          my_put_nbr(tab[i][j]);
          my_putchar(' ');
          j++;
        }
      my_putchar('\n');
      i++;
    }
}

int	taille(int **tab, int index_rowls, int index_cols)
{
  t_taille	my_size;

  my_size.ind_rowl = index_rowls + 1;
  my_size.ind_col = index_cols + 1;
  if (tab[my_size.ind_rowl][index_cols] >= tab[index_rowls][my_size.ind_col])
    {
      if (tab[my_size.ind_rowl][my_size.ind_col] > tab[index_rowls][my_size.ind_col])
	return (tab[index_rowls][my_size.ind_col]);
      return (tab[my_size.ind_rowl][my_size.ind_col]);
    }
  else
    {
      if (tab[my_size.ind_rowl][my_size.ind_col] > tab[my_size.ind_rowl][index_cols])
	return (tab[my_size.ind_rowl][index_cols]);
      return (tab[my_size.ind_rowl][my_size.ind_col]);
    }
}

static char	**put_char_tab(char **tab, int i, int *j, int n)
{
  if (n == 1)
      tab[i][*j] = 'o';
  else
      tab[i][*j] = '.';
  *j = *j + 1;
  return (tab);
}

void	make_map_final(char **tab, int  **tab2, int rowls, int cols, int max)
{
  int	i;
  int	j;
  int	u;

  i = 0;
  u = 0;
  while (i != rowls)
    {
      j = 0;
      while (j != cols)
	{
	  if (tab2[i][j] == 0)
	    tab = put_char_tab(tab, i, &j, 1);
	  else if (tab2[i][j] == max && u == 0)
	    {
	      u++;
	      print_square(tab, i, j, max);
	      j = j + max;
	    }
	  else if (tab[i][j] == 'X')
	    j++;
	  else
	    tab = put_char_tab(tab,i, &j, 2);
	}
      i++;
    }
}

void	print_square(char **tab, int index_rowls, int index_cols, int max)
{
  t_taille	my_size;
  int		count;

  my_size.ind_rowl = index_rowls + max;
  my_size.ind_col = index_cols + max;
  while (index_cols != my_size.ind_col)
    {
      count = index_rowls;
      while (count != my_size.ind_rowl)
	{
	  tab[count][index_cols] = 'X';
	  count++;
	}
      index_cols++;
    }
}

void	print_map_final(char **tab, int rowls, int cols)
{
  int	i;
  int	j;

  i = 0;
  my_putstr("\n\n");
  while (i != rowls)
    {
      j = 0;
      my_putstr("\t\t");
      while (j != cols)
	{
	  my_putchar(tab[i][j]);
	  j++;
	}
      my_putchar('\n');
      i++;
    }
  my_putchar('\n');
}

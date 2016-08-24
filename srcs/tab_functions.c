/*
** fonctions_tab.c for Yeezy in /home/valeru_r/rendu/Prog_Elem/BSQ/CPE_2015_BSQ
** 
** Made by Reever Valerus
** Login   <valeru_r@epitech.net>
** 
** Started on  Wed Dec 16 14:50:25 2015 Reever Valerus
** Last update Wed Jun  1 20:52:25 2016 Reever Valerus
*/

#include "BSQ.h"

int     calc_cols(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\n')
    i++;
  return (i);
}

int     calc_rowls(char *str)
{
  int   i;
  int   result;

  i = 0;
  result = 0;
  while (str[i])
    {
      if (str[i] == '\n')
        result++;
      i++;
    }
  return (result);
}

static void		init_structs(t_data *data, t_alloc *var, char *buff)
{
  data->cols = calc_cols(buff);
  data->rowls = calc_rowls(buff);
  data->result = mem_alloc_2d_array(data->rowls, data->cols);
  data->tab = creat_tab_int(data->rowls, data->cols);
  var->val_tab = data->cols * data->rowls;
  var->index_rowl = 0;
  var->index_col = 0;
  var->index_buff = 0;
  var->mul_col = 1;
}

char    **creat_tab(char *buff)
{
  t_alloc	cre_tab;
  t_data	data;
  int	**tab2;

  init_structs(&data, &cre_tab, buff);
  while (cre_tab.index_rowl != data.rowls)
    {
      if (buff[cre_tab.index_buff] != '\n')
        {
          data.result[cre_tab.index_rowl][cre_tab.index_col] =
	    buff[cre_tab.index_buff];
          cre_tab.index_col++;
          cre_tab.index_buff++;
        }
      else
	{
	  cre_tab.index_buff++;
	  cre_tab.index_col = 0;
	  cre_tab.index_rowl++;
	  cre_tab.mul_col++;
	}
    }
  algorithme(data.result, data.rowls, data.cols, data.tab);
  return (data.result);
}

int	**check_map(char **tab, int rowls, int cols, int **tab2)
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
          j++;
        }
      i++;
    }
  return (tab2);
}

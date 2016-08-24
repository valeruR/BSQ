/*
** BSQ.h for Yeezy in /home/valeru_r/rendu/Prog_Elem/BSQ/CPE_2015_BSQ/include
** 
** Made by Reever Valerus
** Login   <valeru_r@epitech.net>
** 
** Started on  Wed Dec 16 09:40:51 2015 Reever Valerus
** Last update Wed Jun  1 20:51:47 2016 Reever Valerus
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef BSQ_H_
# define BSQ_H_

typedef struct		s_data
{
  int			given;
  int			cols;
  int			rowls;
  int			**tab;
  char			**result;

}			t_data;

typedef struct		s_bsq
{
  int			index_col;
  int			index_rowl;
  int			result;
  int			compare;
}			t_bsq;

typedef struct		s_alloc
{
  int			index_rowl;
  int			index_col;
  int			mul_col;
  int			val_tab;
  int			index_buff;
}			t_alloc;

typedef struct		s_taille
{
  int			result_col;
  int			result_rowl;
  int			ind_col;
  int			ind_rowl;
  int			result;
}			t_taille;

void	my_putchar(char c);
int	my_putstr(char *str);
int	my_strlen(char *str);
char	**mem_alloc_2d_array(int nb_rowls, int nb_cols);
int	my_put_nbr(int nb);
int	**creat_tab_int(int rowls, int cols);
int	calc_cols(char *str);
int	calc_rowls(char *str);
char	**creat_tab(char *buff);
int	**check_map(char **tab, int rowls, int cols, int **tab2);
void	write_tab(char **tab, int rowls, int cols);
void	algorithme(char **tab, int rowls, int cols, int **tab2);
int	taille(int **tab_int, int index_rowls, int index_cols);
int	**tab_int_creat(char **tab ,int rowls, int cols, int **tab2);
void	afficher_tab_int(int **tab, int rowls, int cols);
void	make_map_final(char **tab, int **tab2, int rowls, int cols, int max);
void	print_square(char **tab, int index_rowls, int index_cols, int max);
void	print_map_final(char **tab, int rowls, int cols);
int	fonct_open_read(char *filepath);
char	*get_line(const int fd);

#endif

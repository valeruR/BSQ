/*
** lib_functions2.c for BSQ in /home/valeru_r/rendu/Prog_Elem/BSQ/CPE_2015_BSQ/src
** 
** Made by Reever Valerus
** Login   <valeru_r@epitech.net>
** 
** Started on  Wed Jun  1 16:14:30 2016 Reever Valerus
** Last update Wed Jun  1 20:54:15 2016 Reever Valerus
*/

#include "BSQ.h"

static void		maxnegatif(int nb)
{
  if (nb == -2147483648)
    write(1, "-2147463648", 10);
}

int		my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
      if (nb > 0 && nb < 10)
	my_putchar(nb + '0');
      else if (nb >= 10)
	{
	  my_put_nbr(nb / 10);
	  my_put_nbr(nb % 10);
	}
      maxnegatif(nb);
    }
  else if (nb >= 0 && nb < 10)
    my_putchar(nb + '0');
  else
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  return (0);
}

static int	get_nbr(const char *str, int idx, int neg)
{
  int		value;
  int		token;

  value = 0;
  while (str[idx] && str[idx] >= '0' && str[idx] <= '9')
    {
      token = value;
      if (token > (value * 10 + (str[idx] - '0')))
	return (0);
      value = value * 10 + (str[idx] - '0');
      idx++;
    }
  if (neg % 2 == 0)
    return (value * (-1));
  return (value);
}

int		my_getnbr(char *str)
{
  int		idx;
  int		value;
  int		neg;

  idx = 0;
  neg = 0;
  if (str == NULL)
    return (0);
  while (str[idx])
    {
      if (str[idx] == '-')
	neg++;
      if (str[idx] >= '0' && str[idx] <= '9')
	{
	  value = get_nbr(str, idx, neg);
	  return (value);
	}
      idx++;
    }
  return (0);
}

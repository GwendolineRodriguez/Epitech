/*
** header.h for header in /home/gwendoline/rendu/Piscine_Synthese
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Mon Jun 15 11:50:39 2015 
** Last update Wed Jun 17 21:10:26 2015 
*/

#ifndef HEADER_H_
#define HEADER_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define COUNT 1

typedef struct	s_comp	t_comp;
typedef struct	s_reac	t_reac;
typedef	struct	s_spec	t_spec;
typedef	struct	s_specr	t_specr;
typedef struct	s_opt	t_opt;
typedef struct	s_param	t_param;

typedef struct	s_data
{
  int		sbml;
  int		sbml_level;
  int		sbml_version;
  int		sbml_xmlns;
  int		model;
  int		model_id;
  int		model_name;
  int		comp;
  int		comp_id;
  int		comp_name;
  int		reac;
  int		reac_id;
  int		reac_name;
  int		reac_reversible;
  int		spec;
  int		spec_compartment;
  int		spec_id;
  int		spec_name;
  int		specr;
  int		specr_species;
  int		specr_stoi;
  int		check_i;
  int		check_e;
  int		check_json;
  int		check_gui;
}		t_data;

typedef struct	s_comp
{
  char		*id;
  char		*name;
  t_comp	*next;
}		t_comp;

typedef struct	s_reac
{
  char		*id;
  char		*name;
  char		*reversible;
  t_reac	*next;
}		t_reac;

typedef struct	s_spec
{
  char		*compartment;
  char		*id;
  char		*name;
  t_spec	*next;
}		t_spec;

typedef struct	s_specr
{
  char		*species;
  char		*stoichiometry;
  t_specr	*next;
}		t_specr;

typedef struct	s_param
{
  t_data	*data;
  t_comp	*comp;
  t_reac	*reac;
  t_spec	*spec;
  t_specr	*specr;
}		t_param;

void		my_putchar(char c);
int		my_strlen(char *str);
void		my_putstr(char *str);
void		put_error(char *str);
void		my_putnbr(int nb);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strncpy(char *dest, char *src, int n);
char		*get_next_line(const int fd);
int		parser(char *str, t_param *p);
void		get_sbml_data(char *str, t_param *p);
t_param         *init_param();
void            display_data(t_param *p);
void		check_model(char *str, t_param *p);
void		check_sbml(char *str, t_param *p);
void            display_comp(t_param *p);
void            display_reac(t_param *p);
void            display_model(t_param *p);
void            display_sbml(t_param *p);
void            display_data(t_param *p);
void            display_spec(t_param *p);
void            display_specr(t_param *p);
void            check_specr(char *str, t_param *p);
void            check_spec(char *str, t_param *p);
void            check_reac(char *str, t_param *p);
void            check_comp(char *str, t_param *p);
void            check_model(char *str, t_param *p);
void            check_sbml(char *str, t_param *p);

#endif

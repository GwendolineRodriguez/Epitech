/*
** test_args.c for test_args in /home/gwendoline/rendu/Piscine_Synthese/projTester
**
** Made by 
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jun 18 19:26:08 2015 
** Last update Sat Jun 20 23:07:06 2015 
*/

#include "./../header.h"

void		put_stats(t_param *p)
{
  printf("***************************************\n");
  printf("tests valides : %d\n", p->data->check_ok);
  printf("tests non valides : %d\n", p->data->check_ko);
  printf("***************************************\n");
}

void		exec_redirect(t_param *p, char **tab, char *inputfile)
{
  int		fd;

  fd = open(inputfile, O_RDONLY);
  dup2(fd, 0);
  execvp(p->bin, tab);
}

void		call_son(t_param *p, int fd, int *pipefd, t_list *tmp)
{
  if (p->data->output == 1)
    {
      close(1);
      fd = open(p->data->fileout, O_CREAT | O_APPEND | O_WRONLY, 0644);
      dup2(fd, 1);
    }
  if (my_strcmp(tmp->type, "ENTREE") == 0)
    exec_redirect(p, tmp->prev->args, tmp->inputfile);
  else if (my_strcmp(tmp->type, "RES") == 0)
    {
      close(pipefd[0]);
      dup2(pipefd[1], 1);
    }
  else
    execvp(p->bin, tmp->args);
}

void		call_father(t_param *p, int fd, int *pipefd, t_list *tmp)
{
  wait(NULL);
  if (tmp->res != NULL)
    {
      p->data->input = malloc(sizeof(char) * 10000);
      read(pipefd[0], p->data->input, 10000);
      print_res(tmp->res, p->data->input);
    }
}

void		test_args(t_param *p, int fd)
{
  int		pid;
  t_list	*tmp;
  int		pipefd[1];

  tmp = p->list;
  pipe(pipefd);
  while (tmp)
    {
      pid = fork();
      if ((tmp->next != NULL) && my_strcmp(tmp->type, "ARGS") == 0
	  && (tmp->args[1] == NULL) && my_strcmp(tmp->next->type, "ENTREE") == 0)
	tmp = tmp->next;
      if (!pid)
	call_son(p, fd, pipefd, tmp);
      else
	call_father(p, fd, pipefd, tmp);
      tmp = tmp->next;
    }
  close(fd);
}

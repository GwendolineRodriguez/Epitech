/*
** castmania.c for castmania in /home/gwendoline/Epitech/Tek2/rendu/Piscine_cpp/piscine_cpp_d02m/ex04
**
** Made by Gwendoline Rodriguez
** Login   <gwendoline@epitech.net>
**
** Started on  Thu Jan  7 14:37:30 2016 Gwendoline Rodriguez
** Last update Thu Jan  7 18:31:42 2016 Gwendoline Rodriguez
*/

#include "castmania.h"

void	exec_operation(t_instruction_type instruction_type, void *data)
{
  t_instruction *inst;

  if (instruction_type == DIV_OPERATION)
    {
      inst = (t_instruction *) data;
      exec_div(inst->operation);
      if (inst->output_type == VERBOSE)
	{
	  if (((t_div *) inst->operation)->div_type == INTEGER)
	    printf("%i\n", ((t_integer_op *) ((t_div *) inst->operation)->div_op)->res);
	  else
	    printf("%f\n", ((t_decimale_op *) ((t_div *) inst->operation)->div_op)->res);
	}
    }
  else if (instruction_type == ADD_OPERATION)
    {
      inst = (t_instruction *) data;
      exec_add(inst->operation);
      if (inst->output_type == VERBOSE)
	printf("%i\n", ((t_add *) inst->operation)->add_op.res);
    }
}

void	exec_instruction(t_instruction_type instruction_type, void *data)
{
  if (instruction_type == ADD_OPERATION || instruction_type == DIV_OPERATION)
    exec_operation(instruction_type, data);
  else if (instruction_type == PRINT_INT) {
    printf("%i\n", (int) *((int *) data));
  }
  else if (instruction_type == PRINT_FLOAT) {
    printf("%f\n", (float) *((float *) data));
  }
}

int main(void)
{
  int i = 5;
  float f = 42.5;
  t_instruction inst;
  t_add add;
  t_div div;
  t_integer_op int_op;

  printf("Affiche i : ");
  exec_instruction(PRINT_INT, &i);
  printf("Affiche f : ");
  exec_instruction(PRINT_FLOAT, &f);

  printf("\n");

  int_op.a = 10;
  int_op.b = 3;

  add.add_type = ABSOLUTE;
  add.add_op = int_op;

  inst.output_type = VERBOSE;
  inst.operation = &add;

  printf("10 + 3 = ");
  exec_instruction(ADD_OPERATION, &inst);

  printf("En effet 10 + 3 = %d\n\n", add.add_op.res);

  div.div_type = INTEGER;
  div.div_op = &int_op;

  inst.operation = &div;

  printf("10 / 3 = ");
  exec_instruction(DIV_OPERATION, &inst);

  printf("En effet 10 / 3 = %d\n\n", int_op.res);

  return (0);
}

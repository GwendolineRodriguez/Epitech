#ifndef CASTMANIA_H_
# define CASTMANIA_H_

/*
** Includes
*/

#include <stdio.h>
#include <stdlib.h>

/*
** Enumerations
 */

typedef enum e_instruction_type
  {
    PRINT_INT,
    PRINT_FLOAT,
    ADD_OPERATION,
    DIV_OPERATION
  }                t_instruction_type;

typedef enum e_div_type
  {
    INTEGER,
    DECIMALE
  }		t_div_type;

typedef enum	e_add_type
  {
    NORMAL,
    ABSOLUTE
  }		t_add_type;

typedef enum e_output_type
  {
    SILENT,
    VERBOSE
  }		t_output_type;

/*
** Structures
*/

typedef struct s_integer_op
{
  int	a;
  int	b;
  int	res;
}                t_integer_op;

typedef struct s_decimale_op
{
  int	a;
  int	b;
  float	res;
}                t_decimale_op;

typedef struct s_add
{
  t_add_type	add_type;
  t_integer_op	add_op;
}		t_add;

typedef struct s_div
{
  t_div_type	div_type;
  void		*div_op;
}                t_div;

typedef struct s_instruction
{
  t_output_type	output_type;
  void		*operation;
}		t_instruction;

/*
** Functions
*/

int	integer_div(int a, int b);
float	decimale_div(int a, int b);
void	exec_div(t_div *operation);

int	normal_add(int a, int b);
int	absolute_add(int a, int b);
void	exec_add(t_add *operation);

void	exec_operation(t_instruction_type instruction_type, void *data);
void	exec_instruction(t_instruction_type instruction_type, void *data);

#endif /* CASTMANIA_H_ */

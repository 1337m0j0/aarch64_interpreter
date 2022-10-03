#include <stdlib.h>

#include "program/program.h"

void
Program_Destroy(Instruction** program)
{
  for (int i = 0; program[i] != (Instruction*)NULL; i++) {
    free(program[i]);
  }
  free(program);
}

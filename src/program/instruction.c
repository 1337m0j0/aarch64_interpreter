#include <stdlib.h>

#include "program/instruction.h"

void
Instruction_Destroy(Instruction* instruction)
{
  for (int i = 0; instruction->operands[i] != (Operand*)NULL; i++) {
    free(instruction->operands[i]);
  }
  free(instruction->operands);
  free(instruction);
}

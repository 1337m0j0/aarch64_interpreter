#include <stdarg.h>
#include <stdlib.h>

#include "program/instruction.h"

Instruction*
Instruction_Create(InstructionName name,
                   Operand op0,
                   Operand op1,
                   Operand op2)
{
  Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));
  instruction->name = name;
  instruction->operands[0] = op0;
  instruction->operands[1] = op1;
  instruction->operands[2] = op2;
  return instruction;
}

void
Instruction_Destroy(Instruction* instruction)
{
  if ((Instruction*)NULL != instruction) {
    free(instruction);
  }
}

void
Instruction_DestroyVoid(void* instruction)
{
  Instruction_Destroy((Instruction*)instruction);
}

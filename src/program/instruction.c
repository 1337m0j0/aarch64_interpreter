#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "program/instruction.h"

Instruction*
Instruction_Create(InstructionName name,
                   Operand op0,
                   Operand op1,
                   Operand op2,
                   char* label)
{
  Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));
  instruction->name = name;
  instruction->operands[0] = op0;
  instruction->operands[1] = op1;
  instruction->operands[2] = op2;

  if (label != (char*)NULL) {
    instruction->label = (char*)calloc(strlen(label) + 1, sizeof(char));
    char* res = strncpy(instruction->label, label, strlen(label));
    if (res != instruction->label) {
      // TODO: PANIC
    }
  }
  else {
    instruction->label = (char*)NULL;
  }

  return instruction;
}

void
Instruction_Destroy(Instruction* instruction)
{
  if (instruction->label != (char*)NULL) {
    free(instruction->label);
  }
  if ((Instruction*)NULL != instruction) {
    free(instruction);
  }
}

void
Instruction_DestroyVoid(void* instruction)
{
  Instruction_Destroy((Instruction*)instruction);
}

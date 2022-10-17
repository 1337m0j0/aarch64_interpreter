#ifndef SRC_PROGRAM_INSTRUCTION_H
#define SRC_PROGRAM_INSTRUCTION_H

#include "program/operand.h"

// ---------------------------------------------------------------------------/
// Public types
// ---------------------------------------------------------------------------/

typedef enum
{
  // ALU instructions
  MOV,
  ADD
} InstructionName;

typedef struct
{
  InstructionName name;
  Operand operands[3];
  char* label;
} Instruction;

// ---------------------------------------------------------------------------/
// Public functions
// ---------------------------------------------------------------------------/

Instruction*
Instruction_Create(InstructionName name,
                   Operand op0,
                   Operand op1,
                   Operand op2,
                   char* label);

void
Instruction_Destroy(Instruction* instruction);

#endif

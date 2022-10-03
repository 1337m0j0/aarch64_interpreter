#ifndef PROGRAM_INSTRUCTION_H
#define PROGRAM_INSTRUCTION_H

#include "processor/registers.h"

// ------------------------------------------------------------------------------------------------/
// Public types
// ------------------------------------------------------------------------------------------------/

typedef enum
{
  MOV,
  ADD
} InstructionName;

typedef enum
{
  REGISTER,
  CONSTANT
} OperandType;

typedef struct
{
  OperandType type;
  union
  {
    RegisterName register_name;
    uint64_t constant;
  } value;
} Operand;

typedef struct
{
  InstructionName name;
  Operand** operands;
} Instruction;

// ------------------------------------------------------------------------------------------------/
// Public functions
// ------------------------------------------------------------------------------------------------/

void
Instruction_Destroy(Instruction* instruction);

#endif

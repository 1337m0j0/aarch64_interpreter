#ifndef SRC_PROGRAM_INSTRUCTION_H
#define SRC_PROGRAM_INSTRUCTION_H

#include "processor/registers.h"

// ---------------------------------------------------------------------------/
// Public types
// ---------------------------------------------------------------------------/

typedef enum
{
  // ALU instructions
  MOV,
  ADD
} InstructionName;

typedef enum
{
  REGISTER, // CPU register
  CONSTANT, // immediate value
  NIL       // no operand (placeholder for fixed-length instruction)
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
  Operand operands[3];
} Instruction;

// ---------------------------------------------------------------------------/
// Public functions
// ---------------------------------------------------------------------------/

Instruction*
Instruction_Create(InstructionName name, Operand op0, Operand op1, Operand op2);

void
Instruction_Destroy(Instruction* instruction);

#endif

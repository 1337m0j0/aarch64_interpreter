
#ifndef SRC_PROGRAM_OPERAND_H
#define SRC_PROGRAM_OPERAND_H

#include "processor/registers.h"

// ---------------------------------------------------------------------------/
// Public types
// ---------------------------------------------------------------------------/

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

// ---------------------------------------------------------------------------/
// Public functions
// ---------------------------------------------------------------------------/

Operand
Operand_CreateRegister(RegisterName register_name);

Operand
Operand_CreateConstant(uint64_t constant);

#endif

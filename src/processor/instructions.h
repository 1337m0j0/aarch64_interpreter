#include "processor/registers.h"
#include <stdint.h>

#ifndef INSTRUCTION_SET_A64_H
#define INSTRUCTION_SET_A64_H

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
  OperandType op_type;
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

void
instr_a64_ADD(Registers* registers, Operand op_a, Operand op_b, Operand op_c);

void
instr_a64_MOV(Registers* registers, Operand op_a, Operand op_b);

#endif

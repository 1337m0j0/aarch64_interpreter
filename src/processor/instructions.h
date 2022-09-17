#include "processor/registers.h"
#include <stdint.h>

#ifndef INSTRUCTION_SET_A64_H
#define INSTRUCTION_SET_A64_H

typedef enum {
  MOV,
  ADD
} InstructionName;

typedef enum {
  REGISTER,
  CONSTANT
} OperandType;

typedef struct {
  OperandType op_type;
  union {
    RegisterName register_name;
    uint64_t constant;
  };
} Operand;

typedef struct {
  InstructionName instruction;
  Operand** operands;
} Instruction;

void
instr_a64_ADD(Registers* registers,
              RegisterName register_a,
              RegisterName register_b,
              RegisterName register_c);

void
instr_a64_MOV(Registers* registers,
              RegisterName register_a,
              uint64_t value);

#endif

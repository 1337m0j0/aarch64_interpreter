#ifndef PROCESSOR_ALU_INSTRUCTIONS_H
#define PROCESSOR_ALU_INSTRUCTIONS_H

#include <stdint.h>

#include "processor/registers.h"
#include "program/instruction.h"

// ------------------------------------------------------------------------------------------------/
// Public functions
// ------------------------------------------------------------------------------------------------/

void
instr_a64_ADD(Registers* registers, Operand op_a, Operand op_b, Operand op_c);

void
instr_a64_MOV(Registers* registers, Operand op_a, Operand op_b);

#endif

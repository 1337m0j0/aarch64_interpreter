#include <stdlib.h>

#include "processor/alu_instructions.h"

// ------------------------------------------------------------------------------------------------/
// Internal functions
// ------------------------------------------------------------------------------------------------/

static uint64_t
operand2value(Registers* registers, Operand op)
{
  if (op.type == CONSTANT) {
    return op.value.constant;
  } else {
    return Registers_Read(registers, op.value.register_name);
  }
}

// ------------------------------------------------------------------------------------------------/
// Public functions
// ------------------------------------------------------------------------------------------------/

void
instr_a64_ADD(Registers* registers, Operand op_a, Operand op_b, Operand op_c)
{
  Registers_Write(registers,
                  op_a.value.register_name,
                  operand2value(registers, op_b) +
                    operand2value(registers, op_c));
}

void
instr_a64_MOV(Registers* registers, Operand op_a, Operand op_b)
{
  Registers_Write(
    registers, op_a.value.register_name, operand2value(registers, op_b));
}

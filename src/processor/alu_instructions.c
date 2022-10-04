#include <stdlib.h>

#include "processor/alu_instructions.h"

// ------------------------------------------------------------------------------------------------/
// Internal functions
// ------------------------------------------------------------------------------------------------/

static uint64_t
operand2value(Registers* registers, Operand op)
{
  // TODO: Should the input values be truncated to 32 bits, for 32 bit
  // operations, before or after the operation has been performed?

  if (op.type == CONSTANT) {
    return op.value.constant;
  } else {
    return Registers_Read(registers, op.value.register_name);
  }
}

// ------------------------------------------------------------------------------------------------/
// Public functions
// ------------------------------------------------------------------------------------------------/

// TODO: add documentation from ARM spec
void
instr_a64_ADD(Registers* registers, Operand op_a, Operand op_b, Operand op_c)
{
  // TODO: setting processor flags after the instruction has been executed.

  // TODO: overflow handling for 32 bit and 64 bit operations

  Registers_Write(registers,
                  op_a.value.register_name,
                  operand2value(registers, op_b) +
                    operand2value(registers, op_c));
}

// TODO: add documentation from ARM spec
void
instr_a64_MOV(Registers* registers, Operand op_a, Operand op_b)
{
  Registers_Write(
    registers, op_a.value.register_name, operand2value(registers, op_b));
}

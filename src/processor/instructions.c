#include "processor/instructions.h"

void
instr_a64_ADD(Registers* registers,
              RegisterName register_a,
              RegisterName register_b,
              RegisterName register_c)
{
  Registers_Write(registers,
                 register_a,
                 Registers_Read(registers, register_b) +
                 Registers_Read(registers, register_c));
}

void
instr_a64_MOV(Registers* registers,
              RegisterName register_a,
              uint64_t value)
{
  Registers_Write(registers, register_a, value);
}

#include "registers.h"
#include <stdbool.h>
#include <stdlib.h>

// ------------------------------------------------------------------------------------------------/
// Internal functions
// ------------------------------------------------------------------------------------------------/

static bool
is_32bit_register(RegisterName register_name)
{
  switch (register_name) {
    case W0:
    case W1:
    case W2:
    case W3:
    case W4:
    case W5:
    case W6:
    case W7:
    case W8:
    case W9:
    case W10:
    case W11:
    case W12:
    case W13:
    case W14:
    case W15:
    case W16:
    case W17:
    case W18:
    case W19:
    case W20:
    case W21:
    case W22:
    case W23:
    case W24:
    case W25:
    case W26:
    case W27:
    case W28:
    case W29:
    case W30:
      return true;
    default:
      return false;
  }
}

static uint64_t
clear_high_32_bits(uint64_t value)
{
  uint64_t mask_high = -1;
  mask_high = mask_high >> 32;
  return value & mask_high;
}

static uint64_t*
get_register(Registers* registers, RegisterName register_name)
{
  switch (register_name) {
    case X0:
    case W0:
      return &registers->X0;
    case X1:
    case W1:
      return &registers->X1;
    case X2:
    case W2:
      return &registers->X2;
    case X3:
    case W3:
      return &registers->X3;
    case X4:
    case W4:
      return &registers->X4;
    case X5:
    case W5:
      return &registers->X5;
    case X6:
    case W6:
      return &registers->X6;
    case X7:
    case W7:
      return &registers->X7;
    case X8:
    case W8:
      return &registers->X8;
    case X9:
    case W9:
      return &registers->X9;
    case X10:
    case W10:
      return &registers->X10;
    case X11:
    case W11:
      return &registers->X11;
    case X12:
    case W12:
      return &registers->X12;
    case X13:
    case W13:
      return &registers->X13;
    case X14:
    case W14:
      return &registers->X14;
    case X15:
    case W15:
      return &registers->X15;
    case X16:
    case W16:
      return &registers->X16;
    case X17:
    case W17:
      return &registers->X17;
    case X18:
    case W18:
      return &registers->X18;
    case X19:
    case W19:
      return &registers->X19;
    case X20:
    case W20:
      return &registers->X20;
    case X21:
    case W21:
      return &registers->X21;
    case X22:
    case W22:
      return &registers->X22;
    case X23:
    case W23:
      return &registers->X23;
    case X24:
    case W24:
      return &registers->X24;
    case X25:
    case W25:
      return &registers->X25;
    case X26:
    case W26:
      return &registers->X26;
    case X27:
    case W27:
      return &registers->X27;
    case X28:
    case W28:
      return &registers->X28;
    case X29:
    case W29:
      return &registers->X29;
    case X30:
    case W30:
      return &registers->X30;
    default:
      break;
  }

  // This is the case for XZR and WZR.
  return (uint64_t*)NULL;
}

// ------------------------------------------------------------------------------------------------/
// Public functions
// ------------------------------------------------------------------------------------------------/

Registers*
Registers_Create(void)
{
  return (Registers*)calloc(1, sizeof(Registers));
}

void
Registers_Destroy(Registers* registers)
{
  free(registers);
}

uint64_t
Registers_Read(Registers* registers, RegisterName register_name)
{
  if (register_name == XZR || register_name == WZR) {
    return 0;
  }
  uint64_t result = *get_register(registers, register_name);
  if (is_32bit_register(register_name)) {
    result = clear_high_32_bits(result);
  }
  return result;
}

void
Registers_Write(Registers* registers,
                RegisterName register_name,
                uint64_t new_value)
{
  if (register_name == XZR || register_name == WZR) {
    return;
  }
  if (is_32bit_register(register_name)) {
    new_value = clear_high_32_bits(new_value);
  }
  *get_register(registers, register_name) = new_value;
}

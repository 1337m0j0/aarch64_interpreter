#include "program/operand.h"

Operand Operand_CreateRegister(RegisterName register_name) {
  Operand operand;
  operand.type = REGISTER;
  operand.value.register_name = register_name;
  return operand;
}

Operand Operand_CreateConstant(uint64_t constant) {
  Operand operand;
  operand.type = CONSTANT;
  operand.value.constant = constant;
  return operand;
}

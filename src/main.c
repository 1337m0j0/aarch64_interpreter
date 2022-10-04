#include <bits/stdint-uintn.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "processor/central_processing_unit.h"
#include "processor/registers.h"
#include "program/instruction.h"
#include "program/program.h"

bool
is_little_endian(void)
{
  // create type with two bytes and assign '1' to it.
  uint16_t u = 1;
  // test if '00000001' is stored in the first byte. if so, we
  // are on a little-endian system.
  return *(uint8_t*)&u == 1;
}

bool
is_system_sane(void)
{
  bool result = true;
  // 'long double' must be 128 bit
  if (sizeof(long double) != 128 / 8) {
    result = false;
  }
  // system must be little-endian
  if (!is_little_endian()) {
    result = false;
  }
  return result;
}

Operand*
mk_op_register(RegisterName register_name)
{
  Operand* op = (Operand*)malloc(sizeof(Operand));
  op->type = REGISTER;
  op->value.register_name = register_name;
  return op;
}

Operand*
mk_op_constant(uint64_t constant)
{
  Operand* op = (Operand*)malloc(sizeof(Operand));
  op->type = CONSTANT;
  op->value.constant = constant;
  return op;
}

void
test_long_double(void)
{
  long double reg128 = 0;
  uint8_t* reg128_ptr = (uint8_t*)&reg128;

  reg128_ptr[0] = 0;
  reg128_ptr[1] = 0;
  reg128_ptr[2] = 0;
  reg128_ptr[3] = 0;
  reg128_ptr[4] = 0;
  reg128_ptr[5] = 0;
  reg128_ptr[6] = 0;
  reg128_ptr[7] = 0;

  reg128_ptr[8] = 0x11;
  reg128_ptr[9] = 0x22;
  reg128_ptr[10] = 0x33;
  reg128_ptr[11] = 0x44;
  reg128_ptr[12] = 0xAA;
  reg128_ptr[13] = 0xBB;
  reg128_ptr[14] = 0xCC;
  reg128_ptr[15] = 0xDD;

  // check whether memory of register is contiguous

  printf("&reg128           = %p\n", (void*)&reg128);
  printf("reg128_ptr        = %p\n", (void*)reg128_ptr);
  printf("&reg128_ptr[0])   = %p\n", (void*)&reg128_ptr[0]);
  printf("&reg128_ptr[1])   = %p\n", (void*)&reg128_ptr[1]);
  printf("&reg128_ptr[2])   = %p\n", (void*)&reg128_ptr[2]);
  printf("&reg128_ptr[3])   = %p\n", (void*)&reg128_ptr[3]);
  printf("&reg128_ptr[4])   = %p\n", (void*)&reg128_ptr[4]);
  printf("&reg128_ptr[5])   = %p\n", (void*)&reg128_ptr[5]);
  printf("&reg128_ptr[6])   = %p\n", (void*)&reg128_ptr[6]);
  printf("&reg128_ptr[7])   = %p\n", (void*)&reg128_ptr[7]);
  printf("&reg128_ptr[8])   = %p\n", (void*)&reg128_ptr[8]);
  printf("&reg128_ptr[9])   = %p\n", (void*)&reg128_ptr[9]);
  printf("&reg128_ptr[10])  = %p\n", (void*)&reg128_ptr[10]);
  printf("&reg128_ptr[11])  = %p\n", (void*)&reg128_ptr[11]);
  printf("&reg128_ptr[12])  = %p\n", (void*)&reg128_ptr[12]);
  printf("&reg128_ptr[13])  = %p\n", (void*)&reg128_ptr[13]);
  printf("&reg128_ptr[14])  = %p\n", (void*)&reg128_ptr[14]);
  printf("&reg128_ptr[15])  = %p\n", (void*)&reg128_ptr[15]);

  // check how different integer types can be written to

  uint8_t u8 = 0;
  uint16_t u16 = 0;
  uint32_t u32 = 0;
  uint64_t u64 = 0;

  uint8_t* p = (uint8_t*)&u8;
  p[0] = reg128_ptr[15];
  printf("u8 = %x\n", u8);
  printf("exp: dd\n\n");

  p = (uint8_t*)&u16;
  p[1] = reg128_ptr[14];
  p[0] = reg128_ptr[15];
  printf("u16 = %x\n", u16);
  printf("exp:  ccdd\n\n");

  p = (uint8_t*)&u32;
  p[3] = reg128_ptr[12];
  p[2] = reg128_ptr[13];
  p[1] = reg128_ptr[14];
  p[0] = reg128_ptr[15];
  printf("u32 = %x\n", u32);
  printf("exp:  aabbccdd\n\n");

  p = (uint8_t*)&u64;
  p[7] = reg128_ptr[8];
  p[6] = reg128_ptr[9];
  p[5] = reg128_ptr[10];
  p[4] = reg128_ptr[11];
  p[3] = reg128_ptr[12];
  p[2] = reg128_ptr[13];
  p[1] = reg128_ptr[14];
  p[0] = reg128_ptr[15];
  printf("u64 = %lx\n", u64);
  printf("exp:  11223344aabbccdd\n\n");

  uint32_t out = 0;
  uint8_t* out_cast = (uint8_t*)&out;

  out_cast[0] = reg128_ptr[12];
  out_cast[1] = reg128_ptr[13];
  out_cast[2] = reg128_ptr[14];
  out_cast[3] = reg128_ptr[15];

  printf("&out_cast    = %p\n", (void*)out_cast);
  printf("&out_cast[0] = %p\n", (void*)&out_cast[0]);
  printf("&out_cast[1] = %p\n", (void*)&out_cast[1]);
  printf("&out_cast[2] = %p\n", (void*)&out_cast[2]);
  printf("&out_cast[3] = %p\n", (void*)&out_cast[3]);

  printf("out = %u\n", out);

  uint32_t out_test = -1;
  out_test = out_test >> 8;
  uint8_t* out_test_ptr = (uint8_t*)&out_test;
  printf("out_test = %u\n", out_test);
  printf("out_test_ptr[0] = %u\n", out_test_ptr[0]);
  printf("out_test_ptr[1] = %u\n", out_test_ptr[1]);
  printf("out_test_ptr[2] = %u\n", out_test_ptr[2]);
  printf("out_test_ptr[3] = %u\n", out_test_ptr[3]);

  uint16_t cast16 = 0;
  uint8_t* cast16_addr = (uint8_t*)&cast16;
  cast16_addr[0] = reg128_ptr[14];
  cast16_addr[1] = reg128_ptr[15];
  printf("cast16 = %d\n", cast16);

  uint16_t test16 = -1;
  printf("test16 = %d\n", test16);
}

int
main(void)
{
  int retval = 0;

  if (!is_system_sane()) {
    printf("ERROR: System sanity check failed.");
    retval = -1;
  }

  else {
    Instruction** program = (Instruction**)malloc(4 * sizeof(Instruction*));

    // MOV X1, 8
    program[0] = (Instruction*)malloc(sizeof(Instruction));
    program[0]->name = MOV;
    program[0]->operands = (Operand**)malloc(3 * sizeof(Operand*));
    program[0]->operands[0] = mk_op_register(X1);
    program[0]->operands[1] = mk_op_constant(8U);
    program[0]->operands[2] = (Operand*)NULL;

    // MOV X2, 24
    program[1] = (Instruction*)malloc(sizeof(Instruction));
    program[1]->name = MOV;
    program[1]->operands = (Operand**)malloc(3 * sizeof(Operand*));
    program[1]->operands[0] = mk_op_register(X2);
    program[1]->operands[1] = mk_op_constant(24U);
    program[1]->operands[2] = (Operand*)NULL;

    // ADD X0, X1, X2
    program[2] = (Instruction*)malloc(sizeof(Instruction));
    program[2]->name = ADD;
    program[2]->operands = (Operand**)malloc(4 * sizeof(Operand*));
    program[2]->operands[0] = mk_op_register(X0);
    program[2]->operands[1] = mk_op_register(X1);
    program[2]->operands[2] = mk_op_register(X2);
    program[2]->operands[3] = (Operand*)NULL;

    // end of program
    program[3] = (Instruction*)NULL;

    // setup
    CentralProcessingUnit* cpu = CentralProcessingUnit_Create();
    cpu->program_counter = program;

    // tests
    printf("X0 = %lu\n", Registers_Read(cpu->registers, X0));
    printf("X1 = %lu\n", Registers_Read(cpu->registers, X1));
    printf("X2 = %lu\n", Registers_Read(cpu->registers, X2));

    retval = CentralProcessingUnit_Run(cpu);

    printf("X0 = %lu\n", Registers_Read(cpu->registers, X0));
    printf("X1 = %lu\n", Registers_Read(cpu->registers, X1));
    printf("X2 = %lu\n", Registers_Read(cpu->registers, X2));

    // cleanup
    CentralProcessingUnit_Destroy(cpu);
    Program_Destroy(program);
  }

  test_long_double();

  return retval;
}

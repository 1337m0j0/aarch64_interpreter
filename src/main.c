#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "processor/instructions.h"
#include "processor/registers.h"
#include "processor/central_processing_unit.h"

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
  if (sizeof(long double) != 128/8) {
    result = false;
  }
  // system must be little-endian
  if (!is_little_endian()) {
    result = false;
  }
  return result;
}

int
main(int argc, char** argv)
{
  int retval = 0;

  if (!is_system_sane()) {
    printf("ERROR: System sanity check failed.");
    retval = -1;
  }

  else {
    Instruction** program = (Instruction**)malloc(4 * sizeof(Instruction*));

    // MOV X1, 8
    InstructionName instr_01_name = MOV;
    Operand instr_01_op_01 = { .op_type = REGISTER, .value.register_name = X1 };
    Operand instr_01_op_02 = { .op_type = CONSTANT, .value.constant = 8U };
    Operand** instr_01_operands = (Operand**)malloc(2 * sizeof(Operand*));
    instr_01_operands[0] = &instr_01_op_01;
    instr_01_operands[1] = &instr_01_op_02;
    Instruction instr_01 = { .name = instr_01_name, .operands = instr_01_operands };
    program[0] = &instr_01;

    // MOV X2, 24
    InstructionName instr_02_name = MOV;
    Operand instr_02_op_01 = { .op_type = REGISTER, .value.register_name = X2 };
    Operand instr_02_op_02 = { .op_type = CONSTANT, .value.constant = 24U };
    Operand** instr_02_operands = (Operand**)malloc(2 * sizeof(Operand*));
    instr_02_operands[0] = &instr_02_op_01;
    instr_02_operands[1] = &instr_02_op_02;
    Instruction instr_02 = { .name = instr_02_name, .operands = instr_02_operands };
    program[1] = &instr_02;

    // ADD X0, X1, X2
    InstructionName instr_03_name = ADD;
    Operand instr_03_op_01 = { .op_type = REGISTER, .value.register_name = X0 };
    Operand instr_03_op_02 = { .op_type = REGISTER, .value.register_name = X1 };
    Operand instr_03_op_03 = { .op_type = REGISTER, .value.register_name = X2 };
    Operand** instr_03_operands = (Operand**)malloc(3 * sizeof(Operand*));
    instr_03_operands[0] = &instr_03_op_01;
    instr_03_operands[1] = &instr_03_op_02;
    instr_03_operands[2] = &instr_03_op_03;
    Instruction instr_03 = { .name = instr_03_name, .operands = instr_03_operands };
    program[2] = &instr_03;

    program[3] = (Instruction*)NULL;

    // setup
    CentralProcessingUnit* cpu = CentralProcessingUnit_Create();
    cpu->program_counter = program;

    // tests
    printf("X0 = %llu\n", Registers_Read(cpu->registers, X0));
    printf("X1 = %llu\n", Registers_Read(cpu->registers, X1));
    printf("X2 = %llu\n", Registers_Read(cpu->registers, X2));

    retval = CentralProcessingUnit_Run(cpu);

    printf("X0 = %llu\n", Registers_Read(cpu->registers, X0));
    printf("X1 = %llu\n", Registers_Read(cpu->registers, X1));
    printf("X2 = %llu\n", Registers_Read(cpu->registers, X2));

    // cleanup
    CentralProcessingUnit_Destroy(cpu);

    // long double reg128 = 0;
    // uint8_t* reg128_ptr = (uint8_t*)&reg128;

    // reg128_ptr[0] = 0;
    // reg128_ptr[1] = 0;
    // reg128_ptr[2] = 0;
    // reg128_ptr[3] = 0;
    // reg128_ptr[4] = 0;
    // reg128_ptr[5] = 0;
    // reg128_ptr[6] = 0;
    // reg128_ptr[7] = 0;

    // reg128_ptr[8] = 0x11;
    // reg128_ptr[9] = 0x22;
    // reg128_ptr[10] = 0x33;
    // reg128_ptr[11] = 0x44;
    // reg128_ptr[12] = 0xAA;
    // reg128_ptr[13] = 0xBB;
    // reg128_ptr[14] = 0xCC;
    // reg128_ptr[15] = 0xDD;

    // printf("&reg128           = %p\n", (void*)&reg128);
    // printf("reg128_ptr        = %p\n", (void*)reg128_ptr);
    // printf("&reg128_ptr[0])   = %p\n", (void*)&reg128_ptr[0]);
    // printf("&reg128_ptr[1])   = %p\n", (void*)&reg128_ptr[1]);
    // printf("&reg128_ptr[2])   = %p\n", (void*)&reg128_ptr[2]);
    // printf("&reg128_ptr[3])   = %p\n", (void*)&reg128_ptr[3]);
    // printf("&reg128_ptr[4])   = %p\n", (void*)&reg128_ptr[4]);
    // printf("&reg128_ptr[5])   = %p\n", (void*)&reg128_ptr[5]);
    // printf("&reg128_ptr[6])   = %p\n", (void*)&reg128_ptr[6]);
    // printf("&reg128_ptr[7])   = %p\n", (void*)&reg128_ptr[7]);
    // printf("&reg128_ptr[8])   = %p\n", (void*)&reg128_ptr[8]);
    // printf("&reg128_ptr[9])   = %p\n", (void*)&reg128_ptr[9]);
    // printf("&reg128_ptr[10])  = %p\n", (void*)&reg128_ptr[10]);
    // printf("&reg128_ptr[11])  = %p\n", (void*)&reg128_ptr[11]);
    // printf("&reg128_ptr[12])  = %p\n", (void*)&reg128_ptr[12]);
    // printf("&reg128_ptr[13])  = %p\n", (void*)&reg128_ptr[13]);
    // printf("&reg128_ptr[14])  = %p\n", (void*)&reg128_ptr[14]);
    // printf("&reg128_ptr[15])  = %p\n", (void*)&reg128_ptr[15]);

    // uint8_t u8 = 0;
    // uint16_t u16 = 0;
    // uint32_t u32 = 0;
    // uint64_t u64 = 0;

    // uint8_t* p = (uint8_t*)&u8;
    // p[0] = reg128_ptr[15];
    // printf("u8 = %x\n", u8);
    // printf("exp: dd\n\n");

    // p = (uint8_t*)&u16;
    // p[1] = reg128_ptr[14];
    // p[0] = reg128_ptr[15];
    // printf("u16 = %x\n", u16);
    // printf("exp:  ccdd\n\n");

    // p = (uint8_t*)&u32;
    // p[3] = reg128_ptr[12];
    // p[2] = reg128_ptr[13];
    // p[1] = reg128_ptr[14];
    // p[0] = reg128_ptr[15];
    // printf("u32 = %x\n", u32);
    // printf("exp:  aabbccdd\n\n");

    // p = (uint8_t*)&u64;
    // p[7] = reg128_ptr[8];
    // p[6] = reg128_ptr[9];
    // p[5] = reg128_ptr[10];
    // p[4] = reg128_ptr[11];
    // p[3] = reg128_ptr[12];
    // p[2] = reg128_ptr[13];
    // p[1] = reg128_ptr[14];
    // p[0] = reg128_ptr[15];
    // printf("u64 = %llx\n", u64);
    // printf("exp:  11223344aabbccdd\n\n");

    // uint32_t out = 0;
    // uint8_t *out_cast = (uint8_t*)&out;

    // out_cast[0] = reg128_ptr[12];
    // out_cast[1] = reg128_ptr[13];
    // out_cast[2] = reg128_ptr[14];
    // out_cast[3] = reg128_ptr[15];

    // printf("&out_cast    = %p\n", (void*)out_cast);
    // printf("&out_cast[0] = %p\n", (void*)&out_cast[0]);
    // printf("&out_cast[1] = %p\n", (void*)&out_cast[1]);
    // printf("&out_cast[2] = %p\n", (void*)&out_cast[2]);
    // printf("&out_cast[3] = %p\n", (void*)&out_cast[3]);

    // printf("out = %u\n", out);

    // uint32_t out_test = -1;
    // out_test = out_test >> 8;
    // uint8_t *out_test_ptr = &out_test;
    // printf("out_test = %u\n", out_test);
    // printf("out_test_ptr[0] = %u\n", out_test_ptr[0]);
    // printf("out_test_ptr[1] = %u\n", out_test_ptr[1]);
    // printf("out_test_ptr[2] = %u\n", out_test_ptr[2]);
    // printf("out_test_ptr[3] = %u\n", out_test_ptr[3]);

    // uint16_t cast16 = 0;
    // uint8_t* cast16_addr = &cast16;
    // cast16_addr[0] = reg128[14];
    // cast16_addr[1] = reg128[15];
    // printf("cast16 = %d\n", cast16);

    // uint16_t test16 = -1;
    // printf("test16 = %d\n", test16);
  }

  return retval;
}

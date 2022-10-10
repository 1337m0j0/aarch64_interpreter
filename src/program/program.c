#include <stdlib.h>

#include "program/instruction.h"
#include "program/program.h"

// ------------------------------------------------------------------------------------------------/
// Private definitions
// ------------------------------------------------------------------------------------------------/

#define INSTRUCTIONS_CAPACITY_INCREMENTS 100U
#define INSTRUCTIONS_CAPACITY_MAX 65535U

// ------------------------------------------------------------------------------------------------/
// Private types
// ------------------------------------------------------------------------------------------------/

struct Program
{
  Instruction** instructions;
  unsigned short size;
  unsigned short capacity;
};

// ------------------------------------------------------------------------------------------------/
// Public functions
// ------------------------------------------------------------------------------------------------/

Program*
Program_Create(void)
{
  Program* program = (Program*)malloc(sizeof(Program));
  program->size = 0U;
  program->capacity = INSTRUCTIONS_CAPACITY_INCREMENTS;
  program->instructions =
    (Instruction**)calloc(program->capacity + 1, sizeof(Instruction*));

  return program;
}

int
Program_AppendInstruction(Program* program,
                          char* label,
                          Instruction* instruction)
{
  // TODO: store label association to instruction

  if (program->size == program->capacity) {
    if (program->capacity == INSTRUCTIONS_CAPACITY_MAX) {
      // error: no more space can be allocated
      return -1;
    }
    // create larger array
    unsigned int new_capacity =
      program->capacity + INSTRUCTIONS_CAPACITY_INCREMENTS;
    program->capacity = new_capacity < INSTRUCTIONS_CAPACITY_MAX
                          ? new_capacity
                          : INSTRUCTIONS_CAPACITY_MAX;
    Instruction** new_instructions =
      (Instruction**)calloc(program->capacity + 1, sizeof(Instruction*));
    // copy instructions to new array
    for (int i = 0; i < program->size; i++) {
      new_instructions[i] = program->instructions[i];
    }
    // replace old array with new one
    free(program->instructions);
    program->instructions = new_instructions;
  }

  program->instructions[program->size] = instruction;
  program->size++;

  return 0;
}

Instruction**
Program_GetInitialInstruction(Program* program)
{
  return program->instructions;
}

void
Program_Destroy(Program* program)
{
  for (int i = 0; i < program->size; i++) {
    free(program->instructions[i]);
  }
  free(program);
}

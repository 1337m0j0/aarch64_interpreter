#include <stdlib.h>
#include <string.h>

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
  char* start_label;
};

// ------------------------------------------------------------------------------------------------/
// Private functions
// ------------------------------------------------------------------------------------------------/

Instruction**
get_instruction_at_label(Program* program, char* label)
{
  if (label == (char*)NULL) {
    return (Instruction**)NULL;
  }
  Instruction** current_instruction = program->instructions;
  while (*current_instruction != (Instruction*)NULL) {
    if ((*current_instruction)->label != (char*)NULL &&
        strcmp(label, (*current_instruction)->label) == 0) {
      break;
    }
    current_instruction++;
  }
  return current_instruction;
}

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
  program->start_label = (char*)NULL;
  return program;
}

void
Program_AddStartLabel(Program* program, char* label)
{
  program->start_label = (char*)calloc(strlen(label) + 1, sizeof(char));
  char* res = strncpy(program->start_label, label, strlen(label));
  if (res != program->start_label) {
    // TODO: PANIC
  }
}

int
Program_AppendInstruction(Program* program, Instruction* instruction)
{
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
  return get_instruction_at_label(program, program->start_label);
}

void
Program_Destroy(Program* program)
{
  if (program->start_label != (char*)NULL) {
    free(program->start_label);
  }
  for (int i = 0; i < program->size; i++) {
    free(program->instructions[i]);
  }
  free(program);
}

#include <stdbool.h>
#include <stdlib.h>

#include "processor/alu_instructions.h"
#include "processor/central_processing_unit.h"
#include "processor/registers.h"
#include "program/instruction.h"

// ------------------------------------------------------------------------------------------------/
// Private types
// ------------------------------------------------------------------------------------------------/

struct CentralProcessingUnit
{
  Registers* registers;
  uint64_t status_register;
  Instruction** program_counter;
};

// ------------------------------------------------------------------------------------------------/
// Public functions
// ------------------------------------------------------------------------------------------------/

CentralProcessingUnit*
CentralProcessingUnit_Create(void)
{
  CentralProcessingUnit* cpu =
    (CentralProcessingUnit*)malloc(sizeof(CentralProcessingUnit));
  cpu->registers = Registers_Create();
  return cpu;
}

void
CentralProcessingUnit_SetProgramCounter(CentralProcessingUnit* cpu,
                                        Instruction** program_counter)
{
  cpu->program_counter = program_counter;
}

uint64_t
CentralProcessingUnit_ReadRegister(CentralProcessingUnit* cpu,
                                   RegisterName register_name)
{
  return Registers_Read(cpu->registers, register_name);
}

int
CentralProcessingUnit_Run(CentralProcessingUnit* cpu)
{
  while (true) {
    Instruction* current_instruction = *(cpu->program_counter);
    if (current_instruction == (Instruction*)NULL) {
      break;
    }
    cpu->program_counter++;

    switch (current_instruction->name) {
      case MOV:
        instr_a64_MOV(cpu->registers,
                      (*current_instruction).operands[0],
                      (*current_instruction).operands[1]);
        break;
      case ADD:
        instr_a64_ADD(cpu->registers,
                      (*current_instruction).operands[0],
                      (*current_instruction).operands[1],
                      (*current_instruction).operands[2]);
        break;
      default:
        break;
    }
  };

  return 0;
}

void
CentralProcessingUnit_Destroy(CentralProcessingUnit* cpu)
{
  Registers_Destroy(cpu->registers);
  free(cpu);
}

#include "central_processing_unit.h"
#include <stdlib.h>
#include <stdio.h>

CentralProcessingUnit*
CentralProcessingUnit_Create(void)
{
    CentralProcessingUnit* cpu = (CentralProcessingUnit*)malloc(sizeof(CentralProcessingUnit));
    cpu->registers = Registers_Create();
    return cpu;
}

void
CentralProcessingUnit_Destroy(CentralProcessingUnit* cpu)
{
  Registers_Destroy(cpu->registers);
  free(cpu);
}

int
CentralProcessingUnit_Run(CentralProcessingUnit* cpu)
{
    while (*cpu->program_counter) {
      // FETCH
      // * fetches the instruction at the program counter
      Instruction* current_instruction = *cpu->program_counter;
      // * increments the program counter to point to the next instruction
      cpu->program_counter++;

      // DECODE & EXECUTE
      // * identify the instruction to be executed and its arguments
      // * execute the instruction
      switch (current_instruction->instruction) {
        case MOV:
          instr_a64_MOV(cpu->registers,
                        current_instruction->operands[0]->register_name,
                        current_instruction->operands[1]->constant);
          break;
        case ADD:
          instr_a64_ADD(cpu->registers,
                        current_instruction->operands[0]->register_name,
                        current_instruction->operands[1]->register_name,
                        current_instruction->operands[2]->register_name);
          break;
        default:
          break;
      }
    }
  return 0;
}

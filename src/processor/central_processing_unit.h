#ifndef SRC_PROCESSOR_PROCESSOR_H
#define SRC_PROCESSOR_PROCESSOR_H

#include <stdint.h>

#include "processor/registers.h"
#include "program/instruction.h"

// ------------------------------------------------------------------------------------------------/
// Public types
// ------------------------------------------------------------------------------------------------/

typedef struct
{
  Registers* registers;
  uint64_t status_register;
  Instruction** program_counter;
} CentralProcessingUnit;

// ------------------------------------------------------------------------------------------------/
// Public functions
// ------------------------------------------------------------------------------------------------/

CentralProcessingUnit*
CentralProcessingUnit_Create(void);

void
CentralProcessingUnit_Destroy(CentralProcessingUnit* cpu);

int
CentralProcessingUnit_Run(CentralProcessingUnit* cpu);

#endif

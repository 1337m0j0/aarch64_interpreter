#ifndef SRC_PROCESSOR_PROCESSOR_H
#define SRC_PROCESSOR_PROCESSOR_H

#include "processor/registers.h"
#include "program/instruction.h"
#include <bits/stdint-uintn.h>

// ---------------------------------------------------------------------------/
// Public types
// ---------------------------------------------------------------------------/

typedef struct CentralProcessingUnit CentralProcessingUnit;

// ---------------------------------------------------------------------------/
// Public functions
// ---------------------------------------------------------------------------/

CentralProcessingUnit*
CentralProcessingUnit_Create(void);

void
CentralProcessingUnit_SetProgramCounter(CentralProcessingUnit* cpu,
                                        Instruction** program_counter);

uint64_t
CentralProcessingUnit_ReadRegister(CentralProcessingUnit* cpu,
                                   RegisterName register_name);

void
CentralProcessingUnit_Destroy(CentralProcessingUnit* cpu);

int
CentralProcessingUnit_Run(CentralProcessingUnit* cpu);

#endif

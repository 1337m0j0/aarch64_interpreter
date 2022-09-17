#ifndef SRC_PROCESSOR_PROCESSOR_H
#define SRC_PROCESSOR_PROCESSOR_H

#include <stdint.h>

#include "processor/registers.h"
#include "processor/instructions.h"

typedef struct {

    // registers
    Registers* registers;

    // status register
    uint64_t status_register;

    // program counter
    Instruction** program_counter;

    // memory interface

} CentralProcessingUnit;

CentralProcessingUnit*
CentralProcessingUnit_Create(void);

void
CentralProcessingUnit_Destroy(CentralProcessingUnit* cpu);

int
CentralProcessingUnit_Run(CentralProcessingUnit* cpu);

#endif

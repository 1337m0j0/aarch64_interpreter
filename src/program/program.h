#ifndef SRC_PROGRAM_PROGRAM_H
#define SRC_PROGRAM_PROGRAM_H

#include "program/instruction.h"

// ---------------------------------------------------------------------------/
// Public types
// ---------------------------------------------------------------------------/

typedef struct Program Program;

// ---------------------------------------------------------------------------/
// Public functions
// ---------------------------------------------------------------------------/

Program*
Program_Create(void);

// Note: The program takes ownership of the instruction.
int
Program_AppendInstruction(Program* program,
                          char* label,
                          Instruction* instruction);

Instruction**
Program_GetInitialInstruction(Program* program);

void
Program_Destroy(Program* program);

#endif

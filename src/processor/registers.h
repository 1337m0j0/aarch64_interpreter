#ifndef SRC_PROCESSOR_REGISTERS_H
#define SRC_PROCESSOR_REGISTERS_H

#include <stdint.h>

// ------------------------------------------------------------------------------------------------/
// Public types
// ------------------------------------------------------------------------------------------------/

typedef struct
{
  // general-purpose registers (64 bit)
  uint64_t X0;
  uint64_t X1;
  uint64_t X2;
  uint64_t X3;
  uint64_t X4;
  uint64_t X5;
  uint64_t X6;
  uint64_t X7;
  uint64_t X8;
  uint64_t X9;
  uint64_t X10;
  uint64_t X11;
  uint64_t X12;
  uint64_t X13;
  uint64_t X14;
  uint64_t X15;
  uint64_t X16;
  uint64_t X17;
  uint64_t X18;
  uint64_t X19;
  uint64_t X20;
  uint64_t X21;
  uint64_t X22;
  uint64_t X23;
  uint64_t X24;
  uint64_t X25;
  uint64_t X26;
  uint64_t X27;
  uint64_t X28;
  uint64_t X29;
  uint64_t X30;

  // vector/float registers (128 bit)
  long double Q0;
  long double Q1;
  long double Q2;
  long double Q3;
  long double Q4;
  long double Q5;
  long double Q6;
  long double Q7;
  long double Q8;
  long double Q9;
  long double Q10;
  long double Q11;
  long double Q12;
  long double Q13;
  long double Q14;
  long double Q15;
  long double Q16;
  long double Q17;
  long double Q18;
  long double Q19;
  long double Q20;
  long double Q21;
  long double Q22;
  long double Q23;
  long double Q24;
  long double Q25;
  long double Q26;
  long double Q27;
  long double Q28;
  long double Q29;
  long double Q30;
  long double Q31;
} Registers;

typedef enum
{
  // general purpose registers (64 bit)
  X0,
  X1,
  X2,
  X3,
  X4,
  X5,
  X6,
  X7,
  X8,
  X9,
  X10,
  X11,
  X12,
  X13,
  X14,
  X15,
  X16,
  X17,
  X18,
  X19,
  X20,
  X21,
  X22,
  X23,
  X24,
  X25,
  X26,
  X27,
  X28,
  X29,
  X30,
  // 32 bit access to the Xd registers
  W0,
  W1,
  W2,
  W3,
  W4,
  W5,
  W6,
  W7,
  W8,
  W9,
  W10,
  W11,
  W12,
  W13,
  W14,
  W15,
  W16,
  W17,
  W18,
  W19,
  W20,
  W21,
  W22,
  W23,
  W24,
  W25,
  W26,
  W27,
  W28,
  W29,
  W30,
  // vector/float registers (128 bit)
  Q0,
  Q1,
  Q2,
  Q3,
  Q4,
  Q5,
  Q6,
  Q7,
  Q8,
  Q9,
  Q10,
  Q11,
  Q12,
  Q13,
  Q14,
  Q15,
  Q16,
  Q17,
  Q18,
  Q19,
  Q20,
  Q21,
  Q22,
  Q23,
  Q24,
  Q25,
  Q26,
  Q27,
  Q28,
  Q29,
  Q30,
  Q31,
  // 8 bit access to Qx registers
  B0,
  B1,
  B2,
  B3,
  B4,
  B5,
  B6,
  B7,
  B8,
  B9,
  B10,
  B11,
  B12,
  B13,
  B14,
  B15,
  B16,
  B17,
  B18,
  B19,
  B20,
  B21,
  B22,
  B23,
  B24,
  B25,
  B26,
  B27,
  B28,
  B29,
  B30,
  B31,
  // 16 bit access to Qx registers
  H0,
  H1,
  H2,
  H3,
  H4,
  H5,
  H6,
  H7,
  H8,
  H9,
  H10,
  H11,
  H12,
  H13,
  H14,
  H15,
  H16,
  H17,
  H18,
  H19,
  H20,
  H21,
  H22,
  H23,
  H24,
  H25,
  H26,
  H27,
  H28,
  H29,
  H30,
  H31,
  // 32 bit access to Qx registers
  S0,
  S1,
  S2,
  S3,
  S4,
  S5,
  S6,
  S7,
  S8,
  S9,
  S10,
  S11,
  S12,
  S13,
  S14,
  S15,
  S16,
  S17,
  S18,
  S19,
  S20,
  S21,
  S22,
  S23,
  S24,
  S25,
  S26,
  S27,
  S28,
  S29,
  S30,
  S31,
  // 64 bit access to Qx registers
  D0,
  D1,
  D2,
  D3,
  D4,
  D5,
  D6,
  D7,
  D8,
  D9,
  D10,
  D11,
  D12,
  D13,
  D14,
  D15,
  D16,
  D17,
  D18,
  D19,
  D20,
  D21,
  D22,
  D23,
  D24,
  D25,
  D26,
  D27,
  D28,
  D29,
  D30,
  D31,
  // zero registers
  XZR,
  WZR
} RegisterName;

// ------------------------------------------------------------------------------------------------/
// Public functions
// ------------------------------------------------------------------------------------------------/

Registers*
Registers_Create(void);

void
Registers_Destroy(Registers* registers);

uint64_t
Registers_Read(Registers* registers, RegisterName register_name);

void
Registers_Write(Registers* registers,
                RegisterName register_name,
                uint64_t new_value);

#endif

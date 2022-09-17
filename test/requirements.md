
# Requirements

## Registers

*General Purpose Registers*

* 31 general purpose 64 bit registers named X0 to X30 are provided.
* For every 64 bit register a Wx alias is available to access the 32 low-order bits.
* When a W register is written, the top 32 bits of the underlying 64 bit register are zeroed.

* 32 128 bit registers are provided for vector and floating point operations, named Q0 to Q31.
* Every 128 bit register Qx can be used as an 8 bit register by using the alias Bx.
* Every 128 bit register Qx can be used as an 16 bit register by using the alias Hx.
* Every 128 bit register Qx can be used as an 32 bit register by using the alias Sx.
* Every 128 bit register Qx can be used as an 64 bit register by using the alias Dx.
* When a Q register is written using a B alias, the top 120 bits are zeroed.
* When a Q register is written using a H alias, the top 112 bits are zeroed.
* When a Q register is written using a S alias, the top 98 bits are zeroed.
* When a Q register is written using a H alias, the top 64 bits are zeroed.

// TODO: vector aliases for Q registers.

*Special Purpose Registers*

* The 64 bit zero register named XZR is provided which always reads 0.
* The XZR register ignores writes.
* A 32 bit alias to XZR is provided, named WZR.

* A 64 bit stack pointer register named SP is provided.
// TODO: limitations on using SP in instructions.

* The alias LR is provided for the register X30, representing the link register.
// TODO: exception registers ELR_ELx.

* A 64 bit program counter register PC is provided.
// TODO: how PC is set and used, what instructions can manipulate it.

*System Registers*

// TODO: What system registers there are, how they can be accessed under what execution privilege level.


## Instructions

// TODO: Using "ADR Xd, ." to read the program counter into an X register.

// TODO: Using MRS and MSR to work with system registers.
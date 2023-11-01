#ifndef CTRL_H
#define CTRL_H

#include "CPU.h"


// no need to write a controller for branch, jalr, s/lw since there is only one
// option
namespace CTRL {
    // r-type
    bool RTYPE(CPU *cpu, instruction *instr);

    // i-type
    bool ITYPE(CPU *cpu, instruction *instr);

    // b-type
    bool BLT(CPU *cpu, instruction *instr);

    // j-type
    bool JALR(CPU *cpu, instruction *instr);

    // store word
    bool SW(CPU *cpu, instruction *instr);

    // load word
    bool LW(CPU *cpu, instruction *instr);
}

#endif

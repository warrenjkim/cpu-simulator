#ifndef ALU_H
#define ALU_H

#include <bitset>
#include "util.h"


namespace ALU {
    // r-type
    std::bitset<32> ADD(const std::bitset<32> &rs1, const std::bitset<32> &rs2);
    std::bitset<32> SUB(const std::bitset<32> &rs1, const std::bitset<32> &rs2);
    std::bitset<32> XOR(const std::bitset<32> &rs1, const std::bitset<32> &rs2);
    std::bitset<32> SRA(const std::bitset<32> &rs1, const std::bitset<32> &rs2);
    
    // i-type
    std::bitset<32> ADDI(const std::bitset<32> &rs1, const std::bitset<32> &imm);
    std::bitset<32> ANDI(const std::bitset<32> &rs1, const std::bitset<32> &imm);
}

#endif

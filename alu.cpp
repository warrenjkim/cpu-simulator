#include "alu.h"

namespace ALU {
    std::bitset<32> ADD(const std::bitset<32> &rs1, const std::bitset<32> &rs2) {
        return std::bitset<32>(util::to_decimal(rs1) + util::to_decimal(rs2));
    }


    std::bitset<32> SUB(const std::bitset<32> &rs1, const std::bitset<32> &rs2) {
        return std::bitset<32>(util::to_decimal(rs1) - util::to_decimal(rs2));
    }


    std::bitset<32> XOR(const std::bitset<32> &rs1, const std::bitset<32> &rs2) {
        return rs1 ^ rs2;
    }


    std::bitset<32> SRA(const std::bitset<32> &rs1, const std::bitset<32> &rs2) {
        return std::bitset<32>(util::to_decimal(rs1) >> util::to_decimal(rs2));
    }


    std::bitset<32> ADDI(const std::bitset<32> &rs1, const std::bitset<32> &imm) {
        return ADD(rs1, imm);
    }


    std::bitset<32> ANDI(const std::bitset<32> &rs1, const std::bitset<32> &imm) {
        return rs1 & imm;
    }
}

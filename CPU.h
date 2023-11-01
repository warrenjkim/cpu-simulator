#ifndef CPU_H
#define CPU_H

#include <bitset>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "macros.h"
#include "enums.h"


class instruction {
    public:
        std::bitset<32> instr;              // instruction
        instruction(std::bitset<32> fetch); // constructor

    public:
        // metadata
        std::bitset<REGISTER_WIDTH> rs1;
        std::bitset<REGISTER_WIDTH> rs2;
        std::bitset<REGISTER_WIDTH> rd;
        std::bitset<OPCODE_WIDTH> opcode;
        std::bitset<FUNCT3_WIDTH> funct3;
        std::bitset<FUNCT7_WIDTH> funct7;
        std::bitset<32> immediate;

        Operation operation;
        OperationType operation_type;
};





class CPU {
    private:
        int dmemory[4096]; // data memory byte addressable in little endian fashion;
        unsigned long PC;  // pc
        std::bitset<32> register_file[32];

    public:
        CPU();
        unsigned long readPC();
        void addPC(unsigned long offset);
        void setPC(unsigned long offset);

        std::bitset<32> Fetch(std::bitset<8> *instmem);

        std::bitset<32> get_register(const size_t &reg_num);
        void set_register(const size_t &reg_num, const std::bitset<32> &result);

        std::bitset<32> get_dmemory(const size_t &addr);
        void set_dmemory(const size_t &addr, const std::bitset<32> &data);
};

#endif

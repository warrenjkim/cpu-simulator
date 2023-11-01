#include "CPU.h"
#include "util.h"

instruction::instruction(std::bitset<32> fetch) {
    instr = fetch;
}





CPU::CPU() {
    PC = 0; 
    for (int i = 0; i < 4096; i++)
        dmemory[i] = (0);
}


std::bitset<32> CPU::Fetch(std::bitset<8> *instmem) {
    std::bitset<32> instr = ((((instmem[PC + 3].to_ulong()) << 24)) +
            ((instmem[PC + 2].to_ulong()) << 16) +
            ((instmem[PC + 1].to_ulong()) << 8) +
            (instmem[PC + 0].to_ulong())); // get 32 bit instruction
    PC += 4;                                           // increment PC
    return instr;
}


unsigned long CPU::readPC() { return this->PC; }


void CPU::addPC(unsigned long offset) { 
    this->PC += offset; 
}


void CPU::setPC(unsigned long offset) { 
    this->PC = offset; 
}


std::bitset<32> CPU::get_register(const size_t &reg_num) {
    return this->register_file[reg_num];
}


void CPU::set_register(const size_t &reg_num, const std::bitset<32> &result) {
    this->register_file[reg_num] = result;
}


std::bitset<32> CPU::get_dmemory(const size_t &addr) {
    return std::bitset<32>(this->dmemory[addr]);
}


void CPU::set_dmemory(const size_t &addr, const std::bitset<32> &data) {
    this->dmemory[addr] = util::to_decimal(data);
}


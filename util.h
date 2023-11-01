#ifndef UTIL_H
#define UTIL_H

#include <bitset>
#include <string>

#include "CPU.h"
#include "controller.h"
#include "enums.h"


namespace util {
    template <size_t FromSize, size_t ToSize>
        std::bitset<ToSize> sign_extend(const std::bitset<FromSize>& original) {
            std::bitset<ToSize> extended;

            for (size_t i = 0; i < FromSize; i++)
                extended[i] = original[i];

            bool sign = original[FromSize - 1];
            for (size_t i = FromSize; i < ToSize; i++)
                extended[i] = sign;

            return extended;
        }

    std::bitset<32> parse_immediate(instruction *instr);

    Operation get_instruction(instruction *instr);
    OperationType get_instruction_type(instruction *instr);
    
    bool execute_instruction(CPU *cpu, instruction *instr);

    long int to_decimal(const std::bitset<32> &bitset);

    bool decode(instruction *instr);
}

#endif

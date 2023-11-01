#include "util.h"

namespace util {
    bool execute_instruction(CPU *cpu, instruction *instr) {
        switch(instr->operation_type) {
            case RTYPE:
                return CTRL::RTYPE(cpu, instr);
            case ITYPE:
                return CTRL::ITYPE(cpu, instr);
            case JTYPE:
                return CTRL::JALR(cpu, instr);
            case BTYPE:
                return CTRL::BLT(cpu, instr);
            case LOAD_TYPE:
                return CTRL::LW(cpu, instr);
            case STORE_TYPE:
                return CTRL::SW(cpu, instr);
            case NONE:
                return true;
            default:
                return false;
        }

        return false;
    }


    OperationType get_instruction_type(instruction *instr) {
        if (instr->opcode == R_TYPE_OPCODE)
            return RTYPE;
        else if (instr->opcode == I_TYPE_OPCODE)
            return ITYPE;
        else if (instr->opcode == B_TYPE_OPCODE)
            return BTYPE;
        else if (instr->opcode == J_TYPE_OPCODE)
            return JTYPE;
        else if (instr->opcode == LOAD_OPCODE)
            return LOAD_TYPE;
        else if (instr->opcode == STORE_OPCODE)
            return STORE_TYPE;
        return NONE;
    }


    Operation get_instruction(instruction *instr) {
        switch (instr->operation_type) {
            case RTYPE:
                if (instr->funct3 == ADD_FUNCT3 && instr->funct7 == ADD_FUNCT7)
                    return ADD;
                else if (instr->funct3 == SUB_FUNCT3 && instr->funct7 == SUB_FUNCT7)
                    return SUB;
                else if (instr->funct3 == XOR_FUNCT3 && instr->funct7 == XOR_FUNCT7)
                    return XOR;
                else if (instr->funct3 == SRA_FUNCT3 && instr->funct7 == SRA_FUNCT7)
                    return SRA;
            case ITYPE:
                if (instr->funct3 == ADDI_FUNCT3)
                    return ADDI;
                else if (instr->funct3 == ANDI_FUNCT3)
                    return ANDI;
            case BTYPE:
                if (instr->funct3 == BLT_FUNCT3)
                    return BLT;
            case JTYPE:
                return JALR;
            case LOAD_TYPE:
                if (instr->funct3 == LW_FUNCT3)
                    return LW;
            case STORE_TYPE:
                if (instr->funct3 == SW_FUNCT3)
                    return SW;
            default:
                return DONE;
        }

        return DONE;
    }


    std::bitset<32> parse_immediate(instruction *instr) {
        if (
                instr->operation_type == ITYPE || 
                instr->operation_type == JTYPE || 
                instr->operation_type == LOAD_TYPE
           ) {
            std::bitset<I_TYPE_IMM_WIDTH> immediate(instr->instr.to_string().substr(0, 12));
            return sign_extend<I_TYPE_IMM_WIDTH, 32>(immediate);
        }
        else if (instr->operation_type == STORE_TYPE) {
            std::string instr_string = instr->instr.to_string();
            std::string imm_string = instr_string.substr(0, 7) + instr_string.substr(20, 5);
            std::bitset<I_TYPE_IMM_WIDTH> immediate(imm_string);
            return sign_extend<I_TYPE_IMM_WIDTH, 32>(immediate);
        }
        else if (instr->operation_type == BTYPE) {
            std::string instr_string = instr->instr.to_string();
            std::string imm_string = 
                instr_string.substr(0, 1) +
                instr_string.substr(24, 1) +
                instr_string.substr(1, 5) +
                instr_string.substr(20, 4) +
                "0";
            std::bitset<B_TYPE_IMM_WIDTH> immediate(imm_string);

            return sign_extend<B_TYPE_IMM_WIDTH, 32>(immediate);
        }

        return std::bitset<32>(0);
    }


    long int to_decimal(const std::bitset<32> &bitset) {
        if (bitset.test(31))
            return -((~bitset).to_ulong() + 1);
        else
            return static_cast<long>(bitset.to_ulong());
    }


    bool decode(instruction *curr) {
        curr->funct7 = std::bitset<FUNCT7_WIDTH>(curr->instr.to_string().substr(0, 7));
        curr->rs2    = std::bitset<REGISTER_WIDTH>(curr->instr.to_string().substr(7, 5));
        curr->rs1    = std::bitset<REGISTER_WIDTH>(curr->instr.to_string().substr(12, 5));
        curr->funct3 = std::bitset<FUNCT3_WIDTH>(curr->instr.to_string().substr(17, 3));
        curr->rd     = std::bitset<REGISTER_WIDTH>(curr->instr.to_string().substr(20, 5));
        curr->opcode = std::bitset<OPCODE_WIDTH>(curr->instr.to_string().substr(25, 7));

        curr->operation_type = get_instruction_type(curr);
        curr->operation      = get_instruction(curr);

        return true;
    }
}

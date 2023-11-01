#ifndef MACROS_H
#define MACROS_H

#define REGISTER_WIDTH 5

#define FUNCT3_WIDTH 3
#define FUNCT7_WIDTH 7

#define OPCODE_WIDTH 7

#define I_TYPE_IMM_WIDTH 12
#define B_TYPE_IMM_WIDTH 12
#define J_TYPE_IMM_WIDTH 20


#define R_TYPE_OPCODE 0b0110011
#define I_TYPE_OPCODE 0b0010011
#define B_TYPE_OPCODE 0b1100011
#define J_TYPE_OPCODE 0b1100111
#define LOAD_OPCODE   0b0000011
#define STORE_OPCODE  0b0100011

#define ADD_FUNCT3 0b000
#define ADD_FUNCT7 0b0000000

#define SUB_FUNCT3 0b000
#define SUB_FUNCT7 0b0100000

#define XOR_FUNCT3 0b100
#define XOR_FUNCT7 0b0000000

#define SRA_FUNCT3 0b101
#define SRA_FUNCT7 0b0100000

#define ADDI_FUNCT3 0b000
#define ANDI_FUNCT3 0b111

#define BLT_FUNCT3 0b100

#define LW_FUNCT3 0b010

#define SW_FUNCT3 0b010

#endif

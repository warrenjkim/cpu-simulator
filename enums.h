#ifndef ENUMS_H
#define ENUMS_H

enum OperationType {
    RTYPE,
    ITYPE,
    BTYPE,
    JTYPE,
    LOAD_TYPE,
    STORE_TYPE,
    NONE
};


enum Operation {
    ADD,
    SUB,
    XOR,
    SRA,
    ADDI,
    ANDI,
    BLT,
    JALR,
    LW,
    SW,
    DONE
};

#endif

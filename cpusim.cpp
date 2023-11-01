#include "CPU.h"
#include "util.h"

#include <bitset>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

int main(int argc, char *argv[]) {
    std::bitset<8> instruction_memory[4096];

    if (argc < 2) {
        std::cout << "No file name entered. Exiting...";
        return -1;
    }

    std::ifstream infile(argv[1]); // open the file
    if (!(infile.is_open() && infile.good())) {
        std::cout << "error opening file" << std::endl;
        return 0;
    }


    std::string line;
    int i = 0;
    while (infile) {
        infile >> line;
        std::stringstream line2(line);
        int x;
        line2 >> x;
        instruction_memory[i] = std::bitset<8>(x);
        i++;
    }
    int maxPC = i;

    CPU myCPU; 
    std::bitset<32> curr;
    instruction instr = instruction(curr);
    bool done = true;

    while (done) {
        // fetch
        curr = myCPU.Fetch(instruction_memory); // fetching the instruction
        instr = instruction(curr);

        // decode
        done = util::decode(&instr);
        if (done == false) // break from loop so stats are not mistakenly updated
            break;

        // execute
        util::execute_instruction(&myCPU, &instr);

        // sanity check
        if (myCPU.readPC() > maxPC)
            break;
    }

    std::cout << "(" << util::to_decimal(myCPU.get_register(10))
        << "," << util::to_decimal(myCPU.get_register(11)) << ")" << std::endl;

    return 0;
}

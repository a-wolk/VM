#include "VMOpParser.h"

#include <iostream>

//OPcode: 
// - size 16/32/64 bit (depends on VM config)
// - args size: TODO: let config specify it
//      - r8/16/32/64 - 8/16/32/64
//      - mem8/16/32/64 - ... 
//      - im8/16/32/64 - ...
// - example of op config
//      inst opcode mnemonic type1#name1,type2#name2... basic_inst1;basic_inst2;...
//
//      inst 0x1f add r32#r1,r32#r2 r1=r1+r2
//      adds r1 to r2 and save it in r1 
//      (r32 - means register of size 32, mem  memory address)
//
//      inst 0x1e add r32#r n=n+r
//      (add content of register with code r to register/(mem address) called 'n')    
//
//      register rax 0x1 32
//      (declare register with name 'rax', code 0x1 and 32bit size)
//
//      mem x 0x1000
//      (create alias 'x' for memory address 0x1000)
//
//  Predefined instructions (<basic inst>):
//      - functions, which use the flag register


/*
 *  conditional instruction:
 *  if f(a) is true call ti, else fi
 *  f(a)?ti:fi
 */


void VMOpParser::parse(VMConfig& config, const std::string& line){
    std::vector<std::string> values;
    split(line, values);

    opcode opc;
    std::string name;

    try{
        opc = stoi(values[0]);
    }
    catch(const std::exception& e){
        std::cout<<"Invalid argument for opcode (not a number) in:\n"<<line<<std::endl;
        std::cout<<"Continue without it?[y/n]";
        std::string r;
        std::cin>>r;
        
        if(r == "y")
            return;
        else
            exit(-1);
        
    }

    config.ops_symtable[opc] = OpConfig(opc, name, std::make_unique<VMOp>(rpn_calc, vmr, vmm, values));
}
#include "VMRegisters.h"

VMRegisters::VMRegisters(const std::vector<Register>& registers){
    this->registers = registers;
    for(auto reg : this->registers){
        this->c_registers.insert({reg.get_code(), &reg});

        if(reg.get_type() == Register::IP) ip_reg = this->c_registers[reg.get_code()];
        if(reg.get_type() == Register::FLAGS) flag_reg = this->c_registers[reg.get_code()];
    }
}

Register& VMRegisters::operator[](reg_code r){
    if(c_registers.count(r) == 0); //handle error

    return *c_registers[r];
}

Register& VMRegisters::operator[](const std::string& r_name){
    if(n_registers.count(r_name) == 0); //handle error

    return *(n_registers[r_name]);
}

bool VMRegisters::contains(reg_code r){
    return c_registers.count(r) != 0;
}

bool VMRegisters::contains(const std::string& r_name){
    return n_registers.count(r_name) != 0;
}

void VMRegisters::set_value(reg_code r, reg_val val){
    if(c_registers.count(r) == 0)
        return; //handle error

    c_registers[r]->set_value(val);
}

reg_val VMRegisters::read_value(reg_code r){
    if(c_registers.count(r) == 0)
        return; //handle error

    return c_registers[r]->get_value();
}

void VMRegisters::copy(reg_code rs, reg_code rd){
    if(c_registers.count(rs) == 0 or c_registers.count(rd) == 0)
        return; //handle error

    c_registers[rd]->set_value(c_registers[rs]->get_value());
}

reg_sz VMRegisters::get_sz(reg_code r){
    if(c_registers.count(r) == 0)
        return; //handle error

    return c_registers[r]->get_sz();
}
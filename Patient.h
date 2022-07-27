#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <utility>

class Patient {

private:

    std::string blood_type;
    std::string donor;
    std::string last_name;
    std::string first_name;

public:

    Patient(std::fstream &my_file);
    void write_to_file(std::string last_name, std::string first_name, std::string blood_type, std::string donor, std::pair<int, int> room, std::fstream &my_file);
    std::pair<int,int> assign_room (std::fstream &my_file);

};
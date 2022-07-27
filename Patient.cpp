#include "Patient.h"

Patient::Patient(std::fstream &my_file){

    std::pair<int, int> room;

    std::cout << "Enter last name: ";
    std::cin >> this->last_name;

    std::cout << "Enter first name: ";
    std::cin >> this->first_name;

    std::cout << "Enter blood type: ";
    std::cin >> this->blood_type;

    std::cout << "Are you a donor?: ";
    std::cin >> this->donor;

    room = assign_room(my_file);

    write_to_file(last_name, first_name, blood_type, donor, room, my_file);

}

void Patient::write_to_file(std::string last_name, std::string first_name, std::string blood_type, std::string donor, std::pair<int, int> room, std::fstream &my_file) {

    my_file.open("registered_patients.txt", std::ios_base::app);

    if (my_file.is_open()) {

        my_file << room.first << " " << room.second << ", " << last_name << ", " << first_name << ", " << blood_type << ", " << donor << "\n";

        my_file.close();
    }
}

std::pair<int,int> Patient::assign_room(std::fstream &my_file) {

    int coordinate = 10;
    int temp = 0;
    int x;
    int y;
    std::pair<int, int> room;


    my_file.open("registered_patients.txt", std::ios::in);
    if (my_file.is_open()) {
        std::string line;

        while (getline(my_file, line)) {
            temp = temp + 1;
        }
    }

    my_file.close();

    if (temp > 0) {
        coordinate = temp + coordinate;

        y = coordinate % 10;
        x = coordinate / 10;

        room = std::make_pair(x,y);

        return room;

    }

    else if (temp == 0) {
        y = coordinate % 10;
        x = coordinate / 10;
        
        room = std::make_pair(x,y);

        return room;

    }

    else if (temp > 49) {
        std::cout << "Sorry no more rooms are available" << std::endl;
    }

}
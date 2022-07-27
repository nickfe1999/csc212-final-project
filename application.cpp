#include "Patient.h"
#include "kdtree.h"

void read_file(std::fstream &my_file, KDNode* k1, std::string blood){

    my_file.open("registered_patients.txt", std::ios::in);

    if (my_file.is_open()) {

        std::string line;
        std::string answer = "yes";
        std::string apositive = "a+";
        std::string opositive = "o+";
        std::string bpositive = "b+";
        std::string abpositive = "ab+";
        std::string anegative = "a-";
        std::string onegative = "o-";
        std::string bnegative = "b-";
        std::string abnegative = "ab-";

        while (getline(my_file, line)) {
            std::vector<int> pt;

        size_t found = line.find(answer);
        size_t found2 = line.find(blood);
        size_t found3 = line.find(apositive);
        size_t found4 = line.find(opositive);
        size_t found5 = line.find(bpositive);
        size_t found6 = line.find(abpositive);
        size_t found7 = line.find(anegative);
        size_t found8 = line.find(onegative);
        size_t found9 = line.find(bnegative);
        size_t found10 = line.find(abnegative);

            if (found != std::string::npos) {

                if (found2 != std::string::npos && found8 == std::string::npos) {

                    pt.push_back(line[0] - '0');
                    pt.push_back(line[2] - '0');

                    std::cout << "Patient in room " << pt[0] << ", " << pt[1] << " is eligible" << std::endl;


                }

                if (found8 != std::string::npos) {

                    pt.push_back(line[0] - '0');
                    pt.push_back(line[2] - '0');

                    std::cout << "Patient in room " << pt[0] << ", " << pt[1] << " is eligible" << std::endl;
                }

                if (found4 != std::string::npos && blood == "a+" || found4 != std::string::npos && blood == "b+") {

                    pt.push_back(line[0] - '0');
                    pt.push_back(line[2] - '0');

                    std::cout << "Patient in room " << pt[0] << ", " << pt[1] << " is eligible" << std::endl;

                }

                if (found7 != std::string::npos && blood == "a+" || found7 != std::string::npos && blood == "ab-") {

                    pt.push_back(line[0] - '0');
                    pt.push_back(line[2] - '0');

                    std::cout << "Patient in room " << pt[0] << ", " << pt[1] << " is eligible" << std::endl;

                }

                if (found9 != std::string::npos && blood == "b+" || found9 != std::string::npos && blood == "ab-") {

                    pt.push_back(line[0] - '0');
                    pt.push_back(line[2] - '0');

                    std::cout << "Patient in room " << pt[0] << ", " << pt[1] << " is eligible" << std::endl;

                }

                if (found6 == std::string::npos && blood == "ab+" && found8 == std::string::npos) {

                    pt.push_back(line[0] - '0');
                    pt.push_back(line[2] - '0');

                    std::cout << "Patient in room " << pt[0] << ", " << pt[1] << " is eligible" << std::endl;
                }
            }
        }
    my_file.close();
    }
}

std::string find_type() {

    std::string blood;
    std::cout << "Please Enter Blood Type" << std::endl;

    std::cin >> blood;

    return blood;
}

int main () {

    std::fstream my_file;
    std::string choice;

    std::cout << "Register Patient               Find Patient " << std::endl;
    std::cin >> choice;

    if (choice == "register" || choice[0] == 'r'){

        Patient p1(my_file);

    }

    if (choice == "find" || choice[0] == 'f'){

        KDNode* k1;

        read_file(my_file, k1,find_type());

    }

    return 0;
    
}
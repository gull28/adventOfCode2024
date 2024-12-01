#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


void readText(std::vector<int>& vect1, std::vector<int>& vect2) {
    const char fileName[] = "input.txt";

    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    const char delimiter[] = "   "; 

    std::string line;
    while (std::getline(file, line)) {

        char* cstr = new char[line.size() + 1];
        std::strcpy(cstr, line.c_str());


        char* first = std::strtok(cstr, delimiter);
        char* second = std::strtok(nullptr, delimiter);

        if (first != nullptr && second != nullptr) {
            vect1.push_back(std::stoi(first));
            vect2.push_back(std::stoi(second));
        } else {
            std::cerr << "Invalid line format: " << line << std::endl;
        }

        delete[] cstr;
    }

    file.close();
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector<int> vect1;
    std::vector<int> vect2;
    readText(vect1, vect2);

    std::sort(vect1.begin(), vect1.end());

    std::sort(vect2.begin(), vect2.end());

    int length = vect1.size();

    int difference = 0;

    for(int i = 0; i < length; i++) {
        difference += std::abs(vect1[i] - vect2[i]);
    }

    std::cout<<difference;
    return 0;
}

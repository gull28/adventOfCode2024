#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

/**
 * @brief Parses the input file
 *
 * This function takes two empty vectors and populates them with values from the input file
 * `1   6` -> `[1]` `[6]`
 * @param vect1 First vector reference
 * @param vect2 Second vector reference
 */
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

/**
 * @brief Finds the difference score between 2 arrays
 *
 * This function takes two vectors sorted in ascending order. Calculates the "difference" between each element.
 *
 * @param vect1 First vector
 * @param vect2 Second vector
 */
void problem1(std::vector<int>& vect1, std::vector<int>& vect2) {
    int length = vect1.size();

    int difference = 0;

    for(int i = 0; i < length; i++) {
        difference += std::abs(vect1[i] - vect2[i]);
    }

    std::cout<<difference;
}

/**
 * @brief Calculates "similarity" score for 2 vectors
 *
 * This function takes two vectors, then takes the 1st one and finds the count of occurences for each element
 * in vector2. After that, takes the count of occurences and multiplies the value by current occurence.
 *
 * @param vect1 First vector used for iterations
 * @param vect2 Second vector used to check against
 */
void problem2(std::vector<int>& vect1, std::vector<int>& vect2) {
    int similarityScore = 0;

    for(auto i: vect1) {
        int res = count(vect2.begin(), vect2.end(), i);

        similarityScore += res * i;
    }

    printf("count %2d", similarityScore);   
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector<int> vect1;
    std::vector<int> vect2;
    readText(vect1, vect2);

    std::sort(vect1.begin(), vect1.end());

    std::sort(vect2.begin(), vect2.end());

    problem1(vect1, vect2);

    problem2(vect1, vect2);

    return 0;
}

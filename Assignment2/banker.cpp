// bankers algorithm
// Keegan Calkins

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctype.h>

void getInput(std::vector<std::vector<int>> &allocation, std::vector<std::vector<int>> &max, std::vector<int> &available, int &processes, int &resources) {
    std::ifstream in;
    in.open("data.csv");
    if (!in) {
        std::cerr << "File couldn't open\n";
        exit(1);
    }

    char cIn; // holds the current character from file
    int i = 0;
    std::string tempStr; 
    std::vector<int> vecRow; // holds the row as an int vector

    while(!in.eof()) {
        in.get(cIn); // get the current character from the file
        if(!isdigit(cIn)) { // checks for when the current character is not an integer
            if(tempStr != "") {
                int tempNum = std::stoi(tempStr); // set val of tempNum to tempStr as an int
                if(i == 2) {
                    available.push_back(tempNum); // push tempNum value onto available vector
                }
                vecRow.push_back(tempNum);
            }
            tempStr = "";
        } else if(isdigit(cIn) && cIn != ' ' && cIn != ',') { // when a numeric value, push char onto string
            tempStr.push_back(cIn);
        } 
        
        if(cIn == '\n') { // when end of row, clear current row before moving
            i = 0;
            vecRow.clear();
        } else if(cIn == ',') { // check for comma
            if(i == 0) { // if the iterator is set to 0, push the row vector onto the allocation vector
                allocation.push_back(vecRow);
            } else if(i == 1) { // if the iterator is set to 1, push the row vector onto the max vector
                max.push_back(vecRow);
            }
            vecRow.clear(); // clear row values            
            i++; // increment vector iterator
        }
    }

    processes = allocation.size(); // sets number of processes to allocation vector size
    resources = available.size(); // sets number of resources to max vector size
}

int main() {
    int processes, resources;
    std::vector< std::vector<int> > allocation;
    std::vector< std::vector<int> > max;
    std::vector<int> available;

    getInput(allocation, max, available, processes, resources);

}
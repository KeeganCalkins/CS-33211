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

    char cIn; //holds the current character from file
    int i = 0;
    std::string tempStr; 
    std::vector<int> vecRow; //holds the row as an int vector

    while(!in.eof()) {
        in.get(cIn); //get the current character from the file
        if(!isdigit(cIn)) { //checks for when the current character is not an integer
            if(tempStr != "") {
                int tempNum = std::stoi(tempStr); //set val of tempNum to tempStr as an int
                if(i == 2) {
                    available.push_back(tempNum); //push tempNum value onto available vector
                }
                vecRow.push_back(tempNum);
            }
            tempStr = "";
        } else if(isdigit(cIn) && cIn != ' ' && cIn != ',') { //when a numeric value, push char onto string
            tempStr.push_back(cIn);
        } 
        
        if(cIn == '\n') { //when end of row, clear current row before moving
            i = 0;
            vecRow.clear();
        } else if(cIn == ',') { //check for comma
            if(i == 0) { //if the iterator is set to 0, push the row vector onto the allocation vector
                allocation.push_back(vecRow);
            } else if(i == 1) { //if the iterator is set to 1, push the row vector onto the max vector
                max.push_back(vecRow);
            }
            vecRow.clear(); //clear row values            
            i++; //increment vector iterator
        }
    }

    processes = allocation.size(); //sets number of processes to allocation vector size
    resources = available.size(); //sets number of resources to max vector size
}

int main() {
    int processes, resources; //holds number of processes/resources 
    std::vector< std::vector<int> > allocation;  
    std::vector< std::vector<int> > max;
    std::vector<int> available;

    getInput(allocation, max, available, processes, resources); //invoke function gathering data from input file

    std::cout << "\nAllocation Resources\n"; //output Allocation table values
    for(int i = 0; i < processes; i++) {
        for(int j = 0; j < resources; j++) {
            std::cout << allocation[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::cout << "\nMax Resources\n"; //output Max table values
    for(int i = 0; i < processes; i++) {
        for(int j = 0; j < resources; j++) {
            std::cout << max[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::cout << "\nAvailable Resources\n"; //output available resource values
    for(int i = 0; i < resources; i++) {
        std::cout << available[i] << " ";
    }
    std::cout << "\n\n";

    int finished[processes]; //vector holding finished processes
    int ordered[processes]; //vector holding safe sequence order
    int needed[processes][resources]; //vector holding needed resources

    int proIt = 0; //process iterator

    for(int i = 0; i < processes; i++) {
        finished[i] = 0;
    }

    for(int i = 0; i < processes; i++) { //find needed resource values
        for(int j = 0; j < resources; j++) {
            needed[i][j] = max[i][j] - allocation[i][j];
        }
    }

    std::cout << "Needed Resources\n"; //output needed resource values
    for(int i = 0; i < processes; i++) {
        for(int j = 0; j < resources; j++) {
            std::cout << needed[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << "\n";

    for(int i = 0; i < processes; i++) { //iterate through each process
        for(int j = 0; j < processes; j++) { //find position in sequence through processes
            if(finished[j] == 0) {
                int flag = 0; //flag 0 as false when to define processes position in sequence
            
                for(int k = 0; k < resources; k++) { 
                    if(needed[j][k] > available[k]) { //sets flag to 1 or true when needed is greater
                        flag = 1;                     //than the available value
                        break;
                    }
                }
                if (flag == 0) {
                    ordered[proIt++] = j; //adds the processes position to the ordered sequence
                    for(int l = 0; l < resources; l++) {
                        available[l] += allocation[j][l];
                    }
                    finished[j] = 1; //finishes the specified process
                }
            }
        }
    }
    int flag = 1;
    for(int i = 0; i < processes; i++) { //if not finished then the sequence is unsafe and flag set to 0
        if(finished[i] == 0) {
            flag = 0;
            std::cout << "Sequence is unsafe\n";
            break;
        }
    }

    if (flag == 1) { //if finished, then print the safe sequence in the correct order
        std::cout << "Safe sequence: \n";
        for(int i = 0; i < processes - 1; i++) {
            std::cout << " P" << ordered[i] << " to";
        }
        std::cout << " P" << ordered[processes-1] << std::endl;
    }
    return 0;
}
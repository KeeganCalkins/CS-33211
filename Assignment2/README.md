## Banker's-Algorithm
A very popular algorithm used for deadlock avoidance.

## Problem Explanation
Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Suppose at time t0 following snapshot of the system has been taken: <br> <br>

<img width="631" alt="image" src="https://github.com/KeeganCalkins/test/assets/149719873/b6da7a3e-8ca5-4903-961b-09c9ae74f724"> <br> <br>

Implement the Banker’s algorithm to answer the following question： Is the system in a safe state? If Yes, then what is the safe sequence?

## Implementation
This program first utilizes the Banker's Algorithm by reading in data from the data.csv file into 
vectors. The first portion of data read is the allocation resource table onto the `allocation` vector. Then, the max resource values are read onto the `max` vector. Finally the last values read from the data file is the available resources onto the `available` vector. These values are then printed for the user in their respective form. The program then computes the `needed` vector by subtracting the allocation vector matrix from the max vector matrix and prints this matrix vector for the user. <br>
The program will now iterate through each process to check if the process can be completed with the current available resources. If the needed resources is less than or equal to the available resources then it will be able to complete that process and the program will determine that process is finished and it will be placed on the `ordered` vector to show which order the processes can safely be completed as a sequence by printing the processes, in order, out. If this is not possible, it means one or more of the processes cannot be completed in which the program will tell the user "Sequence is unsafe" setting the flag variable to 0 so that the program will then finish.

## Usage
How to use the Banker's-Algorithm program

Compile code as shown below
```
g++ banker.cpp -o bankers
```
Then run code as shown below
```
./bankers
```

## Example

The banker's algorithm will read in from the file the data as a comma seperated list, then print the data as well as the needed resources table and the safe sequence unless if the sequence is not safe, it will print that too.<br>
This is the output from running the program:
```
Allocation Resources
0 1 0 
2 0 0 
3 0 2 
2 1 1 
0 0 2 

Max Resources
7 5 3 
3 2 2 
9 0 2 
2 2 2 
4 3 3 

Available Resources
3 3 2 

Needed Resources
7 4 3 
1 2 2 
6 0 0 
0 1 1 
4 3 1 

Safe sequence: 
 P1 to P3 to P4 to P0 to P2
```
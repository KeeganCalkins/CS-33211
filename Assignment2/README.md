## Banker's-Algorithm
A very popular algorithm used for deadlock avoidance.

## Problem Explanation
Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. Suppose at time t0 following snapshot of the system has been taken: <br> <br>

![image](https://github.com/KeeganCalkins/CS-33211/assets/149719873/2961cf75-e761-4bb9-8a42-9f11f8d0b5b0) <br> <br>

Implement the Banker’s algorithm to answer the following question： Is the system in a safe state? If Yes, then what is the safe sequence?

## Usage
How to use the Banker's-Algorithm program

Compile code as shown below
```
g++ banker.cpp -o banker
```
Then run code as shown below
```
./banker
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
## Bankers-Algorithm Explanation


## Documentation



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
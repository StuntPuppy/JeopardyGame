# CSC 1061 Jeopardy Game

## Player Class (Topic 2): player.h and player.cpp
 
1. Player class declaration `player.h` requires a macro or include guard.
2. Player class definition is defined in `player.cpp`
3. A single Player object has a:
    - name (single one word name) as a string
    - score as an integer
4. A single Player object performs the following functionality and behaviors:
    1) constructors
       1) default constructor
       2) other constructors
    3) accessor (getters) member functions - constant member functions
        1) getName
        2) getScore
    6) modifiers (setters) member functions
        1) setName
        2) setScore
    9) other member functions:
        1)  `std::string toString();` // REQUIRED returns a string formatting the info of the object to display to the user
            - it does **NOT** get input from the user - NO std::cin or std::cout
            - this is a constant function that formats the data to display to the user
        2) `std::string toFileString();` // REQUIRED returns a string formatted as a comma delimited Record (ie. name,score\n)
            - it does **NOT** read from the file - **NO** `std::ifstream` or `std::ofstream`
            - this is a constant function that formats the data to display in a file
    10) Non-Member Friend Operator Functions
        1) All 6 relational operator overloads `==, !=, >=, <=, >, <` required to be overloaded
            - A Player is compared to another Player based upon the scores of the Players.
            - Players are **NOT** compared considering their names!
        2) `>>` for both istream and ifstream required to be overloaded
            - istream reads from the user input as name and score (include prompts)
            - ifstream reads from a comma delimited file as name,score\n
            - Hint: use std::getline from std::string that reads until a delimiter
        3) `<<` for both ostream and ofstream required to be overloaded
            - ostream should call toString() member function
            - ofstream should call toFileString() member function


### Testing

Update MAKEFILE (you may need to show all hidden files to see this file)
```
SRCS = maintest.cpp player.cpp

OBJS = maintest.o player.o
```
   
- Although NO main file is being submitted at this time, each function written should be thoroughly tested.
- For testing purposes, write your own main and call each function in Player to perform a unit test to validate your class.

### Objectives: 

1. Design and develop large-scale programs using classes and data structures
2. Write properly documented programs following a set of coding standards.
3. Demonstrate an understanding of object-oriented methodology in program design.
4. Create classes to be used as an abstract data type for a program.
5. Demonstrate understanding and use of the process of data abstraction / encapsulation.

> END OF PLAYER CLASS
      
___

## Contestants Class Topic3: contestants.h and contestants.cpp

1. Class must be divided into declaration .h and definition .cpp files
    - Include macro guard defined as CONTESTANTS_H
2. Contestants is an **unordered list** (Bag) data structure that ***has a*** underlying fixed size array of three `Player objects
    - Constant: MAX_SIZE (static constant for class set to 3)
    - Player data[MAX_SIZE]
    - int size;
3. The Contestants data structure should include collection functionality:
    1. `Contestants` Default constructor that creates an empty list
    2. `getSize` - returns the number of elements in the array
    3. `getMaxSize` - returns the fixed-size of the array
    4. `append` into collection at the end - keeping data structure unordered
    5. `remove` or `erase` from the collection by the Player object
         - Unordered removal: Player is found and then the last object is replaced over the object found
    6. `remove` or `erase` from the collection by index
         - Unordered removal: last index used is replaced over index to remove or erase
    7. `clearAll`
         - BigO(1) for constant efficiency
         - reset size to 0!
    8. `find` or `contains` a Player object and return the index
         - Validate index required
    9. `at` or `getItembyIndex` and return the Player object
        - Validate index required
    10. readfile(std::string fileName)
          ```
        create std::ifstream object
        open file
        check the file opened successfully
        read from file into temporary Player object
          while you have NOT reached eof
            append the temporary Player
            read the next Player object from the file
          close the file
          ```
    11. writefile(std::string fileName)
        ```
        Create std::ofstream object
        open file
        check file opened successfully
        Repeat from 0 through size (looping through each index)
          write the item to the file at the index
        close file
        ```
   12. `operator[]` subscript: as a getter needs to be overloaded. This means it should only get or access and return an item from the array - NOT modify or set the item: Player operator[](int index)
  
### Testing

Update MAKEFILE (you may need to show all hidden files to see this file)
```
SRCS = maintest.cpp player.cpp contestants.cpp

OBJS = maintest.o player.o contestants.o
```

- Each function written should be thoroughly tested.
- For testing purposes, write your own main and call each function in Contestants to perform a unit test to validate your class.
  
### Objectives: 

1. Design and develop large-scale programs using classes and data structures.
2. Write properly documented programs following a set of coding standards.
3. Demonstrate an understanding of object-oriented methodology in program design.
4. Create classes to be used as an abstract data type for a program.
5. Demonstrate understanding and use of the process of data abstraction/encapsulation.
6. Implement contiguous data structures in code.

> END OF CONTESTANTS CLASS

___

## Topic 3 Main Program

Update MAKEFILE (you may need to show all hidden files to see this file)
```
SRCS = main.cpp player.cpp contestants.cpp

OBJS = main.o player.o contestants.o
```
1. The `main.cpp` file given, will:
    1. Setup the Contestants object - it should be empty with a CAPACITY of 3
    2. Read from the `assets/player.dat` file into the Contestants collection bag for the "Greatest of all Time" Jeopardy players using `Contestants::readFile` member function call.
    3. Print the Contestant collection bag to the console formatted in a meaningful way for the user experience.
    4. Remove all 3 "Greatest of all Time" Jeopardy players
    5. Ask for the new contestants to be introduced
    6. Create player objects from the given names and scores
    7. Add the 3 players to the Contestant collection.
    8. Print the entire Contestants collection to the console and format for the Console in meaningful way for the user experience
    9. Write the entire Contestants collection to the file `player.dat` file using `Contestants::writeFile` member function call

> END OF MAIN.CPP TOPICS 2 & 3
---

## Record Class (Topic 4): record.h and record.cpp

- Record `is a` std::string
    - All public member functions, operators are inherited from `std::string` in Record
    - Although Record cannot access `std::string` private data member, there are public functions and operators that allow Record access to the private data: `c_str`, `data`, `operator[]`, `at`
  

1. Class must be divided into declaration .h and definition .cpp files
    - Include macro guard defined as RECORD_H
2. Create the Record class that inherits from `std::string`.  Record "is a" std::string
3. Add private data members to Record to assist with the split member function (step 12)
```
Record* fields;
int size, max;
```
4. Add public accessor member function to assist with the split member function
```
int getNumFieldsInRecord() const { return size; } // returns number of fields after split
int getMax() const { return max; }
```
5. Do **NOT** add any public modifier member function for the size or max.  This is all handled within the split member function and NEER should be changed or modifited outside of the Record class!
6. Write the following constructors for the Record class (that map to `std::string` constructors), make sure to call the base class constructor and initialize the private data members of Record to default values

```
(1) default:         Record() : std::string()
(2) copy:            Record(const std::string& str) : std::string(str)
(3) substring:       Record(const std::string& str, size_t pos, size_t len=npos) 
                       : std::string(str, pos, len)
(4) from c-string:   Record(const char* s) : std::string(s)
(5) from sequence:   Record(const char* s, size_t n) : std::string(s, n)
(6) fill:            Record(size_t n, char c) : std::string(n, c)
```
7. Implement the destructor for Record to deallocate memory allocated from split
```
Destructor Prototype: ~Record();
Destructor Definition: Record::~Record() { // will be discussed in lecture }
```
8. Add member functions: upper and lower member to convert the Record object to all uppercase or all lowercase

```
Record Record::upper();
@param: Nothing - it is a member function
@return the new Record that is now all upper

Record Record::lower();
@param: Nothing - it is a member function
@return the new Record that is now all lower
```
  - Investigate Python's upper and lower methods to determine structure of the member function and model `Record::upper` and `Record::lower` in the same manner:
      - https://www.w3schools.com/python/ref_string_upper.asp
      - https://www.w3schools.com/python/ref_string_lower.asp
    - Note the member function does **NOT** change the original object, but creates a copy to convert to all upper or lower and returns out the copy.
9. Add member function to perform comparision without considering case
```
int compareIgnoreCase(const Record& record);
@param: 2nd object used in the comparison
@return: 0 if equal, -1 if the first is less than the second and 1 if the first is greater than the second 
```
   - Investigate `std::string::compare(const string& str);` that is similar, but it is case-sensitive
       - http://www.cplusplus.com/reference/string/string/compare/
   - Note the member function uses the `this` as the first object and the 2nd object is passed into the function as the parameter.
10. Overload `operator>>` for std::istream to read until '\n' NOT just any whitespace.
```
std::istream opeator>>(std::istream& is, Record& r);
@param1: is - the istream object for console input
@param2: r - the Record reference object so that it can be modified and set based upon the input
@return: is - the istream object passed in is also returned to allow input chaining
```
11. Overload `operator>>` for std::ifstream to read until '\n' NOT just any whitespace.
```
std::ifstream opeator>>(std::ifstream& is, Record& r);
@param1: is - the ifstream object for file input
@param2: r - the Record reference object so that it can be modified and set based upon the input
@return: is - the ifstream object passed in is also returned to allow input chaining
```
12. Add a member function to split the Record into separate fields
```
Record* split(char delimiter);
@param: the character delimiter to split the Record at
@return: a dynamic array that represents the fields of the Record after the split
```
   - Investigate Python's split method to determine structure of the member function and task
       - https://www.w3schools.com/python/ref_string_split.asp

### Testing

Update MAKEFILE (you may need to show all hidden files to see this file)
```
SRCS = maintest.cpp player.cpp contestants.cpp record.cpp

OBJS = maintest.o player.o contestants.o record.o
```

- Each function written should be thoroughly tested.
- For testing purposes, write your own main and call each function in Record to perform a unit test to validate your class.
  
### Objectives: 

1. Recognize situations in which inheritance can simplify the implementation of a group of related classes
2. Implement a derived class
3. Recognize situations in which creating an abstract base class will allow the later implementation of many derived classes that share underlying functions.
4. Process memory allocation and management of contiguous data structures in code.

> END OF RECORD.CPP TOPIC 4

___


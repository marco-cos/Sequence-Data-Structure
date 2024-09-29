
# Sequence Data Structure Project

## Overview

This project implements a **Sequence** data structure in C++ using object-oriented principles. The **Sequence** class models a dynamic collection of items that can be modified by adding, removing, or iterating through elements. The project demonstrates core C++ features such as dynamic memory allocation, object-oriented design, and modular programming using header and implementation files. Project for UCLA CS 32 class. 

## Features

- **Dynamic Sequence**: A flexible container that can store and manage a sequence of items.
- **Insert and Erase**: Functions to add or remove items from the sequence at specified positions.
- **Access and Modification**: Ability to retrieve or modify elements at a given position.
- **Iterators**: Enables iteration through the sequence, making it easier to traverse or modify elements.
- **Memory Management**: Dynamically allocates memory to manage the sequence, ensuring efficient use of resources.

## Project Structure

The project is organized into two main files:

- **Sequence.cpp**: Contains the implementation of the **Sequence** class, including member functions for managing the sequence.
- **Sequence.h**: Defines the interface for the **Sequence** class, outlining the available public methods and attributes.

## Key Functions in Sequence Class

### Public Methods

1. **Constructor & Destructor**:
   - Initializes an empty sequence.
   - Ensures proper memory management by cleaning up dynamically allocated memory when the sequence is no longer needed.

2. **Size**:
   - Returns the number of elements currently stored in the sequence.

3. **Empty**:
   - Returns whether the sequence is empty.

4. **Insert**:
   - Inserts an element into the sequence at the specified position.

5. **Erase**:
   - Removes an element from the sequence at the specified position.

6. **Set & Get**:
   - Modifies the value at a given position (Set) or retrieves the value at a given position (Get).

7. **Find**:
   - Searches for a specific element in the sequence and returns its position if found.

8. **Swap**:
   - Swaps the contents of this sequence with another sequence.

## How to Build and Run

### Requirements
- **C++11** or later
- A compatible C++ compiler (e.g., `g++`)

### Build Instructions
1. Clone or download the project to your local environment.

2. Compile the project using the following command:
   ```bash
   g++ -std=c++11 Sequence.cpp -o sequence_program
   ```

3. Run the executable:
   ```bash
   ./sequence_program
   ```

## Example Usage

After building and running the program, you can interact with the **Sequence** by adding, removing, or searching for elements. Example operations might include:

- Inserting elements into the sequence:
  ```cpp
  seq.insert(0, 10); // Insert 10 at the start
  seq.insert(1, 20); // Insert 20 at position 1
  ```

- Erasing elements from the sequence:
  ```cpp
  seq.erase(0); // Remove the element at position 0
  ```

- Accessing elements:
  ```cpp
  int value;
  seq.get(1, value); // Retrieve the element at position 1
  ```

- Checking the size of the sequence:
  ```cpp
  int size = seq.size(); // Get the number of elements in the sequence
  ```

## Conclusion

This project demonstrates a C++ implementation of a dynamic **Sequence** class. It incorporates object-oriented principles, efficient memory management, and modular code design. The **Sequence** class can be used in a wide variety of applications that require flexible handling of ordered data.

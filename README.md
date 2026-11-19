# Data-Structures in C

Basic data structures written in plain C: arrays, singly and doubly linked lists, and stacks.
I wrote these during my Data Structures & Algorithms lab sessions. Each file is a small
program you can compile and run by itself.

## Contents

| Folder | Program | What it covers |
| --- | --- | --- |
| `01-pointers-and-arrays` | `pointer_sum.c` | Adding two numbers through pointers |
| | `array_insert_delete.c` | Inserting and deleting by shifting array elements |
| `02-singly-linked-list` | `linked_list_operations.c` | Insert and delete at the start, end and a given position |
| | `linked_list_user_input.c` | The same operations, with values entered by the user |
| | `linked_list_reverse_dedup.c` | Recursive reverse printing and removing duplicates |
| `03-doubly-linked-list` | `doubly_linked_list.c` | Forward and backward traversal, finding the max and min |
| `04-stack` | `stack_array.c` | Array stack: push, pop, peek, isEmpty, isFull |
| | `stack_linked_list.c` | Linked list stack: push, pop, peek, isEmpty |
| | `stack_array_menu.c` | Menu-driven array stack |
| | `stack_linked_list_menu.c` | Menu-driven linked list stack |

## Running a program

You need a C compiler such as GCC, Clang or MinGW on Windows.

```sh
gcc 02-singly-linked-list/linked_list_operations.c -o linked_list_operations
./linked_list_operations
```

### With CMake

The `CMakeLists.txt` builds every program as its own executable, so this also works in CLion
and other CMake-based IDEs:

```sh
cmake -S . -B build
cmake --build build
./build/stack_array_menu
```

## License

[MIT](LICENSE)

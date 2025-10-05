# push_swap

## 💡 Overview
**push_swap** is a project from [42 Lisboa](https://www.42lisboa.com) that focuses on sorting a stack of integers using a limited set of operations.  
The goal is to reinforce **algorithm design**, **stack manipulation**, and **optimization techniques** in C.  
Although the bonus (“checker” and full optimization) was not completed, **radix sort** and other strategies were implemented to improve performance.

---

## Key Concepts
- Stack operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`)  
- Algorithm design for sorting  
- Optimizing number of operations  
- Memory management and validation of input  

---

## Compilation / Installation
```bash
git clone https://github.com/martimsaunders/pushswap.git
cd push_swap
make
```

This will generate the executable:
```bash
./push_swap
```

## Usage
### Mandatory
```bash
./push_swap 3 2 5 1 4
```
Output (using radix sorting with some improvements)
```bash
rra
rra
pb
ra
ra
pb
ra
sa
pa
pa
```

---

## Tech Stack
- C
- UNIX system calls (`read`, `open`, etc)
- Makefile

---

## Challenges / Lessons Learned
- Implementing and combining stack operations efficiently
- Designing algorithms to minimize the number of moves
- Using radix sort to handle larger sets of integers
- Validating and handling user input
- Debugging complex sorting scenarios

---

Author

- Martim Prazeres Saunders

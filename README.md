# push_swap

## 📚 About the Project

**push_swap** is a sorting algorithm project from the 42 coding school curriculum. The goal is to sort a stack of integers using a very limited set of operations and the least number of moves possible. You must write a program that outputs the instructions needed to sort the stack.

This project focuses on algorithmic thinking, performance optimization, data structures (particularly stacks and linked lists), and writing clean, efficient C code under strict constraints.

---

## 🧩 Project Objective

You must write two programs:

1. `push_swap` – receives a list of integers and outputs the operations needed to sort them.
2. `checker` *(optional/bonus)* – checks if a sequence of operations sorts a list correctly.

--- 

## 🔧 Allowed Operations

You may use only the following operations:

- **Swap**: `sa`, `sb`, `ss`  
- **Push**: `pa`, `pb`  
- **Rotate**: `ra`, `rb`, `rr`  
- **Reverse rotate**: `rra`, `rrb`, `rrr`

These operations manipulate two stacks: **A** and **B**.

---

## 🚀 How It Works

- The program receives a list of integers as command-line arguments.
- It initializes stack **A** with the input values and keeps stack **B** empty.
- Using only the allowed operations, it calculates and prints a sequence of moves to sort stack **A** in ascending order.
- The output is a list of instructions (one per line) that can be passed to a checker program.

---

## 🛠️ How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/push_swap.git
   cd push_swap
   ```

2. Compile the project:
   ```bash
   make
   ```

3. Run the program:
   ```bash
   ./push_swap 3 2 1
   ```

   Output:
   ```
   sa
   rra
   ```

4. *(Optional)* Use your output with a checker:
   ```bash
   ./push_swap 3 2 1 | ./checker 3 2 1
   ```

---

## 🧠 Skills Demonstrated

- Efficient algorithm design and optimization  
- Handling edge cases and invalid input  
- Implementing and manipulating custom data structures (linked lists, stacks)  
- Performance tuning under strict constraints  
- Writing modular and readable C code  
- Time and space complexity analysis

---

## 📌 Notes

- The project restricts the use of standard sorting functions.
- The goal is to minimize the number of operations.
- Bonus implementations may include:
  - Checker program (`checker`)
  - Visualization of the sorting process
  - Support for larger input sizes with advanced algorithms (e.g., radix sort, quick sort logic)

---

## 📁 Project Status

✅ Completed – includes sorting logic for both small and large datasets, and handles all edge cases.

---

## 📫 Contact

Feel free to reach out via [GitHub](https://github.com/Nicolike20) if you have any questions or want to connect.

[![forthebadge](https://forthebadge.com/images/featured/featured-built-with-love.svg)](https://forthebadge.com)

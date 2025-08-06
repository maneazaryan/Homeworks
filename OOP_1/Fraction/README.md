# 🧮 Fraction Class (Basic Arithmetic and Comparisons)

This project implements a **Fraction** class in C++ for representing rational numbers and performing basic arithmetic operations and comparisons:

- Addition, Subtraction, Multiplication, Division  
- Comparison operators: `<`, `>`, `==`, `!=`

---

## 📑 Table of Contents
- [Overview](#overview)  
- [Files](#files)  
- [Requirements](#requirements)  
- [Usage](#usage)  
- [Example Output](#example-output)  
- [License](#license)  

---

## 📌 Overview
The `Fraction` class allows creating fraction objects and performing arithmetic operations while automatically simplifying the results.  
It also supports comparison operators by converting fractions to their decimal representation for accuracy.

---

## 📂 Files
- `fraction.h` → Class declaration (header file)  
- `fraction.cpp` → Class method definitions (implementation)  
- `main.cpp` → Demonstration of class usage  
- `Makefile` → Build automation  

---

## ⚙️ Requirements
- A C++ compiler supporting C++17 or later (e.g., `g++`, `clang++`)  
- Compatible with Linux, macOS, and Windows  

---

## ▶️ Usage

### 🛠️  1. Build the project
```bash
make
```
### ▶️  2. Run the Program
Execute the compiled file:
```bash
./main.exe
```
### 👀 3. View the Output  
After running the program, you will see the results of arithmetic operations on fractions, along with comparison outcomes, printed to the console.

--- 
## 📋 Example  

When you run the program, it demonstrates arithmetic operations and comparisons between two fractions:
```
add
11/10
subtraction
-1/10
mult
3/10
division
5/6
n1<n2 : 1
n1>n2 : 0
n1==n2 : 0
n1!=n2 : 1
```

Here:
- `1` means **true**  
- `0` means **false**  

---
## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

MIT License

Copyright (c) 2025 Mane Azaryan

Permission is hereby granted, free of charge, to any person obtaining a copy  
of this software and associated documentation files (the "Software"), to deal  
in the Software without restriction, including without limitation the rights  
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  
copies of the Software, and to permit persons to whom the Software is  
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all  
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL T

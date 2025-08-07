# 👥 Person-Student-Teacher Class Hierarchy in C++

This project demonstrates a simple class inheritance and polymorphism hierarchy in C++.  
It implements three classes: `Person` (base class), `Student`, and `Teacher` (derived classes), showcasing constructors, destructors, virtual functions, and memory management.

---

## 📑 Table of Contents
- [Overview](#overview)  
- [Files](#files)  
- [Requirements](#requirements)  
- [Usage](#usage)  
- [License](#license)  

---

## 📌 Overview
The `Person` class contains basic personal information fields such as name, age, and education.  
`Student` and `Teacher` inherit from `Person` and add their own specific fields and methods.  
Virtual functions enable polymorphic behavior, allowing overridden methods to print detailed information.  
Dynamic memory management is demonstrated via heap allocation and proper use of virtual destructors.

---

## 📂 Files
- `inc/person.h` → Declaration of `Person` class  
- `inc/student.h` → Declaration of `Student` class  
- `inc/teacher.h` → Declaration of `Teacher` class  
- `src/person.cpp` → Implementation of `Person` methods  
- `src/student.cpp` → Implementation of `Student` methods  
- `src/teacher.cpp` → Implementation of `Teacher` methods  
- `src/main.cpp` → Example usage and testing  
- `Makefile` → Build automation script  

---

## ⚙️ Requirements
- C++ compiler supporting C++17 or newer (e.g., `g++`, `clang++`)  
- Compatible with Linux, Windows, and macOS  
- `make` utility for building (optional, can compile manually)  

---

## 🚀 Usage

Build the project with:

```bash
make
```
## ▶️   Run the Program
Execute the compiled file:
```bash
./bin/main.exe
```

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

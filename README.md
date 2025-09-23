# BSDSF23A020-OS-A01

## 📌 Operating Systems - Programming Assignment 01  

This project is part of the **Operating Systems** course assignment.  
The goal is to learn how real-world C projects are structured, built, and maintained using **multi-file compilation, static & dynamic libraries, Makefiles, and Git/GitHub workflows**.  

---

## 🎯 Learning Objectives
- Modular programming with header (`.h`) and source (`.c`) files  
- Creating and using **static (`.a`)** and **dynamic (`.so`)** libraries  
- Writing professional **Makefiles** for build automation  
- Using tools like `ar`, `nm`, `readelf`, `ldd` for binary analysis  
- Practicing **Git workflows** (branches, commits, tags, releases)  
- Writing **Linux man pages** for documentation  

---

## 📂 Project Structure
```
ROLL_NO-OS-A01/
├── src/         # Source code for library and driver program
├── include/     # Header files
├── lib/         # Compiled static (.a) and dynamic (.so) libraries
├── bin/         # Executable programs
├── obj/         # Intermediate object files
├── man/         # Manual pages
└── REPORT.md    # Analysis and answers to report questions
```

---

## 🚀 Build & Run
1. Clone the repository:
   ```bash
   git clone git@github.com:msaadsbr/BSDSF23A020-OS-A01.git
   cd BSDSF23A020-OS-A01
   ```

2. Build the project:
   ```bash
   make
   ```

3. Run the executable:
   ```bash
   ./bin/client
   ```

---

## 🏷️ Versions & Releases
- **v0.1.1-multifile** → First multi-file build with Makefile  
- **v0.2.1-static** → Static library build  
- **v0.3.1-dynamic** → Dynamic library build  
- **v0.4.1-final** → Final version with man pages & installation  

---

## 👨‍💻 Author
**Fahad Rahman (BSDSF23A020)**  
Instructor: *Dr. Muhammad Arif Butt*  

# 🚀 Customised Dynamic File System (CVFS)

A **Customised Virtual File System (CVFS)** implemented in **C++** that simulates core file system operations in memory.  
This project demonstrates how real operating systems internally manage files using inodes, file tables, and file descriptors.

It is designed for **system programming practice**, **operating system concepts**, and **academic learning purposes**.

---

## 📌 Project Objective

The objective of this project is to:

- Simulate a file system architecture
- Implement core file operations
- Manage files dynamically in memory
- Understand inode and file descriptor mechanisms
- Strengthen system-level programming concepts in C++

---

## 🛠️ Technologies Used

- **Language:** C++
- **Core Concepts:**
  - File System Architecture
  - Inode Structure
  - Super Block Management
  - File Descriptor Table
  - Dynamic Memory Allocation
  - Command Line Interface Design

---

## ⚙️ Features

The Customised Dynamic File System supports:

- 📁 Create File  
- ❌ Delete File  
- ✏️ Write File  
- 📖 Read File  
- 🔓 Open File  
- 🔒 Close File  
- 📋 List All Files (`ls`)  
- 📊 Display File Information (`stat`, `fstat`)  
- 🔄 Truncate File  
- 🧠 In-Memory Inode Management  

---

## 🏗️ Internal Architecture

The system internally maintains the following components:

- **Super Block**
- **Inode Table**
- **File Table**
- **User File Descriptor Table (UFDT)**

Each file contains metadata such as:

- File Name  
- File Size  
- File Type  
- Link Count  
- Reference Count  
- File Permissions  
- File Data Buffer  

---


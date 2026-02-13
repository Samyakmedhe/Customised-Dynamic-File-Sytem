# 🚀 Customised Virtual File System (CVFS)

A fully functional **Customised Virtual File System (CVFS)** implemented in **C++**, designed to simulate core file system operations in memory.

This project mimics how an operating system internally manages files using:

- Super Block
- Inode List (DILB)
- File Table
- User File Descriptor Table (UFDT)

It provides a command-line interface to perform file operations similar to real operating systems.

---

## 📌 Project Overview

The Customised Virtual File System (CVFS) is an in-memory file system that supports creation, deletion, reading, writing, and management of files using inode-based architecture.

It is built to understand:

- File system internal architecture
- Inode management
- File descriptor handling
- Memory management
- System-level programming concepts

---

## 🛠️ Technology Stack

- **Language:** C++
- **Libraries Used:**
  - `stdio.h`
  - `stdlib.h`
  - `string.h`
  - `unistd.h`
  - `iostream`

---

## 🏗️ System Architecture

The system consists of the following components:

### 🔹 Super Block
Stores:
- Total number of inodes
- Free inode count

### 🔹 DILB (Dynamically Inode Linked List)
- Linked list of inodes
- Each inode stores file metadata

### 🔹 Inode Structure
Each file contains:

- File Name
- Inode Number
- File Size
- Actual File Size
- File Type
- Buffer (Data Storage)
- Link Count
- Reference Count
- Permission

### 🔹 File Table
Maintains:
- Read Offset
- Write Offset
- Mode
- Inode Pointer

### 🔹 UFDT (User File Descriptor Table)
- Stores active file descriptors
- Connects file descriptor to file table

---

## ⚙️ Features

The system supports:

- 📁 `create` – Create new file  
- 📂 `open` – Open existing file  
- ❌ `rm` – Delete file  
- 📖 `read` – Read file content  
- ✏️ `write` – Write into file  
- 📋 `ls` – List all files  
- 📊 `stat` – Display file info using name  
- 📊 `fstat` – Display file info using file descriptor  
- 🔄 `lseek` – Change file offset  
- 🔒 `close` – Close file  
- 🔒 `closeall` – Close all files  
- ✂️ `truncate` – Remove file data  
- 📘 `man` – Command manual  
- ❓ `help` – Display all commands  

---

## 📂 Project Structure

Customised-Dynamic-File-System/ → CVFS.cpp | CVFS (Executable) | README.md
---

# Speller

## Overview

**Speller** is a high-performance program that checks the spelling of words in a text file against a dictionary. Built with a hash table for efficient lookups, it identifies misspelled words while providing detailed performance metrics for key operations like loading the dictionary, checking words, and freeing memory.

This project demonstrates core principles of data structures, algorithms, and memory management in C.

---

## Key Features

- **Efficient Spell-Checking:** Uses a hash table for rapid word lookups.
- **Customizable Dictionaries:** Accepts any dictionary file in plain text format.
- **Performance Metrics:** Reports the time taken for:
  - Loading the dictionary.
  - Checking words.
  - Determining dictionary size.
  - Unloading memory.
- **Optimized Hashing:** Implements the `djb2` hash function for balanced performance and distribution.

---

## Prerequisites

Before running the program, ensure your system has:
1. A C compiler (`clang` or `gcc`).
2. The `make` build tool.

Follow the instructions below to install Clang and Make based on your operating system.

---

### Installing Clang and Make

#### **For Ubuntu/Linux**
1. Update your package list:
   ```bash
   sudo apt update
   ```
2. Install Clang and Make:
   ```bash
   sudo apt install clang make
   ```
3. Verify Clang installation:
   ```bash
   clang --version
   ```

#### **For macOS**
1. Install Xcode Command Line Tools:
   ```bash
   xcode-select --install
   ```
2. Verify Clang installation:
   ```bash
   clang --version
   ```

#### **For Windows**
1. Download the LLVM installer from the [official LLVM website](https://llvm.org/builds/).
2. Run the installer and follow the on-screen instructions.
3. Add the LLVM `bin` directory (e.g., `C:\Program Files\LLVM\bin`) to your system's `PATH` environment variable:
   - Open "Environment Variables" in Windows settings.
   - Edit the `Path` variable and add the directory.
4. Verify Clang installation:
   ```cmd
   clang --version
   ```

---

## Getting Started

### Step 1: Clone the Repository
Clone the project repository to your local machine:
```bash
git clone https://github.com/Shahir-47/speller.git
cd speller/speller
```

### Step 2: Compile the Program
Use the provided `Makefile` to build the program:
```bash
make speller
```

This will generate an executable file named `speller`.

### Step 3: Run the Program
Run the program using the following syntax:
```bash
./speller [DICTIONARY] text
```

### Parameters
- **DICTIONARY** (optional): Path to the dictionary file. Defaults to `dictionaries/large` if not provided.
- **text** (required): Path to the text file to be spell-checked.

---

## Usage Examples

#### **Using the Default Dictionary**
```bash
./speller texts/lalaland.txt
```

#### **Specifying a Custom Dictionary**
```bash
./speller dictionaries/small texts/shakespeare.txt
```

#### **Sample Output**
```plaintext
MISSPELLED WORDS

[...]
AHHHHHHHHHHHHHHHHHHHHHHHHHHHT
[...]
Shangri
[...]
fianc
[...]

WORDS MISSPELLED:     15
WORDS IN DICTIONARY:  143091
WORDS IN TEXT:        1024
TIME IN load:         0.12
TIME IN check:        0.45
TIME IN size:         0.01
TIME IN unload:       0.04
TIME IN TOTAL:        0.62
```

---

## Project Structure

```
├── speller/
│   ├── dictionaries/
│   │   ├── small
│   │   └── large
│   ├── texts/
│   │   ├── (various test text files)
│   ├── dictionary.c
│   ├── dictionary.h
│   ├── speller.c
│   ├── Makefile
└── README.md
```

- **`dictionaries/`**: Contains dictionary files, including `small` for debugging and `large` with 143,091 words.
- **`texts/`**: Test text files for running the program.
- **`dictionary.c`**: Implements dictionary functions like `load`, `check`, and `unload`.
- **`dictionary.h`**: Header file with function prototypes and constants.
- **`speller.c`**: Main program that integrates dictionary functions and benchmarks.
- **`Makefile`**: Automates the build process.

---

## Implementation Details

### Key Functions
- **`load`**: Reads the dictionary file into a hash table.
- **`check`**: Checks if a word exists in the hash table.
- **`hash`**: Maps a word to a specific bucket in the hash table.
- **`size`**: Returns the number of words loaded in the dictionary.
- **`unload`**: Frees all memory used by the dictionary.

### Hash Table
- **Number of Buckets (`N`)**: 24,000 for optimized performance.
- **Hash Function**: Based on the [djb2 algorithm](http://www.cse.yorku.ca/~oz/hash.html), designed for speed and uniqueness.

---

## Testing the Program

### Predefined Test Files
The `texts/` directory contains various test files, such as:
- `lalaland.txt`
- `shakespeare.txt`
- `tolstoy.txt`

### Running Tests
To test the program:
```bash
./speller dictionaries/small texts/shakespeare.txt
```

### Expected Output
- A list of misspelled words from the text.
- Performance benchmarks for dictionary loading, word checking, and unloading.

---

## Authors

Developed by [Shahir Ahmed](https://github.com/Shahir-47/).

## License

This project is licensed under the [MIT License](LICENSE).

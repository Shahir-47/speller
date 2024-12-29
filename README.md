# Speller

## Overview

**Speller** is a high-performance spell-checking program that uses a hash table to efficiently verify the spelling of words in a text file. The program compares words from a text file against a dictionary file and reports any misspelled words, along with performance benchmarks for loading, checking, and unloading the dictionary.

## Features

- Identifies misspelled words in text files.
- Utilizes a hash table with adjustable bucket sizes for improved performance.
- Supports custom dictionary files.
- Reports detailed performance benchmarks for:
  - Dictionary loading.
  - Word checking.
  - Dictionary size determination.
  - Dictionary unloading.

## Usage

### Step 1: Compile the Program

Use the provided `Makefile` to compile the program:
```bash
make speller
```

This will create an executable file named `speller`.

### Step 2: Run the Program

Run the program using the following syntax:
```bash
./speller [DICTIONARY] text
```

### Parameters
- **DICTIONARY** (optional): The path to the dictionary file. Defaults to `dictionaries/large` if not provided.
- **text** (required): The path to the text file to be spell-checked.

### Example Usage

Using the default dictionary:
```bash
./speller texts/lalaland.txt
```

Specifying a custom dictionary:
```bash
./speller dictionaries/small texts/shakespeare.txt
```

### Example Output
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

## Project Structure

```
├── speller/
│   ├── dictionaries/
│   │   ├── small
│   │   └── large
│   ├── keys/
│   │   ├── (test text files)
│   ├── texts/
│   │   ├── (test text files)
│   ├── dictionary.c
│   ├── dictionary.h
│   ├── speller.c
│   ├── Makefile
└── README.md
```

- **dictionaries/**: Contains the dictionary files (`small` for debugging, `large` with 143,091 words).
- **keys/** and **texts/**: Various text files for testing the program.
- **speller.c**: The main program file.
- **dictionary.c**: Contains the implementation of dictionary functions.
- **dictionary.h**: Header file defining dictionary-related functions and constants.
- **Makefile**: Automates the build process.

## Implementation Details

### Key Functions
- **`load`**: Loads the dictionary into memory using a hash table.
- **`check`**: Verifies whether a word exists in the dictionary.
- **`hash`**: Hashes words to an index in the hash table.
- **`size`**: Returns the number of words in the loaded dictionary.
- **`unload`**: Frees memory used by the dictionary.

### Hash Table
- **Buckets (`N`)**: 24,000, chosen for optimal performance after testing.
- **Hash Function**: Based on the [djb2 algorithm](http://www.cse.yorku.ca/~oz/hash.html), which balances speed and uniqueness.

## Benchmarks

The program reports execution times for:
1. **Dictionary Loading (`load`)**: Time taken to load the dictionary.
2. **Word Checking (`check`)**: Time taken to verify words against the dictionary.
3. **Dictionary Size (`size`)**: Time taken to determine the size of the dictionary.
4. **Unloading (`unload`)**: Time taken to free memory used by the dictionary.
5. **Total Execution Time**: The sum of all times.

## Testing

### Test Files
The `texts/` directory contains several predefined text files, including:
- `lalaland.txt`
- `shakespeare.txt`
- `tolstoy.txt`
- `constitution.txt`

### Running Tests
To test the program:
```bash
./speller dictionaries/small texts/shakespeare.txt
```

### Expected Output
- List of misspelled words.
- Performance benchmarks.

## Development Notes

- **Dependencies**: Standard C libraries (`stdio.h`, `stdlib.h`, etc.).
- **Platform**: Designed for Unix-like systems (Linux, macOS).
- **Compiler**: Requires `clang` or `gcc`.

## Makefile

The provided `Makefile` automates the build process. To compile the program, run:
```bash
make speller
```

### Makefile Breakdown
- Compiles `speller.c` and `dictionary.c` into object files.
- Links the object files into the `speller` executable.

Makefile content:
```make
speller:
	clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -c -o speller.o speller.c
	clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -c -o dictionary.o dictionary.c
	clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -o speller speller.o dictionary.o -lm
```

## Authors

Developed by [Shahir Ahmed](https://github.com/Shahir-47/).

## License

This project is licensed under the [MIT License](LICENSE).

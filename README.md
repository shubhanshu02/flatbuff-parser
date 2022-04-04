# FlatBuffer Parser

This repository serves as my submission for the RLOS 2022 as the screening exercise for the "Improve FlatBuffer Parser Support in VowpalWabbit".

### Setup Instructions

1. Install FlatBuffers using [this tutorial](https://google.github.io/flatbuffers/flatbuffers_guide_building.html).

1. Assuming you are currently in the root directory of this project. Run the following commands:

```sh
$ mkdir build && cd build
$ cmake ..
$ cmake --build .
```

3. Now to run the program, use the executable named `fparse`.

### Usage

1. To read the serialized data from a file, use the `-r` or `--read` argument.

```sh
$ ./fparse --read <filename>
```

2. To create a new object and serialize it into a file, run the program dirctly.

```sh
$ ./fparse
```

### About the Exercise

This exercise involves:

- Creating a simple FlatBuffer schema file (can be found in `src/schema/schema.fbs`) with the table:

  - a_name: string
  - a_value: float
  - a_flag: bool

- Creating the CLI application to write the serialised data to a file using this schema.
- Creating the CLI application to read the serialised data from a file using this schema.

I have divided the whole code into a pluggable class named `Parser`.

1.  After creating each row for the table, `Parser::createTableRow()` returns an `OStreamBuffer` object which consists of the buffer and its size.
2.  This buffer can be written to the disk using `Parser::writeToDisk()` function.
3.  The logic for handling the arguments is kept only in the `main.cpp`

### Example Output

![Example Output](https://user-images.githubusercontent.com/54344426/161621957-078941b9-3fc7-401e-b44b-914ed424b0a7.png)

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

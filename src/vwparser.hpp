#pragma once

#include <string>

#include <bits/stdc++.h>

#include "flatbuffers/flatbuffers.h"
#include "schema_generated.h"
#include <fstream>
#include <iostream>

class OStreamBuffer
{
  uint8_t *buf;
  int _size;

public:
  OStreamBuffer(uint8_t *buf, int size);
  const char *get_buffer();
  flatbuffers::uoffset_t size();
};

class Parser
{
  flatbuffers::FlatBufferBuilder fbb;

public:
  OStreamBuffer *createTableRow(std::string a_name, float a_float, bool a_flag);
  void writeToDisk(OStreamBuffer *buf, std::string file_name);
  const VW::parser::MyTable *readFromDisk(std::string file_name);
  void printRow(const VW::parser::MyTable *row);
  void take_input(std::string *a_name,
                  float *a_float,
                  bool *a_flag,
                  std::string *file_name);
};

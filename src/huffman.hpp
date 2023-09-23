#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "record.hpp"

#include <string>
#include <vector>
#include <fstream>

struct Huffman {
  Record reg;
  char *code;
  Huffman *left, *right;
};

Huffman *huffmanCreate();
Huffman *huffmanBuild(std::vector<std::pair<std::wstring,
                                  unsigned short>> heap);

void huffmanPreorder(Huffman *t, std::wofstream &output);
void huffmanInorder(Huffman *t, std::wofstream &output);
void huffmanPosorder(Huffman *t, std::wofstream &output);

void huffmanDestroy(Huffman **t);

#endif /* HUFFMAN_H */

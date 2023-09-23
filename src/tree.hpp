#ifndef TREE_H
#define TREE_H

#include "record.hpp"
#include <fstream>

struct Tree {
  Record reg;
  Tree *left, *right;
};

Tree* treeCreate();
bool treeEmpty(const Tree *t);
Tree *treeNewLeaf(Record r);
void treeInsert(Tree **t, Record r);

void treeFind(Tree **t, Tree **aux, Record r);

void treeRemove(Tree **t, Record r);
void treePredecessor(Tree **t, Tree *aux);

void treePreorder(Tree *t, std::wofstream &output);
void treeInorder(Tree *t, std::wofstream &output);
void treePosorder(Tree *t, std::wofstream &output);

void treeDestroy(Tree **t);

#endif /* TREE_H */

#ifndef AVL_H 
#define AVL_H

#include "record.hpp"
#include <fstream>

struct Avl {
  Record reg;
  int weight;
  Avl *left, *right;
};

Avl* avlCreate();
void avlInsert(Avl **t, Record r);

void avlRemove(Avl **t, Avl **f, Record r);
void avlPredecessor(Avl **t, Avl *aux);
void avlRebalance(Avl **t);

void avlPreorder(Avl *t, std::wofstream &output);
void avlInorder(Avl *t, std::wofstream &output);
void avlPosorder(Avl *t, std::wofstream &output);

int getWeight(Avl **t);
int getMaxWeight(int left, int right);

void simple_right_rotation(Avl **t);
void simple_left_rotation(Avl **t);
void double_right_rotation(Avl **t);
void double_left_rotation(Avl **t);

void avlDestroy(Avl **t);

#endif

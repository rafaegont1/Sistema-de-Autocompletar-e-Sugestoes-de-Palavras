#include "tree.hpp"

#include <cstdlib>

Tree* treeCreate() { return nullptr; }

bool treeEmpty(const Tree *t) { return t == nullptr; }

Tree *treeNewLeaf(Record r)
{
  Tree *new_leaf = new Tree;

  new_leaf->reg = r;
  new_leaf->left = new_leaf->right = nullptr;

  return new_leaf;
}

void treeInsert(Tree **t, Record r)
{
  if (treeEmpty(*t)) {
    *t = new Tree;
    (*t)->left = (*t)->right = nullptr;
    (*t)->reg = r;
  } else {
    if (r.key < (*t)->reg.key) treeInsert(&(*t)->left, r);
    else treeInsert(&(*t)->right, r);
  }
}

void treeFind(Tree **t, Tree **aux, Record r) {
  if (*t != nullptr) {
    if ((*t)->reg.key > r.key) { treeFind(&(*t)->left, aux, r); return; }
    if ((*t)->reg.key < r.key) { treeFind(&(*t)->right, aux, r); return; }
  }

  *aux = *t;
}

void treePredecessor(Tree **t, Tree *aux) {
  if ((*t)->right != nullptr) {
    treePredecessor(&(*t)->right, aux);
    return;
  }

  aux->reg = (*t)->reg;
  aux = *t;
  *t = (*t)->left;
  free(aux);
}

void treeRemove(Tree **t, Record r) {
  Tree *aux;

  if (*t == nullptr) {
    return;
  }

  if (r.key < (*t)->reg.key) { treeRemove(&(*t)->left, r); return; }
  if (r.key > (*t)->reg.key) { treeRemove(&(*t)->right, r); return; }

  if ((*t)->right == nullptr) {
    aux = *t;
    *t = (*t)->left;
    free(aux);
    return;
  }

  if ((*t)->left != nullptr) { treePredecessor(&(*t)->left, *t); return; }

  aux = *t;
  *t = (*t)->right;
  free(aux);
}

void treePreorder(Tree *t, std::wofstream &output)
{
  if (t != nullptr) {
    output << t->reg.word << ": " << t->reg.key << '\n';
    treeInorder(t->left, output);
    treeInorder(t->right, output);
  }
}

void treeInorder(Tree *t, std::wofstream &output)
{
  if (t != nullptr) {
    treePosorder(t->left, output);
    output << t->reg.word << ": " << t->reg.key << '\n';
    treePosorder(t->right, output);
  }
}

void treePosorder(Tree *t, std::wofstream &output)
{
  if (t != nullptr) {
    treePosorder(t->left, output);
    treePosorder(t->right, output);
    output << t->reg.word << ": " << t->reg.key << '\n';
  }
}

void treeFree(Tree *t)
{
  if (t != nullptr) {
    treeFree(t->left);
    treeFree(t->right);
    delete t;
  }
}

void treeDestroy(Tree **t)
{
  treeFree(*t);
  *t = nullptr;
}

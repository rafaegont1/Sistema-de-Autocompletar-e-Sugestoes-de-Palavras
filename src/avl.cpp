#include "avl.hpp"

#include <cstdlib>

Avl* avlCreate() { return nullptr; }

void avlInsert(Avl **t, Record r) {
  if (*t == nullptr) {
    *t = new Avl;
    (*t)->left   = nullptr;
    (*t)->right  = nullptr;
    (*t)->weight = 0;
    (*t)->reg    = r;
    return;
  }

  if (r.key < (*t)->reg.key) {
    avlInsert(&(*t)->left, r);

    if ((getWeight(&(*t)->left) - getWeight(&(*t)->right)) == 2) {
      if (r.key < (*t)->left->reg.key) simple_right_rotation(t);

      else double_right_rotation(t);
    }
  }

  else {
    avlInsert(&(*t)->right, r);

    if ((getWeight(&(*t)->right) - getWeight(&(*t)->left)) == 2) {
      if (r.key >= (*t)->right->reg.key) simple_left_rotation(t);

      else double_left_rotation(t);
    }
  }

  (*t)->weight = getMaxWeight(getWeight(&(*t)->left),
                              getWeight(&(*t)->right)) + 1;
}

void avlPredecessor(Avl **t, Avl *tmp) {
  if ((*t)->right != nullptr) {
    avlPredecessor(&(*t)->right, tmp);
    return;
  }

  tmp->reg = (*t)->reg;
  tmp = *t;
  *t = (*t)->left;
  free(tmp);
}

void avlRebalance(Avl **t){
  int balance;
  int left = 0;
  int right = 0;

  balance = getWeight(&(*t)->left) - getWeight(&(*t)->right);
  if ((*t)->left)
    left = getWeight(&(*t)->left->left) - getWeight(&(*t)->left->right);
  if ((*t)->right)
    right = getWeight(&(*t)->right->left) - getWeight(&(*t)->right->right);

  if (balance == 2 && left >= 0) simple_right_rotation(t);
  if (balance == 2 && left < 0) double_right_rotation(t);

  if (balance == -2 && right <= 0) simple_left_rotation(t);
  if (balance == -2 && right > 0) double_left_rotation(t);

}

void avlRemove(Avl **t, Avl **f, Record r) {
  Avl *tmp;

  if (*t == nullptr) {
    wprintf(L"[ERROR]: Record not found!!!\n");
    return;
  }

  if (r.key < (*t)->reg.key){ avlRemove(&(*t)->left, t, r); return; }
  if (r.key > (*t)->reg.key){ avlRemove(&(*t)->right, t, r); return; }

  if ((*t)->right == nullptr) {
    tmp = *t;
    *t = (*t)->left;
    free(tmp);
    avlRebalance(f);
    return;
  }

  if ((*t)->left != nullptr) {
    avlPredecessor(&(*t)->left, *t);
    avlRebalance(t);
    avlRebalance(f);
    return;
  }

  tmp = *t;
  *t = (*t)->right;
  free(tmp);
  avlRebalance(t);
  avlRebalance(f);

}

void avlPreorder(Avl *t, std::wofstream &output)
{
  if (!(t == nullptr)) {
    output << t->reg.word << L" : " << t->reg.key
           << L" : " << t->weight << L'\n';
    avlPreorder(t->left, output);
    avlPreorder(t->right, output);
  }
}

void avlInorder(Avl *t, std::wofstream &output)
{
  if (!(t == nullptr)) {
    avlInorder(t->left, output);
    output << t->reg.word << L" : " << t->reg.key
           << L" : " << t->weight << L'\n';
    avlInorder(t->right, output);
  }
}

void avlPosorder(Avl *t, std::wofstream &output)
{
  if (!(t == nullptr)) {
    avlPosorder(t->left, output);
    avlPosorder(t->right, output);
    output << t->reg.word << L" : " << t->reg.key
           << L" : " << t->weight << L'\n';
  }
}

int getWeight(Avl **t) {
  if (*t == nullptr) return -1;
  return (*t)->weight;
}

int getMaxWeight(int left, int right) {
  if (left > right) return left;
  return right;
}

void simple_right_rotation(Avl **t) {
  Avl *tmp;

  tmp = (*t)->left;
  (*t)->left = tmp->right;
  tmp->right = (*t);
  (*t)->weight = getMaxWeight(getWeight(&(*t)->left),
                              getWeight(&(*t)->right)) + 1;
  tmp->weight  = getMaxWeight(getWeight(&tmp->left), (*t)->weight) + 1;
  (*t) = tmp;
}

void simple_left_rotation(Avl **t) {
  Avl *tmp;

  tmp = (*t)->right;
  (*t)->right = tmp->left;
  tmp->left = (*t);
  (*t)->weight = getMaxWeight(getWeight(&(*t)->left),
                              getWeight(&(*t)->right)) + 1;
  tmp->weight  = getMaxWeight(getWeight(&tmp->left), (*t)->weight) + 1;
  (*t) = tmp;
}

void double_right_rotation(Avl **t) {
  simple_left_rotation(&(*t)->left);
  simple_right_rotation(t);
}

void double_left_rotation(Avl **t) {
  simple_right_rotation(&(*t)->right);
  simple_left_rotation(t);
}

void avlFree(Avl *t)
{
  if (t != nullptr) {
    avlFree(t->left);
    avlFree(t->right);
    delete t;
  }
}

void avlDestroy(Avl **t)
{
  avlFree(*t);
  *t = nullptr;
}

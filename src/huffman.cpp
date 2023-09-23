#include "huffman.hpp"
#include <cstring>
#include <queue>

struct cmp {
  bool operator()(Huffman *a, Huffman *b) { return (a->reg.key > b->reg.key); }
};

void huffmanDecode(Huffman *t, const std::string &code = "") {
  if (t == nullptr) return;

  huffmanDecode(t->left, code + '0');
  huffmanDecode(t->right, code + '1');

  if (t->left == nullptr && t->right == NULL) t->code = strdup(code.c_str());
}

Huffman *huffmanBuild(std::vector<std::pair<std::wstring,
                                  unsigned short>> heap)
{
  std::priority_queue<Huffman*, std::vector<Huffman*>, cmp> pq;

  for (const auto &word : heap) {
    Huffman *new_leaf = new Huffman;

    new_leaf->reg = Record(word.second, word.first.c_str());
    new_leaf->left = new_leaf->right = nullptr;

    pq.push(new_leaf);
  }

  while (pq.size() > 1) {
    Huffman *merged = new Huffman;

    merged->reg.word = nullptr;
    merged->code = nullptr;

    merged->reg.key = pq.top()->reg.key;
    merged->left = pq.top();
    pq.pop();

    merged->reg.key += pq.top()->reg.key;
    merged->right = pq.top();
    pq.pop();

    pq.push(merged);
  }

  huffmanDecode(pq.top());

  return pq.top();
}

void huffmanPreorder(Huffman *t, std::wofstream &output)
{
  if (t != nullptr) {
    if (t->code != nullptr) {
      output << t->reg.word << L" : " << t->reg.key
             << L" : " << t->code << L'\n';
    }
    huffmanPreorder(t->left, output);
    huffmanPreorder(t->right, output);
  }
}

void huffmanInorder(Huffman *t, std::wofstream &output)
{
  if (t != nullptr) {
    huffmanInorder(t->left, output);
    if (t->code != nullptr) {
      output << t->reg.word << L" : " << t->reg.key
             << L" : " << t->code << L'\n';
    }
    huffmanInorder(t->right, output);
  }
}

void huffmanPosorder(Huffman *t, std::wofstream &output)
{
  if (t != nullptr) {
    huffmanPosorder(t->left, output);
    huffmanPosorder(t->right, output);
    if (t->code == nullptr) return;
    output << t->reg.word << L" : " << t->reg.key
           << L" : " << t->code << L'\n';
  }
}

void huffmanFree(Huffman *t)
{
  if (t != nullptr) {
    huffmanFree(t->left);
    huffmanFree(t->right);
    delete t;
  }
}

void huffmanDestroy(Huffman **t)
{
  huffmanFree(*t);
  *t = nullptr;
}

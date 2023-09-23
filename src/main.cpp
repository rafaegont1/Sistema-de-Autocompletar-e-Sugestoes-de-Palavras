#include "utils.hpp"
#include "tree.hpp"
#include "avl.hpp"
#include "huffman.hpp"

#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <chrono>

#define endl L'\n'

using namespace std;

const int HEAP_SIZE = 20;
const wchar_t *word_end = L".!? ,:;()'\"-/\n";
const wchar_t *TRACE = L"__________________________________________________";

int main()
{
  auto start = chrono::high_resolution_clock::now();

  setlocale(LC_ALL, "pt_BR.UTF-8");
  locale loc(locale(), new codecvt_utf8<wchar_t>);

  int file_number = 1;
  wchar_t *buffer = getText(loc, file_number);
  unordered_map<wstring, unsigned short> mp;
  unordered_set<wstring> stop_words;
  wofstream output = createOutput(loc);

  getStopWords(loc, stop_words);

  // Put all words of the inputs on a map
  // (except stop words defined in 'stopwords.txt')

  while(buffer != nullptr) {
    wstring word;

    for (wchar_t *c = buffer; *c; c++) {
      if (!wcschr(word_end, *c)) {
        word += tolower(*c);
      } else if (!word.empty()) {
        if (!stop_words.count(word)) ++mp[word];
        word.clear();
      }
    }

    delete[] buffer;
    buffer = getText(loc, file_number);
  }

  // Search for K most frequent words
  // (K is defined by HEAP_SIZE)

  auto mp_it = mp.begin();
  vector<pair<wstring, unsigned short>> heap;
  pair<wstring, unsigned short> k_plus_one;

  for (int i = 0; i < HEAP_SIZE && mp_it != mp.end(); i++, mp_it++) {
    heap.push_back(*mp_it);
  }

  make_heap(heap.begin(), heap.end(), min_heap);

  while (mp_it != mp.end()) {
    if (mp_it->s > heap.front().s) {
      k_plus_one = heap.front();
      heap.front() = *mp_it;
      make_heap(heap.begin(), heap.end(), min_heap);
    }
    ++mp_it;
  }

  wcout << L"~~~> Original heap <~~~\n" << endl;
  for (const auto &word : heap) {
    wcout << word.f << L": " << word.s << endl;
  }

  // Search for words in input

  vector<wstring> input;

  getInput(loc, input);

  for (const auto &word : input) {
    if (!mp.count(word)) {
      wcout << L"\n~~~> The \"" << word
            << L"\" word isn't present on the texts <~~~"
            << endl;
      continue;
    }

    vector<pair<wstring, unsigned short>> tmp_heap = heap;
    auto heap_it = find_if(tmp_heap.begin(), tmp_heap.end(), Find(word));

    if (heap_it != tmp_heap.end()) {
      tmp_heap.erase(heap_it);
      tmp_heap.push_back(k_plus_one);
      make_heap(tmp_heap.begin(), tmp_heap.end(), min_heap);
    }

    output << L"~~~> \"" << word << L"\" word <~~~" << endl;

    wcout << L"\n~~~> Heap of \"" << word << L"\" word <~~~\n" << endl;
    for (const auto &node : tmp_heap) {
      wcout << node.f << L": " << node.s << endl;
    }

    // --- Basic tree ---

    Tree *tree = treeCreate();

    for (const auto &node : tmp_heap) {
      treeInsert(&tree, Record(node.s, node.f.c_str()));
    }

    output << L"\n---> Basic tree <---\n"
              L"\n-Preorder-" << endl;
    treePreorder(tree, output);
    output << L"\n-Inorder-" << endl;          
    treeInorder(tree, output);
    output << L"\n-Posorder-" << endl;
    treePosorder(tree, output);

    treeDestroy(&tree);

    // --- AVL tree ---

    Avl *avl = avlCreate();

    for (const auto &node : tmp_heap) {
      avlInsert(&avl, Record(node.s, node.f.c_str()));
    }

    output << L"\n--- AVL tree ---\n"
              L"\n-Preorder-" << endl;
    avlPreorder(avl, output);
    output << L"\n\n-Inorder-" << endl;
    avlInorder(avl, output);
    output << L"\n\n-Posorder-" << endl;
    avlPosorder(avl, output);

    avlDestroy(&avl);

    // --- Huffman tree ---

    Huffman *huffman = huffmanBuild(tmp_heap);

    output << L"\n---> Huffman tree <---\n"
             L"\n-Preorder-" << endl;
    huffmanPreorder(huffman, output);
    output << L"\n\n-Inorder-" << endl;
    huffmanInorder(huffman, output);
    output << L"\n\n-Posorder-" << endl;
    huffmanPosorder(huffman, output);
    output << '\n' << TRACE << '\n' << endl;

    huffmanDestroy(&huffman);
  }

  // Close output file
  output.close();

  // Show execution time in milliseconds

  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>
                  (stop - start);
  wcout << '\n' << duration.count() << L" ms" << endl;

  return 0;
}

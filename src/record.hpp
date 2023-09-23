#ifndef RECORD_HPP
#define RECORD_HPP

#include <cwchar>
#include <cstdlib>

struct Record {
  int key;
  const wchar_t *word;
  
  Record() {}
  Record(int key, const wchar_t *word) : key(key), word(wcsdup(word)) {}
  
//  virtual ~Record() {
//    if (word != nullptr) {
//      free(const_cast<wchar_t*>(word));
//    }
//  }
};

#endif /* RECORD_HPP */

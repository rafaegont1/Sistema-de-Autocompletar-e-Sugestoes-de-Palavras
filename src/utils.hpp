#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <unordered_set>
#include <codecvt>

#define f first
#define s second

#define RED "\x1b[1;31m"
#define CYAN "\x1b[1;36m"
#define NO_COLOR "\x1b[0;0m"

struct Find {
  Find(const std::wstring &st) : s(st) {}
  const std::wstring s;
  bool operator()(const std::pair<std::wstring,
                  unsigned short> &word) const
    { return word.first == s; }
};

std::wofstream createOutput(const std::locale &loc);
wchar_t *getText(const std::locale &loc, int &file_number);
void getStopWords(const std::locale &loc,
                  std::unordered_set<std::wstring> &set);
void getInput(const std::locale &loc,
              std::vector<std::wstring> &input);
bool min_heap(const std::pair<std::wstring, int> &a,
              const std::pair<std::wstring, int> &b);
bool max_heap(const std::pair<std::wstring, int> &a,
              const std::pair<std::wstring, int> &b);

#endif /* UTILS_HPP */

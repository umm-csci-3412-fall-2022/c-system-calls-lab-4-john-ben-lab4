#ifndef DISEMVOWEL_H_GUARD
#define DISEMVOWEL_H_GUARD

struct DisemvowelOutput {
  int size;
  char* disemvoweled;
};

struct DisemvowelOutput disemvowel(char *str);

#endif

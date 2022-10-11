#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

int isVowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
  || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

char *disemvowel(char *str) {
  int consonantCount = 0;
  int strLength = strlen(str);
  for (int i = 0; i < strLength; i++) {
    if (!isVowel(str[i])) {
      consonantCount++;
    }
  }

  char *output = (char*)calloc(consonantCount + 1, sizeof(char));
  int consonantPos = 0;
  for (int i = 0; consonantPos < consonantCount; i++) {
    if (!isVowel(str[i])) {
      output[consonantPos++] = str[i];
    }
  }
  output[consonantCount] = '\0';

  return output;
}

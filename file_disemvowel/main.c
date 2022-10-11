#include <stdio.h>
#include <stdlib.h>
#include "disemvowel.h"

void disemvowelFile(FILE* inputFile, FILE* outputFile) {
  const int BUFFER_SIZE = 512;
  char* inputBuffer = (char*) malloc(BUFFER_SIZE * sizeof(char));
  char* outputBuffer;
  int chunkSize;

  do {
    chunkSize = fread(inputBuffer, sizeof(char), BUFFER_SIZE, inputFile);
    outputBuffer = disemvowel(inputBuffer);
    fwrite(outputBuffer, sizeof(char), (chunkSize == BUFFER_SIZE ? chunkSize : chunkSize - 3), outputFile);
    free(outputBuffer);
  } while (chunkSize == BUFFER_SIZE);
}

int main(int argc, char *argv[]) {
  FILE* inputFile = stdin;
  FILE* outputFile = stdout;

  switch (argc) {
    case 3:
      outputFile = fopen(argv[2], "w");
    case 2:
      inputFile = fopen(argv[1], "r");
    case 1:
      break;
    default:
      printf("Usage is file_disemvowel inputFile? outputFile?\n");
      return 1;
  }

  disemvowelFile(inputFile, outputFile);

  if (argc == 2) {
    fclose(inputFile);
  }
  if (argc == 3) {
    fclose(outputFile);
  }

  return 0;
}

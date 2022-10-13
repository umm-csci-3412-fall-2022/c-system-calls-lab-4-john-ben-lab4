#include <stdio.h>
#include <stdlib.h>
#include "disemvowel.h"

void disemvowelFile(FILE* inputFile, FILE* outputFile) {
  const int BUFFER_SIZE = 1024;
  char* inputBuffer = (char*) calloc((BUFFER_SIZE + 1), sizeof(char));
  int chunkSize;

  struct DisemvowelOutput output;
  if(inputBuffer==NULL){printf("inputbuffer is sad\n");}
  //printf("Before the loop...\n");
  do {
    chunkSize = fread(inputBuffer, sizeof(char), BUFFER_SIZE, inputFile);
  //  printf("Read in %d characters\n",chunkSize);
    inputBuffer[chunkSize]='\0';
  //  printf("Pre disemvowel...\n");
    output = disemvowel(inputBuffer);
   // printf("Reading %d bytes and writing %s\n",chunkSize,output.disemvoweled);
    fwrite(output.disemvoweled, sizeof(char), output.size, outputFile);
    free(output.disemvoweled);
  } while (chunkSize == BUFFER_SIZE);
  free(inputBuffer);
}

int main(int argc, char *argv[]) {
  FILE* inputFile = stdin;
  FILE* outputFile = stdout;

  switch (argc) {
    case 3:
      outputFile = fopen(argv[2], "w+");
    case 2:
      inputFile = fopen(argv[1], "r");
    case 1:
      break;
    default:
      printf("Usage is file_disemvowel inputFile? outputFile?\n");
      return 1;
  }

  disemvowelFile(inputFile, outputFile);

  if (argc >= 2) {
    fclose(inputFile);
  }
  if (argc == 3) {
    fclose(outputFile);
  }

  return 0;
}

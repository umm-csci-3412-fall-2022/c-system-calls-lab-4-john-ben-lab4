#include <stdio.h>
#include <ftw.h>


static int num_dirs, num_files;

static int callback(const char* fpath, const struct stat *sb, int typeflag) {
  if (typeflag == FTW_F) {
    num_files++;
  } else {
    num_dirs++;
  }
  return 0;
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: %s <path>\n", argv[0]);
    printf("        where <path> is the file or root of the tree that you want to summarize.\n");
    return 1;
  }

  num_dirs = 0;
  num_files = 0;

  ftw(argv[1], callback, MAX_FTW_DEPTH);

  printf("There were %d directories.\n", num_dirs);
  printf("There were %d regular files.\n", num_files);

  return 0;
}

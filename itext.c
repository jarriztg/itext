#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "formats.h"

int main(int n, char *texto[]) {
  if (n>1) {

    if (!strcmp(texto[1], "-u")) {
      if (n>2) {
        underlined(texto[2]);
      } else {
        print("A text required");
      };
    };

  if (!strcmp(texto[1], "-i")) {
    if (n>2) {
      italics(texto[2]);
    } else {
      print("A text required");
    };
  }

  if (!strcmp(texto[1], "-c")) {
    if (n>2) {
      circles(texto[2]);
    } else {
      print("A text required");
    };
  }

  } else {
    print("A argument required, use itext -h to help you.");
  };
}

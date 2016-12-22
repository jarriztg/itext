#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "formats.h"

int main(int n, char *texto[]) {
  char *ERROR[2];
  ERROR[1] = "A text required.";
  ERROR[2] = "A argument required, use itext -h to help you.";

  if (n>1) {
    char *se_inicio = strstr(texto[1], "-");
    if (se_inicio) {

      if (strstr(texto[1], "ui")) {
        if (n>2) {
          italics_underlined(texto[2]);
        } else {
          print("A text required");
        };
      };

      if (strstr(texto[1], "u")) {
        if (n>2) {
          underlined(texto[2]);
        } else {
          print("A text required");
        };
      };

      if (strstr(texto[1], "i")) {
        if (n>2) {
          italics(texto[2]);
        } else {
          print("A text required");
        };
      };

      if (strstr(texto[1], "c")) {
        if (n>2) {
          circles(texto[2]);
        } else {
          print("A text required");
        };
      };

  };
  } else {
    print(ERROR[2]);
  };
}

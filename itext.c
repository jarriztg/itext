#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "plus.h"
#define BUFFER 256
#define MAX 2

int main(int n, char *texto[]) {
 char *ERROR[MAX];
 ERROR[1] = "A text required.";
 ERROR[2] = "use itext --help to help you.";
 if(n>1){
  char format[BUFFER], j;
  if(!strcmp(texto[1], "--help")) {
    printf("Use: %s\n%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n", "itext -[options] \"your text\"",
    "Options:",
    "h: highlight.",
    "c: circles.",
    "b: bold.",
    "u: underlined.",
    "s: strikethrough.",
    "i: italics");
    exit(0);
  };
  strcpy(format, "\033[");
    switch (texto[1][0]) {
      case '-':
      for(j=strlen(texto[1]);j>0;j--)
        switch (texto[1][j]) {
          case 'b':
              strcat(format, ";1");
              break;
          case 'u':
              strcat(format, ";4");
            break;
          case 'h':
              strcat(format, ";7");
              break;
          case 's':
              strcat(format, ";9");
              break;
          case 'i':
              strcat(format, ";3");
              break;
          case 'c':
              break;
          default:
           if(texto[1][j]){
              printf("Argument '%c' invalid, %s\n", texto[1][j], ERROR[2]);
              return 0;
          };
          };
              break;
      default:
        printf("Argument required, %s\n", ERROR[2]); break;
        exit(0);
    };
    char *text;
    if(strstr(texto[1], "c")) {
      text = __circles(texto[2]);
    } else {
      text = texto[2];
    };
    printf("%sm%s\033[0m\n", format, text);
    return 0;
  } else {
    printf("Argument required, %s\n", ERROR[2]);
  };
}

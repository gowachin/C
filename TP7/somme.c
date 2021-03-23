#include <stdio.h>

int char2int(char c[]){
  int val = 0;
  val = val + c[0] - '0';
  for(int i = 1 ; c[i] != '\0' ; i++){
        val = val * 10 + (c[i] - '0');
    }
  return val;
}

int main (int argc, char *argv[]) {
  int i ;
  int s = 0 ;
  for (i=1 ; i<argc ; i++){
    s = s + char2int(argv[i]);
    printf("%s ", argv[i]) ;
    if(i != argc-1)
      printf("+ ");
  }
  printf("= %d", s);
  printf("\n");
  return 0;
}
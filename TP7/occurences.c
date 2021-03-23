#include <stdio.h>

int main(int argc, char *argv[]){
    FILE* f;
    int list[128];
    char c;
    // init list to 0
    for (int i = 0; i < 128; i++){
        list[i] = 0;
    }
    // open file
    f = fopen( argv[1], "r");
    if ( f == NULL){
        printf("Rentrez un nom de ficher");
        return 1;
    }
    // scan file
    fscanf(f, "%c", &c);
    list[c]++;
    while(!feof(f)){
        fscanf(f, "%c", &c);
        list[c]++;
    }
    // print value
    for (int i = 32; i < 127; i++){ 
        // on évite les caractères spéciaux (saut de ligne) et DEL
        if(list[i] > 0){
            printf("Il y a %d occurences du caractère '%c'\n", list[i], i);
        }
    }
    
    return 0;
}

#include <stdio.h>
#include <string.h>

int main(int argc,char* argv[]){
    FILE *f;
    FILE *g;
    f = fopen(argv[1], "r");
    g = fopen("temp.c", "w");
    char c;
    int i = 0;

    fscanf(f,"%c",&c);
    while(!(feof(f))){

        if(((c=='"' && i==0) || i==2) && i!=3){
            fprintf(g,"%c",c);
            if(i==0){
                i=2;
            } else if(i==2 && c=='"'){
                i=0;
            }

        }
        else if((c== '\\' && i==0) || i==3){
            fprintf(g,"%c",c);
            if(i==0){
                i=3;
            } else{
                i=0;
            }
        }
        else if(c=='\n'){
            fprintf(g,"%c",c);
            i = 0;
        }
        else if(c=='#' || i==1){
            fprintf(g,"%s","");
            i = 1;
        }
        else {
            fprintf(g,"%c",c);
        }


        fscanf(f,"%c",&c);
    }

    fclose(f);
    fclose(g);
    rename( "temp.c", argv[1]);
    return 0;
}
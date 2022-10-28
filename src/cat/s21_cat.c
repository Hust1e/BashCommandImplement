#define MAX 128
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
  int newLine;
  int counterB;
  int counterS;
  int emptyLine;
  int numberFiles;
} options;

void checkFlag(int argc, char** argv, options *config);
void printData(options *config, FILE *fp);

int main(int argc, char* argv[]){
    FILE *fp;
    options config = {0};
   if((fp = fopen(argv[argc - 1], "r")) != NULL){
       checkFlag(argc, argv, &config);
       printData(&config, fp);
       fclose(fp);
   } else {
       printf("Not exist");
   }
}

void checkFlag(int argc, char** argv, options *config){
        for(int i=1; i<argc-1; i++)
    {
        if(!strcmp(argv[i], "-b")){
            config->b = 1;
        }
        if(!strcmp(argv[i], "-e")){
            config->e = 1;
        }
        if(!strcmp(argv[i], "-n")){
            config->n = 1;
        }
        if(!strcmp(argv[i], "-s")){
            config->s = 1;
        }
    }
}
void printData(options *config, FILE *fp){
    char str[MAX];
    int str_count = 1;
    int counter = 0;
    char ch;
    if(config->b == 1) {
        while((ch=fgetc(fp)) !=EOF) {
        if (ch != '\n') {
            if(counter == 0){
                printf("%6d\t", str_count);
                counter = 1;
                str_count ++;
            }
            printf("%c",ch);
        } else {
            printf("%c", ch);
            counter = 0;
        }
    }
    }
    if(config->e == 1) {
        while((ch=fgetc(fp)) !=EOF) {
            if(ch == '\n'){
                printf("$");
            }
            printf("%c", ch);
        }
    }
    if(config->n == 1) {
        while((ch=fgetc(fp)) !=EOF) {
            if (ch != '\n') {
                if(counter == 0){
                    printf("%6d\t", str_count);
                    counter = 1;
                    str_count ++;
                }
                printf("%c",ch);
            } else {
                printf("%c", ch);
                counter = 0;
            }
        }
    }
    if(config->s == 1) {
        while((ch=fgetc(fp)) !=EOF) {
            if (ch != '\n') {
                if(counter == 0){
                    printf("%6d\t", str_count);
                    counter = 1;
                    str_count ++;
                }
                printf("%c",ch);
            } else {
                printf("%c", ch);
                counter = 0;
            }
        }
    }
}
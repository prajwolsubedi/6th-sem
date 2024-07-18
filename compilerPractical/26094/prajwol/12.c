
#include <stdio.h>
#include <string.h>
  int main(){
FILE *fp;
fp = fopen("output.txt", "w");
fprintf(fp, "MOV R0, b\n");
fprintf(fp, "MUL R0, c\n");
fprintf(fp, "MOV t1, R0\n");
// Generate machine code for t2 = a + t1 fprintf(fp, "MOV R0, a\n");
fprintf(fp, "ADD R0, t1\n");
fprintf(fp, "MOV t2, R0\n");
return 0; 
}
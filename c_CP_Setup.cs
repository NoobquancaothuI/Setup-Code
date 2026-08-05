#include <stdio.h>
//clean code competitive
void file(const char *name) {if(name[0]=='\0') return;char in[100],out[100];sprintf(in,"%s.inp",name);sprintf(out,"%s.out",name);freopen(in,"r",stdin);freopen(out,"w",stdout);}



int main(void) {
    file("");
    
}

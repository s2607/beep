#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<unistd.h>
#define R 8000
double fr;

void dieif(char *m, int r) {
	if(r){
		printf("%s\n",m);
		exit(1);
	}
}
float f(int x) {
		return(sin(x*(fr/R))*100);
}
int main(int argc,char **argv) {
	double l;
	int i=0;
	dieif("Usage: beep 4500 0.05",(argc!=3));
	FILE *fp=popen("aplay -t raw >/dev/null","w");
	dieif("crap",!fp);
	fr=atof(*(argv+1));
	l=atof(*(argv+2));
	
	for(i=0;i<l*R;i++) {
		fputc(f(i)+128,fp);
		printf("%f ",f(i));
	}
	dieif("eh",fclose(fp));
	return 0;
}



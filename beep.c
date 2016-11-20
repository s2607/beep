#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define R 8000
#define PI 3.14159
double fr;
void dieif(char *m, int r) {
	if(r){
		printf("%s\n",m);
		exit(1);
	}
}
int fofkey(int k)
{
	k=k+49; //move to middle of keyboard
	return pow(2,(k-49)/12.)*440;
}
float f(int x) {
		return(sin(x*(fr/R)*2*PI)*100);
}
int main(int argc,char **argv) {
	double l;
	int i=0;
	if(argc==1){
		fr=440;
		l=0.05;
	}else{
		dieif("Usage: beep 440 0.05 \n#This beeps A4 for half a tenth of a second.\nbeep A 0.05\n#exactly the same.",(argc!=3));
		fr=atof(*(argv+1));
		if(!fr)
			fr=fofkey(**(argv+1)-'A');
		l=atof(*(argv+2));
	}
	FILE *fp=popen("aplay -r 8000 -q -t raw >/dev/null","w");
	dieif("crap",!fp);
	for(i=0;i<l*R;i++) 
		fputc(f(i)+128,fp);
	dieif("eh",fclose(fp));
	return 0;
}

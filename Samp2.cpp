#include<iostream>
//#include<ncurses.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include<fstream>

using namespace std;

void I_Pat(int x, int y);
void _Pat(int x, int y);
void L_Pat(int x, int y);
void S_Pat(int x, int y);
int p=1,h;
char *GetFirst(char str[5000]){

	char *word = new char[20];
	int j=0;
	for(int i=0;str[i]!='\0';i++){

		if(str[i]!=' '){

			word[j++]=str[i];
		}
		else{
			word[j++]='\0';
			break;	
		}
	}
	return word;
}

void GetCoordinates(char s[3000]){

	int i,j,l=0;
	int x=0,y=0;
	int x1=0,y1=0;
	int right=0,left=0,top=0,bot=0;
	int ver=0,hori=0;
	int flag=1;
	int temp=0;
	int count1=0,count2=0;
	//for(i=0;s[i]!='\0';i++){
	//	s.word[l]=s[i];
	//}
	for(i=0;s[i]!='\0';i++)
	{
		if((s[i]=='l')&& (s[i+1]=='e')&& (s[i+2]=='f') &&(s[i+3]=='t'))
			left++;
		if((s[i]=='r')&& (s[i+1]=='i')&& (s[i+2]=='g') &&(s[i+3]=='h')&& (s[i+4]=='t'))
			right++;
		if((s[i]=='t')&& (s[i+1]=='o') &&(s[i+2]=='p'))
			top++;
		if((s[i]=='b')&& (s[i+1]='o')&& (s[i+2]=='t') && (s[i+3]=='t')&& (s[i+4]=='o')&& (s[i+5]=='m'))
			bot++;
	}
		ver=right+left+1;
		hori=top+bot+1;
		x1=15/ver;
		y1=11/hori;
		//move(y,x);
			for(i=0;s[i]!='\0';i=temp+1){
				for(j=i;s[j]!='.';j++)
				{
					if((s[j]=='l')&& (s[j+1]=='e')&& (s[j+2]=='f') &&(s[j+3]=='t')){
						flag=0;
					}	
					if((s[j]=='r')&& (s[j+1]=='i')&& (s[j+2]=='g') &&(s[j+3]=='h')&& (s[j+4]=='t')){
						x=x+x1;
						//move(y,x);
						
					}
					if((s[j]=='t')&& (s[j+1]=='o') &&(s[j+2]=='p')){
						flag=0;
					}
					if((s[j]=='b')&& (s[j+1]='o')&& (s[j+2]=='t') && (s[j+3]=='t')&& (s[j+4]=='o')&& (s[j+5]=='m')){
						y=y+y1;
						//move(y,x);
						
					}
				}
				temp=j;
			}
			if(p==1){
				_Pat(x,y);
				p++;
			}
			else if(p==2){
				I_Pat(x,y);
				p++;
			}
			else if(p==3){
				L_Pat(x,y);
				p++;
			}
			else if(p==4){
				S_Pat(x,y);
				p++;
			}
			
}

void I_Pat(int x, int y){

	FILE *fp;
	fp = fopen("Coordinates1.txt","a+");
	for(int i=0;i<4;i++){
		fprintf(fp,"%d,%d|",x,y);
		//move(y++,x);
		//printw("*");
		y++;
	}
	fprintf(fp,"\n");
	fclose(fp);
}

void _Pat(int x, int y){

	FILE *fp;
	fp = fopen("Coordinates1.txt","w+");	
	for(int i=0;i<4;i++){
		fprintf(fp,"%d,%d|",x,y);
		//move(y,x++);
		//printw("*");
		x++;
	}
	fprintf(fp,"\n");
	fclose(fp);
}

void L_Pat(int x,int y){
	int r,c,X;
	FILE *fp;
	fp = fopen("Coordinates1.txt","a+");
	for(r=0;r<4;r++)
	{
		X=x;
		for(c=0;c<4;c++)
		{
			
			if((c==0||r==3)){
				//printw("*");
				fprintf(fp,"%d,%d|",X,y);
				X=X+1;
				//move(y,X);
			}
			//else{
				//printw("");
			//}
		}
	//move(++y,x);
	++y;
	}
	fprintf(fp,"\n");
	fclose(fp);

}

void S_Pat(int x ,int y){
	int i,j,side=4,X;
	FILE *fp;
	fp = fopen("Coordinates1.txt","a+");
	for(i = 0; i < side; i++){ 
		X=x;
		for(j = 0; j < side; j++){
			if(i==0 || i==side-1 || j==0 || j==side-1){
				//printw("*");
				fprintf(fp,"%d,%d|",X,y);
				X=X+1;
				//move(y,X);
			}

			else{
				//printw(" ");
				X=X+1;
				//move(y,X);
			}
		}
		//move(++y,x);
		++y;
	}
	fprintf(fp,"\n");
	fclose(fp);
}
struct Object{
	char s[2000];
}obj[10];

int main(){

	//initscr();
	char InputStr[]= "Sun is on the top of tree.Sun is on the top left of girl.Sun is on the left of bush.Girl is on the bottom right of sun.Girl is on the bottom left the bush.Girl is on the right of the tree.Tree is on the bottom of the sun.Tree is on left of the girl.Tree is on bottom left of the bush.Bush is on the top right of the girl.Bush is on the top right of the tree.Bush is on the right of sun.";

	int i=0,k=0,j=0;
	char Str[100][5000];

	for(i=0;i<strlen(InputStr);i++){

		if(InputStr[i]!='.'){

			Str[k][j]=InputStr[i];
			//cout<<Str[k][j];
			j++;
		}
		else{
			Str[k][j++]='.';
			Str[k][j]='\0';
			k++;j=0;
			//cout<<endl;
		}
	}

	char *word = GetFirst(Str[0]);
	char *temp = new char[20];
	//strcat(obj[0].s,Str[0]);
	j=0;
	for(i=0;i<k;i++){

		temp = GetFirst(Str[i]);
		if(strcmp(word,temp)==0){
			strcat(obj[j].s,Str[i]);
		}
		else{
			word = temp;
			j++;
			strcat(obj[j].s,Str[i]);
		}
	}
	for(i=0;i<10;i++){

		int len = strlen(obj[i].s);
		obj[i].s[len+1]='\0';
	}

	//for(i=0;i<k;i++){	
	GetCoordinates(obj[0].s);
	GetCoordinates(obj[1].s);
	GetCoordinates(obj[2].s);
	GetCoordinates(obj[3].s);	
	//}
	//getch();
	//endwin();
	return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int countc(char *file);
int countw(char *file);
int countc(char *file) //返回文件的字符数 
{   
	int zifu=0;
	FILE *f=fopen(file, "r"); 
	char a; 
	if(f==NULL) 
	{ 
		printf("读取文件失败"); 
	} 
	else while (!feof(f)) 
	{ 
		a=fgetc(f);
		if (a != ' ' && a != '\n'&&a != '\t') zifu++; 
	} 
	fclose(f);
	printf("charnum:%d ",zifu); 
	return zifu;
}
int countw(char *file)//返回文件词的数目 
{   
	int cword=0,aword;
	FILE *f=fopen(file,"r"); 
	char ch; 
	if(f == NULL) 
	{ 
		printf("读取文件失败"); 
	} 
	else while(!feof(f)) 
	{ 
		ch=fgetc(f); 
		if((ch >= 'a' && ch <= 'z')||(ch>='A' && ch<='Z')||ch=='_'||(ch >= '0' && ch <= '9')) 
			aword=1; 
		else if (aword) 
		{ 
			cword++; 
			aword=0; 
		} 
	} 
	fclose(f); 
	printf("wordnum:%d ",cword); 
	return cword;
}
int main(int argc, char* argv[])             
{
    FILE *fp;
	while(1)
	{
		if((fp=fopen(argv[2],"r"))==NULL)
		{ 
			printf("读取文件失败\n"); 
			scanf("%s%s%s",argv[0],argv[1],argv[2]); 
			continue; 
		} 
		else if(!strcmp(argv[1],"-w")) countw(argv[2]); 
		else if(!strcmp(argv[1],"-c")) countc(argv[2]); 
		else printf("NullPoint\n"); 
		printf("\n\n"); 
		scanf("%s%s%s",argv[0],argv[1],argv[2]); 
	} 
	return 0; 
}

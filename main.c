#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"funcs.h"
int read_text(char str[],int size,int flag,FILE *fp){
if(fgets(str,size,fp)== NULL)		//reads words and changes the \n with \0
	return -1;						//at the end of word
int len=strlen(str);
if(len<=0)	
{	fprintf(stderr,"Input error\n");
	return -1;
}
else
{
	if(flag && (str[len-1]=='\n'))
	{	str[len-1]='\0';
		len--;
	}
}
return len;
}

int main(){
    FILE *fp;
    fp=fopen("Words.txt","r");
    if(!fp){
        fprintf(stderr,"Could not open file\n");
        return -1;
    }
    srand(time(NULL));
    int wordnum=rand()%10;  //random word form file "Words"
    int i=0;                //containing 10 words
    char word[20];
    while(i<=wordnum){
        read_text(word,sizeof(word),1,fp);
        i++;
    }
    int len=strlen(word);
    char new[40];
    for(i=0;i<len*2;i+=2)
    	{	new[i]='_';		//intitializes array
    		new[i+1]=' ';	//gaps between letters
		}
    new[len*2]='\0';
     int j;
     char given[50];	//contains given letters
     given[0]='\0';
     char letter;
     int cont;
	 i=0;
	while(i<len){
		printf("Given letters:\n");
		j=0;
		while(j<24)
		{	if(given[j]=='\0')
				{	putchar('\n');
					break;
				}
			else{
				printf("%c ",given[j]);
				j++;
			}
		}
		for(j=0;j<len*2;j++)
			printf("%c ",new[j]);
		printf("\nGive a letter:\n");
		scanf("%c",&letter);
		cont=check(word,new,letter);
		if(cont!=-1)	//letter in word
			i+=cont;	//how many 
		else	
			findgiv(given,letter);		
	}
	for(j=0;j<len*2;j++)
			printf("%c ",new[j]);
    fclose(fp);
    return 0;
}

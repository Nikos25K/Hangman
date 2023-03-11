#include"funcs.h"
int check(char word[],char neww[],char letter){
	int i,count=0;
	for(i=0;i<20;i++){
		if(word[i]==letter && neww[i*2]=='_')
		{	neww[i*2]=letter;
			count++;		//letter in word
		}
	}
	if(count==0)
		return -1;	//letter not in word
	else
		return count;	//returns number of letters in word
	
}

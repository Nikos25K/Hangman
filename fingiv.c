#include"funcs.h"
void findgiv(char given[],char letter){
	int i=0;
	while(i<24){
		if(given[i]==letter)
			break;		//already given
		else if(given[i]=='\0')	
			{	given[i]=letter;	//given one new letter not in word
				given[i+1]='\0';
				break;	
			}
		i++;		
	}
}

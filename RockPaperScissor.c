/*-------------------------------------
RockPaperScissors.c
Program to play rock,paper,scissors
--------------------------------------*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

//---------------Prototype---------------
void Menu(int* Choice);
void Play(char *username);


main()
{
	int i,Choice;
	char username[20];
	
	Menu(&Choice);
	
	while(Choice){
		if(Choice==1){
			printf("Enter your username:");
			scanf("%s",username);
			printf("\e[1;1H\e[2J");
			printf("Welcome to the game, User ");
			puts(username);
			Play(username);
		}else if(Choice==2){
			break;
			exit(1);
		}
		Menu(&Choice);
	}
}
//---------------------Function Menu-----------------
void Menu(int *Choice)
{
	printf("\e[1;1H\e[2J");
	printf("1.Play Rock,Paper,Scissors\n");
	printf("2.Exit\n");
	
	printf("Enter the choice:");
	scanf("%d",Choice);
}
//--------------Function Play-----------------
void Play(char *username)
{
	int i,Human_Choice,Computer_Choice,Computer_Score,Human_Score;
	
	Computer_Score=Human_Score=0;
	
	for(i=0;i<5;i++){
		printf("\n");
	    printf("1.Rock\n");
		printf("2.Paper\n");
		printf("3.Scissors\n");
		printf("Enter your choice:");
		scanf("%d",&Human_Choice);
		
		if(Human_Choice==1){
			printf("Human Choice:Rock\n");
		}else if(Human_Choice==2){
			printf("Human Choice:Paper\n");
		}else{
			printf("Human Choice:Scissors\n");
		}
		
		srand(time(0)); // srand provides the seed for rand and time(0) denotes the number of seconds passed from Unix time(00:00 hours, Jan 1, 1970)
				
		Computer_Choice=rand()%3 + 1;
		if(Computer_Choice==1){
			printf("Computer Choice:Rock\n");
		}else if(Computer_Choice==2){
			printf("Computer Choice:Paper\n");
		}else{
			printf("Computer Choice:Scissors\n");
		}
				
		if((Computer_Choice==1 && Human_Choice==3) || (Computer_Choice==2 && Human_Choice==1) || (Computer_Choice==3 && Human_Choice==2 )){
			Computer_Score++;
		}else if((Human_Choice==1 && Computer_Choice==3) || (Human_Choice==2 && Computer_Choice==1) || (Human_Choice==3 && Computer_Choice==2)){
			Human_Score++;
		}else{
			i--;
			
		}
		
		printf("Computer Score:%d vs Human Score:%d",Computer_Score,Human_Score);
		//printf("\ni=%d\n",i);
		printf("\n");
		getch();
	}
	
	
	if(Computer_Score>Human_Score){
		printf("Computer Wins");
	}else if(Computer_Score<Human_Score){
		printf("%s Wins",username);
	}
	getch();
}
	
	

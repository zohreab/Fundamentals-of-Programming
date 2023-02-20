#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <conio.h>
const int MAX_LENGTH = 100;
int ii = 0;
char userStrings[28][10000];
int valueOfHouses[28];
char voh[28][5];
int iinums[] = {0,0,0,0};
int houseCount = 18;
int userCount = 0;
int roundList[] = {50,100,150};
int rounds = 0;
int player;
char names[4][100];
int now = 0;
char begin[10];
int sortList[] = {0,1,2,3};
int dice_value = 0;
int rent = 0;
int counter = 0;
int houseOwner[28];
int numberOfHouses[] = {0,0,0,0};
const int MAX = 10000;
int MainMenu();
int AnotherMenu();
void drawline();
void sleepTime();
int createRand();
int createRandomHouseAmount();
void getNames(int userCount);
int numberOfRounds();
int playerSelect(int userCount);
int incrInt(int a);
int ValueAmount(int value);
void print_do_you_want_to_buy();
void initial_value_of_houses();
void initial_userStrings();
void initial_houseOwner();
void initial_begin(int a);
void sort0(int money[], int userCount);
void scoreBoard(int money[], int userCount);
void print_new_line();
void empty_begin_from_now();
int main(){
	srand(time(0));
	int index = 0;
	int i = 0;
	initial_value_of_houses();
	initial_userStrings();
	initial_houseOwner();
	char houses[10000] =
						"                  %s       %s       %s       %s       %s       %s\n"
						"       .......... .......... .......... .......... .......... .......... .......... ..........\n"
						"      | %s | %s | %s | %s | %s | %s | %s | %s |\n"
						"       .......... .......... .......... .......... .......... .......... .......... ..........\n"
						"%s  | %s |                                                                 | %s |  %s\n"
						"       ..........                                                                   .......... \n"
						"%s  | %s |                                                                 | %s |  %s\n"
						"       ..........                                                                   .......... \n"
						"%s  | %s |                                                                 | %s |  %s\n"
					 	"       ..........                                                                   .......... \n"
						"%s  | %s |                                                                 | %s |  %s\n"
						"       ..........                                                                   .......... \n"
						"%s  | %s |                                                                 | %s |  %s\n"
						"       ..........                                                                   .......... \n"
						"%s  | %s |                                                                 | %s |  %s\n"
						"       .......... .......... .......... .......... .......... .......... .......... ..........\n"
						"      | %s  | %s | %s | %s | %s | %s | %s | %s |\n"
						"       .......... .......... .......... .......... .......... .......... .......... ..........\n"
						"       Start      %s       %s       %s       %s       %s       %s\n"
						;
	int command = MainMenu();
	switch(command){
		case 1:{
			print_new_line();
			userCount = AnotherMenu();
			print_new_line();
			getNames(userCount);
			print_new_line();
			rounds = roundList[numberOfRounds()-1]+1;
			print_new_line();
			player = playerSelect(userCount)-1;
			break;
		}
	}
	int money[userCount];
	print_new_line();
	for(i = 0;i < userCount;i++){
		money[i] = 1000;
	}
	print_new_line();
	int j = 0;
	int each_user_position[userCount];
	for(i = 0; i < userCount;i++){
		each_user_position[i] = -1;
	}
	initial_begin(userCount);
	int finish = 0;
	valueOfHouses[6] = 0;
	valueOfHouses[13] = 0;
	valueOfHouses[20] = 0;
	valueOfHouses[27] = 0;
	while(1){
		counter = 0;
		for(i = 0; i < userCount;i++){
			if(iinums[i] == 0){
				counter++;
			}
		}
		if(counter == 1){
			for(i = 0; i < userCount;i++){
				if(iinums[i] == 0){
					sort0(money, userCount);
					int k;
					printf("\n");
					for(k=0; k<userCount; k++)
						printf("Player %d = %d\n\n", sortList[k]+1, money[sortList[k]]);
					scoreBoard(money, userCount);
					printf("user -> %s won the game ." , names[i]);
					finish = 1;
					break;
				}
			}
		}
		rounds--;
		if(finish == 1 || rounds == 0)break;
		printf( houses  , voh[7] , voh[8] ,  voh[9], voh[10], voh[11], voh[12] , userStrings[6] , userStrings[7] ,userStrings[8], userStrings[9] ,userStrings[10], userStrings[11] , userStrings[12] , userStrings[13] , voh[5], userStrings[5], userStrings[14] , voh[14], voh[4],userStrings[4], userStrings[15] , voh[15], voh[3],userStrings[3], userStrings[16] , voh[16], voh[2],userStrings[2], userStrings[17] , voh[17], voh[1], userStrings[1] , userStrings[18] , voh[18], voh[0], userStrings[0], userStrings[19] , voh[19] , userStrings[27], userStrings[26], userStrings[25], userStrings[24], userStrings[23],userStrings[22] ,userStrings[21] ,userStrings[20] , voh[26] , voh[25], voh[24],voh[23], voh[22], voh[21]);
		drawline();
		for(i = 0;i < userCount;i++){
			if(iinums[i] == 1)continue;
			printf("Player %d: %s %d$ \n" , i+1 , names[i] , money[i]);
		}
		
		printf("\nPlayer %d turn" , now + 1);
		rent = 0;
		print_new_line();
		int sum_dice = 0;
		while(1){
			char ch = 'd';
			if(player == now)
				ch = getch();
			if(ch == 'd')
				dice_value = createRand();
			printf("Dice : %d \n\n" , dice_value);
			sum_dice += dice_value;
			if(dice_value != 6){
				break;
			}
			else if(dice_value == 6){
				printf("!! You can roll the dice another time \n");
			}
		}
		dice_value = sum_dice;
		each_user_position[now] += dice_value;
		
		if(each_user_position[now] > 27){
			money[now] += 200;
			each_user_position[now] -= 28;
		}
		if(valueOfHouses[each_user_position[now]] == -1){
			printf("%s entered to the jail\n\n", names[now]);
			iinums[now] = 1;
			if(money[now] > 0)
				money[now] = 0;
			for(i=0; i<28; i++)	
				if(houseOwner[i] == now+1)
					houseOwner[i] = 0;
			numberOfHouses[now] = 0;
		}
		else if(each_user_position[now] != -1 && houseOwner[each_user_position[now]] != 0){
			int value = valueOfHouses[each_user_position[now]];
			int extra = 0;
			if(numberOfHouses[houseOwner[each_user_position[now]]-1] > 8)
				extra = value * 0.1;
			money[now] -= ValueAmount(value)+ extra;
			money[houseOwner[each_user_position[now]]-1] += ValueAmount(value) + extra;
		}
		else if(valueOfHouses[each_user_position[now]] != 0){
			print_do_you_want_to_buy();
			int choice = rand()%2+1;
			if(player == now)
				scanf("%d" , &choice);
			if(choice == 1){
				int value = valueOfHouses[each_user_position[now]];
				money[now] -= value;
				houseOwner[each_user_position[now]] = now+1;
				numberOfHouses[now]++;
			}
		}
		
		switch(now){
			case 0:{
				for(index = 0;index < 28;index++)
					userStrings[index][0*2] = ' ';
				userStrings[each_user_position[0]][0*2] ='1';
				break;
			}
			case 1:{
				for(index = 0;index < 28;index++)
					userStrings[index][1*2] = ' ';
				userStrings[each_user_position[1]][1*2] ='2';
				break;
			}
			case 2:{
				for(index = 0;index < 28;index++)
					userStrings[index][2*2] = ' ';
				userStrings[each_user_position[2]][2*2] ='3';
				break;
			}
			case 3:{
				for(index = 0;index < 28;index++)
					userStrings[index][3*2] = ' ';
				userStrings[each_user_position[3]][3*2] ='4';
				break;
			}
		}
		if(money[now] <= 0){
			iinums[now] = 1;
			for(i=0; i<28; i++)
				if(houseOwner[i] == now+1)
					houseOwner[i] = 0;
			numberOfHouses[now] = 0;
		}
			
		for(i = 0; i < 4;i++){
			if(iinums[i] == 1){
				for(index = 0;index < 28;index++)userStrings[index][i*2] = ' ';
				continue;
			}
		}
		empty_begin_from_now();
		if(player != now)
			sleepTime();
		now = incrInt(now);
	}
}
int MainMenu(){
	printf("1.play\n");
	printf("Enter a number to continue: ");
	int command = 0;
	scanf("%d" , &command);
	return command;
}
int AnotherMenu(){
	printf("*Number of players\n");
	printf("2. 2 players\n");
	printf("3. 3 players\n");
	printf("4. 4 players\n");
	printf("Enter a number to continue: ");
	int command = 0;
	scanf("%d" , &command);
	return command;
}
void getNames(int userCount){
	int index;
	printf("*Player names\n");
	for(index = 0;index < userCount;index++){
		printf("Insert Player %d name: " , index+1);
		scanf("%s" , names[index]);
	}
}
int numberOfRounds(){
	printf("*Number of rounds\n");
	printf("1. 50 round\n");
	printf("2. 100 round\n");
	printf("3. 150 round\n");
	printf("Enter a number to continue: ");
	int command = 0;
	scanf("%d" , &command);
	return command;
}
int playerSelect(int userCount){
	int index;
	printf("*Which player you want to be?\n");
	for(index = 0;index < userCount;index++){
		printf("%d. Player %d\n" , index+1, index+1);
	}
	printf("Enter a number to continue: ");
	int command = 0;
	scanf("%d" , &command);
	return command;
}
void drawline(){
	printf("\n\n =============================================== \n\n");
}
void sleepTime(){
	int mil = 1000;
	clock_t start = clock();
	while (clock() < start+mil);
}
int createRand(){
	return (rand() % 6 + 1);
}
int createRandomHouseAmount(){
	return (rand() % 400 + 100);
}
int incrInt(int a){
	do{
		a = (a+1)%userCount;
	}
	while(iinums[a] == 1);
	return a;
}
int ValueAmount(int value){
	if(value >= 100 && value <= 200)
		return value * 0.2;
	if(value >= 200 && value <= 300)
		return value * 0.3;
	if(value >= 200 && value <= 400)
		return value * 0.4;
	if(value >= 200 && value <= 500)
		return value * 0.5;
}
void print_do_you_want_to_buy(){
	printf("Want to buy the house? \n");
	printf("1. Yes\n");
	printf("2. No\n");
}
void initial_value_of_houses(){
	int index = 0;
	for(index = 0;index < 28;index++){
		valueOfHouses[index] = createRandomHouseAmount();
		sprintf(voh[index], "%d$", valueOfHouses[index]);
	}
	int ijail;
	for(index = 0;index < rand()%3+3;index++){
		ijail = rand() % 28;
		valueOfHouses[ijail] = -1;
		strcpy(voh[ijail], "jail");
	}
}
void initial_userStrings(){
	int index = 0;
	for(index = 0;index < 27;index++){
		userStrings[index][0] = ' ';
		userStrings[index][1] = ' ';
		userStrings[index][2] = ' ';
		userStrings[index][3] = ' ';
		userStrings[index][4] = ' ';
		userStrings[index][5] = ' ';
		userStrings[index][6] = ' ';
		userStrings[index][7] = ' ';
	}
}
void initial_houseOwner(){
	int index = 0;
	for(index = 0;index < 27;index++){
		houseOwner[index] = 0;
	}
}
void initial_begin(int a){
	switch(a){
		case 2:{
			userStrings[27][0] = '1';
			userStrings[27][1] = ' ';
			userStrings[27][2] = '2';
			userStrings[27][3] = ' ';
			userStrings[27][4] = ' ';
			userStrings[27][5] = ' ';
			userStrings[27][6] = ' ';
			break;
		}
		case 3:{
			userStrings[27][0] = '1';
			userStrings[27][1] = ' ';
			userStrings[27][2] = '2';
			userStrings[27][3] = ' ';
			userStrings[27][4] = '3';
			userStrings[27][5] = ' ';
			userStrings[27][6] = ' ';
			break;
		}
		case 4:{
			userStrings[27][0] = '1';
			userStrings[27][1] = ' ';
			userStrings[27][2] = '2';
			userStrings[27][3] = ' ';
			userStrings[27][4] = '3';
			userStrings[27][5] = ' ';
			userStrings[27][6] = '4';
			break;
		}
	}
}
void sort0(int money[], int userCount){
	int i, j, temp;
	for(i=0; i<userCount-1; i++)
		for(j=0; j<userCount-i-1; j++)	
			if(money[sortList[j]] < money[sortList[j+1]]){
				temp = sortList[j];
				sortList[j] = sortList[j+1];
				sortList[j+1] = temp;
			}
}
void scoreBoard(int money[], int userCount){
	FILE *f;
	int index, j, c;
	f = fopen("ScoreBoard.txt", "w");
	char conv[][7] = {"[7][0]", "[6][0]", "[5][0]", "[4][0]", "[3][0]", "[2][0]", "[1][0]", "[0][0]", "[0][1]", "[0][2]", "[0][3]", "[0][4]", "[0][5]", "[0][6]", "[0][7]", "[1][7]", "[2][7]", "[3][7]", "[4][7]", "[5][7]", "[6][7]", "[7][7]", "[7][6]", "[7][5]", "[7][4]", "[7][3]", "[7][2]", "[7][1]"};
	for(index=0; index<userCount; index++){
		fprintf(f, "Player %d\n", index+1);
		fprintf(f, "Name: %s\n", names[index]);
		fprintf(f, "Money: %d$\n", money[index]);
		c = 0;
		for(j=0; j<28; j++)
			if(houseOwner[j] == index+1 && valueOfHouses[j] != 0)
				c++;
		if(c == 0){
			fprintf(f, "\n");
			continue;
		}
		fprintf(f, "Houses: ");
		for(j=0; j<28; j++)
			if(houseOwner[j] == index+1 && valueOfHouses[j] != 0)
				fprintf(f, "%s  ", conv[j]);
		fprintf(f, "\nValue of houses: ");
		for(j=0; j<28; j++)
			if(houseOwner[j] == index+1 && valueOfHouses[j] != 0)
				fprintf(f, "%d$  ", valueOfHouses[j]);
		fprintf(f, "\n\n");
	}
	fclose(f);
}
void print_new_line(){
	printf("\n");
}
void empty_begin_from_now(){
	begin[now] = ' ';
}

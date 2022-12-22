#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// CRUD = Create, Read, Update, Delete.

struct Data{
	char name[100];
	int age;
};

int main(){
	
	struct Data dt[10]; // array of struct
	int idx = 0;
	int opt;
	char nama[100];
	int umur;
	
	do{
		printf("1. Insert\n");
		printf("2. View\n");
		printf("3. Delete\n");
		printf("4. Exit\n");
		do{
			printf("Input[1..4] ");
			scanf("%d",&opt);
			getchar();
		}while(opt < 1 || opt > 4);
		switch(opt){
			case 1:
				//printf("Menu 1\n");
				if(idx < 10){
					do{
						printf("Input name[4..20]: ");
						scanf("%[^\n]",&nama);
						getchar();
					}while(strlen(nama) < 4 || strlen(nama) > 20);
					
					do{
						printf("Input age [20 - 50]: ");
						scanf("%d",&umur);
						getchar();
					}while(umur < 20 || umur > 50);
					
					strcpy(dt[idx].name,nama);
					dt[idx].age = umur;
					idx++;
				}
				else{
					printf("Data already full\n");
				}
				
				break;
			case 2:
				//printf("Menu 2\n");
				if(idx == 0){
					printf("No Data\n");
				}
				else{
					printf("%-2s %-20s %-3s\n","No","Name","Age");
					for(int i=0; i<idx; i++){
						printf("%-2d %-20s %-3d\n", i+1, dt[i].name, dt[i].age);
					}
				}
				break;
			case 3:
				//Delete Last Data
				if(idx > 0){
					idx--;
					printf("Sucessfully delete last data\n");
				}
				else{
					printf("No Data\n");
				}
				break;
		}
		getchar();
	}while(opt != 4);
	
	return 0;
}

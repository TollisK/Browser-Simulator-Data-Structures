/*************************************************************************
Implementation File	: main.c
Author Date			: Apostolos Karvelas 1115201800312 4/5/2019
Purpose				: Ylopoihsh Session for Browser

**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Session.h"
#define MAX_OPTIONS 17

int main(int argc, char *argv[]) {
	InfoSessionPtr 	MySession1=NULL, MySession2=NULL;
	int option, error;
	int sflag = 0;/*Session sto opoio brhsketai*/
	TabNodePtr flag1,flag2;
	char OpeningAddress[100];
	while(sflag != 1 && sflag != 2){/*Dialegei to session sto opoio thelei na 3ekinhsei*/
		printf("Type 1 for the first Session or 2 for the second Session\n");
		scanf("%d", &sflag);
		if(sflag == 1)
			printf("Current Session: Session 1\n");
		else if(sflag == 2)
			printf("Current Session: Session 2\n");
	}
	do {
		print_options(MAX_OPTIONS);
		scanf("%d",&option);
		switch (option) {
		case 1:
			if(sflag%2==1){/*An alla3oyme to sflag kata 1 allazei kai to Session sto opoio brhsketai*/
				printf("Give the default opening address for Session 1\n");
				MySession1 = SessionNew(Value());
				printf("Session 1 Created!\n");
			}
			else{
				printf("Give the default opening address for Session 2\n");
				MySession2 = SessionNew(Value());
				printf("Session 2 Created!\n");
			}
			break;
		case 2:
			if(sflag%2==1){
				SessionNewTab(MySession1,&error);
				if(error == 1)
					printf("No available Session!\n");
				else
					printf("Tab Created!\n");
			}
			else{
				SessionNewTab(MySession2,&error);
				if(error == 1)
					printf("No available Session!\n");
				else
					printf("Tab Created!\n");
			}
			break;
		case 3:
			if(sflag%2==1)
				printf("%s",SessionTabShow(MySession1));
			else
				printf("%s",SessionTabShow(MySession2));
			break;
		case 4:
			if(sflag%2==1){
				SessionTabNext(MySession1,&error);
				if(error == 1)
					printf("No available Session!\n");
				else
					printf("Next Tab!\n");
			}
			else{
				SessionTabNext(MySession2,&error);
				if(error == 1)
					printf("No available Session!\n");
				else
					printf("Next Tab!\n");			
			}
			break;
		case 5:
			if(sflag%2==1){
				SessionTabPrev(MySession1,&error);
				if(error == 1)
					printf("No available Session!\n");
				else
					printf("Previous Tab!\n");
			}
			else{
				SessionTabPrev(MySession2,&error);
				if(error == 1)
					printf("No available Session!\n");
				else
					printf("Previous Tab!\n");
			}
			break;
		case 6:
			if(sflag%2==1){
				SessionTabMoveLeft(MySession1,&error);
				if(error==1)
					printf("Error!\n");
				else if(error == 2)
					printf("No available Session!\n");
				else
					printf("Tab moved to the left!\n");
			}
			else{
				SessionTabMoveLeft(MySession2,&error);
				if(error==1)
					printf("Error!\n");
				else if(error == 2)
					printf("No available Session!\n");
				else
					printf("Tab moved to the left!\n");
			}
			break;
		case 7:	
		if(sflag%2==1){
				SessionTabMoveRight(MySession1,&error);
				if(error==1)
					printf("Error!\n");
				else if(error == 2)
					printf("No available Session!\n");
				else
					printf("Tab moved to the right!");	
			}
			else{
				SessionTabMoveRight(MySession2,&error);
				if(error==1)
					printf("Error!\n");
				else if(error == 2)
					printf("No available Session!\n");
				else
					printf("Tab moved to the right!\n");	
			}
			break;
		case 8:
			if(sflag%2==1){
				printf("Give new OpeningAddress\n");
				SessionNewOpeningAddress(MySession1,Value(),&error);
				if(error == 1)
					printf("No available Session!\n");
			}
			else{
				printf("Give new OpeningAddress\n");
				SessionNewOpeningAddress(MySession2,Value(),&error);
				if(error == 1)
					printf("No available Session!\n");
			}
			break;
		case 9:	
			if(sflag%2==1)
				printf("%s", SessionShowOpeningAddress(MySession1));
			else
				printf("%s", SessionShowOpeningAddress(MySession2));
			break;
		case 10:
			if(sflag%2==1){
				SessionSiteNext(MySession1,&error);
				if(error == 1)
					printf("No available Session!\n");
				else
					printf("Next Site!\n");
			}
			else{
				SessionSiteNext(MySession2,&error);
				if(error == 1)
					printf("No available Session!\n");
				else
					printf("Next Site!\n");
			}
			break;
		case 11:
			if(sflag%2==1){
				SessionSitePrev(MySession1,&error);
				if(error == 1)
					printf("No available Session!\n");
				else
					printf("Previous Site!\n");
			}
			else{
				SessionSitePrev(MySession2,&error);
				if(error == 1)
					printf("No available Session!\n");
				else
					printf("Previous Site!\n");
			}
			break;
		case 12:
			if(sflag%2==1)
				printf("%s",SessionSiteShow(MySession1));
			else
				printf("%s",SessionSiteShow(MySession2));
			break;
		case 13:
			if(sflag%2==1){
				if(MySession1!=NULL){
					SessionTabClose(&MySession1,flag1);
					printf("Tab Closed!\n");
				}
				else
					printf("No available Session!\n");
			}
			else{
				if(MySession2!=NULL){
					SessionTabClose(&MySession2,flag2);
					printf("Tab Closed!\n");
				}
				else
					printf("No available Session!\n");
			}
			break;
		case 14:
			if(sflag%2==1){
				if(MySession1!=NULL){
					SessionClose(&MySession1);
					printf("Session Closed!\n");
				}
				else
					printf("No available Session!\n");
			}
			else{
				if(MySession2!=NULL){
					SessionClose(&MySession2);
					printf("Session Closed!\n");
				}
				else
					printf("No available Session!\n");
			}
			break;
		case 15:
			if(sflag%2==1){
				printf("Give opening address for the new site\n");
				SessionNewAddress(MySession1,Value(),&error);
				if(error == 1)
					printf("No available Session!\n");
				else
					printf("New Site!\n");
			}
			else{
				printf("Give opening address for the new site\n");
				SessionNewAddress(MySession2,Value(),&error);
				if(error == 1)
					printf("No available Session!\n");
				else
					printf("New Site!\n");
			}
			break;
		case 16:
			if(sflag%2==1){
				SessionOpenNewTab(MySession1,&flag1,&error);
				if(error == 1)
					printf("No available Session!\n");
				else
					printf("New Tab!\n");	
			}
			else{
				SessionOpenNewTab(MySession2,&flag2,&error);
				if(error == 1)
					printf("No available Session!\n");
				else
					printf("New Tab!\n");		
			}
			break;
		case 17:
			sflag++;/*prosthetei sto sflag + 1*/
			if(sflag%2==1)
				printf("Current Session: MySession1\n");
			else
				printf("Current Session: MySession2\n");
		}
	}	while (option);	
	return 0;
}

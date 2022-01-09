/*************************************************************************
Implementation File	: Session.c
Author Date			: Apostolos Karvelas 1115201800312 4/5/2019
Purpose				: Functions for the  Session

**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Session.h"

typedef struct InfoSession {
	TabNodePtr FirstTab;/*Prwto Tab*/
	TabNodePtr LastTab;/*Teleutaio Tab*/
	TabNodePtr CurrTab;/*Trexwn Tab*/
	TabNodePtr AuxTab;/*Bohthhtiko Tab*/
	char* 	  OpeningAddress;
} InfoSession; /*typos toy Session*/

typedef struct TabNode {	
	TabNodePtr PrevTab, NextTab;/*Proioumeno kai epomeno Tab*/
	SiteNodePtr FirstSite;/*Prwto Site*/
	SiteNodePtr CurrSite;/*Teleutaio Site*/
} TabNode; /*typos toy Tab*/

typedef struct SiteNode{
	SiteNodePtr PrevSite, NextSite;/*Proigoumeno kai epomeno Site*/
	TabNodePtr UpTab;/*To Tab poy anhkei to Site*/
	char *Address;/*H dieuthunsh toy site*/
} SiteNode; /*typos toy Site*/

InfoSessionPtr SessionNew(char * OpeningAddress){
	
	InfoSessionPtr Session;
	TabNodePtr TabN;
	SiteNodePtr SiteN;
	
	Session = malloc(sizeof(InfoSession));/*Dhmiourgei toys komvous*/
	TabN = malloc(sizeof(TabNode));
	SiteN = malloc(sizeof(SiteNode));
	
	Session->FirstTab = TabN;/*arxikopoiei tis metavlhtes toy Session*/
	Session->LastTab = TabN;
	Session->CurrTab = TabN;
	Session->AuxTab = NULL;
	Session->OpeningAddress = OpeningAddress; 
	
	TabN->PrevTab = TabN;/*arxikopoiei tis metavlhtes toy Tab*/
	TabN->NextTab = TabN;
	TabN->FirstSite = SiteN;
	TabN->CurrSite = SiteN;
	
	SiteN->Address = Session->OpeningAddress;/*arxikopoiei tis metavlhtes toy Site*/
	SiteN->NextSite = NULL;
	SiteN->PrevSite = NULL;
	SiteN->UpTab = TabN;
	
	return Session;
}

void SessionNewTab(InfoSessionPtr Session,int *error){
	
	TabNodePtr pro;
	SiteNodePtr SiteN;
	if(Session!=NULL){/*An yparxei Session*/
		*error = 0;	
		pro = malloc(sizeof(TabNode));/*Dhmiourgei to prosorino Tab kai to Site toy*/
		SiteN = malloc(sizeof(SiteNode));
	
		pro->NextTab = Session->FirstTab;/*Arxikopoiei to Tab stis metavlhtes toy Session*/
		pro->PrevTab = Session->LastTab;
	
		Session->LastTab->NextTab = pro;/*Arxikopoiei tis metavlhtes toy Tab*/
		Session->FirstTab->PrevTab = pro;
		Session->LastTab = pro;
		Session->CurrTab = pro;
	
		pro->FirstSite = SiteN;/*/*Arxikopoiei to Site stis metavlhtes toy Tab*/
		pro->CurrSite = SiteN;
	
		SiteN->Address = Session->OpeningAddress;/*arxikopoiei tis metavlhtes toy Site*/
		SiteN->NextSite = NULL;
		SiteN->PrevSite = NULL;
		SiteN->UpTab = pro;}
	else/*An den yparxei Session error = 1*/
		*error = 1;
}

/* The rest of the interface functions follow */

char * SessionTabShow(InfoSessionPtr Session){
	if(Session!=NULL)/*An yparxei Session*/
		return Session->CurrTab->CurrSite->Address;
	else
		return "No available Session!\n";
}

void SessionTabNext(InfoSessionPtr Session,int *error){
	if(Session!=NULL){/*An yparxei Session*/
		*error = 0;
		Session->CurrTab = Session->CurrTab->NextTab;
	}
	else
		*error = 1;
}

void SessionTabPrev(InfoSessionPtr Session,int *error){
	if(Session!=NULL){/*An yparxei Session*/
		*error = 0;
		Session->CurrTab = Session->CurrTab->PrevTab;
	}
	else
		*error = 1;	
}

void SessionTabMoveLeft(InfoSessionPtr Session,int *error){
	TabNodePtr temp1,temp2,temp3;
	if(Session!=NULL){/*An  yparxei Session*/
		*error = 0;	
	if(Session->FirstTab==Session->CurrTab)/*An den yparxei aristeros komvos(oxi kyklika)*/
		*error = 1;
	else if(Session->CurrTab==Session->LastTab && Session->CurrTab->PrevTab == Session->FirstTab){/*An yparxoyn mono 2 Tabs*/
		Session->LastTab = Session->FirstTab;
		Session->FirstTab = Session->CurrTab;
	}
	else {
		*error = 0;
		temp1 = Session->CurrTab->PrevTab->PrevTab;
		temp2 = Session->CurrTab->NextTab;
		temp3 = Session->CurrTab->PrevTab;
		
		temp2->PrevTab = Session->CurrTab->PrevTab;/*prospernaei ton CurrTab*/
		temp1->NextTab = Session->CurrTab; 
		
		Session->CurrTab->PrevTab->NextTab = temp2;
		Session->CurrTab->PrevTab = temp1;
		Session->CurrTab->NextTab = temp3;
		
		temp3->NextTab = temp2;
		temp3->PrevTab = Session->CurrTab;
		
		if(Session->CurrTab==Session->FirstTab)/*An to proigoymeno toy CurrTab htan to FirstTab*/
			Session->FirstTab = temp3;
		if(Session->CurrTab==Session->LastTab)/*An to epomeno toy CurrTab htan to LastTab*/
			Session->LastTab = temp3;

	}
	}
	else
		*error = 2;
	
}
void SessionTabMoveRight(InfoSessionPtr Session,int *error){
	TabNodePtr temp1,temp2,temp3;
	if(Session!=NULL){/*An  yparxei Session*/
		*error = 0;	
	if(Session->LastTab == Session->CurrTab)/*An den yparxei de3hs komvos(oxi kyklika)*/
		*error = 1;
	else if(Session->CurrTab==Session->FirstTab && Session->CurrTab->NextTab == Session->LastTab){/*An yparxoyn mono 2 Tabs*/
		Session->LastTab = Session->FirstTab;
		Session->FirstTab = Session->CurrTab->NextTab;
	}
	else {
		*error = 0;
		temp1 = Session->CurrTab->NextTab->NextTab;
		temp2 = Session->CurrTab->PrevTab;
		temp3 = Session->CurrTab->NextTab;
		
		temp2->NextTab = Session->CurrTab->NextTab;/*prospernaei ton CurrTab*/
		temp1->PrevTab = Session->CurrTab;
		
		Session->CurrTab->NextTab->PrevTab = temp2;
		Session->CurrTab->NextTab = temp1;
		Session->CurrTab->PrevTab = temp3;
		
		temp3->PrevTab = temp2;
		temp3->NextTab = Session->CurrTab;
		if(temp3==Session->LastTab)/*An to proigoymeno toy CurrTab htan to FirstTab*/
			Session->LastTab = Session->CurrTab;
		if(temp3==Session->FirstTab)/*An to epomeno toy CurrTab htan to LastTab*/
			Session->FirstTab = Session->CurrTab;
	}
	}
	else
		*error = 2;
}

void SessionNewOpeningAddress(InfoSessionPtr Session,char *Open,int *error){
	if(Session!=NULL){
		*error = 0;
		Session->OpeningAddress = Open;
	}
	else
		*error = 1;
}

char * SessionShowOpeningAddress(InfoSessionPtr Session){
	if(Session!=NULL)
		return Session->OpeningAddress;
	else
		return "No available Session!\n";
}

void SessionSiteNext(InfoSessionPtr Session,int *error){
	if(Session!=NULL){
		*error = 0;
		if(Session->CurrTab->CurrSite->NextSite != NULL)/*An yparxei epomenos komvos*/
			Session->CurrTab->CurrSite = Session->CurrTab->CurrSite->NextSite;
	}
	else
		*error = 1;
}

void SessionSitePrev(InfoSessionPtr Session,int *error){
	if(Session!=NULL){
		*error = 0;
	if(Session->CurrTab->CurrSite->PrevSite != NULL)/*An yparxei proigoumenos komvos*/
		Session->CurrTab->CurrSite = Session->CurrTab->CurrSite->PrevSite;
	}
	else
		*error = 1;
}

char *SessionSiteShow(InfoSessionPtr Session){
	if(Session!=NULL)
		return Session->CurrTab->CurrSite->Address;
	else
		return "No available Session!\n";
}

void SessionTabClose(InfoSessionPtr *Session,TabNodePtr flag){
	SiteNodePtr todel,todel2;
	TabNodePtr pro,pre;
	/*Diagrafh twn Site toy CurrTab*/
	todel= (*Session)->CurrTab->FirstSite;
	while(todel!=NULL){/*oso yparxei epomeno Site*/
		todel2=todel;
		todel=todel->NextSite;
		free(todel2);
	}
	(*Session)->CurrTab->FirstSite = NULL;
	
	/*Diagrafh toy CurrTab*/
	if((*Session)->FirstTab==(*Session)->LastTab){/*An yparxei mono ena Tab tote diegrapse olo to Session*/
		free((*Session)->CurrTab);
		free((*Session));
		(*Session) = NULL;
	}
	else{
			pro = (*Session)->CurrTab;
			pre = pro->PrevTab;
			
			if(pro == (*Session)->FirstTab)/*An einai o prwtos komvos*/
				(*Session)->FirstTab = pro->NextTab;
			
			if(pro == (*Session)->LastTab)/*An einai o teleutaios komvos*/
				(*Session)->LastTab = pro->PrevTab;
			
			(*Session)->CurrTab = pro->NextTab;
			pre->NextTab = pro->NextTab;
			(*Session)->CurrTab->PrevTab = pre;
			
			if(pro == flag)/*An to CurrTab einai to Tab pou dhmiourgththke apo to SessionOpenNewTab tote paei sto site sto opoio dhmiourghthke*/
				(*Session)->CurrTab = (*Session)->AuxTab;
				
			free(pro);
	}

}

void SessionClose(InfoSessionPtr *Session){
	TabNodePtr pro,pre;
	SiteNodePtr todel,todel2;
	
	pro = (*Session)->FirstTab;
	while(pro!=(*Session)->LastTab){/*diagrafh twn Tabs*/
		pre=pro;
		pro = pro->NextTab;
		
		todel = pre->FirstSite;
		while(todel!=NULL){/*Diagrafh twn Site gia kathe Tab*/
			todel2=todel;
			todel=todel->NextSite;
			free(todel2);
		}
		pre->FirstSite = NULL;
		
		free(pre);
	}
	
	(*Session)->CurrTab = NULL;
	/*diagrafh toy Session*/
	free(*Session);
	*Session = NULL;
}

void SessionNewAddress(InfoSessionPtr Session,char *Open,int *error){
	SiteNodePtr todel,todel2;
	SiteNodePtr SiteN;
	
	if(Session!=NULL){
		*error = 0;
		todel = Session->CurrTab->CurrSite->NextSite;
		while(todel!=NULL){/*Diagrafh twn Site meta toy CurrSite toy CurrTab*/
			todel2=todel;
			todel=todel->NextSite;
			free(todel2);
		}
		Session->CurrTab->CurrSite->NextSite = NULL;
		
		SiteN = malloc(sizeof(SiteNode));/*arxikopoihsh toy neoy Site*/
		SiteN->Address = Open;
		SiteN->NextSite = NULL;
		SiteN->PrevSite = Session->CurrTab->CurrSite;
		Session->CurrTab->CurrSite->NextSite = SiteN;
		SiteN->UpTab = Session->CurrTab;
		Session->CurrTab->CurrSite = SiteN;
	}
	else
		*error = 1;
}

void SessionOpenNewTab(InfoSessionPtr Session,TabNodePtr *flag,int *error){
	TabNodePtr pro;
	SiteNodePtr SiteN;
	
	if(Session!=NULL){
		*error = 0;
	Session->AuxTab = Session->CurrTab; /*apothhkeyei ton CurrTab se enan deikth gia thn diagrafh toy meta*/
	
	pro = malloc(sizeof(TabNode));/*dhmiourgei to neo Tab kai Site*/
	SiteN = malloc(sizeof(SiteNode));
	
	pro->NextTab = Session->FirstTab;/*arxikopoiei tis metavlhtes toy tab*/
	pro->PrevTab = Session->LastTab;
	
	Session->LastTab->NextTab = pro;/*allazei tis metavlhtes toy Session*/
	Session->FirstTab->PrevTab = pro;
	Session->LastTab = pro;
	Session->CurrTab = pro;
	
	pro->FirstSite = SiteN; /*arxikopoiei tis metavlhtes toy Site*/
	pro->CurrSite = SiteN;
	
	SiteN->Address = Session->OpeningAddress;/*allazei tis metavlhtes toy Tab*/
	SiteN->NextSite = NULL;
	SiteN->PrevSite = NULL;
	SiteN->UpTab = pro;
	
	*flag = pro;/*apothhkeuei ton neo komvo se enan deikth ws flag gia thn diagrafh toy*/
	}
	else
		*error = 1;
	
	
	
}

char *Value(){/*Eisagoyme ena string ston deikth vl*/
	char *vl;
	vl = malloc(100*sizeof(char));
	scanf("%s", vl);
	return vl;
}	

void print_options(int MAX_OPTIONS)/*Ektypwnei tis epiloges gia to switch case*/
{
	printf("\n");
	printf("0. Exit\n");
	printf("1. Create new session\n");
	printf("2. Create new tab\n");
	printf("3. Show tab\n");
	printf("4. Go to next tab\n");
	printf("5. Go to previous tab\n");
	printf("6. Move tab to the left\n");
	printf("7. Move tab to the right\n");
	printf("8. Give new opening address\n");	
	printf("9. Show the opening address\n");
	printf("10. Go to the next site\n");
	printf("11. Go to the previous site\n");
	printf("12. Show site\n");
	printf("13. Close tab\n");
	printf("14. Close the session\n");
	printf("15. New address\n");
	printf("16. Open new tab\n");
	printf("17. Switch Session\n");
	printf("Enter your input (1-%d): ", MAX_OPTIONS);
}



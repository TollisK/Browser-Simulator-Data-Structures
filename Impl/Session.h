/*************************************************************************
Implementation File	: Session.h
Author Date			: Apostolos Karvelas 1115201800312 4/5/2019
Purpose				: Header file for Session.c

**************************************************************************/
#ifndef __SESSION__
#define __SESSION__

typedef struct InfoSession *InfoSessionPtr;
typedef struct SiteNode *SiteNodePtr;
typedef struct TabNode *TabNodePtr;

InfoSessionPtr SessionNew(char *);/*Dhmiourgei neo Session*/
void SessionNewTab(InfoSessionPtr,int *);/*Dhmiourgei neo tab sto session*/

/* The rest of the interface functions follow */
char * SessionTabShow(InfoSessionPtr Session);/*return to OpeningAddress tou CurrSite toy CurrTab*/
void SessionTabNext(InfoSessionPtr Session,int *);/*Phgainei ston epomeno tab kyklika*/
void SessionTabPrev(InfoSessionPtr Session,int *);/*Phgainei ston proigoymeno tab kyklika*/
void SessionTabMoveLeft(InfoSessionPtr Session,int *);/*Antimetathesh me ton proigoumeno Tab tou CurrTab*/
void SessionTabMoveRight(InfoSessionPtr Session,int *error);/*Antimetathesh me ton epomeno Tab tou CurrTab*/
void SessionNewOpeningAddress(InfoSessionPtr Session,char *Open,int *);/*Bazei diaforetikh timh sto OpeningAddress*/
char * SessionShowOpeningAddress(InfoSessionPtr Session);/*return to OpeningAddress*/
void SessionSiteNext(InfoSessionPtr Session,int *);/*Phgainei sto epomeno site*/
void SessionSitePrev(InfoSessionPtr Session,int *);/*Phgainei sto proigoymeno site*/
char *SessionSiteShow(InfoSessionPtr Session);/*return to OpeningAddress toy CurrSite toy CurrTab*/
void SessionTabClose(InfoSessionPtr *Session,TabNodePtr flag);/*Diagrafei to CurrTab kai o deikths paei ston epomeno kyklika*/
void SessionClose(InfoSessionPtr *Session);/*Diagrafei to session*/
void SessionNewAddress(InfoSessionPtr Session,char *,int *);/*Dhmioyrgei neo site ston CurrTab me neo OpeningAddress*/
void SessionOpenNewTab(InfoSessionPtr Session,TabNodePtr *,int *);/*Dhmiourgei neo tab to opoio an diagrafei paei sto site sto opoio dhmioyrghthhke*/
char *Value();/*Return mia timh poy eisagoume*/
void print_options(int);/*Deixnei tis epiloges toy switch case*/

#endif

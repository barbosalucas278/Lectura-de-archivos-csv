/*
 ============================================================================
 Name        : Distribuidora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "Distribuidora.h"

#define PATH_SAVE "mapeado.csv"

int main(void) {
	setbuf(stdout, NULL);
	LinkedList* articlesList = ll_newLinkedList();
	int option;
	do{
		option = menu();
		switch(option){
		case 1:
			distribuidora_readFromFlie(articlesList);
			break;
		case 2:
			distribuidora_sortArticles(articlesList);
			break;
		case 3:
			distribuidora_listArticles(articlesList);
			break;
		case 4:
			distribuidora_calculateDiscount(articlesList);
			break;
		case 5:
			distribuidora_saveOnFile(articlesList,PATH_SAVE);
			break;
		case 6:
			distribuidora_informes(articlesList);
			break;
		case 7:
			break;
		}
	}while(option!=7);

	return 0;
}

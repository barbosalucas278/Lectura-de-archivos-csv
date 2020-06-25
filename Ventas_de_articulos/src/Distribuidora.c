/*
 * Distribuidora.c
 *
 *  Created on: 25 jun. 2020
 *      Author: pocho
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "utn.h"
#include "Articulo.h"
#include "parser.h"

/*
 *
 *
 */
int distribuidora_printAllArticles (LinkedList* pList , int lenList){
	int ret = -1;
	int i;
	eArticulo* this;
	if(pList != NULL && lenList >= 0){
		for(i = 0; i <lenList; i++){
			this = ll_get(pList,i);
			if(this != NULL){
				articulo_printArticle(this);
				ret = 1;
			}
		}
	}
	return ret;
}
/*
 *
 *
 */

int distribuidora_readFromFlie(LinkedList* pList){
	int ret = -1;
	FILE* file = openFileFromText();
	if(file != NULL){
		if(parser_articlesFromText(file,pList)){
			ret = 1;
		}
	}
	return ret;
}
/*
 *
 *
 */
int distribuidora_listArticles(LinkedList *pList) {
	int ret = -1;
	int lenLL = ll_len(pList);
	if (pList != NULL) {
		if (distribuidora_printAllArticles(pList, lenLL)) {
			ret = 1;
		}
	}
	return ret;
}
/*
 *
 *
 */
int distribuidora_sortArticles(LinkedList* pList){
	int ret = -1;

	if(pList != NULL){
		if(!ll_sort(pList,sortByArticle,1)){
			distribuidora_listArticles(pList);
			ret = 1;
		}
	}
	return ret;
}
/*
 *
 *
 */
int distribuidora_calculateDiscount(LinkedList* pList){
	int ret = -1;
	if(pList != NULL){
		if(ll_map(pList,articulo_discount)!= NULL){
			ret = 1;
			printf("MAP OK\n");
		}
	}
	return ret;
}
/*
 *
 *
 */
int distribuidora_saveOnFile(LinkedList* pList,char* path){
	int ret = -1;
	FILE* file;
	if(pList != NULL && path != NULL){
		file = writeFileFromText(path);
		if(file != NULL){
			if(saveAsText(file,pList)){
				ret = 1;
			}
		}
	}
	return ret;
}



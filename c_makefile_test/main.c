/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/01/2017 14:57:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jimmy Chen (JC), visperc@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "logger.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	print();
	printf("\nHello , This is My first C Program !\n");


	static void *p = &&tag;
	goto *p;
	printf("before tag\n");
	tag:
	printf("after tag\n");

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */


/*
Author: Christian Hernandez
 * 
 */

#include <stdio.h>

int main() {
	int i = 8, j = 5, k;      float x = 5.0;	
	//	i *= ++j; // 48 6
	//	i *= ( j++ -2); // 24 6
	//  k = 5 + ( j++ + --i );	// 17 7 6
	//  i %= ( j - 2 ); // 2 5
	// x -= i / j; // 4.0 8 5

	// printf("%f %d %d \n ",x, i,j);
	int a, b;
	float c, d;

	a=3.3;
	b=2.4;
	a=a/b;
	d=(a*1.0)/b;
	printf("%f %f\n", c, d);

	return 0;
}

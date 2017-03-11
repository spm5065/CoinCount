#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	int value;	

	if(argc == 1) {
		value = 100000;
		std::cout << "No argument specified, defaulting to change for $1000.00\r\n";
	} else {
		value = atoi(argv[1]);
		std::cout << "Counting ways to make change for $" << value << "\r\n";
		value = value * 100;
	}

	unsigned long ways = 0;
	for( unsigned int quarters = 0;; quarters++){
		if(25*quarters > value) break;
		for( unsigned int dimes = 0;; dimes++){
			if((25*quarters+10*dimes) > value) break;
			else ways += ((value - (25*quarters + 10*dimes)) / 5) + 1;
		}
	}
	
	std::cout << "The number of ways is: " << ways << "\r\n";

}

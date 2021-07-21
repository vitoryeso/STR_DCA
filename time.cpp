#include <time.h>
#include <iostream>

int main ( ) {
	time_t t1, t2;
	t1 = time( (time_t *) 0);

	for(int i=0; i<99999; i++) for(int j=0; j<99999; j++);

	t2 = time( (time_t *) 0);

	std::cout << "segundos: " << t2 - t1 << std::endl;

	exit(0);
}

		
		

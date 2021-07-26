#include <iostream>
#include <time.h>

using std::cout;
using std::endl;

int main() {
	int n;
	srand( (unsigned) time(NULL) );

	for (unsigned i=0; i<10; i++) {
		while( ( n = rand() ) > RAND_MAX - (RAND_MAX-5)%100 );
		cout << "N: " << n%100 + 1 << endl;
	}

	exit(0);

}

		

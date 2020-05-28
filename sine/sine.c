#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *argv0;

void
usage()
{
	fprintf(stderr, "Usage: %s [sample_rate]\n", argv0);
	exit(1);
}

int
main(int argc, char *argv[])
{
	argv0 = argv[0] ;
	int sr;
	if(argc==2) {
		sr = atoi(argv[1]) ;
		if(!(sr>0))
			usage();
	} else {
		usage();
	}

	for( int i=0 ; i<sr ; ++i ){
		float amp = sin(((float)i/sr)*M_PI*2.) ;
		fwrite(&amp, 4, 1, stdout);
	}
	
	return 0 ;
}

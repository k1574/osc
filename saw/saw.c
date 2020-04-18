#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char *argv0;

static void
usage()
{
	fprintf(stderr, "Usage: %s [sample_rate]\n", argv0);
	exit(1);
}

int
main(int argc, char *argv[])
{
	int sr;
	argv0 = argv[0] ;
	if(argc==2) {
		sr = atoi(argv[1]) ;
		if(!(sr>0))
			usage();
	} else {
		usage();
	}

	for( int i=0 ; i<sr ; ++i ){
		float amp = (float)i/sr ;
		fwrite(&amp, 4, 1, stdout);
	}

	return 0 ;
}

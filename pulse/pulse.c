#include <stdlib.h>
#include <stdio.h>
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

	int sr2 = sr/2 ;
	for( int i=0 ; i<sr ; ++i ){
		float amp = (i/sr2) ? 1 : -1 ;
		fwrite(&amp, 4, 1, stdout);
	}

	return 0 ;
}

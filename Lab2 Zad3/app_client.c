/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "app.h"


void
testowy_1(char *host)
{
	CLIENT *clnt;
	wyjscie  *result_1;
	wejscie  obliczenia_1_arg;
    int liczba1, liczba2;
    printf("\nPodaj wiadomosc: ");
    scanf("%d", &liczba1);
    
#ifndef	DEBUG
	clnt = clnt_create (host, TESTOWY, PROBNA, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	obliczenia_1_arg.x1 = liczba1;
	obliczenia_1_arg.x2 = liczba2;

	result_1 = obliczenia_1(&obliczenia_1_arg, clnt);
	if (result_1 == (wyjscie *) NULL) {
		clnt_perror (clnt, "call failed");
	}

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 1) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	testowy_1 (host);
exit (0);
}

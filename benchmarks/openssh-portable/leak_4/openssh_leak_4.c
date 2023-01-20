/*
	buggy parent : 7ad8b28
	commit id : 4f7cc2f8cc861a21e6dbd7f6c25652afb38b9b96
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "../stdio.h"
#include "../openssh.h"

char *host;
char *config_file_name;
int log_stderr_fd;

/* Prints a help message to the user.  This function never returns. */

static void
usage(void)
{
	fprintf(stderr,
"usage: ssh [-1246AaCfGgKkMNnqsTtVvXxYy] [-b bind_address] [-c cipher_spec]\n"
"           [-D [bind_address:]port] [-E log_file] [-e escape_char]\n"
"           [-F configfile] [-I pkcs11] [-i identity_file]\n"
"           [-L address] [-l login_name] [-m mac_spec]\n"
"           [-O ctl_cmd] [-o option] [-p port]\n"
"           [-Q cipher | cipher-auth | mac | kex | key]\n"
"           [-R address] [-S ctl_path] [-W host:port]\n"
"           [-w local_tun[:remote_tun]] [user@]hostname [command]\n"
	);
	exit(255);
}

/* redirect what would usually get written to stderr to specified file */
void
log_redirect_stderr_to(const char *logfile)
{
	int fd;

	if ((fd = open(logfile, O_WRONLY|O_CREAT|O_APPEND, 0600)) == -1) {
		fprintf(stderr, "Couldn't open logfile %s: %s\n", logfile,
		     strerror(errno));
		exit(1);
	}
	log_stderr_fd = fd;
}

int main (int ac, char **av)
{
	int opt = 3;
	char *logfile, *p, *cp;
	int optind = 1, optreset;
	extern char *optarg;

	logfile = NULL;
again:
	
	logfile = malloc(10);	/* allocation site, memory leak */
		
	
	opt -= optind;
	av += optind;
	
	
		if (opt > 1) {
			optind = 1;
			goto again;
		}
		

	return 0;
}

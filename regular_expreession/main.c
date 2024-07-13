

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <regex.h>
#include <malloc.h>

int main()
{
    char log_syslog[] = "2024-07-11T17:53:09+00:00 %AAA-LOCAL-I-SESSION: sudo: session closed for user root";
    char log_tech[] = "<6>1 2024-07-11T17:52:56+00:00 esr-15vf kernel - - - %SYSTEM-I-KERNEL: [    0.000000] Booting Linux on physical CPU 0x0";
    // printf("Hello World");
    char * str[2];
    str[0] = log_syslog;
    str[1] = log_tech;
    
    char pattern[] = "^<[0-9]{1,3}>1 ";

	regex_t * regexp = malloc(sizeof(regex_t));

	regmatch_t pmatch[1];

	if (regcomp(regexp, pattern, REG_EXTENDED) != 0)
		fprintf(stderr, "regcomp");   // my

    for (int i = 0; i < 2; i++) {
        printf("str before regular...");
        printf("%s\n", str[i]);
    	if (regexec(regexp, str[i], 2, pmatch, 0) == 0)
    	{
    		printf("PATTERN: log_tech - YES\n");   // my
    		printf("str: %s\n\n\n", str[i] + pmatch[0].rm_eo);
    		
    	}
    	else
    	{
    		printf("str: %s\n\n\n", str[i]);
    	}
        
    }

// 	if (regexec(regexp, log_syslog, 2, pmatch, 0) == 0)
// 	{
// 		printf("PATTERN: log_syslog - YES\n");   // my
// 		printf("pmatch: %s\n", log_syslog + pmatch[0].rm_so);
// 	}

	
	



    regfree(regexp);
    return 0;
}

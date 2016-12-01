/*
 * Jesse Deaton
 *
 * String generation program
 * for possible use with brute
 * force attack.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>
#include <ctype.h>

#define PROGRAM_NAME "simple_brute"
#define SUGGEST_HELP "Try \'%s --help\' for more information.\n"
#define MIN_ARGS 2

typedef struct program_params {
        bool lflg; //lowercase
        bool cflg; //capitals
        bool nflg; //numbers
        bool sflg; //special
        bool pflg; //inclue string
        bool permflg; //permutate over string
        bool hflg; //help
} program_params;

void print_help();

int proc_opt(int argc, char *argv[],
        struct program_params *params);

int main(int argc, char *argv[])
{
    program_params params = {0,0,0,0,0,0,0};

    /* test successful option parsing 
    int min_len = atoi(argv[1]);
    int max_len = atoi(argv[2]);
    printf("Min len: %d\n", min_len);
    printf("Max len: %d\n", max_len);

    //this must come after the above four lines
    proc_opt(argc, argv, &params);

    printf("lflag=%d\n", params.lflg);
    printf("cflag=%d\n", params.cflg);
    printf("nflag=%d\n", params.nflg);
    printf("sflag=%d\n", params.sflg);
    printf("pflag=%d\n", params.pflg);
    printf("penflag=%d\n", params.permflg);
    printf("hflag=%d\n", params.hflg);
    */

    return 0;
}

void print_help()
{
    // TODO
    // print simple message with improper usage
    // print this expanded message with --help
    printf("Usage: %s [min_length] [max_length] "
           "arg1 arg2 arg3...\n"
           "-l\t\tlowercase\n"
           "-c\t\tcapitals\n"
           "-n\t\tnumbers\n"
           "-s\t\tspecial characters\n"
           "-p[some string]\tincorporate custom string\n"
           "-P[some string]\tpermutate over custom string\n"
           "-h,\t\tprint this message\n", PROGRAM_NAME);
}

/*
 process options
 for documentation, see
 https://www.gnu.org/software/libc/manual/html_node/Using-Getopt.html#Using-Getopt
*/
int proc_opt(int argc, char *argv[],
        struct program_params *params)
{
    // TODO
    // use stderr correctly(?) so that program name
    // doesn't have to be passed twice
    if(argc < 2)
        fprintf(stderr, "%s: missing file operand\n"
            SUGGEST_HELP, PROGRAM_NAME, PROGRAM_NAME);

    static struct option const long_options[] = {
        {"help", no_argument, NULL, 'h'}
    };

    int c;
    while ((c = getopt_long(argc, argv, "lcnsp:P:h",
                    long_options, NULL)) != -1) {
        switch (c) {
            case 'l': params->lflg = 1;
                break;
            case 'c': params->cflg = 1;
                break;
            case 'n': params->nflg = 1;
                break;
            case 's': params->sflg = 1;
                break;
            case 'p': params->pflg = 1;
                break;
            case 'P': params->permflg = 1;
                break;
            case 'h':
                params->hflg = 1;
                print_help();
                break;
            case '?':
                if(optopt == 'p' || optopt == 'P')
                    fprintf(stderr, SUGGEST_HELP, PROGRAM_NAME);
                else
                    fprintf(stderr, SUGGEST_HELP, PROGRAM_NAME);
                break;
            default:
                fprintf(stderr, "proc_opt\n");
        }
    }
    return 0;
}


#include<argp.h>
#include<common.h>
#include<file.h>

#define SHELL 0x01
#define PY2   0x02
#define PY3   0x03
#define BASH  0x04
#define PHP   0x05
#define PERL  0x06

const char *argp_program_version = "ESFM 1.69";
const char *argp_program_bug_address = "<sanaf@0x30c4.dev>";
static char doc[] = "CLI tool for making executable files";
static char args_doc[] = "[FILENAME]";
static struct argp_option options[] = { 
    { "custom",     'c',    "EXE_NAME", 0, "For custom interpreter"  },
    { "sh",         SHELL,  "FILE",     0, "For sh interpreter"      },
    { "py3",        PY3,    "FILE",     0, "For python3 interpreter" },
    { "py2",        PY2,    "FILE",     0, "For python2 interpreter" },
    { "bash",       BASH,   "FILE",     0, "For bash interpreter"    },
    { "php",        PHP,    "FILE",     0, "For php interpreter"     },
    { "prel",       PERL,   "FILE",     0, "For prel interpreter"    },
    { 0 } 
};

struct arguments {
    char *exe;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;

    if (state->argc == 1)
        argp_error(state, "Not enough arguments or options!!"); 

    switch (key) {
        case 'c': 
            printf("-> %s\n", state->argv[state->next]);
            break;
        case SHELL:
            create_or_update(arg, "sh");
            break;
        case PY3:
            create_or_update(arg, "python3");
            break;
        case PY2:
            create_or_update(arg, "python2");
            break;
        case BASH:
            create_or_update(arg, "bash");
            break;
        case PHP:
            create_or_update(arg, "php");
            break;
        case PERL:
            create_or_update(arg, "perl");
            break;
        case ARGP_KEY_ARG: 
            /* printf("%s\n", arg); */
            if (state->arg_num >= 1)
                /* Too many arguments. */
                argp_error(state, "Too many arguments!!");
            break;
        /* case ARGP_KEY_END: */
            /* break; */
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int main(int argc, char *argv[]){

    struct arguments arguments;

    arguments.exe = NULL;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    /* printf("ARG1 = %s\n", arguments.exe); */

    /* create_file("test/test.py", "python3"); */

    /* append_to_file("test/test.py", "test/test.py.tmp_filejlkncnvd"); */

	return 0;
}

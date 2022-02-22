#include<argp.h>
#include<common.h>

#define SHELL 0x01
#define PY2   0x02
#define PY3   0x03
#define BASH  0x04
#define PHP   0x05
#define PERL  0x06

const char *argp_program_version = "ESFM 1.69";
const char *argp_program_bug_address = "<sanaf@0x30c4.dev>";
static char doc[] = "CLI tool for making executable files";
static char args_doc[] = "[FILENAME]...";
static struct argp_option options[] = { 
    { "custom",     'c',    "EXE_NAME", 0, "For custom interpreter"  },
    { "sh",         SHELL,  0,          0, "For sh interpreter"      },
    { "py3",        PY3,    0,          0, "For python3 interpreter" },
    { "py2",        PY2,    0,          0, "For python2 interpreter" },
    { "bash",       BASH,   0,          0, "For bash interpreter"    },
    { "php",        PHP,    0,          0, "For php interpreter"     },
    { "prel",       PERL,   0,          0, "For prel interpreter"    },
    { 0 } 
};

struct arguments {
    char *exe;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;
    switch (key) {
        case 'c': 
            arguments->exe = arg;
            break;
        case SHELL:
            arguments->exe = "sh";
            break;
        case PY2:
            arguments->exe = "python3";
            break;
        case PY3:
            arguments->exe = "python2";
            break;
        case BASH:
            arguments->exe = "bash";
            break;
        case PHP:
            arguments->exe = "php";
            break;
        case PERL:
            arguments->exe = "perl";
            break;
        case ARGP_KEY_ARG: 
            if (state->arg_num >= 1)
                /* Too many arguments. */
                argp_error(state, "Too many arguments!!");
            break;
        case ARGP_KEY_END:
            if (state->arg_num < 1)
                /* Not enough arguments. */
                argp_error(state, "Not enough arguments!!");
            break;
        default: return ARGP_ERR_UNKNOWN;
    }
    printf("%s\n", state->arg);
    return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int main(int argc, char *argv[]){

    struct arguments arguments;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    printf("ARG1 = %s\n", arguments.exe);

	return 0;
}

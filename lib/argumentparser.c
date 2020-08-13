#include "argumentparser.h"

int arg_parser(int argc, char *argv[], struct FILE_NAME_TYPE file_name_type_array[]) { 
    int c;
    int file_struct_array_size = 0;
    static struct option long_options[] = {
        {OPTION_BIO[BASH], required_argument, 0, BASH },
        {OPTION_BIO[SH],   required_argument, 0, SH   },
        {OPTION_BIO[ZSH],  required_argument, 0, ZSH  },
        {OPTION_BIO[FISH], required_argument, 0, FISH },
        {OPTION_BIO[PHP],  required_argument, 0, PHP  },
        {OPTION_BIO[PY2],  required_argument, 0, PY2  },
        {OPTION_BIO[PY3],  required_argument, 0, PY3  },
        {OPTION_BIO[RUBY], required_argument, 0, RUBY },
        {OPTION_BIO[PERL], required_argument, 0, PERL },
        {OPTION_BIO[CUST], required_argument, 0, CUST },
        {OPTION_BIO[HELP], no_argument,       0, 'h'  },
        {0,                0,                 0,  0   }
    };

    while (1) {
        int option_index = 0;
        
        c = getopt_long(argc, argv, "h",
                    long_options, &option_index);

        if (c == -1) break;

        if (file_struct_array_size > FILE_NAME_TYPE_ARRAY_MAX){
            printf("too much arguments!!\n");
            exit(0);
        }

        if (c >= BASH && c <= CUST){
            if (c == CUST){
                file_name_type_array[file_struct_array_size].type = CUST;
                memcpy(file_name_type_array[file_struct_array_size++].file_name, optarg, strlen(optarg));
                printf("Custom path!! : %s \n", optarg);
            }else{
                if (strlen(optarg) > NAME_MAX){
                    printf("file name too long\n");
                    exit(0);
                }
                file_name_type_array[file_struct_array_size].type = c;
                memcpy(file_name_type_array[file_struct_array_size++].file_name, optarg, strlen(optarg));
            }
        }  
        else if (c == 'h')
            printf("help\n");
        else if (c == '?')
            printf("error\n");
        else
            printf("?? getopt returned character code 0%o ??\n", c);
    }

    if (optind < argc) {
        printf("non-option ARGV-elements: ");
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
    }
    return file_struct_array_size;
}
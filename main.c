#include "lib/common.h"
#include "lib/file_maker.h"
#include "lib/argumentparser.h"


int main(int argc, char *argv[]){
	struct FILE_NAME_TYPE file_name_type_array[FILE_NAME_TYPE_ARRAY_MAX];
	int array_size = arg_parser(argc, argv, file_name_type_array);

	for (int i = 0; i < array_size; ++i){
		printf("type : %d | file name : %s\n", file_name_type_array[i].type, file_name_type_array[i].file_name);
		file_maker(file_name_type_array[i].file_name, file_name_type_array[i].type);
	}

	return 0;
}
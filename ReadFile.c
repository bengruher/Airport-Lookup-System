#include <stdio.h>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

int main (int argc, char *argv[])
{
	char *fileName;
	vector <string> parseList;
	FILE *inFile;
	char word[255];
	if (argc < 2) {
	  printf ("usage: %s server_host\n", argv[0]);
	  exit (1);
	}
	fileName = argv[1];
	inFile = fopen(fileName, "r");
	while(inFile){
		if (fgets(word, 255, inFile) != NULL){
			//puts(word);
			parseList.push_back(word);
		}
		if(feof(inFile))
        break;
	}
	fclose(inFile);
	
	printf("the size is:%d\n", parseList.size());

	for( int i = 0; i < parseList.size(); i++ ){
		printf("%s", parseList[i].c_str());
	}
	
	exit (0);
}

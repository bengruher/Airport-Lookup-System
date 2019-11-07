/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "PlacesToAirport.h"
#include "kdtree.c"
#include "distance.c"
#include <fstream>
#include <string>
#include <iostream>
#include <locale>
#include <vector>
using namespace std;

char *trim(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}

void reassign(kd_node_t* x, kd_node_t* y){
	strcpy(x->city, y->city);
	strcpy(x->code, y->code);
	x->x[0] = y->x[0];
	x->x[1] = y->x[1];
	x->left = y->left;
	x->right = y->right;
	x->x[2] = y->x[2];
}

int partition(kd_node_t list[], int left, int right, int dim) {
  int i, j;
  kd_node_t node;
  double pivot = list[left].x[dim];
  i = left; j = right+1;
  while(1){
	do ++i;
	while( list[i].x[dim] <= pivot && i <= right );
	do --j;
	while( list[j].x[dim] > pivot );
	if( i >= j )
	  break;
	node = list[i];
	list[i] = list[j];
	list[j] = node;
  }
  node = list[left];
  list[left] = list[j];
  list[j] = node;
  return j;
}

void quickSort(kd_node_t list[], int left, int right, int dim) {
	if( left < right ){
		int i = partition(list, left, right, dim);
		quickSort(list, left, i-1, dim);
		quickSort(list, i+1, right, dim);
  }
}

void inorder(kd_node_t* ptr){
  if(!ptr){
	return;
  }
	inorder(ptr->left);
	printf("%s, %f\n", ptr->city, ptr->x[0]);
	inorder(ptr->right);
}


void kNearest(kd_node_t *head, kd_node_t list[], double coords[], int dim){
	if(head!=NULL){
		if(head->x[dim]>coords[dim]){
			kNearest(head->left, list, coords, (dim+1)%2);
			if(list[4].x[0] == 0 && list[4].x[1] == 0){
				strcpy(list[4].city, head->city);
				strcpy(list[4].code, head->code);
				strcpy(list[4].state, head->state);
				list[4].x[0] = head->x[0];
				list[4].x[1] = head->x[1];
				list[4].left = head->left;
				list[4].right = head->right;
				list[4].x[2] = distance(coords[0], coords[1], head->x[0], head->x[1], 'M');
				quickSort(list, 0, 4, 2);
			}
			else if(distance(coords[0], coords[1], head->x[0], head->x[1], 'M' ) <
					distance(coords[0], coords[1], list[4].x[0], list[4].x[1], 'M')){
				strcpy(list[4].city, head->city);
				strcpy(list[4].code, head->code);
				strcpy(list[4].state, head->state);
				list[4].x[0] = head->x[0];
				list[4].x[1] = head->x[1];
				list[4].left = head->left;
				list[4].right = head->right;
				list[4].x[2] = distance(coords[0], coords[1], head->x[0], head->x[1], 'M');
				quickSort(list, 0, 4, 2);
			}
			double lat1 = coords[0];
			double lon1 = coords[1];
			double lat2 = head->x[0];
			double lon2 = head->x[1];
			if(dim == 1){
				lat2 = lat1;
			}
			else{
				lon2 = lon1;
			}
			if(list[4].x[0] == 0 && list[4].x[1] == 0 || distance(lat1, lon1, lat2, lon2,'M') <
					distance(list[4].x[0],list[4].x[1], coords[0],coords[1],'M')){
				kNearest(head->right, list, coords, (dim+1)%2);
			}
		}
		else{
			kNearest(head->right, list, coords, (dim+1)%2);
			if(list[4].x[0] == 0 && list[4].x[1] == 0){
				strcpy(list[4].city, head->city);
				strcpy(list[4].code, head->code);
				strcpy(list[4].state, head->state);
				list[4].x[0] = head->x[0];
				list[4].x[1] = head->x[1];
				list[4].left = head->left;
				list[4].right = head->right;
				list[4].x[2] = distance(coords[0], coords[1], head->x[0], head->x[1], 'M');
				quickSort(list, 0, 4, 2);
			}
			else if(distance(coords[0], coords[1], head->x[0], head->x[1], 'M' ) <
					distance(coords[0], coords[1], list[4].x[0], list[4].x[1], 'M')){
				strcpy(list[4].city, head->city);
				strcpy(list[4].code, head->code);
				strcpy(list[4].state, head->state);
				list[4].x[0] = head->x[0];
				list[4].x[1] = head->x[1];
				list[4].left = head->left;
				list[4].right = head->right;
				list[4].x[2] = distance(coords[0], coords[1], head->x[0], head->x[1], 'M');
				quickSort(list, 0, 4, 2);
			}
			double lat1 = coords[0];
			double lon1 = coords[1];
			double lat2 = head->x[0];
			double lon2 = head->x[1];
			if(dim == 1){
				lat2 = lat1;
			}
			else{
				lon2 = lon1;
			}
			if(list[4].x[0] == 0 && list[4].x[1] == 0 || distance(lat1, lon1, lat2, lon2,'M') <
					distance(list[4].x[0],list[4].x[1], coords[0],coords[1],'M')){
				kNearest(head->left, list, coords, (dim+1)%2);
			}
		}
	}
}

returnTypeA *
ptoa_1_svc(LatLon *argp, struct svc_req *rqstp)
{
    static returnTypeA  result;
	xdr_free((xdrproc_t)xdr_returnTypeA, (char*)&result);
	
	vector<airports> fileToStruct;
	vector <string> parseList;
	FILE *inFile;
	char word[255]; 
	//inFile = fopen(fileName, "r");
	inFile = fopen("airport-locations.txt", "r");
	while(inFile){
		if (fgets(word, 255, inFile) != NULL && word != "\n"){
			
			if(strlen(word) > (size_t)3){
				parseList.push_back(word);
			}
		}
		if(feof(inFile)){
			break;
		}
	}
	
	kd_node_t kdNode[parseList.size() - 1]; 
	kd_node_t* hdNode = &kdNode[0];
	kd_node_t* iter = hdNode;

	for(int i=1; i < parseList.size(); i++){
		if(parseList[i].size() < 10){
			continue;
		}
		string CODE;
		CODE = parseList[i].substr(1,3);
		char* aCode = new char[CODE.length() + 1];
		strcpy(aCode, CODE.c_str());
		
		string LAT;
		LAT = parseList[i].substr(6,5); 
		string LON;
		LON = parseList[i].substr(11,7);
		int NAMESIZE;
		NAMESIZE = (parseList[i].substr(20,30).size()) - 1; 
		string NAME = parseList[i].substr(20, NAMESIZE); 
		char* aName = new char[NAME.length() + 1];
		strcpy(aName, NAME.c_str());
		size_t bla = NAME.find(",");
		string city = NAME.substr(0, (int)bla);
		char* aCity = new char[city.length() + 1];
		strcpy(aCity, city.c_str());
		aCity = trim(aCity);
		string state = NAME.substr((int)bla+1,2);
		char* aState = new char[state.length() + 1];
		strcpy(aState, state.c_str());
		
		char* aLat = new char[LAT.length() + 1];
		strcpy(aLat, LAT.c_str());
		
		char* aLon = new char[LON.length() + 1];
		strcpy(aLon, LON.c_str());
		
		double aaaalat = atof(aLat);
		double aaaalon = atof(aLon);
		
		char bCity[64];
		strncpy(bCity,aCity, 63);
		
		char bCode[4];
		strncpy(bCode,aCode, 4);
		
		char bState[3];
		strncpy(bState,aState, 3);
		
		iter->x[0] = aaaalat;
		iter->x[1] = aaaalon;
		strcpy(iter->city,bCity);
		stpcpy(iter->code,bCode);
		strcpy(iter->state,bState);
		iter++;
		
		airports* newstruct = new airports();
		strncpy(newstruct->name, aCity, 63);
		strncpy(newstruct->code, aCode, 3);
		strncpy(newstruct->state, aState, 2);
		newstruct->lat = aaaalat;
		newstruct->lon = aaaalon;

		fileToStruct.push_back(*newstruct);
		
	}
	
	hdNode = make_tree(kdNode, parseList.size()-1, 0, 2);
    	
	double coords[2];
	
	coords[0] = argp->lat;
	coords[1] = argp->lon;
	
	kd_node_t list[5];
	
	for(int i = 0; i<5; i++){
		list[i].x[0]=0;
		list[i].x[1]=0;
		list[i].x[2]=10000;
		strcpy(list[i].city, "hello");
		strcpy(list[i].code, "AAA");
		strcpy(list[i].state, "AA");
	}
	
	kNearest(hdNode, list, coords, 2);
	
    airports** airportList;
    delete result.returnTypeA_u.resultA;
    airportList = &result.returnTypeA_u.resultA;
	
	int counter = 0;
	
	//make this list 6 later
	for(int i = 0; i < 6; i++){
		airports* p = new airports();
		strncpy(p->name, list[counter].city, 63);
		strncpy(p->code, list[counter].code, 3);
		strncpy(p->state, list[counter].state, 2);
		p->lat = list[counter].x[0];
		p->lon = list[counter].x[1];
		p->dist = list[counter].x[2];
		airports* temp = (*airportList);
		if(temp == NULL){
			strncpy(p->name, "City", 63);
			strncpy(p->state, "ST", 2);
			p->lat = 30.33;
			p->lon = 70.77;
			(*airportList) = p;
			counter--;
		}
		else{
			while(temp->next){
				temp = temp->next;
			}
			temp->next = p;
		}
		counter++;
	}
	
    fclose(inFile);
	/*
	delete aCode;
	delete aName;
	delete aLat;
	delete aLon;
	delete aCity;
	delete aState;
	*/
    return &result;
}

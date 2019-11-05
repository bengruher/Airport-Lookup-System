//ClientToPlaces.x
typedef struct places places;
typedef struct city city;

struct places {
	char code[4];
	char name[64];
	char state[3];
	double dist;
	double lat;
	double lon;
	struct places *next;
};

struct city {
	char state[3];
	char city[64];
};

/*Union*/
union returnTypeC switch (int err){
    case 0:
        places *resultC;
    default:
        void;
};

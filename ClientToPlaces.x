//ClientToPlaces.x
typedef struct places places;
typedef struct city city;

struct places {
	string code<4>;
	string name<64>;
	string state<3>;
	double dist;
	double lat;
	double lon;
	struct places *next;
};

struct city {
	string state<3>;
	string city<64>;
};

/*Union*/
union returnTypeC switch (int err){
    case 0:
        places *resultC;
    default:
        void;
};

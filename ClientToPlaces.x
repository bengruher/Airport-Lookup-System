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

/*IDL*/
program CLIENT_TO_PLACES {
    version CLIENT_TO_VERS {
        returnTypeC CToP(city*) = 1;
    } = 1;
} = 0x27077077;

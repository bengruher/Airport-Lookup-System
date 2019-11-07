/*ClientToPlaces.x*/

/*data*/
struct places{
    char code[4];
    char name[64];
    char state[3];
    double dist;
    double lat;
    double lon;
    places* next;
};

struct city{
    char state[3];
    char city[64];
};

/*union*/
union returnTypeC switch (int err){
    case 0:
        places* resultC;
    default:
        void;
};

/*IDL*/
program CLIENT_TO_PLACES {
    version CLIENT_TO_VERS {
        returnTypeC CToP(city*) = 1;
    } = 1;
} = 0x23465879;

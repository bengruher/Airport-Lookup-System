//PlacesToAirport.x
struct airports{
    string code<4>;
    string name<64>;
    string state<3>;
    double lat;
    double lon;
    double dist;
    airports* next;
};

struct LatLon{
    double lat;
    double lon;
};

/*Union*/
union returnTypeA switch (int err){
    case 0:
        airports* resultA;
    default:
        void;
};

/*IDL*/
program PLACES_TO_AIRPORT {
    version PLACES_TO_VERS {
        returnTypeA PToA(LatLon*) = 1;
    } = 1;
} = 0x28088088;

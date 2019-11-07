# Airport-Lookup-System
The  project  aims  to  design  and  implement  a  three-tiered  client-server system to serve a  user’s airport  lookups  by  using  RPCs.  The  system  consists  of  three  components:  the  client,  the  places server and the airports server. 

HW #4 - Design
Team members: 
Rueben Tiow - IDL Programs, Debugging, RPC communication, KD-Tree, KNN, Prefix Tree
Ben Gruher - Debugging, RPC communication, KD-Tree, KNN, Prefix Tree

Data Structures and algorithms to use:
1. KD-Tree (https://github.com/questbeat/kdtree): Improves performance by constructing a  2 dimensional KD tree from the airport locations and then organize the nodes in such a way that it alternates between latitude and longitude.
2. KNN algorithm: This algorithm is used to improve performance by finding the 5 nearest neighbor to a point on a 2D KD Tree.
3. Prefix tree: Used to optimize the search from the client’s query. (Looks through places2k.txt)
4. spherical distance formula: Provided and is used to calculate the spherical distance between two points

Instructions:
Run PlacesToAirports server, use airport-locations.txt
    ./PlacesToAirports_server "<filename.txt>"&
Run ClientToPlaces server, use places2k.txt
    ./ClientToPlaces_server "<filename.txt>"&
Run Client
    ./ClientToPlaces_client localhost "<city>" <two letter state>
    OR
    ./ClientToPlaces_client <ClientToPlaces_server host> "<city>" <two letter state>

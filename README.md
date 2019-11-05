# Airport-Lookup-System
The  project  aims  to  design  and  implement  a  three-tiered  client-server system to serve a  user’s airport  lookups  by  using  RPCs.  The  system  consists  of  three  components:  the  client,  the  places server and the airports server. 

HW #4 - Design
Team members: 
Rueben Tiow - IDL Programs, Debugging, RPC communication, KD-Tree, KNN, Prefix Tree
Ben Gruher - Debugging, RPC communication, KD-Tree, KNN, Prefix Tree

Data Structures and algorithms to use:
KD-Tree (https://github.com/questbeat/kdtree): Improves performance by constructing a  2 dimensional KD tree from the airport locations and then organize the nodes in such a way that it alternates between latitude and longitude.
KNN algorithm: This algorithm is used to improve performance by finding the 5 nearest neighbor to a point on a 2D KD Tree.
Prefix tree: Used to optimize the search from the client’s query. (Looks through places2k.txt)
spherical distance formula: Provided and is used to calculate the spherical distance between two points

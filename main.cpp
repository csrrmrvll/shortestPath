#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include "Heap.h"

using namespace std;

template<typename Container>
ostream & operator<<(ostream & out, const Container & c)
{
    copy(begin(c), --end(c), ostream_iterator<int>(cout,","));
    cout << *(--end(c)) << endl;
    return out;
}

Graph read()
{
    Graph g;
    ifstream is;
//    is.open("dijkstraData.txt",ios::in);
    is.open("tc1.txt",ios::in);
//    is.open("tc2.txt",ios::in);
//    is.open("tc3.txt",ios::in);
//    is.open("tc4.txt",ios::in);
//    is.open("tc5.txt",ios::in);
    if (is.is_open())
    {
        string line;
        while (getline(is,line))
        {
            using Vector = vector<int>;
            Vector v;
            istringstream iss(line);
            copy(istream_iterator<int>(iss),istream_iterator<int>(), back_insert_iterator<Vector>(v));
            g.insert(make_pair(Vertex(v[0]), Vertex(v[1])));
        }
    }
    else
    {
        throw runtime_error("File is not open!!");
    }
    is.close();
    return make_pair(g, gRev);
}

int main()
{
    ShortestPath sp{g};
    ShortestPaths sps = sp.compute(),
//    const vector<int> result = { sp[7], sp[37], sp[59], sp[82], sp[99], sp[115], sp[133], sp[165], sp[188], sp[197] };
    const vector<int> result;
    transform(sps.begin(),sps.end(),[](auto & v) { result.emplace_back(v.second); });
    cout << "Shortest paths from node 1 to nodes {7,37,59,82,99,115,133,165,188,197}: " << result << endl;
    return 0;
}

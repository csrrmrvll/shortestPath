#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <utility>
#include <vector>
#include "ShortestPath.h"

using namespace std;
using Vector = vector<int>;

ostream & operator<<(ostream & out, const Vector & v)
{
    const Vector::const_iterator last = --end(v);
    copy(begin(v), last, ostream_iterator<int>(cout,","));
    cout << *last << endl;
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
            Vector v;
            istringstream iss(line);
            copy(istream_iterator<int>(iss),istream_iterator<int>(), back_inserter(v));
            g.insert(make_pair(Vertex(v[0]), Vertex(v[1])));
        }
    }
    else
    {
        throw runtime_error("File is not open!!");
    }
    is.close();
    return g;
}

int main()
{
    ShortestPath sp{read()};
    DijkstraScores ds = sp.compute();
//    const vector<int> result = { sp[7], sp[37], sp[59], sp[82], sp[99], sp[115], sp[133], sp[165], sp[188], sp[197] };
    Vector result;
    transform(ds.begin(),ds.end(),back_inserter(result),[](auto & sp) { return sp.second; });
    cout << "Shortest paths from node 1 to nodes {7,37,59,82,99,115,133,165,188,197}: " << result << endl;
    return 0;
}

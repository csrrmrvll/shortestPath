#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include "ShortestPath.h"

using namespace std;
using Vector = vector<int>;

ostream & operator<<(ostream & out, const Edge & e)
{
    cout << e.first << "," << e.second;
    return out;
}

template<typename T>
ostream & operator<<(ostream & out, const vector<T> & v)
{
    for (auto t : v) out << t << ' ';
    return out;
}

Graph read()
{
    Graph g;
    ifstream is;
    is.open("dijkstraData.txt",ios::in);
//    is.open("tc1.txt",ios::in);
//    is.open("tc2.txt",ios::in);
//    is.open("tc3.txt",ios::in);
//    is.open("tc4.txt",ios::in);
//    is.open("tc5.txt",ios::in);
//    is.open("tc6.txt",ios::in);
//    is.open("tc7.txt",ios::in);
    if (is.is_open())
    {
        string line;
        while (getline(is,line))
        {
            istringstream iss(line);
            Vertex v;
            Edges es;
            for (istream_iterator<string> issit = istream_iterator<string>(iss);
                issit != istream_iterator<string>(); ++issit)
            {
                const string s = *issit;
                string::size_type it = s.find(',');
                if (it == string::npos)
                {
                    istringstream i(s);
                    i >> v;
                }
                else
                {
                    const string    s1 = s.substr(0,it),
                                    s2 = s.substr(++it);
                    istringstream   i1(s1),
                                    i2(s2);
                    Vertex w;
                    i1 >> w;
                    g.insert(make_pair(w,Edges()));
                    Distance d;
                    i2 >> d;
                    const Edge e = make_pair(w,d);
                    g[v].emplace_back(e);
                }
            }
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
    const vector<int> result = { ds[7], ds[37], ds[59], ds[82], ds[99], ds[115], ds[133], ds[165], ds[188], ds[197] };
//    Vector result;
//    transform(ds.begin(),ds.end(),back_inserter(result),[](auto & sp) { return sp.second; });
    cout << "Shortest paths from node 1 to nodes {7,37,59,82,99,115,133,165,188,197}: " << endl << result << endl;
    return 0;
}

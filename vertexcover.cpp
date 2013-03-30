#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
namespace IO{
  const int SIZE = 1 << 19;
  char buff[SIZE], *p = buff + SIZE;
	char read_char(){
		if( p == buff + SIZE ){
		    fread( buff, 1, SIZE, stdin );
		    p = buff;
		}
		return *(p++);
	}
	inline int read_str(char * s){
		char c;
		while( isspace(c = read_char()) );
		while( !isspace(c = read_char()) ) {
			*s=c;
			s++;
		}
		*s=0;
		return 0;
	}

	inline int read_int(){
		char c,pc;
		pc=c=read_char(); while( (!isdigit(c)) ) {pc=c;c=read_char();}
		int r = c-'0';
		while( isdigit( c = read_char() ) )
			r = 10*r + c - '0';
		if(pc=='-')
			return -1*r;
		return r;
	}
}
using namespace IO;
using namespace std;
#define MAX 100002
int degree[MAX]={0};
set<int> vertices;
vector<int> *graph;
int main()
{
    int n;
    n=read_int();
    for(int i=1;i<=n;i++)
        vertices.insert(i);
    graph=new vector<int> [n+1];
    for(int i=1;i<n;i++)
    {
        int x,y;
        //cin>>x>>y;
        x=read_int();
        y=read_int();
        graph[x].push_back(y);
        graph[y].push_back(x);
        degree[x]++;
        degree[y]++;
        if(degree[x]==2)
            vertices.erase(x);
        if(degree[y]==2)
            vertices.erase(y);

    }
    set<int>::iterator p;
    vector<int>::iterator itr;
    int counter=0;
    int tedges=0;

    while(!vertices.empty())
    {
        p=vertices.begin();
        int adj;
        for(itr=graph[*p].begin();itr!=graph[*p].end();itr++)
            if(degree[*itr]>0)
            {
                adj=*itr;
            }
        counter++;
        vertices.erase(*p);
        for(itr=graph[adj].begin();itr!=graph[adj].end();itr++)
        {
            if(degree[*itr]>0)
            {
                degree[adj]--;
                tedges++;
                vertices.erase(*itr);
                degree[*itr]--;
                if(degree[*itr]==1)
                {
                    vertices.insert(*itr);
                }

            }
        }
        vertices.erase(adj);
        if(tedges==(n-1))
            break;
    }
    cout<<counter<<endl;
    return 0;
}

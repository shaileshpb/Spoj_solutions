#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
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
int main()
{
	int tc;
	tc=read_int();
	while(tc--)
	{
		int n;
		n=read_int();
		vector<pair<pair<int,int>,int> > v;
		for (int i = 0; i < n; ++i)
		{
			int s,f,cost;
			//cin>>s>>f>>cost;
			s=read_int();
			f=read_int();
			cost=read_int();

			pair<int,int> p;
			p.first=f+s;
			p.second=s;
			v.push_back(make_pair<pair<int,int>,int>(p,cost));
		}
		sort(v.begin(), v.end());
		int size=v.size();
		int p[n+1];
		p[0]=0;
		for (int i = 0; i < size; ++i)
		{
		    int interval=0;
		    for(int j=i-1;j>=0;j--)
		    {
		        if(v[i].first.second>v[j].first.first)
		        {
		            interval=j+1;
		            break;
		        }

		    }
		    p[i+1]=interval;
		}

		long long int opt[n+3];
		opt[0]=0;
		for(int i=0;i<n;i++)
		{
		    opt[i+1]=max(v[i].second+opt[p[i+1]],opt[i]);
		}
		cout<<opt[n]<<endl;
	}
	return 0;
}

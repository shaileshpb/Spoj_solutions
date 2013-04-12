/*
	In this program I have implemented an simple inserter for sparse matrix.
	The inputs given to inserter(or program)  will be according to the example given in mtl4_fenics.pdf.
	This program also performs a simple matrix_vector multiplication using inserter datastructure.
	Hope you like it. :-)
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <functional>
using namespace std;
//#include <dune/common/fmatrix.hh>
class Inserter
{
	private:
		vector<int> *inserter;
		vector<int> *Values;
		map<pair<int,int>,int> container;
		int row,col;

	public:
	Inserter(int r,int c)
	{
		this->row=r;
		this->col=c;
		inserter=new vector<int>[r];
		Values=new vector<int>[r];
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
			{
				inserter[i].push_back(-1);
				Values[i].push_back(-1);
			}
	}

	//Adding data into inserter and Values
	void add(int r,int c,int val)
	{
		int found=0;

		//To check whether slot is full, if yes then put the data into container
		if(inserter[r][this->col-1]!=-1)
		{
			container.insert(make_pair<pair<int,int>,int>(make_pair<int,int>(r,inserter[r][this->col-1]),Values[r][this->col-1]));
		}

		for(int i=0;i<this->col;i++)
		{
			if(inserter[r][i]==-1)
			{
				inserter[r][i]=c;
				Values[r][i]=val;
				found=1;
			}
			else if(inserter[r][i]>c)
			{
			    //shifting data to right side
				for(int j=this->col-1;j>i;j--)
				{
					inserter[r][j]=inserter[r][j-1];
					Values[r][j]=Values[r][j-1];
				}
				inserter[r][i]=c;
				Values[r][i]=val;
				found=1;
				break;
			}
			if(found==1)
				break;
		}

	}

    //To print columns and values
	void printInserter()
	{
		for(int i=0;i<this->row;i++)
		{
		    cout<<"row "<<i<<"->\n";
		    for(int j=0;j<this->col;j++)
		    {
		        if(inserter[i][j]==-1)
		            continue;
		        cout<<inserter[i][j]<<" ";
		    }
		    cout<<endl;
		    for(int j=0;j<this->col;j++)
		    {
		        if(Values[i][j]==-1)
		            continue;
		        cout<<Values[i][j]<<" ";
		    }
		    cout<<endl;
		}
	}

    //To perform matrix-vector multiplication
	template<class T>
	T matrix_Vector_Product(T &x)
	{
	    T y(this->row,0);
	    for(int i=0;i<this->row;i++)
	    {
	        for(int j=0;j<this->col;j++)
	        {
	            if(Values[i][j]==-1)
                    continue;
                y[i]+=(Values[i][j]*x[inserter[i][j]]);
	        }
	    }
	    return y;
	}

	~Inserter()
	{
        }
};
int main()
{
    //creating inserter with slot of 3

    Inserter ins(3,3);

    //Adding data to inserter
    ins.add(0,0,1);
    ins.add(0,2,2);

    ins.add(1,3,3);

    ins.add(2,1,4);
    ins.add(2,4,5);

    //Printing columns and values
    ins.printInserter();


    vector<int> x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    vector<int> y(3);
    /*
    *   y=ins*x
    *  This is call  matrix_Vector_Product method to perform multiplication of original matrix with
    *  vector x using newly created inserter datastructure
    */
    y=ins.matrix_Vector_Product(x);

    //Printing the result of matrix-vector multiplication
    cout<<"Result of matrix-vector multiplication\n";
    for(int i=0;i<y.size();i++)
        cout<<y[i]<<" ";

    return 0;
}

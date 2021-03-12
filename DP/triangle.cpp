#include<iostream>
#include<vector>

using namespace std;



int minimumTotal(vector<vector<int> >& triangle) {
    int r=triangle.size();
    cout<<r<<endl;
    // for(int i=0; i<r; i++){
    //     for(int j=0; j<=i;j++){
    //         triangle[i][j]=triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]);
    //     }
    // }
    for (int i = 0; i < r; ++i)
    {
    	/* code */
    	for (int j = 0; j <=i; ++j)
    	{
    			
    		    triangle[i][j]=triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]);
    	}
    }

    for (int i = 0; i < r; ++i)
    {
    	/* code */
    	for (int j = 0; j <=i; ++j)
    	{
    		cout<<triangle[i][j]<<" ";
    		/* code */
    	}
    	cout<<endl;
    }
    return triangle[r-1][r-1];   
}



int main(){
	vector<vector<int> > triangle;
	triangle.resize(4);
	triangle[0].push_back(1);
	triangle[1].push_back(3);
	triangle[1].push_back(4);
	triangle[2].push_back(6);
	triangle[2].push_back(5);
	triangle[2].push_back(7);
	triangle[3].push_back(4);
	triangle[3].push_back(1);
	triangle[3].push_back(8);
	triangle[3].push_back(3);
	cout<<minimumTotal(triangle);
	return 0;
}
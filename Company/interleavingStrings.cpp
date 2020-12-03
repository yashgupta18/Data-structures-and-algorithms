#include <iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
using namespace std; 



int printIls(char str1[], char str2[], char str3[], int n1, int n2, int n3){
	if(n1+n2!=n3) return false;

	int t[n1+1][n2+1];
	for (int i = 0; i < n1; ++i)
	{
		t[i][0]=false;
	}

	for (int j = 0; j < n2; ++j)
	{
			t[0][j]=false;
	}

	for (int i = 0; i <=n1; ++i)
	{
		for (int j = 0; j <= n2; ++j)
		{
			if(str3[i+j-1]==str2[i-1]){
				t[i][j]=t[i-1][j];
			}
			else if(str3[i+j-1]==str1[i-1]){
				t[i][j]=t[i][j] || t[i-1][j];
			}
		}
	}
	return t[n1][n2];
}



int main()  
{  
    char str1[] = "AB";  
    char str2[] = "CD";  
    char str3[] = "BCDA";
   	cout<< printIls(str1, str2, str3, strlen(str1), strlen(str2), strlen(str3));  
    return 0;  
} 
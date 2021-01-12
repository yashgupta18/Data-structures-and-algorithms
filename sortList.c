#include<iostream>
#include<map>
#include<list>
#include<unordered_map>
#include<map>
#include<set>
#include<queue>
using namespace std;
 
struct Project 
{
    string name; 
    int time; 
    int rank; 
};
 
bool compareTwoStudents(Project a, Project b)
{
    if (a.name != b.name)
        return a.name < b.name;
}
void computeRanks(Project a[], int n)
{
    sort(a, a + 5, compareTwoStudents);
 
    for (int i = 0; i < n; i++)
        a[i].rank = i + 1;
}
 
int main()
{
    int n = 5;
 
    Project a[n];
    a[0].name = "Design an Outfit for Ellie";
    a[0].time = 1120;
   
    a[1].name = "Light in your Kitchen";
    a[1].time = 1210;
 
    a[2].name = "Use the Twilio API";
    a[2].time = 150;
 
    a[3].name = "Build a Data Visualization";
    a[3].time = 230;
 
    a[4].name = "Make a Logo for a Project";
    a[4].time = 400;
 
    computeRanks(a, n);
 
    cout << "Rank"
         << " \t\t\t"
         << "Name"
         << "\t\t     ";
    cout << "Time"
         << "\n";
 
    for (int i = 0; i < n; i++) {
        cout << a[i].rank << " \t   ";
        cout<<a[i].name<<" \t    ";
        cout << a[i].time << "   \t      ";
        cout << "\n";
    }
 
    return 0;
}


#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void solve(vector<double> v){
  if(v[1]<v[0]){
    cout<<"ERROR\n";
    return;
  }
  
  string nameChange[]={"PENNY", "NICKEL","DIME","QUARTER","HALF DOLLAR", "ONE","TWO","FIVE","TEN","TWENTY","FIFTY","ONE HUNDRED"};
  float coinChange[]={.01,.05,.10,.25,.50,1.00,2.00,5.00,10.00,20.00,50.00,100.00};
  float change=v[1]-v[0];
  cout<<"Change="<<change<<endl;
  if(v[1]==v[0]){
    cout<<"ZERO\n";
    return;
  }
  else{

    int i=11;
    while(change>0){
      if(coinChange[i]<=change){
        change=change-coinChange[i];
        cout<<nameChange[i]<<",";
        cout<<"Change="<<change<<endl;
      }
      else{
        i--;
      }
    }
  }
  return;
}
int main() {
  // input costprice, moneybycustomer separated by ';'
  // ex input>> 15.23;17.20
  string line;
  cin>>line;
  vector<string> v;
  stringstream ss(line);
  while(ss.good()){
    string substr;
    getline(ss, substr, ';');
    v.push_back(substr);
  }
  vector<double> v1;
  for(int i=0; i<2; i++){
    string val=v[i];
    stringstream degree(val);
    double x=0;
    degree>>x;
    v1.push_back(x);
  }
  solve(v1);
  
  
  return 0;
  
}
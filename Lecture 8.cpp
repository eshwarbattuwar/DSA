#include<iostream>
using namespace std;
int main(){
	int a[9];
	int i;
	cout<<"enter 10 integers as input"<<endl;
	for(i=0;i<10;i++){
		cin>>a[i];
	}
	cout<<"the given inputs are : "<<endl;
	for(i=9;i>=0;i--){
		cout<<a[i]<<" ";
	}
	return 0;
}

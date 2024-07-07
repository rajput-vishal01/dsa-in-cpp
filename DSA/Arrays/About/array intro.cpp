#include<iostream>
using namespace std;

int main() {
	int num[15];
	cout<<"value at index 14"<<num[14]<<endl;

	int n[15]= {2,3};
	int k=15;
	//2,3 ke alawa saari values 0 hogyi
	n[7]=9;  //updating the value in an array
	for(int i=0; i<k; i++) {
		cout<<n[i]<<" ";
	}
	cout<<endl;

	int a[10]= {0};
	int l=10;
	//saari values 0 hogyi but ye sirf 0 sai hi hoga
	for(int i=0; i<l; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;

	int b[10]= {1};
	int s=10;
	//saari values 0 hogyi but ye sirf 0 sai hi hoga even 1 sai v ni hoga
	for(int i=0; i<s; i++) {
		cout<<b[i]<<" ";
	}
	cout<<endl;

	int arr[5]; // Declare an array of size 5
    int w = 10; // Initialize with the desired number

    // Initialize all elements of the array with the number
    fill(arr, arr + 5, w);

    // Display the array elements
    cout << "Array elements after initialization: ";
    for(int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
	return 0;
}
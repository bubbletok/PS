#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,k;
	cin >> n >> m;
	int** a = new int*[n];
	for(int i=0; i<n; i++){
		a[i] = new int[m];
		for(int j=0; j<m; j++){
			cin >> a[i][j];
		}
	}
	cin >> m >> k;
	int** b = new int*[m];
	for(int i=0; i<m; i++){
		b[i] = new int[k];
		for(int j=0; j<k; j++){
			cin >> b[i][j];
		}
	}
	int** ab = new int*[n];
	for(int i=0; i<n; i++) ab[i] = new int[k];
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++) ab[i][j] = 0;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			for(int l=0; l<k; l++){
				ab[i][l] += a[i][j] * b[j][l];
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			cout << ab[i][j] << " ";
		}
		cout << "\n";
	}
	for(int i=0; i<n; i++){
		delete[] a[i];
		delete[] ab[i];
	}
	for(int i=0; i<m; i++) delete[] b[i];
	delete[] a, delete[] b, delete[] ab;
	
	return 0;
}
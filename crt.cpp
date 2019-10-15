#include "iostream"
using namespace std;
const int N = 1e5 + 5;

int A[N];
int M[N];
int NN[N];
int Y[N];

int ext_gcd(int a, int b){
	int s0 = 1, s1 = 0, q, r, cur_s;
	while(b != 0){
		q = a / b;
		r = a % b;
		cur_s = s0 - s1 * q;
		s0 = s1;
		s1 = cur_s;
		a = b;
		b = r;
	}
	return s0;
}

int gcd(int a, int b){
	while(b > 0){
		int mod = a % b;
		a = b;
		b = mod;
	}
	return a;
}

int main(){
	int n;
	cout << "Enter the no of Pairs: ";
	cin >> n;
	int N_total = 1, res = 0;
	for(int i = 0; i < n; i++){
		cout << "Enter the " << i + 1 << " pair: ";
		cin >> A[i] >> M[i];
		int fl = 0;
		for(int j = i - 1; j >= 0; j--){
			if(gcd(M[i], M[j]) != 1){
				fl = 1;
				break;
			}
		}
		if(fl == 1){
			cout << "Invalid Pair Entered\n";
			i--;
		}
		else N_total *= M[i];
	}

	for(int i = 0; i < n; i++){
		NN[i] = N_total / M[i];
	}

	for(int i = 0; i < n; i++){
		Y[i] = ext_gcd(NN[i], M[i]);
	}

	for(int i = 0; i < n; i++){
		res += Y[i] * A[i] * NN[i];
	}
	res %= N_total;
	if(res < 0) res += N_total;
	cout << "The First Five Solutions are: ";
	for(int i = 0; i < 5; i++){
		cout << res << " ";
		res += N_total;
	}
}

#include <iostream>
#include <cmath>

using namespace std;
double P0(const int k, const int N) {
	double P = 1;
	for (int i = k; i <= N; i++) {
		P *= ((1.0 * k / i) + (1.0 * i / N));
	}
	return P;
}
double P1(const int k, const int N, const int i) {
	if (i > N)
		return 1;
	else
		return ((1.0 * k / i) + (1.0 * i / N)) * P1(k, N, i + 1);
}
double P2(const int k, const int N, const int i) {
	if (i < k)
		return 1;
	else
		return ((1.0 * k / i) + (1.0 * i / N)) * P2(k, N, i - 1);
}
double P3(const int k, const int N, const int i, double t) {
	t = t * ((1.0 * k / i) + (1.0 * i / N));
	if (i >= N)
		return t;
	else
		return P3(k, N, i + 1, t);
}
double P4(const int k, const int N, const int i, double t) {
	t = t * ((1.0 * k / i) + (1.0 * i / N));
	if (i <= k)
		return t;
	else
		return P4(k, N, i - 1, t);
}
int main(){
	int k, N;
	cout << "N = "; cin >> N;
	cout << "K = "; cin >> k;

	cout << "(iter)        P0 = " << P0(k, N) << endl;
	cout << "(rec up ++)   P1 = " << P1(k, N, k) << endl;
	cout << "(rec up --)   P2 = " << P2(k, N, N) << endl;
	cout << "(rec down ++) P3 = " << P3(k, N, k, 1.0) << endl;
	cout << "(rec down --) P4 = " << P4(k, N, N, 1.0) << endl;

	return 0;
}
// N = 3
// K = 2
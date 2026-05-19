#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

vector<double> reflect(double a, double b, double x0, double y0, double u, double v)
{
	double t = (sqrt(pow(u, 2) / pow(a, 2) + pow(v, 2) / pow(b, 2) - pow((u * y0 - v * x0) / (a * b), 2)) - (u * x0 / pow(a, 2) + v * y0 / pow(b, 2))) / (pow(u, 2) / pow(a, 2) + pow(v, 2) / pow(b, 2));
	double x1 = x0 + t * u;
	double y1 = y0 + t * v;
	vector<double> v1 = { u, v };
	vector<double> n = { 2.0 * x1 / pow(a, 2), 2.0 * y1 / pow(b, 2) };
	double dot = (u * n[0] + v * n[1]) / (pow(n[0], 2) + pow(n[1], 2));
	return { x1, y1, u - 2.0 * dot * n[0], v - 2.0 * dot * n[1] };
}
 
int main()
{
	cout << fixed << setprecision(3);
	double x, y, u, v, a, b;
	vector<double> v1, v2;
	while (cin >> x >> y >> u >> v >> a >> b)
	{
		v1 = reflect(a, b, x, y, u, v);
		v2 = reflect(a, b, v1[0], v1[1], v1[2], v1[3]);
		cout << v1[0] << " " << v1[1] << endl;
		cout << v2[0] << " " << v2[1] << endl;
	}
    return 0;
}


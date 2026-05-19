#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void reflect(double a, double b, double& x0, double& y0, double& u, double& v)
{
	double t = (sqrt(pow(u, 2) / pow(a, 2) + pow(v, 2) / pow(b, 2) - pow((u * y0 - v * x0) / (a * b), 2)) - (u * x0 / pow(a, 2) + v * y0 / pow(b, 2))) / (pow(u, 2) / pow(a, 2) + pow(v, 2) / pow(b, 2));
	double x1 = x0 + t * u;
	double y1 = y0 + t * v;
	double nx = 2.0 * x1 / pow(a, 2);
	double ny = 2.0 * y1 / pow(b, 2);
	double dot = (u * nx + v * ny) / (pow(nx, 2) + pow(ny, 2));
	x0 = x1;
	y0 = y1;
	u = u - 2.0 * dot * nx;
	v = v - 2.0 * dot * ny;
}
 
int main()
{
	cout << fixed << setprecision(3);
	double x, y, u, v, a, b;
	while (cin >> x >> y >> u >> v >> a >> b)
	{
		reflect(a, b, x, y, u, v);
		cout << x << " " << y << endl;
		reflect(a, b, x, y, u, v);
		cout << x << " " << y << endl;
	}
    return 0;
}

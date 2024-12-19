#include<iostream>

int main()
{
	int a, b, c, d, e, f;

	std::cin >> a >> b >> c >> d >> e >> f;
	
    
	int y = (c * d - a * f) / (b * d - a * e);
	int x = (c * e - b * f) / (a * e - b * d);
	
	//결과
	std::cout << x << ' ' << y;
    
	return 0;
}

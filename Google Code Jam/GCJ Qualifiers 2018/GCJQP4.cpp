#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

double mod (double first, double second) {
	return sqrt((first * first) + (second * second));
}

class Coordinates {
	public:
		double x, y, z;
		
		Coordinates (double _x, double _y, double _z) {
    		x = _x; y = _y; z = _z;
		}
		
		void RotateXAxis (double radians) {
			if (z == 0 && y == 0) return;
			this->solve(false, true, radians);
		}
		
		void RotateZAxis (double radians) {
			if (x == 0 && y == 0) return;
			this->solve(true, true, radians);
		}
		
	private: 
		void solve (bool _x, bool _y, double radians) {
			double gradient, area;
			
			if (_x && _y) gradient = mod(y, x);
			else gradient = mod(z, y);
			
			if (_x && _y) area = radians + atan2(y, x);
			else area = radians + atan2(z, y);
			
			if (_x && _y) {
				x = gradient * cos(area);
				y = gradient * sin(area);
			} else {
				y = gradient * cos(area);
				z = gradient * sin(area);	
			}
		}
};

class Collection {
	public:
		vector<Coordinates> collection;
  		
		void Add (double x, double y, double z) {
    		collection.push_back(Coordinates(x, y, z));
		}
		
		void RotateXAxis (double radians) {
    		for (int i = 0; i < collection.size(); i++) collection[i].RotateXAxis(radians);
		}
		
		void RotateZAxis (double radians) {
    		for (int i = 0; i < collection.size(); i++) collection[i].RotateZAxis(radians);
		}
		
		static Collection Cube() {
			Collection collection;
			double distance = 0.500000;
		  
			collection.Add(-distance, -distance, -distance);
			collection.Add(distance, -distance, -distance);
			collection.Add(distance, -distance, distance);
			collection.Add(-distance, -distance, distance);
			collection.Add(-distance, distance, -distance);
			collection.Add(distance, distance, -distance);
			collection.Add(distance, distance, distance);
			collection.Add(-distance, distance, distance);
			collection.Add(distance, 0, 0);
			collection.Add(0, distance, 0);
			collection.Add(0, 0, distance);
		
			return collection;
		}
		
		static double smallArea(Collection collection) {
			return abs(collection.collection[0].z - collection.collection[7].z);
		}
		
		static double largeArea(Collection collection) {
  			double rectangle = sqrt(2) * abs(collection.collection[0].x - collection.collection[1].x);
  			double triangle = sqrt(2) * abs(collection.collection[5].x - collection.collection[2].x);
  
  			return triangle + rectangle;
		}
};

void solve (double area, bool isSmall) {
	Collection cube = Collection::Cube();
	double shadow, min = 0.000000, max = 6.283185307179586476 / 8;

	if (!isSmall) cube.RotateXAxis(max);

	Collection copy = cube;
	if (isSmall) shadow = Collection::smallArea(copy);
	else shadow = Collection::largeArea(copy);
	
	while (abs(shadow - area) > 0.00000000001) {
		double radians = (max + min) / 2;
		copy = cube;
		
		if (isSmall) copy.RotateXAxis(radians);
		else copy.RotateZAxis(radians);
		
		if (isSmall) shadow = Collection::smallArea(copy);
		else shadow = Collection::largeArea(copy);
		
		if (shadow < area) min = radians;
		else max = radians;
	}
	
	for (int i = 8; i < copy.collection.size(); i++) {
    	cout << copy.collection[i].x << " " << copy.collection[i].y << " " << copy.collection[i].z << endl;
    }
}

int main() {
	freopen("Q4.txt", "r", stdin);
  
	int testCases;
	cin >> testCases;
	
	for (int test = 1; test <= testCases; test++) {	
		double area;
		cin >> area;
    	
        cout << "Case #" << test << ": " << endl;
  	
		if (sqrt(2) > area) solve(area, true);
		else solve(area, false);
	}
}

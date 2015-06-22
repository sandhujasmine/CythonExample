/*
 * just a basic check of C++ code
 */
#include <iostream>
#include "polygon.h"

using namespace std;


int main () {
	/*
	 * cython wrapper will be using this as described by this test
	 */
	int h = 4;
	int w = 5;

	Polygon *poly;
	Rectangle *rect;

	poly = new Rectangle();
	poly->set_values(w, h);
	rect = dynamic_cast<Rectangle *>(poly);

	//cout << "Rect h, w: " << h << ", " << w << " area: " << rect.area() << '\n';
	cout << "Rect h, w: " << h << ", " << w << " area: " << rect->area() << '\n';
	//cout << "Tri h, w: " << h << ", " << w << " area: " << trgl.area() << '\n';

	// try some dynamic_casts
	delete rect;
	return 0;
}

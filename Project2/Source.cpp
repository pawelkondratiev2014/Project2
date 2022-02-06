#include <iostream>
#include <string>
#include <cassert>
#include <clocale>
#include <list>
#include <algorithm>

#include "TFrac.h"
#include "InOutDo.h"


int main()
{
	setlocale(LC_CTYPE, "rus");

	std::list<TFrac> m;

	InOutDo::Input(m);
	InOutDo::Output(m);
	InOutDo::SortUp(m);
	InOutDo::Output(m);
	//InOutDo::SortDown(m);
	//InOutDo::Output(m);
	std::cout << InOutDo::Sum(m) << std::endl;


	system("pause");
	return 0;
};

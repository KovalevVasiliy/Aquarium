#include "Exception.h"



Exception::Exception(int err)
{
	switch (err)
	{
	case 1:
		error = "Wrond range of values!\n\n(For Planktons:\nradOfView: 2-4\n radOfDisp: 1 - 3\n lifeTime: 3 - 5 days)";
		break;
	case 2:
		error = "Wrond range of values!\n\n(For Herbivores:\nradOfView: 6-9\n radOfDisp: 4 - 6\n lifeTime: 8 - 11 days\n eatTime: 4 - 5 days)";
		break;
	case 3:
		error = "Wrond range of values!\n\n(For Predators:\nradOfView: 6-8\n radOfDisp: 6 - 7\n	lifeTime: 3 - 5 days\n eatTime : 2 - 3 days)";
		break;
	case 4:
		error = "Aquarium is crowed";
		break;
	default:
		break;
	}
}


Exception::~Exception()
{
}

const char* Exception::what() const noexcept
{
	return error;
}
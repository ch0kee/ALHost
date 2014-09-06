// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cstdint>
#include <memory>
#include <string>

//////////////////////////////////////////////////////////////////////////
// makrók
#define MEMSET_THIS() memset(this, 0, sizeof(*this))
//////////////////////////////////////////////////////////////////////////

struct LatLng {
	LatLng() { MEMSET_THIS(); }
	double longitude;
	double latitude;
};

struct Zoom {
	Zoom() { MEMSET_THIS(); }
	int32_t	level;
};

struct Viewport {
};

struct CenterZoomViewport
	: public Viewport {
private:
	LatLng		_center;
	Zoom		_zoom;
};

class GoogleMaps {
	Viewport AskForViewport(LatLng pos) {

	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}


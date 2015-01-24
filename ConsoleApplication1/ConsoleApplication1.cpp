// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cstdint>
#include <memory>
#include <string>
#include <functional>
#include <map>

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

class ViewportMethod {
public:
  virtual void serialize() = 0;
  ~ViewportMethod(){}
};




class Viewport {


  ViewportMethod* _method; 
public:
  Viewport()
    : _method(nullptr){}
  void serialize() { _method->serialize();  }

};


class CenterZoomViewportMethod
	: public ViewportMethod {
public:
protected:
private:
	LatLng		_center;
	Zoom		_zoom;
};

#define EXPERIMENTAL 1

#if EXPERIMENTAL

typedef std::string serialized_data_t;

template<class _FunctionHost>
class Module {
public:
protected:
  typedef _FunctionHost functionhost_t;
	template<class T>
  T deserialized(serialized_data_t&);
  template<class T>
  serialized_data_t& serialized(serialized_data_t&, T);
  
  int _nextFunctionCode = 0;


 /* template<class _Ret, class _Par>
  void register_function(_Ret(functionhost_t::*func) ()) {
    _functions[_nextFunctionCode++] = [this, func](serialized_data_t& in) {
      return serialized<_Ret>(func());
    }
  }*/


  template<class _Ret, class _Par, class F>
  void register_function(F func);
/*

  template<class _Ret, class _Par1, class _Par2>
  void register_function(_Ret (functionhost_t::*f) (_Par1, _Par2)) {

  }*/


private:
  std::map<int, std::function<serialized_data_t&(serialized_data_t&)> > _functions;

};
#endif


#define ALHOSTFUNCTION(x) (x)

// kliens
class GoogleMapsC
  : public Module<GoogleMapsC>{
public:
  Viewport AskForViewport(LatLng pos) {
#if EXPERIMENTAL
		//deserialized(pos);
		//////////////////////////////////////////////////////////////////////////
		// pos használható

    Viewport vp;

		return vp;
#endif
	}

public:
  void eh()
  {
    register_function<Viewport, LatLng>(&GoogleMapsC::AskForViewport);
  }

};

template<class T>
template<class _Ret, class _Par, class F>
void Module<T>::register_function(F func) {
//  std::function<_Ret(_Par)> f = [=](_Par p) { return func(p); };
  _functions[_nextFunctionCode++] = [=](serialized_data_t& in)  {
   // ((functionhost_t*)this)->*func)();
    
    return serialized(in, func(deserialized<_Par>(in)));
  };
}

class Library {

};

class 

// szerver
class GoogleMapsS {
	Viewport AskForViewport(LatLng pos) {
    Viewport vp;
    return vp;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
  GoogleMapsC c;
  c.eh();
	return 0;
}


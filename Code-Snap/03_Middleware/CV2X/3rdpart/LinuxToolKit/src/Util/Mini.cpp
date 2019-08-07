
#include "Mini.h"


namespace toolkit {

template<>
mINI_basic<string, variant> &mINI_basic<string, variant>::Instance(){
	static mINI_basic<string, variant> instance;
	return instance;
}

}  // namespace toolkit



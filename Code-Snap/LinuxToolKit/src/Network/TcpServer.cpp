
#include "TcpServer.h"


namespace toolkit {

SessionMap &SessionMap::Instance(){
	static SessionMap instance;
	return instance;
}

} /* namespace toolkit */


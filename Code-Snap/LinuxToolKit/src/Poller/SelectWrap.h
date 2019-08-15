
#ifndef SRC_POLLER_SELECTWRAP_H_
#define SRC_POLLER_SELECTWRAP_H_

#include "Util/Util.h"

namespace toolkit {

class FdSet {
public:
	FdSet();
	~FdSet();
	void fdZero();
	void fdSet(int fd);
	void fdClr(int fd);
	bool isSet(int fd);
	void *_ptr;
};
int zl_select(int cnt,FdSet *read,FdSet *write,FdSet *err,struct timeval *tv);

} /* namespace toolkit */



#endif /* SRC_POLLER_SELECTWRAP_H_ */

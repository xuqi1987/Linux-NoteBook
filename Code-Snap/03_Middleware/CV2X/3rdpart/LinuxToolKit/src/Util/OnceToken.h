

#ifndef UTIL_ONCETOKEN_H_
#define UTIL_ONCETOKEN_H_

#include <functional>
#include <type_traits>

using namespace std;

namespace toolkit {

class OnceToken {
public:
	typedef function<void(void)> task;
	OnceToken(const task &onConstructed, const task &onDestructed = nullptr) {
		if (onConstructed) {
			onConstructed();
		}
		_onDestructed = onDestructed;
	}
	OnceToken(const task &onConstructed, task &&onDestructed) {
		if (onConstructed) {
			onConstructed();
		}
		_onDestructed = std::move(onDestructed);
	}
	~OnceToken() {
		if (_onDestructed) {
			_onDestructed();
		}
	}
private:
	OnceToken(){};
	OnceToken(const OnceToken &){};
	OnceToken(OnceToken &&){};
	OnceToken &operator =(const OnceToken &);
	OnceToken &operator =(OnceToken &&);
	task _onDestructed;
};

} /* namespace toolkit */

#endif /* UTIL_ONCETOKEN_H_ */

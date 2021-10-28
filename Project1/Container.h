#ifndef __CONTAINER_H__
#define __CONTAINER_H__
#include "Account.h"

typedef Account* Element;

class Container {
private:
	Element* arr;
	int length;
	int aIndex;

public:
	Container(int len = 50);
	Container(const Container& container);
	Container& operator=(const Container& container);
	~Container();
	void Insert(Element data);
	Element Remove(int idx);

	Element GetItem(int idx);
	Element GetItem(int idx) const;
	int GetElemSum() const { return aIndex; }
};
#endif // !__CONTAINER_H__

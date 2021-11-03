#ifndef __CONTAINER_H__
#define __CONTAINER_H__
#include "Account.h"

//typedef Account* Element;

template <typename T>
class Container {
private:
	T* arr;
	int length;
	int aIndex;

public:
	Container(int len = 50);
	Container(const Container& container);
	Container& operator=(const Container& container);
	~Container();
	void Insert(T data);
	T Remove(int idx);

	T GetItem(int idx);
	T GetItem(int idx) const;
	int GetElemSum() const { return aIndex; }
};

template <typename T>
Container<T>::Container(int len) : length(len), aIndex(0) {
	arr = new T[length];
}

template <typename T>
Container<T>::Container(const Container<T>& container) {
	arr = new T[container.length];
	length = container.length;
	aIndex = container.aIndex;
}

template <typename T>
Container<T>& Container<T>::operator=(const Container<T>& container) {
	delete[] arr;
	arr = new T[container.length];
	length = container.length;
	aIndex = container.aIndex;
	return *this;
}

template <typename T>
Container<T>::~Container() {
	delete[] arr;
}

template <typename T>
void Container<T>::Insert(T data) {
	arr[aIndex++] = data;
}

template <typename T>
T Container<T>::Remove(int idx) {
	T removed = arr[idx];
	for (int i = idx; i < aIndex - 1; i++) {
		arr[idx] = arr[idx + 1];
	}
	aIndex--;
	return removed;
}

template <typename T>
T Container<T>::GetItem(int idx) {
	return arr[idx];
}

template <typename T>
T Container<T>::GetItem(int idx) const {
	return arr[idx];
}
#endif // !__CONTAINER_H__

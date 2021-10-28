#include "Container.h"

Container::Container(int len) : length(len), aIndex(0) {
	arr = new Element[length];
}
Container::Container(const Container& container) {
	arr = new Element[container.length];
	length = container.length;
	aIndex = container.aIndex;
}
Container& Container::operator=(const Container& container) {
	delete[] arr;
	arr = new Element[container.length];
	length = container.length;
	aIndex = container.aIndex;
	return *this;
}
Container::~Container() {
	//delete[] arr;
	for (int i = 0; i < length; i++) {
		delete arr[i];
	}
}
void Container::Insert(Element data) {
	arr[aIndex++] = data;
}
Element Container::Remove(int idx) {
	Element removed = arr[idx];
	for (int i = idx; i < aIndex - 1; i++) {
		arr[idx] = arr[idx + 1];
	}
	aIndex--;
	return removed;
}
Element Container::GetItem(int idx) {
	return arr[idx];
}
Element Container::GetItem(int idx) const {
	return arr[idx];
}
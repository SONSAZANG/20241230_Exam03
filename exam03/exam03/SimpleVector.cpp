#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class SimpleVector {
private:
	vector<T> data;
	int currentSize;
	int currentCapacity;

public:
	/// <summary>
	/// 기본 생성자 크기는 10으로 생성
	/// </summary>
	SimpleVector() : currentCapacity(10), currentSize(0) {
		data = vector<T>(currentCapacity);
	}

	/// <summary>
	/// 숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기의 배열 생성
	/// </summary>
	SimpleVector(int capacity) : currentCapacity(capacity), currentSize(0) {
		data = vector<T>(currentCapacity);
	}

	/// <summary>
	/// push_back 인자로 받은 원소를 맨 뒤에 추가
	/// 배열의 크기가 꽉 찼을 경우 동작 X
	/// </summary>
	void push_back(T value) {
		if (currentSize < currentCapacity) {
			data[currentSize] = value;
			currentSize++;
		}
		else {
			cout << "배열이 가득 찼습니다!" << endl;
		}
	}

	
	/// <summary> 
	///	pop_back은 벡터의 마지막 원소를 제거
	/// 제거할 원소가 없으면 동작 X
	/// </summary>
	void pop() {
		if (currentSize > 0) {
			currentSize--;
		}
		else {
			cout << "제거할 원소가 없습니다!" << endl;
		}
	}

	
	/// <summary>
	/// size는 현재 원소의 개수를 반환
	/// </summary>
	int size() {
		return currentSize;
	}
	
	
	/// <summary>
	/// capacity는 현재 내부 배열의 크기를 반환
	/// </summary>
	int capacity() {
		return currentCapacity;
	}
};

int main() {

	int size = 0;
	cin >> size;

	auto a = SimpleVector<int>(size);

	cout << a.size() << endl;
	cout << a.capacity() << endl;


	return 0;
}
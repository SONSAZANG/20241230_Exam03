#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;

public:
	/// <summary>
	/// 기본 생성자 크기는 10으로 생성
	/// </summary>
	SimpleVector() : data(new T[10]), currentCapacity(10), currentSize(0) {
		cout << "크기 : 10(기본값) 배열이 생성되었습니다." << endl;
	}

	/// <summary>
	/// 숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기의 배열 생성
	/// </summary>
	SimpleVector(int capacity) : data(new T[capacity]), currentCapacity(capacity), currentSize(0) {
		cout << "크기: " << capacity << "배열이 생성되었습니다." << endl;
	}

	/// <summary>
	/// 도전 기능 - 복사생성자
	/// </summary>
	/// <param name="obj"></param>
	SimpleVector(const SimpleVector& obj) {
		data = obj.data;
		currentSize = obj.currentSize;
		currentCapacity = obj.currentCapacity;
	}

	~SimpleVector() {
		delete[] data;
		cout << "SimpleVector 소멸되었습니다." << endl;
	}

	/// <summary>
	/// push_back 인자로 받은 원소를 맨 뒤에 추가
	/// 배열의 크기가 꽉 찼을 경우 동작 X
	/// </summary>
	void push_back(T value) {
		if (currentSize < currentCapacity) {
			data[currentSize] = value;
			currentSize++;
			cout << "값이 추가되었습니다!" << endl;
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
			cout << "값이 제거되었습니다!" << endl;
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

	/// <summary>
	/// 도전기능 - resize()
	/// 정수를 인자로 받고 배열의 크기와 비교해서 인자가 배열의 크기보다 크면 배열 재할당
	/// 기존 원소는 그대로 있어야 한다.
	/// </summary>
	/// <param name="resizeValue"></param>
	void resize(int resizeValue) {
		if (resizeValue > currentCapacity) {
			auto temp = new T[resizeValue];

			for (int i = 0; i < currentCapacity; ++i) {
				temp[i] = data[i];
			}

			currentCapacity = resizeValue;

			cout << "배열의 크기가 " << currentCapacity << " 에서 " << resizeValue << "로 변경되었습니다." << endl;
		}
		else {
			cout << "변경하려는 값이 기존 배열의 크기보다 작아서 동작하지 않습니다!" << endl;
			cout << "변경하려는 값: " << resizeValue << ", 기본 배열의 크기: " << currentCapacity << endl;
		}
	}


	/// <summary>
	/// 내부 데이터를 정렬하는 함수.
	/// bool형으로 인자를 받아서 오름차순, 내림차순 선택
	/// </summary>
	/// <param name="isUpper"></param>
	void sortData(bool isUpper) {
		if (isUpper) {
			sort(data, data + currentSize, greater<>());
		}
		else {
			sort(data, data + currentSize, less<>());
		}

		cout << "배열의 데이터가 " << (isUpper ? "내림차순" : "오름차순") << "으로 정렬되었습니다." << endl;
	}

	/// <summary>
	/// 데이터 출력
	/// </summary>
	void printValue() {
		for (int i = 0; i < currentSize; ++i) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
};

enum FUNCTION {
	CHANGE_SIZE = 1,
	PUSH_VALUE,
	POP_VALUE,
	DESCENDING_SORT,
	ASSCENDING_SORT,
	PRINT_VALUE,
	EXIT = 9,
};

void simpleVectorProgram() {
	cout << "---------------------------------------------" << endl;
	cout << "SimpleVector 프로그램" << endl;
	cout << "---------------------------------------------" << endl;
	cout << "배열을 생성하려고 합니다. 배열의 크기를 입력하세요: ";
	int size = 0;
	cin >> size;

	auto sv = SimpleVector<int>(size);
	cout << "크기 " << size << "를 가진 배열이 생성되었습니다." << endl;
	sv.printValue();

	bool isFinish = false;
	int num = 0;
	while (isFinish == false) {
		cout << "---------------------------------------------" << endl;
		cout << "원하시는 기능을 입력하세요. \n1. 크기 변경 \n2. 값 추가 \n3. 값 제거 \n4. 내림차순 정렬 \n5. 오름차순 정렬 \n6. 값출력 \n9. 종료" << endl;
		cout << "---------------------------------------------" << endl;

		cin >> num;

		switch ((FUNCTION)num)
		{
		case CHANGE_SIZE:
		{
			int changeValue = 0;
			cout << "변경할 크기를 입력하세요" << endl;
			cin >> changeValue;
			sv.resize(changeValue);
			break;
		}
		case PUSH_VALUE:
		{
			int appendValue = 0;
			cout << "추가 할 값을 입력하세요." << endl;
			cin >> appendValue;
			sv.push_back(appendValue);
			sv.printValue();
			break;
		}
		case POP_VALUE:
		{
			sv.pop();
			sv.printValue();
			break;
		}
		case DESCENDING_SORT:
		{
			sv.sortData(true);
			sv.printValue();
			break;
		}
		case ASSCENDING_SORT:
		{
			sv.sortData(false);
			sv.printValue();
			break;
		}
		case PRINT_VALUE:
		{
			cout << "배열의 데이터를 출력합니다" << endl;
			sv.printValue();
			break;
		}
		case EXIT:
			isFinish = true;
			break;
		default:
			break;
		}
	}
	cout << "프로그램 종료" << endl;
}

int main() {
	simpleVectorProgram();
}
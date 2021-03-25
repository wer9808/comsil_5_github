#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <class T>
class Stack : public LinkedList<T>{
	public:
		bool Delete (T &element){
			//first가 0이면 false반환
			if(this->first == 0) return false;

			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
			Node<T> *current = this->first, *next = current->link; // current는 stack의 1번째, next는 2번째 노드
			
			if(current->link == 0) {// stack에 연결된 노드가 없을 경우 stack을 초기화
				this->first = 0;
				this->current_size = 0;
			}
			else { // 아닐경우 stack의 1번째 노드를 next 노드로 설정 후 스택 크기 감소
				this->first = next;
				this->current_size--;
			}

			element = current -> data;

			// current에 할당된 노드 해제
			delete current;

			return true;
			}
};

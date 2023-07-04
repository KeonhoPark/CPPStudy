#include<iostream>
using namespace std;

class Node{
    //double linked list를 구현해야 하기 때문에(양방향)
    //이전노드와 다음노드를 담을 수 있는 노드포인터를 맴버변수로 가진다.
    private:
        int data;
        Node* right;
        Node* left;
    public:
        //디폴트 생성자
        Node() = default;

        //node에 넣고싶은 데이터를 같이 넣어 노드 객체를 생성하는 생성자
        Node(int dataInput) : data(dataInput){
            this->right = nullptr;
            this->left = nullptr;
        } 

        //노드의 데이터를 가져오는 getter
        int getData() const{
            return this->data;
        }

        //노드의 데이터를 쓸수있는 setter
        void setData(int input){
            this->data = input;
        }

        //노드의 오른쪽(다음)노드의 주소를 가져오는 getter
        Node* getRight() const{
            return this->right;
        }

        //노드의 오른쪽(다음)노드의 주소를 지정하는 setter
        Node* setRight(Node* rightNode){
            this->right = rightNode;
            return this->right;
        }


        //노드의 왼쪽(이전)노드의 주소를 가져오는 getter
        Node* getLeft() const{
            return this->left;
        }

        //노드의 왼쪽(이전)노드의 주소를 지정하는 setter
        Node* setLeft(Node* leftNode){
            this->left = leftNode;
            return this->left;
        }
};

//double linked list
//멤버변수로 노드포인터와 리스트의 길이를 가진다.
class MyDoubleLinkedList{
    private:
        Node* root;
        int length;

    public:
        //기본생성자
        MyDoubleLinkedList() = default;

        //원하는 값을 넣으면 새로운 루트노드를 생성하여
        //linked list를 생성하는 생성자.
        MyDoubleLinkedList(int dataInput){
            length = 1;
            this->root = new Node(dataInput);
        }

        //소멸자
        ~MyDoubleLinkedList(){
            delete root;
        }

        // index값과 새로운 노드객체를 받아 인덱스 위치에 노드를 삽입하는 함수
        Node* nodeInsert(int index, Node &refNode){
            Node* curNode = this->root;
            for(int i = 0; i < index; i++){
                if(curNode->getRight() == nullptr){
                    break;
                }
                curNode = curNode -> getRight();
            }

            //인덱스 값이 length와 같다면 마지막에 노드를 추가한다는 의미이다.
            //따라서 새로운 노드의 다음노드를 널포인터로 지정한다.
            if(index == length){
                for(int i = 0; i < index; i++){
                    if(curNode->getRight() == nullptr){
                        break;
                    }
                    curNode = curNode -> getRight();
                }
                curNode->setRight(&refNode);
                refNode.setLeft(curNode);
                refNode.setRight(nullptr);
            }

            //리스트의 중간에 노드를 삽입하는 경우이다.
            //
            else{
                for(int i = 0; i < index; i++){
                    curNode = curNode -> getRight();
                }
                Node* right = curNode->getRight();
                right->setLeft(&refNode);
                refNode.setRight(right);
                curNode->setRight(&refNode);
                refNode.setLeft(curNode);
            }
            length++;
        }

        Node* nodeFind(int input){
            Node* curNode = root;
            for(int i = 0; i < length; i++){
                if(curNode->getData() == input){
                    return curNode;
                }
                curNode = curNode -> getRight();
            }

            return nullptr;
        }

        bool nodeDelete(int input){
            Node* findNode = nodeFind(input);
            if(findNode == nullptr){
                return false;
            }
            else{
                Node* left = findNode->getLeft();
                Node* right = findNode->getRight();
                right->setLeft(left);
                left->setRight(right);
                length--;
            }

            return true;
        }

        Node* nodeUpdate(int input, int value){
            Node* curNode = nodeFind(input);
            if(curNode == nullptr){
                return nullptr;
            }
            else{
                curNode->setData(value);
                return curNode;
            }
        }

        int getLength() const{
            return this->length;
        }

        void showAllNode(){
            Node* curNode = root;
            for(int i = 0; i < length; i++){
                cout << "i : " << i << " data : " << curNode->getData() << endl;
                curNode = curNode->getRight();
            }
        }
};

int main(){
    MyDoubleLinkedList list(1);
    int len = list.getLength();
    Node n1(2);
    Node n2(3);
    Node n3(4);
    list.nodeInsert(list.getLength(), n1);
    list.nodeInsert(list.getLength(), n2);
    //list.nodeInsert(2, n3);
    list.showAllNode();
    list.nodeDelete(2);
    list.nodeUpdate(1, 5);
    list.showAllNode();  

    return 0;
}
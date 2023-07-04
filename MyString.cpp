#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class MyString{
    private:
        char* data = nullptr; // 0 -> 111aaasss
        int length;

    public:
        MyString() : length(0){};

        int getLength(){
            return this->length;
        }

        void setLength(int length){
            this->length = length;
        }

        char* getData(){
            return data;
        }

        void setData(const char* input){
            if(input == nullptr){
                this->data = nullptr;
            }
            else{
                if(this->data != nullptr)
                {
                    char* tmp = new char[strlen(this->data) + strlen(input)+1]{0};
                    strcpy(tmp, input);
                    this->data = tmp;
                }
                else {
                    char* tmp = new char[strlen(input)+1]{0};
                    strcpy(tmp, input);
                    this->data = tmp;
                    
                }
                this->setLength(strlen(this->data));
            }
        }

        void operator=(const char* input){
            this->setData(input);
            this->setLength(strlen(input));
        }

        char operator[](int index){
            return *((this->data) + index);
        }

        friend std::ostream& operator<<(std::ostream out, MyString string){
            char* data = string.getData();
            int len = string.getLength();
            for(int i = 0; i < len; i++){
                out << *(data+i);
            }

            return out;
        }

        void erase(){
            this->setLength(0);
            this->data = nullptr;
            return;
        }

        bool erase(int start, int end){
            if(start > end || start < 1 || end > this->getLength() + 1){
                return false;
            }

            char* data = this->getData();
            int len = this->getLength();
            int blankSize = end - start + 1;
            for(int i = end; i < len; i++){
                *(data + i - blankSize) = *(data + i);
            }
            len -= blankSize;
            this->setLength(len);

            return true;
        }

        bool replace(int start, int end, char input){
            if(start > end || start < 1 || end > this->getLength() + 1){
                return false;
            }
    
            for(int i = start - 1; i <= end - 1; i++){
                *(this->data + i) = input;
            }

            return true;
        }

        void showMyString(){
            if(this->getLength() == 0){
                cout << "no data";
            }

            for(int i = 0; i < this->getLength(); i++){
                cout << *(this->getData()+i) << endl;
                cout << "length : " << this->getLength() << endl;
            }
            cout << endl;
        }
};

int main(){

    MyString s1;
    s1 = "abc";
    s1 = "abcdef";
    s1.showMyString();
    cout << s1[0] << endl;
    s1.replace(1, 3, 'z');
    s1.showMyString();
    MyString s2;
    s2 = "abcdef";
    s2.showMyString();
    s2.erase();
    s2.showMyString();

}
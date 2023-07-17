using namespace std;
class node {
public:
    char data;
    string color;
    node* next;
    node(char x, string y){
        data = x;
        color = y;
        next = NULL;
    }
};

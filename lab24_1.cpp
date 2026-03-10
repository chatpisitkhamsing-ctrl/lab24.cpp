#include<iostream>
using namespace std;


class Node{
    public:
    	int data;
    	Node *next;
    	~Node();
};

class List{
	public:
		Node *root;
		int size;
		void show();
		void append(int);
		void insert(int,int);
		void remove(int);
};

Node::~Node(){
    cout << data << " was deleted.\n";
}

void List::insert(int d,int idx){	
	Node *n = new Node;
	n->data = d;
	
	if(idx == 0){
		n->next = root;
		root = n;
		return;
	}
	Node *current = root;
	for(int i = 0; i < idx-1;i++){
		current = current->next;
	}
	n->next = current->next;
	current->next = n;		
}

void List::show(){
	Node *current = root;
	cout << current->data << " ";	
	while(current->next){
		current = current->next;
		cout << current->data << " ";
	}	
}

void List::append(int d){	
	Node *n = new Node;
	n->data = d; n->next = NULL;
	if(root == NULL) root = n;
	else{
		Node *current = root;
		while(current->next){
			current = current->next;
		}
		current->next = n;
	}
	size++;
}

//Write List::remove() here
void List::remove(int idx){
    // 1. ตรวจสอบว่า List ว่างหรือไม่
    if(root == NULL) return;

    Node *toBeDeleted;

    // 2. กรณีลบที่ตำแหน่งแรก (index 0)
    if(idx == 0){
        toBeDeleted = root;
        root = root->next;
    } 
    // 3. กรณีลบตำแหน่งอื่นๆ
    else {
        Node *current = root;
        // วนลูปไปจนถึง Node ก่อนหน้าตำแหน่งที่ต้องการลบ
        for(int i = 0; i < idx - 1; i++){
            if(current->next == NULL) return; // ป้องกัน index out of bounds
            current = current->next;
        }
        
        toBeDeleted = current->next;
        if(toBeDeleted == NULL) return; // กรณีตำแหน่งที่ระบุไม่มี Node อยู่จริง

        // เชื่อม Node ก่อนหน้าข้าม Node ที่จะลบไปหา Node ถัดไป
        current->next = toBeDeleted->next;
    }

    delete toBeDeleted; // เรียก Destructor (~Node) เพื่อพิมพ์ข้อความ "X was deleted."
    size--;
}
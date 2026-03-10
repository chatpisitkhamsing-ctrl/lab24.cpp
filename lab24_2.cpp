#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void printList(list<string> s){
	list<string>::iterator i;
	for( i = s.begin(); i != s.end(); i++){
		cout << *i << " ";
	}		
	cout << "\n";	
}

int main(){
	
	list<string> line_up;
	list<string>::iterator loc;
	
	line_up.push_back("Alice");
	line_up.push_back("Bob");
	
	loc = find(line_up.begin(),line_up.end(),"Bob");
	line_up.insert(loc,"Oscar");
	
	//Write your code here
	// Luffy, Sanji, Nami มาต่อแถวด้านหลังตามลำดับ
	line_up.push_back("Luffy");
	line_up.push_back("Sanji");
	line_up.push_back("Nami");

	// 2 คนที่หัวแถวได้เข้าไปในส้วมแล้ว (Alice และ Oscar ออกไป)
	line_up.pop_front();
	line_up.pop_front();

	// Narutu มาแทรกแถวหลัง Luffy
	loc = find(line_up.begin(), line_up.end(), "Luffy");
	line_up.insert(++loc, "Narutu"); // ใช้ ++loc เพื่อแทรก "ข้างหลัง" ตำแหน่งที่เจอ

	// Prayath ท้องเสียปวดขี้สุด ๆ เลยมาแทรกแซวหน้าสุด
	line_up.push_front("Prayath");

	// Tony ยอมไม่ได้เลยมาแทรกด้านหลัง Prayath
	loc = find(line_up.begin(), line_up.end(), "Prayath");
	line_up.insert(++loc, "Tony");

	// Bob ทนไม่ไหวเลย เปลี่ยนใจออกไปขี้ที่อื่น
	loc = find(line_up.begin(), line_up.end(), "Bob");
	line_up.erase(loc);

	// 3 คนที่หัวแถวได้เข้าไปในส้วมแล้ว (Prayath, Tony, และ Luffy ออกไป)
	line_up.pop_front();
	line_up.pop_front();
	line_up.pop_front();
	printList(line_up);
		
	return 0;
}

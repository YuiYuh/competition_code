#include<bits/stdc++.h>
using namespace std;
class calculator{
	protected:
		int x,y;
	public:
		virtual void get(int x, int y){
			this->x=x;
			this->y=y;
		}
};
class add : public calculator{
	private:
		void get(int x, int y){
			cout << (x + y) << endl;
		}
};
class sub : public calculator{
	private:
		void get(int x,int y){
			cout <<(x-y)<<endl;
		}
};
class mul : public calculator{
	private:
		void get(int x, int y){
			cout<< (x*y)<< endl;
		}
};
class dive :public calculator{
	private:
		void get (int x,int y){
			if (y==0)
				cout <<"Error"<< endl;
			else
				cout << (x/y)<< endl;
		}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	char str[100] = {0};
	cin.getline(str,sizeof(str));
	string op;
	int a,b;
	stringstream ss(str);
	ss >> op >> a >> b;
	for(char&c : op) c=tolower(c);
	calculator *calc = nullptr;
	if(op == "add") calc = new add;
	else if(op == "sub") calc = new sub;
	else if(op == "mul") calc = new mul;
	else if(op == "div") calc = new dive;
	
	if(calc){
		calc->get(a,b);
		delete calc;
	}else{
		cout << "Error" << endl;
	}
	return 0;
}








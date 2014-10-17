#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
//first type
typedef pair<int, int> T;
bool cmp(T const &a, T const &b)  {
	return a.first != b.first ? (a.first < b.first) : (a.second < b.second);
}
//second type
struct TT{
	int first, second;
	bool operator < (const TT &x) const {
		return first != x.first ? (first < x.first) : (second < x.second);
	}
}test[5] = {{1, 3}, {2, 5}, {2, 1}, {10, 3}, {-1, -1}};
/* first and second type works beautifully in std::sort() */

//third type for std::priority_queue
struct Comp{
	bool operator () (TT &a, TT &b) {
		return a < b;
	}
};
/* T, TT performs pair<int, int> with compare function equivalent to default */
int main(int argc, char *argv[]) {
	priority_queue<int> q1; //basic (max heap)
	priority_queue<int, vector<int>, greater<int> > q2; //min heap

	q1.push(30);q1.push(100);q1.push(25);q1.push(40);
	q2.push(30);q2.push(100);q2.push(25);q2.push(40);

	while (!q1.empty()) {
		cout << ' ' << q1.top();
		q1.pop();  //100 40 30 25
  	}
	cout << "\n";
	while (!q2.empty()) {
		cout << ' ' << q2.top();
		q2.pop();  //25 30 40 100
  	}
  	cout << "\n";

	priority_queue<TT, vector<TT>, Comp > q3(test, test+5);// heap using custom comp

	while(!q3.empty()) {
		printf("(%d, %d)", q3.top().first, q3.top().second);
		q3.pop();  //(10, 3)(2, 5)(2, 1)(1, 3)(-1, -1)
	}
	return 0;
}

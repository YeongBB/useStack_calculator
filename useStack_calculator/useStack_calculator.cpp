#include<iostream>
#include<stack>

using namespace std;

int counta(int num);

void main()
{

	stack<int> sta;
	stack<int> sta2;
	stack<int> result;

	int num1, coi1, co = 0;
	int num2, coi2, ca;

	cout << "1번째 숫자 : ";
	cin >> num1;
	cout << "2번째 숫자 : ";
	cin >> num2;

	coi1 = counta(num1) / 10;			//num1의 자릿수를 10의 제곱으로 표현  ex) num1=92134, coi1=10000
	coi2 = counta(num2) / 10;			//num2의 자릿수를 10의 제곱으로 표현   

	while (coi1 > 0)					//sta 스택에 하나씩 넣기
	{
		sta.push((num1 / coi1) % 10);
		coi1 /= 10;

	}
	while (coi2 > 0)				//sta2스택에 하나씩 넣기
	{
		sta2.push((num2 / coi2) % 10);
		coi2 /= 10;

	}


	//while(sta.empty() == false && sta2.empty() == false) 뭐지? 왜 안되는거지? 음...
	while (1)
	{
		if (sta.empty() == true)	//sta스택이 공백일시 0 넣기
		{
			sta.push(0);
		}
		else if (sta2.empty() == true)	//sta2스택이 공백일시 0 넣기
		{
			sta2.push(0);
		}

		result.push(sta.top() + sta2.top()); // result에 

		if (co > 0)
		{
			result.top() = result.top() + 1;
		}
		co = 0;
		if (result.top() >= 10)
		{
			result.top() = result.top() % 10;
			co++;
		}
		sta.pop();
		sta2.pop();
		if (sta.empty() == true && sta2.empty() == true)
		{
			break;
		}
	}

	cout << "결과 : ";
	while (result.empty() == false)
	{
		cout << result.top();
		result.pop();
	}
}
int counta(int num)
{
	int counta = 0, i = 1;
	while (num > i)
	{

		i *= 10;
		counta++;
	}
	if (counta == 0)
	{
		counta = 1;
	}

	return i;
}
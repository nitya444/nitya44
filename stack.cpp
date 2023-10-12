// reverse a sentence using stack
/*
# include<iostream>
# include<stack>
using namespace std;
	void reversesentence(string s)
	{
		stack<string>st;
		for(int i=0;i<s.length();i++)
		{
			string word=" ";
			while(s[i]!=' ' && i<s.length())
			{
				word+=s[i];
				i++;
			}
			st.push(word);
		}
		while(!st.empty())
		{
			cout<<st.top()<<" ";
			st.pop();
		}
		cout<<endl;
	}
	int main()
	{
		string s="Hey, are you doing?";
		reversesentence(s);
		
		return 0;
	}
*/
// reversing a stack
/*
# include<iostream>
# include<stack>
using namespace std;
void insertatbottom(stack<int> &st,int ele)
{
	if(st.empty())
	{
		st.push(ele);
		return;
	}
	int topele=st.top();
	st.pop();
	insertatbottom(st,ele);
	
	st.push(topele);
}
void reverse(stack<int> &st)
{
	if(st.empty())
	{
		return;
	}
	int ele=st.top();
	st.pop();
	reverse(st);
	insertatbottom(st,ele);
}
int main()
{
	stack<int>st;
	st.push(1);
	st.push(2);
	st.push(3);
	
//	reverse(st);
	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
	}
	cout<<endl;
}
*/
// INFIX TO POSTFIX
/*
# include<iostream>
# include<stack>
# include<algorithm>
using namespace std;
int prec(char c)
{
	if(c=='^')
	return 3;
	else if(c=='*'||c=='/')
	return 2;
	else if(c=='+'||c=='-')
	return 1;
	else
	return -1;
}
string infixtopostfix(string s)
{
	stack<char>st;
	string res;
	
	for(int i=0;i<s.length();i++)
	{
		if((s[i]>='a'&& s[i]<='z')|| (s[i]>='A' && s[i]<='Z'))
		{
			res+=s[i];
		}
		else if(s[i]=='(')
		{
			st.push(s[i]);
		}
		else if(s[i]==')')
		{
			while(!st.empty() && st.top()!='(')
			res+=st.top();
			st.pop();
		}
		else if(!st.empty())
		{
			st.pop();
		}
		else
		{
			while(!st.empty() && prec(st.top())>prec(s[i]))
			{
				res+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	while(!st.empty())
	{
		res+=st.top();
		st.pop();
	}
	return res;
}
}
main()
{
	cout<<infixtopostfix("(a-b/c)*(a/k-l)")<<endl;
}
*/
// INFIX TO PREFIX
/*
# include<iostream>
# include<stack>
# include<algorithm>
using namespace std;
int prec(char c)
{
	if(c=='^')
	return 3;
	else if(c=='/'||c=='*')
	return 2;
	else if(c=='-'||c=='+')
	return 1;
	else 
	return -1;
}
string infixtoprefix(string s)
{
	reverse(s.begin(),s.end());
	stack<char>st;
	string res;
	
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='a'&& s[i]<='z'||s[i]>='A' && s[i]<='Z')
		{
			res+=s[i];
		}
		else if(s[i]==')')
		st.push(s[i]);
		else if(s[i]=='(')
		{
			while(!st.empty() && st.top()!=')')
			{
				res+=st.top();
				st.pop();
			}
			if(!st.empty())
			{
				st.pop();
			}
		}
		else
		{
			while(!st.empty() && prec(st.top())>=prec(s[i]))
			res+=st.top();
			st.pop();
		}
		st.push(s[i]);
	}
while(!st.empty())
{
	res+=st.top();
	st.pop();
}
reverse(res.begin(),res.end());
return res;
}
int main()
{
	cout<<infixtoprefix("(a-b/c)*(a/k-l)")<<endl;
}
*/
// BALANCED PARENTHESIS
/*
# include<iostream>
# include<stack>
 //# include<bits/stdc++.h>
using namespace std;
bool isvalid(string s)
{
int i;
int n = s.size();

stack<char>st;
bool ans=true;

for(int i=0;i<n;i++)
{
	if(s[i]=='{'||s[i]=='['||s[i]=='('){
	st.push(s[i]);
}
else if(s[i]==')')
{
	if(!st.empty() && st.top()=='(')
	{
		st.pop();
	}
	else
	{
		ans=false;
		break;
	}
}
else if(s[i]=='{')
{
     	if(!st.empty() && st.top()=='}')
	{
		st.pop();
	}
	else
	{
		ans=false;
		break;
	}
}	
else if(s[i]=='[')
{
	
     	if(!st.empty() && st.top()==']')
	{
		st.pop();
	}
	else
	{
		ans=false;
		break;
	}
}
}
if(!st.empty())
 {
 	return false;
 }
 
 return ans;
}
int main()
{
	string s="{([])}";
	if(isvalid(s))
	{
		cout<<"valid string"<<endl;
	}
	else
	{
		cout<<"invalid string"<<endl;
	}
	return 0;
}
*/
//QUEUE USING STACK
/*
# include<iostream>
# include<stack>
# include<algorithm>
using namespace std;
class que
{
	stack<int>s1;
	stack<int>s2;
	
	public:
		void push(int x){
		s1.push(x);
}
int pop()
{
	if(s1.empty() && s2.empty())
 	{
		cout<<"queue is empty";
		return -1;
	}
	if(s2.empty())
	{
		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	int topval=s2.top();
	s2.pop();
	return topval;
}
bool empty()
{
	if(s1.empty() && s2.empty())
	 return true;
	return false;
}
};
int main()
{
	que q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout<<q.pop();
	q.push(5);
	cout<<q.pop()<<"\n";
	cout<<q.pop()<<"\n";
	cout<<q.pop()<<"\n";
	cout<<q.pop()<<"\n";
	cout<<q.pop()<<"\n";
}
*/

# include<iostream>
# include<algorithm>
# include<deque>
# include<vector>
using namespace std;
int main()
{
	int n,k,i;
	cin>>n>>k;
	vector<int>a(n);
	for(auto &i:a)
	cin>>i;
	
	deque<int>q;
	vector<int>ans;
	for(i=0;i<k;i++)
	{
		while(!q.empty() && a[q.back()]<a[i])
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	ans.push_back(nums[q.front()]);
	for(i=k;i<n;i++)
	{
		if(q.front()==i-k)
		{
			q.pop_front();
		}
		while(!q.empty() && a[q.back()]<a[i])
		{
			q.pop_back();
		}
		q.push_back(i);
		ans.push_back(a[q.front()]);
	}
	for(auto i:ans)
	cout<<i<<" ";
}






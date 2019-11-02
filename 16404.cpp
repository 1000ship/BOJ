#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, m;
int min( int a, int b)
{
    return (a>b)?b:a;
}

class Person {
public:
    int sid;
    int id;
    int childNum;
    vector<int> children;
    static int cnt;
};
int Person::cnt = 0;
Person *people;

class Segment {
public:
    int from;
    int to;
    int value;
    Segment *left;
    Segment *right;
    Segment *top;
    Segment (int from, int to) {
        this->value = 0;
        this->from = from;
        this->to = to;
        this->top = this->left = this->right = NULL;
    }
    void makeChildren( Segment* *seg_arr)
    {
        if( from == to )
        {
            seg_arr[ from ] = this;
            return;
        }
        int mid = (from+to)/2;
        left = new Segment(from, mid);
        right = new Segment(mid+1, to);
        left->top = right->top = this;
        left->makeChildren(seg_arr);
        right->makeChildren(seg_arr);
    }
    int getValue ()
    {
        if( top == NULL )
            return value;
        return value + top->getValue();
    }
};
Segment *seg;
Segment* *seg_arr;

void assign_sid ( )
{
    stack<Person*> stack;
    stack.push(&people[0]);
    while( !stack.empty() )
    {
        Person *person = stack.top();
        if(person == NULL)
        {
            stack.pop();
            person = stack.top();
            person->childNum = Person::cnt - person->sid - 1;
            stack.pop();
            continue;
        }
        person->sid = Person::cnt++;
        stack.push(NULL);
        for(int i = 0; i < person->children.size(); ++ i)
            stack.push( &people[person->children.at(i)] );
    }
}

void range_sum ( Segment *seg, int from, int to, int value )
{
    if(seg->from == from && seg->to == to)
    {
        seg->value += value;
        return;
    }
    int mid = (seg->from+seg->to)/2;
    if( to <= mid )
    {
        range_sum(seg->left, from, to, value);
        return;
    }
    else if( mid < from )
    {
        range_sum(seg->right, from, to, value);
        return;
    }
    range_sum(seg->left, from, mid, value);
    range_sum(seg->right, mid+1, to, value);
}

void debug ( void )
{
    for(int i = 0; i < n; ++ i )
        cout << ">> " << seg_arr[i]->from << '~' << seg_arr[i]->to << ' ' << seg_arr[i]->value << '\n';
}

void debug2 ( void )
{
    for(int i = 0; i < n; ++ i )
        cout << ">> " << people[i].id << '/' << people[i].sid << ' ' << people[i].childNum << '\n';
}

void debug3 ( Segment *seg )
{
    cout << ">> " << seg->from << '~' << seg->to << " / " << seg->value << '\n';
    if(seg->left == NULL)
        return;
    debug3(seg->left);
    debug3(seg->right);
}

int main ( void )
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    seg_arr = new Segment*[n];
    seg = new Segment(0, n-1);
    seg->makeChildren(seg_arr);
    people = new Person[n];
    for(int i = 0; i < n; ++ i)
    {
        people[i].id = i;
        int sasu;
        cin >> sasu;
        if(sasu != -1)
            people[sasu-1].children.push_back(i);
    }
    assign_sid();

    for(int t = 0;  t < m; ++ t )
    {
        int a, b, c;
        cin >> a >> b;
        b -= 1;
        switch( a ){
            case 1:
                cin >> c;
                range_sum(seg, people[b].sid, people[b].sid+people[b].childNum, c);
                break;
            case 2:
                cout << seg_arr[people[b].sid]->getValue() << '\n';
                break;
        }
    }
    return 0;
}
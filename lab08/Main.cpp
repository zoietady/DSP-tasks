
// COS30008, Tutorial 10, 2021

#include <iostream>
#include <string>

#define P1
#define P2
#define P3
#define P4

using namespace std;

#ifdef P1

#include "Stack.h"

void testP1()
{
    Stack<string> lStack;
    
    string aaaa( "AAAA" );
    string cccc( "CCCC" );

    cout << "Test of stack:" << endl;

    lStack.push( aaaa );
    lStack.push( "BBBB" );
    lStack.push( cccc );
    lStack.push( "DDDD" );
    
    cout << "top: " << lStack.top() << endl;
    lStack.pop();
    cout << "top: " << lStack.top() << endl;
    lStack.pop();
    cout << "top: " << lStack.top() << endl;
    cout << "size: " << lStack.size() << endl;
    cout << "is empty: " << (lStack ? "T" : "F" ) << endl;
    lStack.pop();
    cout << "top: " << lStack.top() << endl;
    lStack.pop();
    cout << "is empty: " << (lStack ? "T" : "F" ) << endl;
    
    try
    {
        lStack.pop();
    }
    catch (underflow_error e)
    {
        cout << "Exception successfully caught: " << e.what() << endl;
    }
    
    cout << "Test of stack completed." << endl;
}

#endif

#ifdef P2

#include "Stack.h"
#include "StackIterator.h"

void testP2()
{
    Stack<string> lStack;
    
    string s1( "One" );
    string s2( "Two" );
    string s3( "Three" );
    string s4( "Four" );
    string s5( "Five" );
    string s6( "Six" );
    
    lStack.push( s1 );
    lStack.push( s2 );
    lStack.push( s3 );
    lStack.push( s4 );
    lStack.push( s5 );
    lStack.push( s6 );
    
    cout << "Test of stack iterator:" << endl;

    for ( const string& s : lStack )
    {
        cout << s << endl;
    }
 
    cout << "Test of stack iterator completed." << endl;
}

#endif

#ifdef P3

#include "Queue.h"

void testP3()
{
    Queue<int> lQueue;
    
    int lVar3 = 3;
    int lVar6 = 6;

    lQueue.enqueue( 1 );
    lQueue.enqueue( 2 );
    lQueue.enqueue( lVar3 );
    lQueue.enqueue( 4 );
    lQueue.enqueue( 5 );
    lQueue.enqueue( lVar6 );
    
    cout << "Test of queue:" << endl;
    
    for ( ; !lQueue; lQueue.dequeue() )
    {
        cout << "top: " << lQueue.top() << endl;
    }
    
    try
    {
        lQueue.dequeue();
    }
    catch (underflow_error e)
    {
        cout << "Exception successfully caught: " << e.what() << endl;
    }

    cout << "Test of queue completed." << endl;
}
    
#endif

#ifdef P4

#include "Queue.h"
#include "QueueIterator.h"

void testP4()
{
    Queue<string> lQueue;
    
    lQueue.enqueue( "One" );
    lQueue.enqueue( "Two" );
    lQueue.enqueue( "Three" );
    lQueue.enqueue( "Four" );
    lQueue.enqueue( "Five" );
    lQueue.enqueue( "Six" );
    
    cout << "Test of queue iterator:" << endl;

    QueueIterator<string> iter( lQueue );
    
    for ( const string& s : lQueue )
    {
        cout << s << endl;
    }
        
    cout << "Test of queue iterator completed." << endl;
}

#endif

int main()
{
#ifdef P1
    testP1();
#endif

#ifdef P2
    testP2();
#endif

#ifdef P3
    testP3();
#endif

#ifdef P4
    testP4();
#endif

	return 0;
}

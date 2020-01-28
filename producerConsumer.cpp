// Consumer Producer Algo
// headerfiles
#include<iostream>
// namespace
using namespace std;
int mutex = 1;
int x = 0;
int full = 0;  // Variable to store Number of filled slots in buffer
int empty = 0; // Variable to store Number of empty slots in buffer
void producer(string*); // function for Producer to Produce
void consumer(string*); // function for Consumer to Consume
int wait(int);   // funtion to Decrement value of variable
int signal(int); // function to Insert value of variable
void PutItemIntoBuffer(string*,string); // function to put item into buffer
int main()
{
  system("Title Producer Consumer Algorithm"); // to set title of window
  system("mode con: cols=100 lines=30"); // to set size of window 
  int n;// variable to store choice
  system("COLOR 9F");
  // to input buffer size from user
  cout << "\n\n\n\t\t\tEnter the size of Buffer: ";
  cin >> empty;
  string buffer[empty]; 
  system("cls"); 
  cout << "\n\n";
  system("COLOR 8F"); 
  cout << "\t\t\t" << char(201);
  for(int i=0; i<30; i++)
  {
    cout << char(205);
  }
    cout << char(187) << endl;
    cout << "\t\t\t" << char(186) << " 1)Producer                   " << char(186) << endl;
    cout << "\t\t\t" << char(186) << " 2)Consumer                   " << char(186) << endl;
    cout << "\t\t\t" << char(186) << " 3)Display Buffer             " << char(186) << endl;
    cout << "\t\t\t" << char(186) << " 4)Exit                       " << char(186) << endl;
    cout << "\t\t\t" << char(200);
    for(int i=0; i<30; i++)
    {
      cout<<char(205);
    }
      cout <<char(188)<<endl;
      while(1)
    {
	//for user to enter the choice
	cout << "\n\t\t\tEnter your choice:";
	cin >> n;
	switch(n)
	{
	  case 1:	
	   if((mutex == 1)&&(empty != 0))  // Condition where no one is in critical section and buffer is not full.
	   producer(buffer); // Calling Producer Function
	   else
	       cout << "\n\t\t\tBuffer is already full! You cannot produce more!" << endl;
	       break;
	   case 2:	
	    if((mutex == 1)&&(full != 0)) // Condition where no one is in critical section and buffer is not empty
	    consumer(buffer); // Calling Consumer Function
	    else
	        cout << "\n\t\t\tBuffer is already empty! You cannot consume more!" << endl;
		break;
	    case 3:
	     if(full == 0) // if condition when buffer is empty
	       {
	         cout << "\n\t\t\tThe Buffer is Empty!" << endl;
		 break;
	       }
	         cout << "\n\t\t\t|| Displaying Buffer ||" << endl;
	         for(int i = full-1 ; i >= 0; i--) // displaying Buffer
	       {
		 cout << "\n\t\t\t" << buffer[i] << endl;
	       }		
		break;
	     case 4:
	          cout << "\n\t\t\tThankyou!";
		  exit(0);
	          break;
		}
	}	
	return 0;
}
   int wait(int s)
{
   return (--s); // first decrement and then return that value
}
   int signal(int s)
{
   return(++s); // first increment and then return that value
}
   void producer(string *b)
{
   cin.ignore();
   string item ;
   cout << "\n\t\t\tEnter item Name: ";
   getline(cin,item,'\n');	
   mutex = wait(mutex); 
   PutItemIntoBuffer(b,item);
   cout << "\n\t\t\tProducer produces the item " << b[full] << endl;
   full = signal(full); 
   empty = wait(empty);
   x++;
   mutex = signal(mutex);
}
    void consumer(string *b)
{
    mutex = wait(mutex); 
    full = wait(full);
    cout << "\n\t\t\tConsumer consumes item " << b[full] << endl;
    empty = signal(empty);
    x--;
    mutex = signal(mutex);
}
    void PutItemIntoBuffer(string *b,string item)
{	
    b[full] = item;	
}

#include <iostream>

using namespace std;

/*int main()

{
	int size, A, B, C , D;
	cout<< "Enter N, A, B , C , D"<<endl;
	cin >>size >> A >> B >> C>>  D;
	if (size <= 0 || A> B || C> D || D > size)
	{
	cout<<"Erorr"<<endl;
 	return 1 ; 
        }
        int* arr = new int[size];
        for(int i = 0; i< size ; i++) arr[i] = i+1;
        cout << "our arr"<<endl;
        for(int i = 0; i< size ; i++) cout<<arr[i]<<" ";
        cout << endl;
        int rev1, rev2;
        int size1 = B;
        int size2 = D;
        for (int i = A-1 ; i<= (B-A)/2+A-1; i++ )   
        {
                rev1 = arr[i];
                arr[i] = arr[size1-1];
                arr[size1-1]=rev1;
                size1--;
                rev1 =0; 
        }    
        cout<< "first reverse"<< endl;
        for(int i = 0; i< size ; i++) cout<<arr[i]<<" ";
        cout << endl;


        for (int i = C-1 ; i<= (D-C)/2+C-1; i++ )   
        {
                rev2 = arr[i];
                arr[i] = arr[size2-1];
                arr[size2-1]=rev2;
                size2--;
                rev2 =0; 
        }    
        cout<< " second reverse"<< endl;
        for(int i = 0; i< size ; i++) cout<<arr[i]<<" ";
        cout << endl;

        delete[] arr;
        arr = nullptr;
        return 0;

}*/


/*#include <iostream>
using namespace std;

int main()

{
        int size;
        cin >>size;
        if (size <= 0)
        {
        cout<<"Error"<<endl;
	return 1 ; 
        }
	int num = 0;
        int* arr = new int[size];
        for(int i = 0; i< size ; i++) cin >> arr[i];
        cout << "our arr"<<endl;
        for(int i = 0; i< size ; i++)
	{	
		num+= arr[i];
		cout<<arr[i]<<" ";
	}
	double result =static_cast<double>(num)/size;
        cout << endl;
	cout << result << endl;



	delete [] arr;
	arr = nullptr;
	return 0;

}*/


/*#include <iostream>
using namespace std;

int main()
{
        const int max =100;
	char* first= new char[max];
	char* second= new char[max];
	char* result = new char [max *2];
	cout << "enter First"<<endl;
	cin >> first;
	cout << "enter Second"<<endl;
	cin >> second;
        
	char* r = result;
	char* f = first;
	char* s = second;

	while(*f != '\0')
	{
		*r=*f;
		r++;
		f++;
	}

	while(*s != '\0')
        {       
                *r=*s;
                r++;
                s++;
        } 
	
	cout<< result<<endl;
	delete[] first;
	delete[] second;
	delete[] result;
        return 0;
}*/





/*
#include <iostream>
using namespace std;

int main()
{	
	int number ;
	cin>> number ;
	int* arr = new int[number];
	for(int i= 0 ; i< number ; i++) cin>> arr[i];
	for(int i= 0 ; i< number ; i++) cout<<arr[i]<<" " ;
	cout << endl;
	for (int i= 0; i< number/2 ; i++ )
	{
		int res;
		res = arr[i];
		arr[i]=arr[number-1-i];
		arr[number-1-i]=res;
	}
	for(int i= 0 ; i< number ; i++) cout<<arr[i]<<" " ;
	cout << endl;
	delete[] arr;
	return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main()
{
        int number ;
        cin>> number ;
        int* arr = new int[number];
        for(int i= 0 ; i< number ; i++) cin>> arr[i];
        for(int i= 0 ; i< number ; i++) cout<<arr[i]<<" " ;
        cout << endl;
	int N, M;
	cout << "Enter 2 numbers"<<endl;
	cin >> N>>M;
	if(N>number || N<0 || M<0 || M==N || M> number )
	{
		cout<<"Error"<<endl;
		return 1;
	}
	int result = 0;
        for (int i= N-1; i<M ; i++ )
        {
		result +=arr[i];
		if(i==M-1) cout <<arr[i];
		else cout<<arr[i]<< " + ";
        }
        cout <<"="<<result<< endl;
        delete[] arr;
        return 0;
}*/

/*
#include <iostream>
using namespace std;

int main()
{
        int number ;
        cin>> number ;
        int* arr = new int[number];
        for(int i= 0 ; i< number ; i++) cin>> arr[i];
        for(int i= 0 ; i< number ; i++) cout<<arr[i]<<" " ;
        cout << endl;
	int result = 0;
        for (int i=0; i<number ; i++ )
        {
		if ((i%3==0 || i%5==0 )&& i != 0) result +=arr[i]; 
        }
	cout << result << endl;
        delete[] arr;
        return 0;
}*/

/*

#include <iostream>
using namespace std;

int main()
{
        int row, col ;
	cout <<" enter row and col"<<endl;
        cin>> row >> col ;
	int sum= 0;
        int** matrix= new int*[row];
        for(int i= 0 ; i< row ; i++)
	{
		matrix[i]=new int[col];
	}
        for(int i= 0 ; i< row; i++)
	{
		for (int j =0; j<col; j++)	
		{
			cin >> matrix[i][j];
		}
	}
	  for(int i= 0 ; i< row; i++)
        {
                for (int j =0; j<col; j++)
                {
                        cout << matrix[i][j]<< " ";
			if (i==j)
			{
				for (int nn= 0 ; nn<col; nn++) sum+=matrix[i][nn];
				matrix[i][j]=sum;
				sum = 0;
			}
                }
		cout << "\n";
        }
	  for(int i= 0 ; i< row; i++)
        {
                for (int j =0; j<col; j++)  cout<< matrix[i][j]<<" ";
		cout << "\n";       
        }
	for (int i =0 ; i< row ; i++) delete[] matrix[i]; 
        delete[] matrix;
        return 0;
}
*/




/*
#include <iostream>
using namespace std;

int main ()
{
	int row , col;
	cin>> row>> col;
	if(col<=1 || row <=1)
	{
		cout<<"error"<<endl;
		return 1;
	}
	int** matrix= new int*[row];
	for (int i = 0; i<row; i++) matrix[i]=new int[col];
	for (int i = 0; i<row; i++)
	{
		for (int j= 0; j<col; j++) cin>> matrix[i][j];
	}
	int max=matrix[0][1];
	for (int i = 0; i<row; i++) 
        {
		for (int j= 0; j<col; j++) cout<< matrix[i][j]<< " ";
		cout << "\n";
		int bor ;
		if(row>col) bor= col;
			else bor =row;
		for (int j= i+1; j<bor; j++)
                {  
                        if (matrix[i][j]>max) max = matrix[i][j];
                }   

        }
	cout <<"Max is : "<< max<<endl;	

	for (int i= 0 ; i< row ; i++) delete[] matrix[i];
	delete[] matrix; 
	return 0;
}
*/




/*
#include <iostream>
using namespace std;

int main ()
{
        int row , col;
        cin>> row>> col;
        if(col<=1 || row <=1)
        {   
                cout<<"error"<<endl;
                return 1;
        }   
        float** matrix= new float*[row];
        for (int i = 0; i<row; i++) matrix[i]=new float [col];
        for (int i = 0; i<row; i++)
        {   
                for (int j= 0; j<col; j++) cin>> matrix[i][j];
        }   
        int result =0 ;
        for (int i = 0; i<row; i++) 
        {   
                for (int j= 0; j<col; j++)
                {
			cout<< matrix[i][j]<< " ";
			
			if (j<=i && matrix[i][j]>=12.3 && matrix[i][j]<34.1) result++;
		}
		cout<<"\n";

        }   
        cout <<"Result is : "<< result<<endl; 

        for (int i= 0 ; i< row ; i++) delete[] matrix[i];
        delete[] matrix; 
        return 0;
}
*/

/*
#include <iostream>
using namespace std;
#include <string>

int main()
{
	string lett="abcdefghijklmnopqrstuvwxyz";
	string text;
	cout << "Enter a text"<<endl;
	cin>>text;
	int num ;
	cout<< "Enter a number"<<endl;
	cin>>num;
	if (num<=0 || num> 26)
	{	
		cout<<"wrong"<<endl;
		return 1;
	}
	for (int i =0 ; i<text.length();i++)
	{
		for (int j = 0; j<26; j++)
		{
			if (text[i]==lett[j])
			 
			{
				text[i]=lett[(j+num+26)%26];
				break;	
			}
			}	
		
	}
	cout<<"New text "<<text<<endl;
return 0;
}*/

#include <iostream>
using namespace std;

int main ()
{
        int row , col;
        cin>> row>> col;
        if(col<=1 || row <=1)
        {
                cout<<"error"<<endl;
                return 1;
        }
        float** matrix= new float*[row];
        for (int i = 0; i<row; i++) matrix[i]=new float [col];
        for (int i = 0; i<row; i++)
        {
                for (int j= 0; j<col; j++) cin>> matrix[i][j];
        }
        int result =0 ;
        for (int i = 0; i<row; i++)
        {
                for (int j= 0; j<col; j++)
                {
                        cout<< matrix[i][j]<< " ";
			
                }
                cout<<"\n";
		int bor ;
                if(row>col) bor= col;
                else bor =row;
		for (int j = i+1 ;j<bor ;j ++)
		{
		
                        if (j>=i && matrix[i][j]>=12.3 && matrix[i][j]<34.1) result++;
		}

        }
        cout <<"Result is : "<< result<<endl;

        for (int i= 0 ; i< row ; i++) delete[] matrix[i];
        delete[] matrix;
        return 0;
}


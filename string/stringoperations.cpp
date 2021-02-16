#include <iostream>
using namespace std;
# define NO_OF_CHARS 256


 void reverseString(vector<char>& s) {
        int n=s.size();
        for(int i=0;i<n/2;i++)
            {
                char temp=s[i];
                s[i]=s[n-i-1];
                s[n-i-1]=temp;
        }

 int isPlaindrome(string S)
	{
	    // Your code goes here
	    int n= S.length();
	    for (int i=0;i<n/2;i++)
	        {
	            if(S[n-i-1]!=S[i])
	                return 0;
	        }
	   return 1;
	}

// C++ program to count all duplicates
// from string using hashing

class gfg
{
	public :
	
	/* Fills count array with
	frequency of characters */
	void fillCharCounts(char *str, int *count)
	{
		int i;
		for (i = 0; *(str + i); i++)
		count[*(str + i)]++;
	}

	/* Print duplicates present 
	in the passed string */
	void printDups(char *str)
	{
		
		// Create an array of size 256 and fill
		// count of every character in it
		int *count = (int *)calloc(NO_OF_CHARS, 
									sizeof(int));
		fillCharCounts(str, count);

		// Print characters having count more than 0
		int i;
		for (i = 0; i < NO_OF_CHARS; i++)
		if(count[i] > 1)
			printf("%c, count = %d \n", i, count[i]);

		free(count);
	}
};

/* Driver code*/
int main()
{
	gfg g ;
	char str[] = "test string";
	g.printDups(str);
	//getchar();
	return 0;
}

// This code is contributed by SoM15242

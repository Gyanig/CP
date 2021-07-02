#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct suffix
{
	int index;
	char *suff;
};

int cmp(struct suffix a, struct suffix b)
{
	return strcmp(a.suff, b.suff) < 0? 1 : 0;
}

int *buildSuffixArray(char *txt, int n)
{
	struct suffix suffixes[n];
	for (int i = 0; i < n; i++)
	{
		suffixes[i].index = i;
		suffixes[i].suff = (txt+i);
	}
	sort(suffixes, suffixes+n, cmp);

	int *suffixArr = new int[n];
	for (int i = 0; i < n; i++)
		suffixArr[i] = suffixes[i].index;

	return suffixArr;
}

void printArr(int arr[], int n)
{
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void search(char *pat, char *txt, int *suffArr, int n)
{
    int m = strlen(pat);  
    int l = 0, r = n-1;  
    while (l <= r)
    {
        int mid = l + (r - l)/2;
        int res = strncmp(pat, txt+suffArr[mid], m);
        if (res == 0)
        {
            cout << "Pattern found at index " << suffArr[mid];
            return;
        }

        if (res < 0) r = mid - 1;
        else l = mid + 1;
    }
 
    cout << "Pattern not found";
}

int main()
{
	char txt[] = "banana";
	int n = strlen(txt);
	int *suffixArr = buildSuffixArray(txt, n);
	cout << "Following is suffix array for " << txt << endl;
	printArr(suffixArr, n);

	char pat[] = "nan"; 
	search(pat, txt, suffixArr, n);
 
	return 0;
}

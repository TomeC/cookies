#ifndef __KMP_H__
#define __KMP_H__
//±©¡¶∆•≈‰
int indexBF (const char *S, const char* T)
{
	int lenS, lenT, i, j;
	lenS = strlen (S);
	lenT = strlen (T);
	i = j = 0;
	while ((i < lenS) && (j < lenT))
	{
		if (S[i] == T[j])
		{
			i++;
			j++;
		}else
		{
			i = i-j+1;
			j = 0;
		}
	}
	if (j == lenT)
		return i-j;
	return -1;
}
//KMP
int* getNext(const char* T)
{
    int lenT = strlen(T);
    int* a = new int[lenT];
    a[0] = -1;
    int j = -1;
    for(int i = 1; i < lenT; i++)
    {
        while(j > -1 && T[i] != T[j + 1])
            j = a[j];
        if(T[j+1] == T[i])
            j = j + 1;
        a[i] = j;
    }
    return a;
}

int indexKMP(const char* S, const char* T)
{
    int j = -1;
    int lenT = strlen(T);
    int lenS = strlen(S);
	int *a = getNext (T);
    for(int i = 0; i < lenS; i++)
    {
        while(j > -1 && S[i] != T[j + 1])
            j = a[j];
        if(S[i] == T[j + 1])
            j++;

        if(j == lenT -1)
        {
			return i-lenT+1;
        }
    }
	return -1;
}
/*
//Test procedure
int main()
{
    char* S = "aaas";
    char* T = "aaas";
	cout<<indexBF(S, T)<<endl;
    cout<<indexKMP(S, T)<<endl;;
    return 0;
}
*/
#endif
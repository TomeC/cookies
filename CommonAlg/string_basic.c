#include <stdio.h>
char *strcpy (char *strDest, char *strSrc)
{
	if (strDest == NULL || strSrc == NULL)
		return NULL;
	if (strDest == strSrc)
		return strDest;
	char *tmp = strDest;
	while ((*strDest++ = *strSrc++) != '\0');
	return tmp;
}
int strcmp (const char * src,const char * dst)
{
        int ret = 0 ;
        while( ! (ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
                ++src, ++dst;
        if ( ret < 0 )
                ret = -1 ;
        else if ( ret > 0 )
                ret = 1 ;
        return( ret );
}
char *strcat (char * dst,const char * src)
{
        char * cp = dst;
        while( *cp )
               cp++;                   
        while( *cp++ = *src++ ) ;      
        return( dst );                  
}
int strlen (const char * str)
{
        const char *eos = str;
        while( *eos++ ) ;
        return( (int)(eos - str - 1) );
}
char *strstr (const char * str1,const char * str2)
{
        char *cp = (char *) str1;
        char *s1, *s2;
        if ( !*str2 )
            return((char *)str1);
             while (*cp)
             {
                     s1 = cp;
                     s2 = (char *) str2;
                     while ( *s1 && *s2 && !(*s1-*s2) )
                            s1++, s2++;
                     if (!*s2)
                             return(cp);
                     cp++;
             }
            return(NULL);
}
int abs (int number)
{
        return( number>=0 ? number : -number );
}
int memcmp (const void * buf1,const void * buf2,size_t count)
{
        if (!count)
		return(0);
         while ( --count && *(char *)buf1 == *(char *)buf2 ) 
	 {
                 buf1 = (char *)buf1 + 1;
                 buf2 = (char *)buf2 + 1;
	 }
         return( *((unsigned char *)buf1) - *((unsigned char *)buf2) );
}
void *memcpy (void * dst,const void * src,size_t count)
{
        void * ret = dst;
        while (count--) 
	{
                *(char *)dst = *(char *)src;
                dst = (char *)dst + 1;
                src = (char *)src + 1;
        }
        return(ret);
}
void *memset (void *dst,int val,size_t count)
{
        void *start = dst;
        while (count--)
	{
                *(char *)dst = (char)val;
                dst = (char *)dst + 1;
        }
        return(start);
}
int main ()
{
	char *a = "hello";
	char *c = "haha";
	char b[10];
	printf ("%s\n",strcpy (b, a));
	printf ("%s\n", b);
	printf ("%d\n", strcmp (a, c));
	printf ("%s\n", strcat (b, a));
	return 0;
}

// Move the assignment into the test
// Memory msut be guaranteed to be allocated before entry
// Doesn't do any null pointer checking--should let it segfault
void strcpy_kc(char dest[], const char source[]) 
{
    int i = 0;
    while ((dest[i] = source[i]) != '\0')
    {
        i++;
    } 
}
/* FIXME: Implement! */
char smallest_character(char str[], char c, int index)
{
    if( str[index] != 127){
        if(str[index] > c)
            return str[index];
        else
            return smallest_character(str, c, ++index);
    }
    return str[0];

}



/* FIXME: Implement! */
char smallest_character(char str[], char c)
{
	for(int i = 0; str[i] != 127; i++){
		if( str[i] > c)
			return str[i];
	}
	return str[0];
}


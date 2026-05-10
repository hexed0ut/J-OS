char input_buffer[2048];
char output_buffer[2048];

void flush_input_buffer()
{

}

void memcpy(char* source, char* destination, int size)
{
	char temp[size];
	for (int i=0; i<size; i++)
	{
		temp[i] = *source;
		source += 1;
	}
	for (int i=0; i<size; i++)
	{
		*destination = temp[i];
		destination += 1;
	}
}
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>


// Define functions that you want to use in your dictionary
void functionCall_1(void);
void functionCall_2(void);
void functionCall_3(void);
void functionCall_4(void);

// Define a structure that will be used for dictionary
struct functionDictionary 
{ 
	const char key;
	const char *decription;
	void(*functionAddress)(); 
};

// Define your structure to be used by your help function
const struct functionDictionary HelpDictionary[] = {
  { '+', "This is a description for PLUS function", 	functionCall_1 },
  { '-', "This is a description for MINUS function", 	functionCall_2 },
  { '.', "This is a description for DOT function", 		functionCall_3 },
  { '=', "This is a description for EQUALS function", 	functionCall_4 },
};
const int HelpDictionary_Size = 4;


// This is the function that will go trough given dictionary and print out all descriptions and characters
void Dictionary_Show(const struct functionDictionary *dict, const int dictSize)
{
	uint8_t i;

	printf("------------ HELP -----------\r\n");
	printf("Dictionary has %d entries\r\n", dictSize);
	printf("'X' - Description\r\n");

	for(i=0; i< dictSize; i++)
	{
		printf("'%c' - %s\n", dict[i].key, dict[i].decription);
	}

	printf("------------ END -----------\r\n");
}

bool Dictionary_Execute(const struct functionDictionary *dict, const int dictSize, uint8_t *requestChar)
{
	uint8_t i;

	for(i=0; i< dictSize; i++)
	{
		if(dict[i].key == *requestChar)
		{
			dict[i].functionAddress();
			return true;
		}
	}

	return false;
}


int main(void)
{
	uint8_t ch = 0;

	printf("Select option: \r\n");
	printf("(type 'h' for help or 'q' for quit) \r\n");	
	while(ch != 'q')
	{
		ch = getchar();
		printf("\r\n>> ");

		if(ch == '\r' || ch == '\n')
		{
			continue;
		}
		else 
		{

			if(ch == 'h')
			{
				Dictionary_Show(HelpDictionary, HelpDictionary_Size);
			}
			else if(ch=='q')
			{
				printf("Goodbye! \r\n");	
				return 0;
			}
			else
			{
				if(Dictionary_Execute(HelpDictionary, HelpDictionary_Size, &ch) == true)
				{
					printf("Function executed! \r\n");
				}
				else
				{
					printf("Function failed to execute or find corresponding function.\r\n");
				}
			}

		}


	}

	return 0;
}


void functionCall_1(void)
{
	printf("Function 1 called\r\n");
}

void functionCall_2(void)
{
	printf("Function 2 called\r\n");
}

void functionCall_3(void)
{
	printf("Function 3 called\r\n");
}

void functionCall_4(void)
{
	printf("Function 4 called\r\n");
}
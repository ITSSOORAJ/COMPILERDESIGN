#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
	FILE *input, *output;
	int l = 1;
	int t = 0;
	int j = 0;
	int i, flag;
	char ch, str[100];
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	char keyword[30][30] = { "int", "main", "if", "else", "do", "while","printf","scanf" };
	fprintf(output, "Line no. \t Token no. \t\t Token \t\t Lexeme\n\n");

	while (!feof(input))
	{
		i = 0;
		flag = 0;
		ch = fgetc(input);

		// Detect the start of a string literal
		if (ch == '"')
		{
			str[i++] = ch;
			ch = fgetc(input);

			// Read until the closing quote is found
			while (ch != '"' && ch != EOF)
			{
				str[i++] = ch;
				ch = fgetc(input);
			}

			// Include the closing quote
			if (ch == '"')
			{
				str[i++] = ch;
			}

			str[i] = '\0'; // Null-terminate the string

			fprintf(output, "%7d\t\t %7d\t\t Literal\t %7s\n", l, t, str);
			t++;
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		{
			fprintf(output, "%7d\t\t %7d\t\t Operator\t %7c\n", l, t, ch);
			t++;
		}
		else if (ch == ';' || ch == '{' || ch == '}' || ch == '(' || ch == ')' || ch == '?' || ch == '@' || ch == '!')
		{
			fprintf(output, "%7d\t\t %7d\t\t Special symbol\t %7c\n", l, t, ch);
			t++;
		}
		else if (isdigit(ch))
		{
			str[i++] = ch;
			ch = fgetc(input);

			// Continue reading as long as the next character is a digit
			while (isdigit(ch))
			{
				str[i++] = ch;
				ch = fgetc(input);
			}
			str[i] = '\0'; // Null-terminate the string

			fprintf(output, "%7d\t\t %7d\t\t Digit\t\t %7s\n", l, t, str);
			t++;

			// If the last character read isn't part of the number, put it back to be processed later
			if (!isspace(ch) && !isalnum(ch))
			{
				ungetc(ch, input);
			}
		}
		else if (isalpha(ch))
		{
			str[i++] = ch;
			ch = fgetc(input);

			while (isalnum(ch))
			{
				str[i++] = ch;
				ch = fgetc(input);
			}

			str[i] = '\0';

			for (j = 0; j < 30; j++)
			{
				if (strcmp(str, keyword[j]) == 0)
				{
					flag = 1;
					break;
				}
			}

			if (flag == 1)
			{
				fprintf(output, "%7d\t\t %7d\t\t Keyword\t %7s\n", l, t, str);
				t++;
			}
			else
			{
				fprintf(output, "%7d\t\t %7d\t\t Identifier\t %7s\n", l, t, str);
				t++;
			}

			// If the last character read isn't part of the identifier, put it back to be processed later
			if (!isspace(ch) && !isalnum(ch))
			{
				ungetc(ch, input);
			}
		}
		else if (ch == '\n')
		{
			l++;
		}
	}

	fclose(input);
	fclose(output);
	return 0;
}

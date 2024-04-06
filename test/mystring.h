#ifndef MYSTRING_H
#define MYSTRING_H

// Calcula la longitud de una cadena
int my_strlen(const char* str) {
	int len = 0;
	for (char* p = (char*)str; *p != '\0'; p++) {
		len++;
	}
	return len;
}

// Copia una cadena desde el origen al destino. Asume que la cadena dest tiene suficiente longitud. 
char* my_strcpy(char* dest, const char* src) {
	for (char* p = (char*)src; *p != '\0'; p++) {
		*(dest++) = *(p++);
	}
	*(dest + 5) = '\0';
	return dest;
}

// Concatena dos cadenas y devuelve el resultado
char* my_strcat(char* dest, const char* src);

// Busca la primera ocurrencia de un carácter en una cadena y devuelve un puntero a esa posición
char* my_strchr(const char* str, int c);

// Extrae un substring de una cadena y devuelve un puntero al substring
char* my_substr(const char* str, int start, int end);

// Invertir una cadena utilizando punteros
void my_reverse(char* str);

// Divide una cadena en tokens basándose en un delimitador.
char* my_strtok(char* str, const char* delim);

#endif // MYSTRING_H
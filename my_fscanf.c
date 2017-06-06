#include "my_fscanf.h"
#include <stdarg.h>
#include <ctype.h>

void my_fscanf(FILE *fp, const char *format, ...){
	va_list list;
	char _s;
	int num = 0;
	va_start(list, format);
	while(*format){
		if(*format == '%'){
			format++;
			switch(*format){
				case 's':
					while(isdigit(_s=getc(fp))){
						num = num * 10 + _s - '0';
						_s = getc(fp);
					}
					ungetc(_s, fp);
				case 'd':
					_s = getc(fp);
					break;		
			}
		}
	}
	va_end(list);
}

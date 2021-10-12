#ifndef GO_DEFINITIONS_H
#define GO_DEFINITIONS_H
/*
DATA TYPE					SIZE(IN BYTES)						RANGE
*********					**************						*****

SHORT INT					2									- 32, 768 TO 32, 767
UNSIGNED SHORT INT			2									0 TO 65, 535
UNSIGNED INT				4									0 TO 4, 294, 967, 295
INT							4									- 2, 147, 483, 648 TO 2, 147, 483, 647
LONG INT					8									- 2, 147, 483, 648 TO 2, 147, 483, 647
UNSIGNED LONG INT			8									0 TO 4, 294, 967, 295
LONG LONG INT				8									- (2 ^ 63) TO(2 ^ 63) - 1
UNSIGNED LONG LONG INT		8									0 TO 18, 446, 744, 073, 709, 551, 615
SIGNED CHAR					1									- 128 TO 127
UNSIGNED CHAR				1									0 TO 255
FLOAT						4
DOUBLE						8
LONG DOUBLE					12
WCHAR_T						2 OR 4								1 WIDE CHARACTER
*/

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#endif



typedef		short int					GOsint;			//2
typedef		unsigned short int			GOusint;		//2
typedef		unsigned int				GOuint;			//4
typedef		int							GOint;			//4
typedef		long int					GOlint;			//8
typedef		unsigned long int			GOulint;		//8
typedef		long long int				GOllint;		//8
typedef		unsigned long long int		GOullint;		//8
typedef		signed char					GOchar;			//1
typedef		unsigned char				GOuchar;		//1
typedef		float						GOfloat;		//4
typedef		double						GOdouble;		//8
typedef		long double					GOldouble;		//12
typedef		wchar_t						GOwchar;		//2 OR 4

typedef		bool						GObool;
typedef		const char					GOcchar;

#endif //GO_DEFINITIONS_H

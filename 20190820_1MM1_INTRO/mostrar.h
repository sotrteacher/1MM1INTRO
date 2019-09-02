#define cadena(x)	#x
#define mostrar1(x,y)	\
printf("%10s",cadena(x));printf(" = %10.4f  ",x);\
printf("%10s",cadena(y));printf(" = %10.4f  ",y);

static void show_int(int);
static void show_float(float);
#define formar(tipo)	show##_##tipo
#define mostrar2(tipo,x,y)	\
printf("%10s",cadena(x));show##_##tipo(x);\
printf("%10s",cadena(y));show##_##tipo(y);

static void mostrar_int(int);
static void mostrar_float(float);
#define mostrar3(tipo,z)	\
mostrar##_##tipo(z);

static void show_float(float f){printf(" = %10.4f  ",f);}
static void show_int(int f){printf(" = %10d  ",f);}
static void mostrar_int(int d){printf("%d",d);}
static void mostrar_float(float f){printf("%10.4f",f);}

/**Recibe tres cadenas para formar un n\'umero de version.
 * Generalmente utilizo la fecha, por ejemplo:
 * static char X[]="2019";
 * static char Y[]="09";
 * static char Z[]="02";
 */ 
#define VERSION(x,y,z)	\
printf("%s.%s.%s",x,y,z)


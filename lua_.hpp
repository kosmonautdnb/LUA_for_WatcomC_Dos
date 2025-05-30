#pragma read_only_file;

#pragma read_only_file;

typedef char *__va_list[1];

typedef __va_list va_list;

#pragma read_only_file;

typedef unsigned size_t;

typedef unsigned short wchar_t;

typedef int ptrdiff_t;

extern int *__threadid(void);  
 
#pragma read_only_file;

typedef struct lua_State lua_State;

typedef  double  lua_Number;

typedef  long  lua_Integer;

typedef  unsigned long  lua_Unsigned;

typedef  ptrdiff_t  lua_KContext;

typedef int (*lua_CFunction) (lua_State *L);

typedef int (*lua_KFunction) (lua_State *L, int status, lua_KContext ctx);

typedef const char * (*lua_Reader) (lua_State *L, void *ud, size_t *sz);

typedef int (*lua_Writer) (lua_State *L, const void *p, size_t sz, void *ud);

typedef void * (*lua_Alloc) (void *ud, void *ptr, size_t osize, size_t nsize);

typedef void (*lua_WarnFunction) (void *ud, const char *msg, int tocont);

typedef struct lua_Debug lua_Debug;

typedef void (*lua_Hook) (lua_State *L, lua_Debug *ar);

extern const char lua_ident[];

extern  lua_State *(lua_newstate) (lua_Alloc f, void *ud);
 extern  void       (lua_close) (lua_State *L);
 extern  lua_State *(lua_newthread) (lua_State *L);
 extern  int        (lua_closethread) (lua_State *L, lua_State *from);
 extern  int        (lua_resetthread) (lua_State *L);   

extern  lua_CFunction (lua_atpanic) (lua_State *L, lua_CFunction panicf);

extern  lua_Number (lua_version) (lua_State *L);

extern  int   (lua_absindex) (lua_State *L, int idx);
 extern  int   (lua_gettop) (lua_State *L);
 extern  void  (lua_settop) (lua_State *L, int idx);
 extern  void  (lua_pushvalue) (lua_State *L, int idx);
 extern  void  (lua_rotate) (lua_State *L, int idx, int n);
 extern  void  (lua_copy) (lua_State *L, int fromidx, int toidx);
 extern  int   (lua_checkstack) (lua_State *L, int n);

extern  void  (lua_xmove) (lua_State *from, lua_State *to, int n);

extern  int             (lua_isnumber) (lua_State *L, int idx);
 extern  int             (lua_isstring) (lua_State *L, int idx);
 extern  int             (lua_iscfunction) (lua_State *L, int idx);
 extern  int             (lua_isinteger) (lua_State *L, int idx);
 extern  int             (lua_isuserdata) (lua_State *L, int idx);
 extern  int             (lua_type) (lua_State *L, int idx);
 extern  const char     *(lua_typename) (lua_State *L, int tp);

extern  lua_Number      (lua_tonumberx) (lua_State *L, int idx, int *isnum);
 extern  lua_Integer     (lua_tointegerx) (lua_State *L, int idx, int *isnum);
 extern  int             (lua_toboolean) (lua_State *L, int idx);
 extern  const char     *(lua_tolstring) (lua_State *L, int idx, size_t *len);
 extern  lua_Unsigned    (lua_rawlen) (lua_State *L, int idx);
 extern  lua_CFunction   (lua_tocfunction) (lua_State *L, int idx);
 extern  void	       *(lua_touserdata) (lua_State *L, int idx);
 extern  lua_State      *(lua_tothread) (lua_State *L, int idx);
 extern  const void     *(lua_topointer) (lua_State *L, int idx);

extern  void  (lua_arith) (lua_State *L, int op);

extern  int   (lua_rawequal) (lua_State *L, int idx1, int idx2);
 extern  int   (lua_compare) (lua_State *L, int idx1, int idx2, int op);

extern  void        (lua_pushnil) (lua_State *L);
 extern  void        (lua_pushnumber) (lua_State *L, lua_Number n);
 extern  void        (lua_pushinteger) (lua_State *L, lua_Integer n);
 extern  const char *(lua_pushlstring) (lua_State *L, const char *s, size_t len);
 extern  const char *(lua_pushstring) (lua_State *L, const char *s);
 extern  const char *(lua_pushvfstring) (lua_State *L, const char *fmt,
                                                      va_list argp);
 extern  const char *(lua_pushfstring) (lua_State *L, const char *fmt, ...);
 extern  void  (lua_pushcclosure) (lua_State *L, lua_CFunction fn, int n);
 extern  void  (lua_pushboolean) (lua_State *L, int b);
 extern  void  (lua_pushlightuserdata) (lua_State *L, void *p);
 extern  int   (lua_pushthread) (lua_State *L);

extern  int (lua_getglobal) (lua_State *L, const char *name);
 extern  int (lua_gettable) (lua_State *L, int idx);
 extern  int (lua_getfield) (lua_State *L, int idx, const char *k);
 extern  int (lua_geti) (lua_State *L, int idx, lua_Integer n);
 extern  int (lua_rawget) (lua_State *L, int idx);
 extern  int (lua_rawgeti) (lua_State *L, int idx, lua_Integer n);
 extern  int (lua_rawgetp) (lua_State *L, int idx, const void *p);

extern  void  (lua_createtable) (lua_State *L, int narr, int nrec);
 extern  void *(lua_newuserdatauv) (lua_State *L, size_t sz, int nuvalue);
 extern  int   (lua_getmetatable) (lua_State *L, int objindex);
 extern  int  (lua_getiuservalue) (lua_State *L, int idx, int n);

extern  void  (lua_setglobal) (lua_State *L, const char *name);
 extern  void  (lua_settable) (lua_State *L, int idx);
 extern  void  (lua_setfield) (lua_State *L, int idx, const char *k);
 extern  void  (lua_seti) (lua_State *L, int idx, lua_Integer n);
 extern  void  (lua_rawset) (lua_State *L, int idx);
 extern  void  (lua_rawseti) (lua_State *L, int idx, lua_Integer n);
 extern  void  (lua_rawsetp) (lua_State *L, int idx, const void *p);
 extern  int   (lua_setmetatable) (lua_State *L, int objindex);
 extern  int   (lua_setiuservalue) (lua_State *L, int idx, int n);

extern  void  (lua_callk) (lua_State *L, int nargs, int nresults,
                           lua_KContext ctx, lua_KFunction k);

extern  int   (lua_pcallk) (lua_State *L, int nargs, int nresults, int errfunc,
                            lua_KContext ctx, lua_KFunction k);

extern  int   (lua_load) (lua_State *L, lua_Reader reader, void *dt,
                          const char *chunkname, const char *mode);

extern  int (lua_dump) (lua_State *L, lua_Writer writer, void *data, int strip);

extern  int  (lua_yieldk)     (lua_State *L, int nresults, lua_KContext ctx,
                               lua_KFunction k);
 extern  int  (lua_resume)     (lua_State *L, lua_State *from, int narg,
                               int *nres);
 extern  int  (lua_status)     (lua_State *L);
 extern  int (lua_isyieldable) (lua_State *L);

extern  void (lua_setwarnf) (lua_State *L, lua_WarnFunction f, void *ud);
 extern  void (lua_warning)  (lua_State *L, const char *msg, int tocont);

extern  int (lua_gc) (lua_State *L, int what, ...);

extern  int   (lua_error) (lua_State *L);

extern  int   (lua_next) (lua_State *L, int idx);

extern  void  (lua_concat) (lua_State *L, int n);
 extern  void  (lua_len)    (lua_State *L, int idx);

extern  size_t   (lua_stringtonumber) (lua_State *L, const char *s);

extern  lua_Alloc (lua_getallocf) (lua_State *L, void **ud);
 extern  void      (lua_setallocf) (lua_State *L, lua_Alloc f, void *ud);

extern  void (lua_toclose) (lua_State *L, int idx);
 extern  void (lua_closeslot) (lua_State *L, int idx);

extern  int (lua_getstack) (lua_State *L, int level, lua_Debug *ar);
 extern  int (lua_getinfo) (lua_State *L, const char *what, lua_Debug *ar);
 extern  const char *(lua_getlocal) (lua_State *L, const lua_Debug *ar, int n);
 extern  const char *(lua_setlocal) (lua_State *L, const lua_Debug *ar, int n);
 extern  const char *(lua_getupvalue) (lua_State *L, int funcindex, int n);
 extern  const char *(lua_setupvalue) (lua_State *L, int funcindex, int n);

extern  void *(lua_upvalueid) (lua_State *L, int fidx, int n);
 extern  void  (lua_upvaluejoin) (lua_State *L, int fidx1, int n1,
                                               int fidx2, int n2);

extern  void (lua_sethook) (lua_State *L, lua_Hook func, int mask, int count);
 extern  lua_Hook (lua_gethook) (lua_State *L);
 extern  int (lua_gethookmask) (lua_State *L);
 extern  int (lua_gethookcount) (lua_State *L);

extern  int (lua_setcstacklimit) (lua_State *L, unsigned int limit);

struct lua_Debug {
  int event;
  const char *name;	 
  const char *namewhat;	 
  const char *what;	 
  const char *source;	 
  size_t srclen;	 
  int currentline;	 
  int linedefined;	 
  int lastlinedefined;	 
  unsigned char nups;	 
  unsigned char nparams; 
  char isvararg;         
  char istailcall;	 
  unsigned short ftransfer;    
  unsigned short ntransfer;    
  char short_src[ 60 ];  
  
struct CallInfo *i_ci;   
};

extern  int (luaopen_base) (lua_State *L);

extern  int (luaopen_coroutine) (lua_State *L);

extern  int (luaopen_table) (lua_State *L);

extern  int (luaopen_io) (lua_State *L);

extern  int (luaopen_os) (lua_State *L);

extern  int (luaopen_string) (lua_State *L);

extern  int (luaopen_utf8) (lua_State *L);

extern  int (luaopen_math) (lua_State *L);

extern  int (luaopen_debug) (lua_State *L);

extern  int (luaopen_package) (lua_State *L);

extern  void (luaL_openlibs) (lua_State *L);

#pragma read_only_file;

#pragma pack(__push,1);

typedef wchar_t wint_t;
typedef wchar_t wctype_t;

struct __stream_link;
typedef struct	__iobuf {
    unsigned char	 *_ptr;		 
    int			  _cnt;		 
    struct __stream_link *_link; 	 
    unsigned		  _flag;	 
    int			  _handle;	 
    unsigned		  _bufsize;	 
    unsigned short	  _ungotten;	 
} FILE;

typedef long	fpos_t;

extern FILE  __near  __iob[];

extern void	clearerr( FILE *__fp );
   extern int	fclose( FILE *__fp );
   extern int	feof( FILE *__fp );
   extern int	ferror( FILE *__fp );
   extern int	fflush( FILE *__fp );
   extern int	fgetc( FILE *__fp );
   extern int	fgetpos( FILE *__fp, fpos_t *__pos );
   extern char	*fgets( char *__s, int __n, FILE *__fp );
   extern FILE	*fopen( const char *__filename, const char *__mode );
   extern int	fprintf( FILE *__fp, const char *__format, ... );
   extern int	fputc( int __c, FILE *__fp );
   extern int	fputs( const char *__s, FILE *__fp );
   extern size_t	fread( void *__ptr, size_t __size, size_t __n, 
			       FILE *__fp );
   extern FILE	*freopen( const char *__filename, const char *__mode, 
				  FILE *__fp );
   extern int	fscanf( FILE*__fp, const char *__format, ... );
   extern int	fseek( FILE *__fp, long int __offset, int __whence );
   extern int	fsetpos( FILE *__fp, const fpos_t *__pos );
   extern long int ftell( FILE *__fp );
   extern size_t	fwrite( const void *__ptr, size_t __size, size_t __n, 
			        FILE *__fp );
   extern int	getc( FILE *__fp );
   extern int	getchar( void );
   extern int	_getw( FILE *__fp );
   extern char	*gets( char *__s );
   extern void	perror( const char *__s );
   extern FILE *	_popen( const char *__command, const char *__mode );
   extern int	_pclose( FILE *__fp );
   extern int	printf( const char *__format, ... );
   extern int	putc( int __c, FILE *__fp );
   extern int	putchar( int __c );
   extern int	_putw( int __binint, FILE *__fp );
   extern int	puts( const char *__s );
   extern int	remove( const char *__filename );
   extern int	rename( const char *__old, const char *__new );
   extern void	rewind( FILE *__fp );
   extern int	scanf( const char *__format, ... );
   extern void	setbuf( FILE *__fp, char *__buf );
   extern int	setvbuf( FILE *__fp, char *__buf, int __mode, 
				 size_t __size );
   extern int	sprintf( char *__s, const char *__format, ... );
   extern int	sscanf( const char *__s, const char *__format, ... );
   extern char *	_tempnam( char *__dir, char *__prefix );
   extern FILE	*tmpfile( void );
   extern char	*tmpnam( char *__s );
   extern int	ungetc( int __c, FILE *__fp );
   extern int	vfprintf( FILE *__fp, const char *__format, 
				  __va_list __arg );
   extern int	vprintf( const char *__format, __va_list __arg );
   extern int	vsprintf( char *__s, const char *__format, 
				  __va_list __arg );

extern int	fcloseall( void );
   extern FILE	*fdopen( int __handle, const char *__mode );
   extern FILE	*_fdopen( int __handle, const char *__mode );
   extern int	_grow_handles( int __new_count );
   extern int	_fgetchar( void );
   extern int	fgetchar( void );
   extern int	_fputchar( int __c );
   extern int	fputchar( int __c );
   extern FILE	*_fsopen( const char *__filename, const char *__mode, 
				  int __shflag );
   extern int	flushall( void );
   extern int	vfscanf( FILE *__fp, const char *__format, 
				 __va_list __arg );
   extern int	vscanf( const char *__format, __va_list __arg );
   extern int	vsscanf( const char *__s, const char *__format, 
				 __va_list __arg );
   extern int	_bprintf( char *__buf, size_t __bufsize, 
				  const char *__fmt, ... );
   extern int	_snprintf( char *__buf, size_t __bufsize, 
				   const char *__fmt, ... );
   extern int	_vbprintf( char *__s, size_t __bufsize, 
				   const char *__format, __va_list __arg );
   extern int	_vsnprintf( char *__s, size_t __bufsize, 
				    const char *__format, __va_list __arg );

extern FILE	*_wfopen( const wchar_t *, const wchar_t * );
   extern int	fwprintf( FILE *, const wchar_t *, ... );
   extern int	fputws( const wchar_t *, FILE * );
   extern FILE	*_wfsopen( const wchar_t *__filename,
				   const wchar_t *__mode,  int __shflag );
   extern FILE	*_wfdopen( int, const wchar_t * );
   extern FILE	*_wfreopen( const wchar_t *, const wchar_t *, FILE * );
   extern wint_t	putwc( wint_t, FILE * );
   extern wint_t	fputwc( wint_t, FILE * );
   extern wint_t	getwc( FILE * );
   extern wint_t	fgetwc( FILE * );
   extern wint_t	ungetwc( wint_t, FILE * );
   extern int	fwscanf( FILE *, const wchar_t *, ... );
   extern wchar_t *fgetws( wchar_t *, int, FILE * );
   extern int	vfwprintf( FILE *, const wchar_t *, __va_list );
   extern int	vfwscanf( FILE *, const wchar_t *, __va_list );
   extern int	vwscanf( const wchar_t *, __va_list );
   extern int	vswscanf( const wchar_t *, const wchar_t *, __va_list );
   extern int	vswprintf( wchar_t *, size_t, const wchar_t *, 
				   __va_list );
   extern wint_t	getwchar( void );
   extern wint_t	_fgetwchar( void );
   extern wint_t	fgetwchar( void );
   extern wchar_t *_getws( wchar_t * );
   extern wchar_t *getws( wchar_t * );
   extern wint_t	putwchar( wint_t );
   extern int	_putws( const wchar_t * );
   extern int	putws( const wchar_t * );
   extern int	_wremove( const wchar_t * );
   extern wchar_t *_wtempnam( wchar_t *__dir, wchar_t *__prefix );
   extern wchar_t *_wtmpnam( wchar_t * );
   extern int	wprintf( const wchar_t *, ... );
   extern int	wscanf( const wchar_t *, ... );

extern int	swprintf( wchar_t *, size_t, const wchar_t *, ... );

extern int	swscanf( const wchar_t *, const wchar_t *, ... );
   extern wint_t	_fputwchar( wint_t );
   extern wint_t	fputwchar( wint_t );
   extern void	_wperror( const wchar_t * );
   extern int	vwprintf( const wchar_t *, __va_list );
   extern int	_bwprintf( wchar_t *, size_t, const wchar_t *, ... );
   extern int	_snwprintf( wchar_t *, size_t, const wchar_t *, ... );
   extern int	_vbwprintf( wchar_t *, size_t, const wchar_t *, __va_list );
   extern int	_vsnwprintf( wchar_t *, size_t, const wchar_t *, 
				    __va_list );
   extern int	_wrename( const wchar_t *, const wchar_t * );
   extern FILE *	_wpopen( const wchar_t *__command, const wchar_t *__mode );

extern int	_usprintf( wchar_t *, const wchar_t *, ... );
   extern int	_uvsprintf( wchar_t *, const wchar_t *, __va_list );

#pragma pack(__pop);

typedef struct luaL_Buffer luaL_Buffer;

typedef struct luaL_Reg {
  const char *name;
  lua_CFunction func;
} luaL_Reg;

extern  void (luaL_checkversion_) (lua_State *L, lua_Number ver, size_t sz);

extern  int (luaL_getmetafield) (lua_State *L, int obj, const char *e);
 extern  int (luaL_callmeta) (lua_State *L, int obj, const char *e);
 extern  const char *(luaL_tolstring) (lua_State *L, int idx, size_t *len);
 extern  int (luaL_argerror) (lua_State *L, int arg, const char *extramsg);
 extern  int (luaL_typeerror) (lua_State *L, int arg, const char *tname);
 extern  const char *(luaL_checklstring) (lua_State *L, int arg,
                                                          size_t *l);
 extern  const char *(luaL_optlstring) (lua_State *L, int arg,
                                          const char *def, size_t *l);
 extern  lua_Number (luaL_checknumber) (lua_State *L, int arg);
 extern  lua_Number (luaL_optnumber) (lua_State *L, int arg, lua_Number def);

extern  lua_Integer (luaL_checkinteger) (lua_State *L, int arg);
 extern  lua_Integer (luaL_optinteger) (lua_State *L, int arg,
                                          lua_Integer def);

extern  void (luaL_checkstack) (lua_State *L, int sz, const char *msg);
 extern  void (luaL_checktype) (lua_State *L, int arg, int t);
 extern  void (luaL_checkany) (lua_State *L, int arg);

extern  int   (luaL_newmetatable) (lua_State *L, const char *tname);
 extern  void  (luaL_setmetatable) (lua_State *L, const char *tname);
 extern  void *(luaL_testudata) (lua_State *L, int ud, const char *tname);
 extern  void *(luaL_checkudata) (lua_State *L, int ud, const char *tname);

extern  void (luaL_where) (lua_State *L, int lvl);
 extern  int (luaL_error) (lua_State *L, const char *fmt, ...);

extern  int (luaL_checkoption) (lua_State *L, int arg, const char *def,
                                   const char *const lst[]);

extern  int (luaL_fileresult) (lua_State *L, int stat, const char *fname);
 extern  int (luaL_execresult) (lua_State *L, int stat);

extern  int (luaL_ref) (lua_State *L, int t);
 extern  void (luaL_unref) (lua_State *L, int t, int ref);

extern  int (luaL_loadfilex) (lua_State *L, const char *filename,
                                               const char *mode);

extern  int (luaL_loadbufferx) (lua_State *L, const char *buff, size_t sz,
                                   const char *name, const char *mode);
 extern  int (luaL_loadstring) (lua_State *L, const char *s);

extern  lua_State *(luaL_newstate) (void);

extern  lua_Integer (luaL_len) (lua_State *L, int idx);

extern  void (luaL_addgsub) (luaL_Buffer *b, const char *s,
                                     const char *p, const char *r);
 extern  const char *(luaL_gsub) (lua_State *L, const char *s,
                                    const char *p, const char *r);

extern  void (luaL_setfuncs) (lua_State *L, const luaL_Reg *l, int nup);

extern  int (luaL_getsubtable) (lua_State *L, int idx, const char *fname);

extern  void (luaL_traceback) (lua_State *L, lua_State *L1,
                                  const char *msg, int level);

extern  void (luaL_requiref) (lua_State *L, const char *modname,
                                 lua_CFunction openf, int glb);

struct luaL_Buffer {
  char *b;   
  size_t size;   
  size_t n;   
  lua_State *L;
  union {
     lua_Number n; double u; void *s; lua_Integer i; long l ;   
    char b[ ((int)(16 * sizeof(void*) * sizeof(lua_Number))) ];   
  } init;
};

extern  void (luaL_buffinit) (lua_State *L, luaL_Buffer *B);
 extern  char *(luaL_prepbuffsize) (luaL_Buffer *B, size_t sz);
 extern  void (luaL_addlstring) (luaL_Buffer *B, const char *s, size_t l);
 extern  void (luaL_addstring) (luaL_Buffer *B, const char *s);
 extern  void (luaL_addvalue) (luaL_Buffer *B);
 extern  void (luaL_pushresult) (luaL_Buffer *B);
 extern  void (luaL_pushresultsize) (luaL_Buffer *B, size_t sz);
 extern  char *(luaL_buffinitsize) (lua_State *L, luaL_Buffer *B, size_t sz);

typedef struct luaL_Stream {
  FILE *f;   
  lua_CFunction closef;   
} luaL_Stream;


#include "lua.hpp"
#include <stdlib.h>
#include <string.h>

int voila3(lua_State *L) {
  lua_pushstring(L,"!!voila3!!");
  return 1;
}

const char *LUAPROGRAM = 
  "function print2(a)\n"
  "  print(a..\" !!voila2!!\")"
  "end\n"
  "-- lala\n"
  "io.write(\"In Lua\\n\");\n"
  "x=x or 0\n"
  "for i=1,#values do\n"
  "  print(i,values[i],\" =\",x+values[i])\n"
  "  x=x+values[i]\n"
  "end\n"
  "print(voila3());\n"
  "io.write(\"Returning to C with:\"..x..\"\\n\");\n"
  "return x\n";

int main (int argc, char **argv) {
  printf("%s\n",LUA_COPYRIGHT);

  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
  luaL_loadstring(L, LUAPROGRAM);
  lua_setglobal(L,"main");

  lua_newtable(L);
  for (int i = 1; i <= 5; i++) {
    lua_pushnumber(L,i);
    lua_pushnumber(L,i*2);
    lua_rawset(L,-3);
  }
  lua_setglobal(L,"values");

  lua_pushcfunction(L,voila3);
  lua_setglobal(L, "voila3");

  lua_getglobal(L,"main");
  lua_call(L,0,1);

  double sum = lua_tonumber(L,-1);
  lua_pop(L,1);
  printf("result:%f\n",sum);

  lua_getglobal(L,"print");
  lua_pushstring(L,"voila!");
  lua_call(L,1,0);

  lua_getglobal(L,"print2");
  lua_pushstring(L,"!!and again!!");
  lua_call(L,1,0);

  lua_getglobal(L,"main");
  lua_call(L,0,1);
  sum = lua_tonumber(L,-1);
  lua_pop(L,1);
  printf("result:%f\n",sum);

  lua_close(L);

  return 1;
}


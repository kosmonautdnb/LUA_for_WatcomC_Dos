del lua_.cpp
del lua_.hpp
wcl386.exe /p !cpp.in >> lua_.cpp
wcl386.exe /p !hpp.in >> lua_.hpp
_build\clearone.exe lua_.cpp
_build\clearone.exe lua_.hpp

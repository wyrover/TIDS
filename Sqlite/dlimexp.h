#pragma once

#ifdef SQLITE_EXPORTS
#define SQLITE_EXPORT_API _declspec(dllexport)
#else
#define SQLITE_EXPORT_API _declspec(dllimport)
#endif
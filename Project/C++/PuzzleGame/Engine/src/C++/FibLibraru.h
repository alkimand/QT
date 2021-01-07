#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define FIBLIBRARY_API __declspec(dllexport)
#else
#define FIBLIBRARY_API __declspec(dllimport)
#endif

//extern "C" {
	 extern "C" FIBLIBRARY_API void fibonacci_init(const unsigned long long a, const unsigned long long b);
	 extern "C" FIBLIBRARY_API bool fibonacci_next();
	 extern "C" FIBLIBRARY_API unsigned long long fibonacci_current();
	 extern "C" FIBLIBRARY_API unsigned fibonacci_index();




//}
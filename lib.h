//
// Created by olokreZ on 22.11.2023.
//

#ifndef VOENMEH_LIB_H
#define VOENMEH_LIB_H
#ifdef APP_LIB
	#define LIB_API __declspec(dllexport)
#else
	#define LIB_API __declspec(dllimport)
#endif



#endif

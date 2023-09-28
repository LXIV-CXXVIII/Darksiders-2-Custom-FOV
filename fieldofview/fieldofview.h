#pragma once
#include "MinHook/include/MinHook.h"
#include "inih-master/cpp/INIReader.h"

namespace fieldofview {

	class init {

	public:
		init();
		~init();

		static init* getsingleton() {
			static init singleton;
			return &singleton;
		};
		virtual void read_setting();

		float setting;
	
	};

	extern "C" VOID xFOV1();
	extern "C" VOID xFOV2();
	extern "C" DWORD64 rFOV1;
	extern "C" DWORD64 rFOV2;
	extern "C" float fov_setting;

	BOOL write_branch(DWORD64, LPVOID);
	VOID init_hooks();

};
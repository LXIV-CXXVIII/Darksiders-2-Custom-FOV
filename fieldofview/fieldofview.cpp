#include "fieldofview.h"

namespace fieldofview {

	init::init() {
	
		this->read_setting();
	
	}
	init::~init() {};

	void init::read_setting() {

		INIReader reader("plugins/fieldofview.ini");
		if (reader.ParseError() < 0) { printf("parse error"); };
	
		this->setting = (float)reader.GetReal("SETTING", "fieldofview", 45.00f);

	};

	BOOL write_branch(DWORD64 addr, LPVOID code) {

		if ((MH_CreateHook((LPVOID)addr, (LPVOID)code, NULL) != MH_OK) || (MH_EnableHook((LPVOID)addr) != MH_OK)) {
			return false;
		} else {
			return true;
		}

	};

	DWORD64 rFOV1 = NULL;
	DWORD64 rFOV2 = NULL;
	float fov_setting = 0.00f;

	VOID init_hooks() {

		auto ptr = init::getsingleton();
		fov_setting = ptr->setting;
		printf("%f\n", fov_setting);

		auto addr = (0x1401C527A);
		rFOV1 = (0x1401C5281);
		if (!write_branch(addr, xFOV1)) {
			return;
		}

		addr = (0x14014D665);
		rFOV2 = (0x14014D66A);
		if (!write_branch(addr, xFOV2)) {
			return;
		}
	
	};

};
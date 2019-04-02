#include "fb3dscfg.h"
#include "ff.h"

#define FB3DSCFG_TEXT \
	"BOOT_MODE = Quiet" "\n" \
	"BOOT_OPTION1 = sdmc:/boot.firm" "\n" \
	"BOOT_OPTION2 = sdmc:/gm9/payloads/GodMode9.firm" "\n" \
	"BOOT_OPTION2_BUTTONS = START" "\n" 

#define FB3DSCFG_NAME "fastbootcfg.txt"
#define HOMEBREW_PATH "0:/3ds"


u32 PresetFastBoot3dsConfig(void) {
	const char* txt = FB3DSCFG_TEXT;
	u32 len = strlen(txt);

	FIL fp;
	UINT bw;

    // make sure the homebrew path exists
	f_mkdir(HOMEBREW_PATH);

	// open the config file for writing
	if (f_open(&fp, HOMEBREW_PATH "/" FB3DSCFG_NAME, FA_WRITE|FA_CREATE_ALWAYS) != FR_OK)
        return 1;

    // write the config data
    if ((f_write(&fp, txt, len, &bw) != FR_OK) || (len != bw)) {
    	f_close(&fp);
    	return 1;
    }

    // close config file
    f_close(&fp);

    return 0;
}
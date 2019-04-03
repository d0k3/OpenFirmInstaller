# OpenFirmInstaller
Safe, simple, user-friendly installer for sighax bootloaders

OpenFirmInstaller is based on [SafeB9SInstaller](https://github.com/d0k3/SafeB9SInstaller) and works the same way as that. All input files go into `sdmc:/ofi`. At the present time, only [boot9strap](https://github.com/SciresM/boot9strap) and [fastboot3DS](https://github.com/derrekr/fastboot3DS) are supported as input files.

Note to developers: Building this requires [firmtool](https://github.com/TuxSH/firmtool), [Python 3.5+](https://www.python.org/downloads/) and [devkitARM](https://sourceforge.net/projects/devkitpro/). To compile the CakesROP entrypoint you also need `xxd` from the `vim` package installed (install it via `pacman -S vim`).

## Quick Start Guide
For this, we are assuming you already have boot9strap and CFW installed, your 3DS is in working order and you want to switch to fastboot3DS.
1. Create a folder called `ofi` on your 3DS SD card. 
2. Download [fastboot3DS](https://github.com/derrekr/fastboot3DS/releases) and copy `fastboot3ds.firm` from the ZIP file to `ofi/fastboot3ds.firm` on your SD card.
3. [optional] Get [GodMode9](https://github.com/d0k3/GodMode9/releases) and copy `GodMode9.firm` to `gm9/payloads/GodMode9.firm` on your SD card. If you are a [Luma 3DS](https://github.com/AuroraWright/Luma3DS) user, move `GodMode9.firm` from `luma/payloads/GodMode9.firm` to `gm9/payloads/GodMode9.firm`.
4. Copy `OpenFirmInstaller.firm` from the [release ZIP](https://github.com/d0k3/OpenFirmInstaller/releases) to your SD card. If you are a Luma 3DS user, the file goes to `luma/payloads/OpenFirmInstaller.firm`.
5. Run `OpenFirmInstaller.firm` from your SD card. For a Luma 3DS user, thats as simple as holding `START` when booting the console and selecting `OpenFirmInstaller.firm`  when (if) prompted. You may also run `OpenFirmInstaller.firm` from GodMode9 (via [A] -> `FIRM options...` -> `Boot FIRM`).
6. Follow the on screen instructions. When you're asked to input a key sequence to confirm, input the key sequence.
7. Done, now fastboot3DS is your bootloader. Further configuration is not required. Your CFW is autobooted as you are used to, and if - you installed it - GodMode9 is booted when you hold START after turning on your console.

OpenFirmInstaller can also work from A9LH systems (you also need to provide `secret_sector.bin` then), from unhacked systems on earlier OS versions and via ntrboot cards. Refer to the usual instructions for these special cases. fastboot3DS is highly customizable, you can set boot from CTRNAND, add more payloads via key combos, change splashes (but you absolutely don't have to!). You may enter the fastboot3DS menu by holding HOME when booting.

## Credits
* **Normmatt**, for sdmmc.c / sdmmc.h
* **Cha(N)**, **Kane49**, and all other FatFS contributors for FatFS
* **Myria** for the sighax bruteforcer and for finding the sighax (retail&dev) signature
* **SciresM** for dumping boot9, creating boot9strap.firm and for being the first fearless person to test this
* **hedgeberg** for her tireless efforts in dumping the bootrom
* **TuxSH** for FIRM research and useful hints
* **Plailect** for providing the guide and making SafeB9SInstaller accessible to the common user
* **stuckpixel** for his tireless behind-the-scenes work
* **Gelex** for being of great help on countless occasions
* **profi200** and **derrek** for enabling compatibility with fastboot3DS
* The fine folks on **freenode #Cakey**
* All **[3dbrew.org](https://www.3dbrew.org/wiki/Main_Page) editors**
* Everyone who helped test this, especially **Al3x_10m**, **Wolfvak**, **Shadowhand**, **Lilith Valentine** and **Crimson**
* Everyone I possibly forgot, if you think you deserve to be mentioned, just contact me!

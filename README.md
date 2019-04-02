# OpenFirmInstaller
Safe, simple, user-friendly installer for sighax bootloaders

OpenFirmInstaller is based on [SafeB9SInstaller](https://github.com/d0k3/SafeB9SInstaller) and works the same way as that. All input files go into `sdmc:/ofi`. At the present time, only [boot9strap](https://github.com/SciresM/boot9strap) and [fastboot3DS](https://github.com/derrekr/fastboot3DS) are supported as input files.

Note to developers: Building this requires [firmtool](https://github.com/TuxSH/firmtool), [Python 3.5+](https://www.python.org/downloads/) and [devkitARM](https://sourceforge.net/projects/devkitpro/). To compile the CakesROP entrypoint you also need `xxd` from the `vim` package installed (install it via `pacman -S vim`).

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

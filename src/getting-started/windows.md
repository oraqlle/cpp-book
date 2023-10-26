# Windows

Windows has many different compilers at its disposal. Some offer native support to building against the Windows runtime while others will emulate a UNIX (the predecessor to Linux and BSD) environment to aid in porting software built for UNIX-like systems. The installation of each of the toolchains are vastly different to each other so we will cover them separately.

## MSVC Installation

The Microsoft Visual C++ (MSVC) compiler is Microsoft's official toolchain for building software natively on Windows. It is installed with the Visual Studio Integrated Developer Environment (IDE). MSVC (and the whole Visual Studio suite) can be obtained from Microsoft's [official download page](https://visualstudio.microsoft.com/vs/). Make sure to select the correct edition (community being the free version) and click 'Download'. This will download the setup program `VisualStudioSetup.exe`, which is used to install and configure Visual Studio Installer (VSI). The VSI allows you to select which tools and technologies from the Visual Studio suite you want to install. Once you have installed the VSI, start the program and you should be presented with some default tool configurations (workflows). For developing with C++ you will need to select the 'Desktop development with C++' workflow. You will also want to tick a few optional features as well (found in the side bar).

![VSI Options Reference Image](imgs/vsi-cpp-workflow-install.png)

Finally, click the 'Install' button in the bottom right of the window to start the installation.

> [Microsoft's official installation instructions for C++](https://learn.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=msvc-170)

## Verifying MSVC Installation

To verify you installed Visual Studio correctly you can open the newly installed 'Developer Command Prompt for VS'. This prompt is needed in order to load the MSVC tooling into the prompt as it is not including by default in CMD or PowerShell. Simply run the following command to verify the install of the compiler.

```cmd
$ cl
Microsoft (R) C/C++ Optimizing Compiler Version 19.37.32822 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

usage: cl [ option... ] filename... [ /link linkoption... ]
```

> Notes:
>
> - Alternatively you can follow [Microsoft's tutorial](https://learn.microsoft.com/en-us/cpp/build/vscpp-step-1-create?view=msvc-170) for creating a new C++ VS Project. This will be more convenient than opening a 'Developer Command Prompt' every time you want to compile a program and having to run the `cl` command manually but it takes more work setting compiler flags etc. for simple projects.
> - Throughout this book, any commands will assume the GCC CLI flags and names. You will need to look up the equivalent flags for MSVC.

## MinGW Installation

~

## MinGW Verify

~

## Cygwin Installation

~

## Cygwin Verify

~

## MYSYS2 Installation

~

## MYSYS2 Verify

~

## WSL

~

<!-- Don't show install, just direct them to Microsoft's docs -->

## Other

Next we will need to install a C compiler toolchain. There a many different environments such as CygWin, MinGW but the most ideal environment is Microsoft's official development environment, MSVC. Download the Community Edition of Visual Studio and launch the installer. Under the 'Workloads' tab of the installer select the 'C++ Build Tools' bundle and click install. This may take a while. Once installed (may require restart) open the 'Start' menu and navigate to the 'Visual Studio' folder. There should a variety of different terminal environment applications. This is because Windows has slightly different toolchains and environments for x86 (32-bit) and x86_64 (64-bit). Select the 'Developer Command Prompt for VS 2022' app. In the terminal that spawns, run the command.

```cmd
cl
```

This will display the help options for `cl`, Window's C compiler.

[Download MSVC](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019)

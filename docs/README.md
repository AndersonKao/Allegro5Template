## Installation

> Images in this page are not updated, but most of them are just difference on version. 

- [Windows](#windows)
  - [Visual Studio](#visual-studio)
  - [Code::Blocks](#codeblocks)
  - [Dev-C++](#dev-c)
- [Mac OS](#mac-os)
  - [XCode](#xcode)
- [Others](#others)

### Note
If you links Allegro5 libraries by yourself, that is, using a pre-built Allegro5 binaries to setup your project **(For Code::Blocks, Dev-C++, XCode, we do in this way)**, please download the **matched (closest) version of Allegro5 binaries to your gcc(compiler) version**. (You can find them on [Allegro5 Github page](https://github.com/liballeg/allegro5/releases).

For example, if you're using Code::Blocks v20.03 shipped with minGW compiler, your gcc version would be 8.1.0. In this case, please download [pre-built Allegro5 for gcc 8.2.1](https://github.com/liballeg/allegro5/releases/download/5.2.5.0/allegro-x86_64-w64-mingw32-gcc-8.2.1-posix-seh-static-5.2.5.1.zip).

To check your gcc version, open command window, go to the folder where you installed minGW. (.../CodeBlocks/MinGW/bin for Code::Blocks) And type **"gcc --version"**.

![image](https://user-images.githubusercontent.com/56912772/207344304-bd9880f7-961a-4c3f-b0dc-e87f88c43c1d.png)

Then go the the Allegro5 github page to find the matched version of pre-built binaries.

![image](https://user-images.githubusercontent.com/56912772/207345642-8f772a58-c640-4a5a-b3ee-30d6808b9d9e.png)


### Windows

#### Visual Studio

**This year we highly recommend you use visual studio 2019**

If you use the release VS2019, open it with Visual Studio 2019 will be enough.

Step-by-step [tutorial(English)](https://gamefromscratch.com/allegro-tutorial-series-part-1-getting-started/)

Step-by-step tutorial on [YouTube](https://youtu.be/HPHd92nj0Io).

> Just watch the video will be enough.

#### Code::Blocks

Step-by-step tutorial on [YouTube](https://youtu.be/6qzWKRxw9eY).

- Download [allegro-x86_64-w64-mingw32-gcc-8.2.1-posix-seh-static-5.2.5.1.zip](https://github.com/liballeg/allegro5/releases/download/5.2.5.0/allegro-x86_64-w64-mingw32-gcc-8.2.1-posix-seh-static-5.2.5.1.zip)

  Un-zip the file and move it to your C drive. The full path should be like: `C:\allegro-x86_64-w64-mingw32-gcc-8.2.1-posix-seh-static-5.2.5.1.zip\allegro`

- Create a new project
  - Open Code::Blocks
  - `File > New > Project...`
  - Click `Console application` and `Go`.
  - Click `Next`, Select `C` and `Next`.
  - Enter title `allegro-test`, `Next`, `Finish`.

- Set up project
  - `Project > Build options...`
  - `[Optional]` In `Compiler settings > Compiler flags`, you can check the `-std=c99` flag if you want to use C99 features.
  - Set up include directories

    Make sure that the focus on the left side is the project name (`allegro-test`). Select `Search directories > Compiler` and click `Add`, paste the following path into the textbox and click `OK`.

    ```
    C:\allegro-x86_64-w64-mingw32-gcc-8.2.1-posix-seh-static-5.2.5.1.zip\allegro\include\
    ```

  - Set up library directories

    Make sure that the focus on the left side is the project name (`allegro-test`). Select `Search directories > Linker` and click `Add`, paste the following path into the textbox and click `OK`.

    ```
    C:\allegro-x86_64-w64-mingw32-gcc-8.2.1-posix-seh-static-5.2.5.1.zip\allegro\lib\
    ```

  - Select `Debug` at the left side. Select `Linker settings` and click `Add`, paste the following path into the textbox and click `OK`.

    ```
    C:\allegro-x86_64-w64-mingw32-gcc-8.2.1-posix-seh-static-5.2.5.1.zip\allegro\lib\liballegro_monolith-debug.dll.a
    ```

  - Select `Release` at the left side. Select `Linker settings` and click `Add`, paste the following path into the textbox and click `OK`.

    ```
    C:\allegro-x86_64-w64-mingw32-gcc-8.2.1-posix-seh-static-5.2.5.1.zip\allegro\lib\liballegro_monolith.dll.a
    ```

  - Click `OK`.

- Test the library

  - Copy the code below and paste to your `main.c` at the left side `Projects > Workspace > [ProjectName](allegro-test) > Sources > main.c`:

    ```c
    #include <allegro5/allegro.h>
    #include <allegro5/allegro_font.h>
    int main(int argc, char **argv) {
        al_init();
        al_init_font_addon();
        ALLEGRO_DISPLAY* display = al_create_display(800, 600);
        ALLEGRO_FONT* font = al_create_builtin_font();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "Welcome to Allegro!");
        al_flip_display();
        al_rest(5.0);
        al_destroy_font(font);
        al_destroy_display(display);
        return 0;
    }
    ```

  - Press `F9` to compile and run.

  - If it pops a `dll not found` error, copy the file below to `[Project Directory]\bin\Debug\`
    ```
    C:\allegro-mingw-gcc6.2.0-x86-static-5.2.2\allegro\bin\allegro_monolith-debug-5.2.dll
    ```

  - Press `F9` and the window will pop out saying "Welcome to Allegro!".

#### Dev-C++

Step-by-step tutorial on [YouTube](https://youtu.be/lwscVtIUy6k).

> Just watch the video will be enough.

### Mac OS

#### XCode

Step-by-step tutorial on [YouTube](https://youtu.be/QZdHjFQUQPo).
###### ~~Step-by-step tutorial on [YouTube](https://youtu.be/7nJNDRCq5o0).~~(Old macOS 10.X)

Open `Terminal` and type:

```shell
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

You might need to enter your password and press yes a several times.

After finish installing, type:

```shell
brew install allegro
```

Open `XCode`, Create a new `MacOS` project, choose `App`.

Product Name type `allegro-test`, and for Organization Identifier, you can type anything you want. For language, choose `Objective-C`, and uncheck all other checkboxes.

Delete `AppDelegate.h`, `AppDelegate.m`, `ViewController.h`, `ViewController.m`, `Main.m` and select `Move to Trash`.

![](imgs/mac-del-file.png)
![](imgs/mac-trash.png)

Click your project at the left side, go to `Building Settings > All` and search `Search Paths`.

Under `Search Paths`, set `Header Search Paths` to `/usr/local/include` and `/opt/homebrew/Cellar/allegro/5.2.7.0/include`(For new `homebrew` case) and set `Library Search Paths` to `/usr/local/lib` and `/opt/homebrew/Cellar/allegro/5.2.7.0/lib`. Both use `non-recursive`.

![](imgs/mac-search-paths.png)
**The image is not updated!!**

Open terminal and type:

```shell
cd /usr/local/Cellar
# or /opt/homebrew/Cellar/allegro
open .
```

Navigate to `allegro/5.2.7.0/lib/`

Sort by `Modified date` and select all files that is modified today. (don't need to select the `pkgconfig` folder)

![](imgs/mac-lib.png)

Go back to XCode and click `General`

Drag the selected files into the `Frameworks, Libraries, and Embedded Content`.

![](imgs/mac-link.png)

Create `main.c` (`File > New > File... > C file`), uncheck `Also create a header file`.

Paste the code below to the file.

```c
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
int main(int argc, char **argv) {
    al_init();
    al_init_font_addon();
    ALLEGRO_DISPLAY* display = al_create_display(800, 600);
    ALLEGRO_FONT* font = al_create_builtin_font();
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "Welcome to Allegro!");
    al_flip_display();
    al_rest(5.0);
    al_destroy_font(font);
    al_destroy_display(display);
    return 0;
}
```

![](imgs/mac-code.png)

Click the `Play` button.

![](imgs/mac-result.png)

### Others

Inspect your processor and download the corresponding library:

- [allegro-i686-w64-mingw32-gcc-7.2.0-posix-dwarf-static-5.2.4.1.zip](https://github.com/liballeg/allegro5/releases/download/5.2.4.0/allegro-i686-w64-mingw32-gcc-7.2.0-posix-dwarf-static-5.2.4.1.zip)
- [allegro-x86_64-w64-mingw32-gcc-7.2.0-posix-seh-static-5.2.4.1.zip](https://github.com/liballeg/allegro5/releases/download/5.2.4.0/allegro-x86_64-w64-mingw32-gcc-7.2.0-posix-seh-static-5.2.4.1.zip)
- [allegro-mingw-gcc6.2.0-x86-static-5.2.2.zip](https://github.com/liballeg/allegro5/releases/download/5.2.2.0/allegro-mingw-gcc6.2.0-x86-static-5.2.2.zip)
- [allegro-mingw-gcc6.2.0-x64-static-5.2.2.zip](https://github.com/liballeg/allegro5/releases/download/5.2.2.0/allegro-mingw-gcc6.2.0-x64-static-5.2.2.zip)

Unzip the file and put it under C drive.

Create `main.c` and paste the code below:

```c
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
int main(int argc, char **argv) {
    al_init();
    al_init_font_addon();
    ALLEGRO_DISPLAY* display = al_create_display(800, 600);
    ALLEGRO_FONT* font = al_create_builtin_font();
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_text(font, al_map_rgb(255, 255, 255), 400, 300, ALLEGRO_ALIGN_CENTER, "Welcome to Allegro!");
    al_flip_display();
    al_rest(5.0);
    al_destroy_font(font);
    al_destroy_display(display);
    return 0;
}
```

Type the command that matches your download.

```shell
gcc -Wall -g -IC:\allegro-i686-w64-mingw32-gcc-7.2.0-posix-dwarf-static-5.2.4.1\allegro\include main.c -LC:\allegro-i686-w64-mingw32-gcc-7.2.0-posix-dwarf-static-5.2.4.1\allegro\lib -lallegro_monolith.dll
```

```shell
gcc -Wall -g -IC:\allegro-x86_64-w64-mingw32-gcc-7.2.0-posix-seh-static-5.2.4.1\allegro\include main.c -LC:\allegro-x86_64-w64-mingw32-gcc-7.2.0-posix-seh-static-5.2.4.1\allegro\lib -lallegro_monolith.dll
```

```shell
gcc -Wall -g -IC:\allegro-mingw-gcc6.2.0-x86-static-5.2.2\allegro\include main.c -LC:\allegro-mingw-gcc6.2.0-x86-static-5.2.2\allegro\lib -lallegro_monolith.dll
```

```shell
gcc -Wall -g -IC:\allegro-mingw-gcc6.2.0-x64-static-5.2.2\allegro\include main.c -LC:\allegro-mingw-gcc6.2.0-x64-static-5.2.2\allegro\lib -lallegro_monolith.dll
```

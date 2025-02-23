#include <xtd/xtd>
#include <vector>

using namespace std;
using namespace xtd;

int main() {
  const vector logo = {
    u8"████████████████████████████████████████████████████████████",
    u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████",
    u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████",
    u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░██████████",
    u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████",
    u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████",
    u8"██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████",
    u8"███████████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░█████████████",
    u8"██████████████████████████████████████████████████████████████████████",
    u8"██████████████████████████████████████████████████████████████████████",
    u8"██████████████████████████▀▄▄▄▄▀███████▀▄▄▄▄▀█████████████████████████",
    u8"███████████████████████████▀▀▀▀███████▀▀▀▀▀███████████████████████████",
    u8"██████████████████████████      ▀████       ▀█████████████████████████",
    u8"███████████             ▐         ▀▀         ▐              ██████████",
    u8"█████████               ▐   ███   ▌▐   ███   ▐               █████████",
    u8"█████████               ▐   █▄▄▌  ▌▐  ▐▄▄█   ▐               █████████",
    u8"█████████                ▐▄  ▀▀ ▄▀  ▀▄ ▀▀  ▄▀                █████████",
    u8"█████████                  ▀▀▄▄▀      ▀▀▄▄▀                  █████████",
    u8"█████████                                                    █████████",
    u8"█████████                 █▄                ▌                █████████",
    u8"█████████                  ▌▀▀▄          ▄██                 █████████",
    u8"█████████                  ▐   ▀▀▄▄▄▄▄▄█▀ █▌                 █████████",
    u8"█████████                   ▐            ▄█                  █████████",
    u8"█████████                    █          ▄█                   █████████",
    u8"█████████                     ▀▄       █▀                    █████████",
    u8"█████████                       ▀▄▄▄▄██▀                     █████████",
    u8"█████████                                                    █████████",
    u8"█████████                                                    █████████",
    u8"█████████                                                    █████████",
    u8"█████████                                                    █████████",
    u8"█████████                                                    █████████",
    u8"██████████████████████████████████████████████████████████████████",
  };
  
  console::output_code_page(65001);
  
  for (size_t index = 0; index < logo.size(); ++index)
    console::out << (index == 0 || index == logo.size() - 1 ? "       " : "     ") << background_color(console_color::white) << foreground_color(console_color::dark_blue) << logo[index] << reset_color() << endl;
    
  console::out << foreground_color(console_color::dark_blue) << u8"                                    Gammasoft                                   " << endl;
  console::out << foreground_color(console_color::dark_gray) << u8" More than thirty years of passion for high technology especially in development" << endl;
  console::out << u8" (c++, c#, objective-c, ...)." << reset_color() << endl;
}

// This code produces the following output with colors:
//
//        ████████████████████████████████████████████████████████████
//      ██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████
//      ██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████
//      ██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░██████████
//      ██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████
//      ██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████
//      ██████████████████████████████░░░░░░░░░░░░░░░░░░░░░░████░░████████████
//      ███████████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░█████████████
//      ██████████████████████████████████████████████████████████████████████
//      ██████████████████████████████████████████████████████████████████████
//      ██████████████████████████▀▄▄▄▄▀███████▀▄▄▄▄▀█████████████████████████
//      ███████████████████████████▀▀▀▀███████▀▀▀▀▀███████████████████████████
//      ██████████████████████████      ▀████       ▀█████████████████████████
//      ███████████             ▐         ▀▀         ▐              ██████████
//      █████████               ▐   ███   ▌▐   ███   ▐               █████████
//      █████████               ▐   █▄▄▌  ▌▐  ▐▄▄█   ▐               █████████
//      █████████                ▐▄  ▀▀ ▄▀  ▀▄ ▀▀  ▄▀                █████████
//      █████████                  ▀▀▄▄▀      ▀▀▄▄▀                  █████████
//      █████████                                                    █████████
//      █████████                 █▄                ▌                █████████
//      █████████                  ▌▀▀▄          ▄██                 █████████
//      █████████                  ▐   ▀▀▄▄▄▄▄▄█▀ █▌                 █████████
//      █████████                   ▐            ▄█                  █████████
//      █████████                    █          ▄█                   █████████
//      █████████                     ▀▄       █▀                    █████████
//      █████████                       ▀▄▄▄▄██▀                     █████████
//      █████████                                                    █████████
//      █████████                                                    █████████
//      █████████                                                    █████████
//      █████████                                                    █████████
//      █████████                                                    █████████
//        ██████████████████████████████████████████████████████████████████
//                                    Gammasoft
// More than thirty years of passion for high technology especially in development
// (c++, c#, objective-c, ...).

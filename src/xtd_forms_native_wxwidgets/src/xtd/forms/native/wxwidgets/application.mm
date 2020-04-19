#if defined(__APPLE__)
#include <Quartz/Quartz.h>

void __xtd_osx_enable_dark_mode__() {
  [NSApp setAppearance:[NSAppearance appearanceNamed:NSAppearanceNameDarkAqua]];
}

void __xtd_osx_enable_light_mode__() {
  [NSApp setAppearance:[NSAppearance appearanceNamed:NSAppearanceNameAqua]];
}

bool __xtd_osx_dark_mode_enabled__() {
  //return [[[NSAppearance currentAppearance] name] isEqualToString:(NSAppearanceNameDarkAqua)];
  return [[[NSApp appearance] name] isEqualToString:(NSAppearanceNameDarkAqua)];
}

#endif

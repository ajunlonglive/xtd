#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/date_time.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <chrono>
#include <cstdio>
#include <ctime>
#include <time.h>
#include <Windows.h>

int daylight = 0;
long timezone = 0;
const char* tzname[2] = {"Local", "Local"};
#define tzset _tzset

using namespace std;
using namespace xtd::native;

namespace {
  static const int64_t ticks_per_second = 10000000;
  
  /* Generate by this c# code source :
   
  using System;
  using System.Collections.ObjectModel;
  
  namespace TestConsole {
    class MainClass {
      [STAThread]
      static void Main() {
        ReadOnlyCollection<TimeZoneInfo> systemTimeZones = TimeZoneInfo.GetSystemTimeZones();
        string timezones = "vector<date_time::time_zone_info> system_time_zones = {";
        foreach (TimeZoneInfo item in systemTimeZones)
        timezones += string.Format("{{\"{0}\", {1}, \"{2}\", \"{3}\", \"{4}\", {5}}}, ", item.Id, item.BaseUtcOffset.Ticks, item.DaylightName, item.DisplayName, item.StandardName, item.SupportsDaylightSavingTime.ToString().ToLower(), item.BaseUtcOffset.Ticks >= 0 ? "+" : "", item.BaseUtcOffset);
        timezones += "};";
        Console.WriteLine(timezones);
        Console.ReadKey();
      }
    }
  }
   */
  
  // Generate on Windows 10.0.19044.1415 at 26/12/2021
  static const vector<date_time::time_zone_info> system_time_zones = {{"Dateline Standard Time", -432000000000, "Dateline Daylight Time", "(UTC-12:00) International Date Line West", "Dateline Standard Time", false}, {"UTC-11", -396000000000, "UTC-11", "(UTC-11:00) Coordinated Universal Time-11", "UTC-11", false}, {"Aleutian Standard Time", -360000000000, "Aleutian Daylight Time", "(UTC-10:00) Aleutian Islands", "Aleutian Standard Time", true}, {"Hawaiian Standard Time", -360000000000, "Hawaiian Daylight Time", "(UTC-10:00) Hawaii", "Hawaiian Standard Time", false}, {"Marquesas Standard Time", -342000000000, "Marquesas Daylight Time", "(UTC-09:30) Marquesas Islands", "Marquesas Standard Time", false}, {"Alaskan Standard Time", -324000000000, "Alaskan Daylight Time", "(UTC-09:00) Alaska", "Alaskan Standard Time", true}, {"UTC-09", -324000000000, "UTC-09", "(UTC-09:00) Coordinated Universal Time-09", "UTC-09", false}, {"Pacific Standard Time (Mexico)", -288000000000, "Pacific Daylight Time (Mexico)", "(UTC-08:00) Baja California", "Pacific Standard Time (Mexico)", true}, {"UTC-08", -288000000000, "UTC-08", "(UTC-08:00) Coordinated Universal Time-08", "UTC-08", false}, {"Pacific Standard Time", -288000000000, "Pacific Daylight Time", "(UTC-08:00) Pacific Time (US & Canada)", "Pacific Standard Time", true}, {"US Mountain Standard Time", -252000000000, "US Mountain Daylight Time", "(UTC-07:00) Arizona", "US Mountain Standard Time", false}, {"Mountain Standard Time (Mexico)", -252000000000, "Mountain Daylight Time (Mexico)", "(UTC-07:00) Chihuahua, La Paz, Mazatlan", "Mountain Standard Time (Mexico)", true}, {"Mountain Standard Time", -252000000000, "Mountain Daylight Time", "(UTC-07:00) Mountain Time (US & Canada)", "Mountain Standard Time", true}, {"Yukon Standard Time", -252000000000, "Yukon Daylight Time", "(UTC-07:00) Yukon", "Yukon Standard Time", true}, {"Central America Standard Time", -216000000000, "Central America Daylight Time", "(UTC-06:00) Central America", "Central America Standard Time", false}, {"Central Standard Time", -216000000000, "Central Daylight Time", "(UTC-06:00) Central Time (US & Canada)", "Central Standard Time", true}, {"Easter Island Standard Time", -216000000000, "Easter Island Daylight Time", "(UTC-06:00) Easter Island", "Easter Island Standard Time", true}, {"Central Standard Time (Mexico)", -216000000000, "Central Daylight Time (Mexico)", "(UTC-06:00) Guadalajara, Mexico City, Monterrey", "Central Standard Time (Mexico)", true}, {"Canada Central Standard Time", -216000000000, "Canada Central Daylight Time", "(UTC-06:00) Saskatchewan", "Canada Central Standard Time", false}, {"SA Pacific Standard Time", -180000000000, "SA Pacific Daylight Time", "(UTC-05:00) Bogota, Lima, Quito, Rio Branco", "SA Pacific Standard Time", false}, {"Eastern Standard Time (Mexico)", -180000000000, "Eastern Daylight Time (Mexico)", "(UTC-05:00) Chetumal", "Eastern Standard Time (Mexico)", true}, {"Eastern Standard Time", -180000000000, "Eastern Daylight Time", "(UTC-05:00) Eastern Time (US & Canada)", "Eastern Standard Time", true}, {"Haiti Standard Time", -180000000000, "Haiti Daylight Time", "(UTC-05:00) Haiti", "Haiti Standard Time", true}, {"Cuba Standard Time", -180000000000, "Cuba Daylight Time", "(UTC-05:00) Havana", "Cuba Standard Time", true}, {"US Eastern Standard Time", -180000000000, "US Eastern Daylight Time", "(UTC-05:00) Indiana (East)", "US Eastern Standard Time", true}, {"Turks And Caicos Standard Time", -180000000000, "Turks and Caicos Daylight Time", "(UTC-05:00) Turks and Caicos", "Turks and Caicos Standard Time", true}, {"Paraguay Standard Time", -144000000000, "Paraguay Daylight Time", "(UTC-04:00) Asuncion", "Paraguay Standard Time", true}, {"Atlantic Standard Time", -144000000000, "Atlantic Daylight Time", "(UTC-04:00) Atlantic Time (Canada)", "Atlantic Standard Time", true}, {"Venezuela Standard Time", -144000000000, "Venezuela Daylight Time", "(UTC-04:00) Caracas", "Venezuela Standard Time", true}, {"Central Brazilian Standard Time", -144000000000, "Central Brazilian Daylight Time", "(UTC-04:00) Cuiaba", "Central Brazilian Standard Time", true}, {"SA Western Standard Time", -144000000000, "SA Western Daylight Time", "(UTC-04:00) Georgetown, La Paz, Manaus, San Juan", "SA Western Standard Time", false}, {"Pacific SA Standard Time", -144000000000, "Pacific SA Daylight Time", "(UTC-04:00) Santiago", "Pacific SA Standard Time", true}, {"Newfoundland Standard Time", -126000000000, "Newfoundland Daylight Time", "(UTC-03:30) Newfoundland", "Newfoundland Standard Time", true}, {"Tocantins Standard Time", -108000000000, "Tocantins Daylight Time", "(UTC-03:00) Araguaina", "Tocantins Standard Time", true}, {"E. South America Standard Time", -108000000000, "E. South America Daylight Time", "(UTC-03:00) Brasilia", "E. South America Standard Time", true}, {"SA Eastern Standard Time", -108000000000, "SA Eastern Daylight Time", "(UTC-03:00) Cayenne, Fortaleza", "SA Eastern Standard Time", false}, {"Argentina Standard Time", -108000000000, "Argentina Daylight Time", "(UTC-03:00) City of Buenos Aires", "Argentina Standard Time", true}, {"Greenland Standard Time", -108000000000, "Greenland Daylight Time", "(UTC-03:00) Greenland", "Greenland Standard Time", true}, {"Montevideo Standard Time", -108000000000, "Montevideo Daylight Time", "(UTC-03:00) Montevideo", "Montevideo Standard Time", true}, {"Magallanes Standard Time", -108000000000, "Magallanes Daylight Time", "(UTC-03:00) Punta Arenas", "Magallanes Standard Time", true}, {"Saint Pierre Standard Time", -108000000000, "Saint Pierre Daylight Time", "(UTC-03:00) Saint Pierre and Miquelon", "Saint Pierre Standard Time", true}, {"Bahia Standard Time", -108000000000, "Bahia Daylight Time", "(UTC-03:00) Salvador", "Bahia Standard Time", true}, {"UTC-02", -72000000000, "UTC-02", "(UTC-02:00) Coordinated Universal Time-02", "UTC-02", false}, {"Mid-Atlantic Standard Time", -72000000000, "Mid-Atlantic Daylight Time", "(UTC-02:00) Mid-Atlantic - Old", "Mid-Atlantic Standard Time", true}, {"Azores Standard Time", -36000000000, "Azores Daylight Time", "(UTC-01:00) Azores", "Azores Standard Time", true}, {"Cape Verde Standard Time", -36000000000, "Cabo Verde Daylight Time", "(UTC-01:00) Cabo Verde Is.", "Cabo Verde Standard Time", false}, {"UTC", 0, "Coordinated Universal Time", "(UTC) Coordinated Universal Time", "Coordinated Universal Time", false}, {"GMT Standard Time", 0, "GMT Daylight Time", "(UTC+00:00) Dublin, Edinburgh, Lisbon, London", "GMT Standard Time", true}, {"Greenwich Standard Time", 0, "Greenwich Daylight Time", "(UTC+00:00) Monrovia, Reykjavik", "Greenwich Standard Time", false}, {"Sao Tome Standard Time", 0, "Sao Tome Daylight Time", "(UTC+00:00) Sao Tome", "Sao Tome Standard Time", true}, {"Morocco Standard Time", 0, "Morocco Daylight Time", "(UTC+01:00) Casablanca", "Morocco Standard Time", true}, {"W. Europe Standard Time", 36000000000, "W. Europe Daylight Time", "(UTC+01:00) Amsterdam, Berlin, Bern, Rome, Stockholm, Vienna", "W. Europe Standard Time", true}, {"Central Europe Standard Time", 36000000000, "Central Europe Daylight Time", "(UTC+01:00) Belgrade, Bratislava, Budapest, Ljubljana, Prague", "Central Europe Standard Time", true}, {"Romance Standard Time", 36000000000, "Romance Daylight Time", "(UTC+01:00) Brussels, Copenhagen, Madrid, Paris", "Romance Standard Time", true}, {"Central European Standard Time", 36000000000, "Central European Daylight Time", "(UTC+01:00) Sarajevo, Skopje, Warsaw, Zagreb", "Central European Standard Time", true}, {"W. Central Africa Standard Time", 36000000000, "W. Central Africa Daylight Time", "(UTC+01:00) West Central Africa", "W. Central Africa Standard Time", false}, {"Jordan Standard Time", 72000000000, "Jordan Daylight Time", "(UTC+02:00) Amman", "Jordan Standard Time", true}, {"GTB Standard Time", 72000000000, "GTB Daylight Time", "(UTC+02:00) Athens, Bucharest", "GTB Standard Time", true}, {"Middle East Standard Time", 72000000000, "Middle East Daylight Time", "(UTC+02:00) Beirut", "Middle East Standard Time", true}, {"Egypt Standard Time", 72000000000, "Egypt Daylight Time", "(UTC+02:00) Cairo", "Egypt Standard Time", true}, {"E. Europe Standard Time", 72000000000, "E. Europe Daylight Time", "(UTC+02:00) Chisinau", "E. Europe Standard Time", true}, {"Syria Standard Time", 72000000000, "Syria Daylight Time", "(UTC+02:00) Damascus", "Syria Standard Time", true}, {"West Bank Standard Time", 72000000000, "West Bank Gaza Daylight Time", "(UTC+02:00) Gaza, Hebron", "West Bank Gaza Standard Time", true}, {"South Africa Standard Time", 72000000000, "South Africa Daylight Time", "(UTC+02:00) Harare, Pretoria", "South Africa Standard Time", false}, {"FLE Standard Time", 72000000000, "FLE Daylight Time", "(UTC+02:00) Helsinki, Kyiv, Riga, Sofia, Tallinn, Vilnius", "FLE Standard Time", true}, {"Israel Standard Time", 72000000000, "Jerusalem Daylight Time", "(UTC+02:00) Jerusalem", "Jerusalem Standard Time", true}, {"South Sudan Standard Time", 72000000000, "South Sudan Daylight Time", "(UTC+02:00) Juba", "South Sudan Standard Time", true}, {"Kaliningrad Standard Time", 72000000000, "Russia TZ 1 Daylight Time", "(UTC+02:00) Kaliningrad", "Russia TZ 1 Standard Time", true}, {"Sudan Standard Time", 72000000000, "Sudan Daylight Time", "(UTC+02:00) Khartoum", "Sudan Standard Time", true}, {"Libya Standard Time", 72000000000, "Libya Daylight Time", "(UTC+02:00) Tripoli", "Libya Standard Time", true}, {"Namibia Standard Time", 72000000000, "Namibia Daylight Time", "(UTC+02:00) Windhoek", "Namibia Standard Time", true}, {"Arabic Standard Time", 108000000000, "Arabic Daylight Time", "(UTC+03:00) Baghdad", "Arabic Standard Time", true}, {"Turkey Standard Time", 108000000000, "Turkey Daylight Time", "(UTC+03:00) Istanbul", "Turkey Standard Time", true}, {"Arab Standard Time", 108000000000, "Arab Daylight Time", "(UTC+03:00) Kuwait, Riyadh", "Arab Standard Time", false}, {"Belarus Standard Time", 108000000000, "Belarus Daylight Time", "(UTC+03:00) Minsk", "Belarus Standard Time", true}, {"Russian Standard Time", 108000000000, "Russia TZ 2 Daylight Time", "(UTC+03:00) Moscow, St. Petersburg", "Russia TZ 2 Standard Time", true}, {"E. Africa Standard Time", 108000000000, "E. Africa Daylight Time", "(UTC+03:00) Nairobi", "E. Africa Standard Time", false}, {"Volgograd Standard Time", 108000000000, "Volgograd Daylight Time", "(UTC+03:00) Volgograd", "Volgograd Standard Time", true}, {"Iran Standard Time", 126000000000, "Iran Daylight Time", "(UTC+03:30) Tehran", "Iran Standard Time", true}, {"Arabian Standard Time", 144000000000, "Arabian Daylight Time", "(UTC+04:00) Abu Dhabi, Muscat", "Arabian Standard Time", false}, {"Astrakhan Standard Time", 144000000000, "Astrakhan Daylight Time", "(UTC+04:00) Astrakhan, Ulyanovsk", "Astrakhan Standard Time", true}, {"Azerbaijan Standard Time", 144000000000, "Azerbaijan Daylight Time", "(UTC+04:00) Baku", "Azerbaijan Standard Time", true}, {"Russia Time Zone 3", 144000000000, "Russia TZ 3 Daylight Time", "(UTC+04:00) Izhevsk, Samara", "Russia TZ 3 Standard Time", true}, {"Mauritius Standard Time", 144000000000, "Mauritius Daylight Time", "(UTC+04:00) Port Louis", "Mauritius Standard Time", true}, {"Saratov Standard Time", 144000000000, "Saratov Daylight Time", "(UTC+04:00) Saratov", "Saratov Standard Time", true}, {"Georgian Standard Time", 144000000000, "Georgian Daylight Time", "(UTC+04:00) Tbilisi", "Georgian Standard Time", false}, {"Caucasus Standard Time", 144000000000, "Caucasus Daylight Time", "(UTC+04:00) Yerevan", "Caucasus Standard Time", true}, {"Afghanistan Standard Time", 162000000000, "Afghanistan Daylight Time", "(UTC+04:30) Kabul", "Afghanistan Standard Time", false}, {"West Asia Standard Time", 180000000000, "West Asia Daylight Time", "(UTC+05:00) Ashgabat, Tashkent", "West Asia Standard Time", false}, {"Ekaterinburg Standard Time", 180000000000, "Russia TZ 4 Daylight Time", "(UTC+05:00) Ekaterinburg", "Russia TZ 4 Standard Time", true}, {"Pakistan Standard Time", 180000000000, "Pakistan Daylight Time", "(UTC+05:00) Islamabad, Karachi", "Pakistan Standard Time", true}, {"Qyzylorda Standard Time", 180000000000, "Qyzylorda Daylight Time", "(UTC+05:00) Qyzylorda", "Qyzylorda Standard Time", true}, {"India Standard Time", 198000000000, "India Daylight Time", "(UTC+05:30) Chennai, Kolkata, Mumbai, New Delhi", "India Standard Time", false}, {"Sri Lanka Standard Time", 198000000000, "Sri Lanka Daylight Time", "(UTC+05:30) Sri Jayawardenepura", "Sri Lanka Standard Time", false}, {"Nepal Standard Time", 207000000000, "Nepal Daylight Time", "(UTC+05:45) Kathmandu", "Nepal Standard Time", false}, {"Central Asia Standard Time", 216000000000, "Central Asia Daylight Time", "(UTC+06:00) Astana", "Central Asia Standard Time", false}, {"Bangladesh Standard Time", 216000000000, "Bangladesh Daylight Time", "(UTC+06:00) Dhaka", "Bangladesh Standard Time", true}, {"Omsk Standard Time", 216000000000, "Omsk Daylight Time", "(UTC+06:00) Omsk", "Omsk Standard Time", true}, {"Myanmar Standard Time", 234000000000, "Myanmar Daylight Time", "(UTC+06:30) Yangon (Rangoon)", "Myanmar Standard Time", false}, {"SE Asia Standard Time", 252000000000, "SE Asia Daylight Time", "(UTC+07:00) Bangkok, Hanoi, Jakarta", "SE Asia Standard Time", false}, {"Altai Standard Time", 252000000000, "Altai Daylight Time", "(UTC+07:00) Barnaul, Gorno-Altaysk", "Altai Standard Time", true}, {"W. Mongolia Standard Time", 252000000000, "W. Mongolia Daylight Time", "(UTC+07:00) Hovd", "W. Mongolia Standard Time", true}, {"North Asia Standard Time", 252000000000, "Russia TZ 6 Daylight Time", "(UTC+07:00) Krasnoyarsk", "Russia TZ 6 Standard Time", true}, {"N. Central Asia Standard Time", 252000000000, "Novosibirsk Daylight Time", "(UTC+07:00) Novosibirsk", "Novosibirsk Standard Time", true}, {"Tomsk Standard Time", 252000000000, "Tomsk Daylight Time", "(UTC+07:00) Tomsk", "Tomsk Standard Time", true}, {"China Standard Time", 288000000000, "China Daylight Time", "(UTC+08:00) Beijing, Chongqing, Hong Kong, Urumqi", "China Standard Time", false}, {"North Asia East Standard Time", 288000000000, "Russia TZ 7 Daylight Time", "(UTC+08:00) Irkutsk", "Russia TZ 7 Standard Time", true}, {"Singapore Standard Time", 288000000000, "Malay Peninsula Daylight Time", "(UTC+08:00) Kuala Lumpur, Singapore", "Malay Peninsula Standard Time", false}, {"W. Australia Standard Time", 288000000000, "W. Australia Daylight Time", "(UTC+08:00) Perth", "W. Australia Standard Time", true}, {"Taipei Standard Time", 288000000000, "Taipei Daylight Time", "(UTC+08:00) Taipei", "Taipei Standard Time", false}, {"Ulaanbaatar Standard Time", 288000000000, "Ulaanbaatar Daylight Time", "(UTC+08:00) Ulaanbaatar", "Ulaanbaatar Standard Time", true}, {"Aus Central W. Standard Time", 315000000000, "Aus Central W. Daylight Time", "(UTC+08:45) Eucla", "Aus Central W. Standard Time", false}, {"Transbaikal Standard Time", 324000000000, "Transbaikal Daylight Time", "(UTC+09:00) Chita", "Transbaikal Standard Time", true}, {"Tokyo Standard Time", 324000000000, "Tokyo Daylight Time", "(UTC+09:00) Osaka, Sapporo, Tokyo", "Tokyo Standard Time", false}, {"North Korea Standard Time", 324000000000, "North Korea Daylight Time", "(UTC+09:00) Pyongyang", "North Korea Standard Time", true}, {"Korea Standard Time", 324000000000, "Korea Daylight Time", "(UTC+09:00) Seoul", "Korea Standard Time", false}, {"Yakutsk Standard Time", 324000000000, "Russia TZ 8 Daylight Time", "(UTC+09:00) Yakutsk", "Russia TZ 8 Standard Time", true}, {"Cen. Australia Standard Time", 342000000000, "Cen. Australia Daylight Time", "(UTC+09:30) Adelaide", "Cen. Australia Standard Time", true}, {"AUS Central Standard Time", 342000000000, "AUS Central Daylight Time", "(UTC+09:30) Darwin", "AUS Central Standard Time", false}, {"E. Australia Standard Time", 360000000000, "E. Australia Daylight Time", "(UTC+10:00) Brisbane", "E. Australia Standard Time", false}, {"AUS Eastern Standard Time", 360000000000, "AUS Eastern Daylight Time", "(UTC+10:00) Canberra, Melbourne, Sydney", "AUS Eastern Standard Time", true}, {"West Pacific Standard Time", 360000000000, "West Pacific Daylight Time", "(UTC+10:00) Guam, Port Moresby", "West Pacific Standard Time", false}, {"Tasmania Standard Time", 360000000000, "Tasmania Daylight Time", "(UTC+10:00) Hobart", "Tasmania Standard Time", true}, {"Vladivostok Standard Time", 360000000000, "Russia TZ 9 Daylight Time", "(UTC+10:00) Vladivostok", "Russia TZ 9 Standard Time", true}, {"Lord Howe Standard Time", 378000000000, "Lord Howe Daylight Time", "(UTC+10:30) Lord Howe Island", "Lord Howe Standard Time", true}, {"Bougainville Standard Time", 396000000000, "Bougainville Daylight Time", "(UTC+11:00) Bougainville Island", "Bougainville Standard Time", true}, {"Russia Time Zone 10", 396000000000, "Russia TZ 10 Daylight Time", "(UTC+11:00) Chokurdakh", "Russia TZ 10 Standard Time", true}, {"Magadan Standard Time", 396000000000, "Magadan Daylight Time", "(UTC+11:00) Magadan", "Magadan Standard Time", true}, {"Norfolk Standard Time", 396000000000, "Norfolk Daylight Time", "(UTC+11:00) Norfolk Island", "Norfolk Standard Time", true}, {"Sakhalin Standard Time", 396000000000, "Sakhalin Daylight Time", "(UTC+11:00) Sakhalin", "Sakhalin Standard Time", true}, {"Central Pacific Standard Time", 396000000000, "Central Pacific Daylight Time", "(UTC+11:00) Solomon Is., New Caledonia", "Central Pacific Standard Time", false}, {"Russia Time Zone 11", 432000000000, "Russia TZ 11 Daylight Time", "(UTC+12:00) Anadyr, Petropavlovsk-Kamchatsky", "Russia TZ 11 Standard Time", true}, {"New Zealand Standard Time", 432000000000, "New Zealand Daylight Time", "(UTC+12:00) Auckland, Wellington", "New Zealand Standard Time", true}, {"UTC+12", 432000000000, "UTC+12", "(UTC+12:00) Coordinated Universal Time+12", "UTC+12", false}, {"Fiji Standard Time", 432000000000, "Fiji Daylight Time", "(UTC+12:00) Fiji", "Fiji Standard Time", true}, {"Kamchatka Standard Time", 432000000000, "Kamchatka Daylight Time", "(UTC+12:00) Petropavlovsk-Kamchatsky - Old", "Kamchatka Standard Time", true}, {"Chatham Islands Standard Time", 459000000000, "Chatham Islands Daylight Time", "(UTC+12:45) Chatham Islands", "Chatham Islands Standard Time", true}, {"UTC+13", 468000000000, "UTC+13", "(UTC+13:00) Coordinated Universal Time+13", "UTC+13", false}, {"Tonga Standard Time", 468000000000, "Tonga Daylight Time", "(UTC+13:00) Nuku'alofa", "Tonga Standard Time", true}, {"Samoa Standard Time", 468000000000, "Samoa Daylight Time", "(UTC+13:00) Samoa", "Samoa Standard Time", true}, {"Line Islands Standard Time", 504000000000, "Line Islands Daylight Time", "(UTC+14:00) Kiritimati Island", "Line Islands Standard Time", false}, };
  
  
  string string_printf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    string formatted_string(vsnprintf(nullptr, 0, fmt, args), 0);
    va_end(args);
    va_start(args, fmt);
    vsnprintf(&formatted_string[0], formatted_string.size() + 1, fmt, args);
    va_end(args);
    if (formatted_string == "INF") formatted_string = "inf";
    if (formatted_string == "NAN") formatted_string = "nan";
    return formatted_string;
  }
}

date_time::time_zone_info date_time::get_local_time_zone() {
  time_zone_info local_time_zone;
  bool local_time_zone_found = false;
  tzset();
  for (auto tzi : get_system_time_zones()) {
    if (tzi.id == reinterpret_cast<const char*>(tzname[0])) {
      local_time_zone = tzi;
      local_time_zone_found = true;
      break;
    }
  }
  
  if (!local_time_zone_found) {
    local_time_zone.id = reinterpret_cast<const char*>(tzname[0]);
    local_time_zone.base_utc_offset = static_cast<int64_t>(timezone * ticks_per_second);
    local_time_zone.daylight_name = reinterpret_cast<const char*>(tzname[1]);
    local_time_zone.display_name = string_printf("(UTC%s%02d:%02d) %s", -timezone ? "+" : "", timezone / 3600, timezone % 3600 / 60, reinterpret_cast<const char*>(tzname[0]));
    local_time_zone.standard_name = reinterpret_cast<const char*>(tzname[0]);
    local_time_zone.supports_daylight_saving_time = daylight != 0;
  }
  
  return local_time_zone;
}

vector<date_time::time_zone_info> date_time::get_system_time_zones() {
  return system_time_zones;
}

bool date_time::is_daylight(time_t time) {
  tm value {};
  localtime_s(&value, &time);
  return value.tm_isdst != 0;
}

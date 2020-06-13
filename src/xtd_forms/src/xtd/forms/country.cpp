#include "../../../include/xtd/forms/country.h"
#include "../../../include/xtd/forms/countries.h"
#include <xtd/drawing/system_images.h>
#include <filesystem>

using namespace std;
using namespace xtd;
using namespace std::filesystem;
using namespace xtd::drawing;
using namespace xtd::forms;

const vector<string> country::enclosed_letters {u8"\U0001F1E6", u8"\U0001F1E7", u8"\U0001F1E8", u8"\U0001F1E9", u8"\U0001F1EA", u8"\U0001F1EB", u8"\U0001F1EC", u8"\U0001F1ED", u8"\U0001F1EE", u8"\U0001F1EF", u8"\U0001F1F0", u8"\U0001F1F1", u8"\U0001F1F2", u8"\U0001F1F3", u8"\U0001F1F4", u8"\U0001F1F5", u8"\U0001F1F6", u8"\U0001F1F7", u8"\U0001F1F8", u8"\U0001F1F9", u8"\U0001F1FA", u8"\U0001F1FB", u8"\U0001F1FC", u8"\U0001F1FD", u8"\U0001F1FE", u8"\U0001F1FF"};

const country country::empty() {
  return country();
}

const image country::flag() const {
  return bitmap((path(__XTD_FORMS_RESOURCES_PATH__)/"share"/"xtd"/"resources"/"countries"/(strings::to_lower(alpha_2_code()) + ".png")).string());
}

const image country::flag_squared() const {
  return system_images::from_name(strings::format("flag-{}", strings::to_lower(alpha_2_code())), drawing::size {1024, 1024});
}

country country::from_name(const std::string& name) {
  for (const auto& country : countries::get_countries())
    if (strings::starts_with(strings::to_lower(strings::replace(country.name(), " ", "")), strings::to_lower(strings::replace(name, " ", "")))) return country;
  return empty();
}

country country::from_alpha_2_code(const std::string& alpha_2_code) {
  static map<string, country> countries {{"AF", countries::afghanistan()}, {"AX", countries::aland_islands()}, {"AL", countries::albania()}, {"DZ", countries::algeria()}, {"AS", countries::american_samoa()}, {"AD", countries::andorra()}, {"AO", countries::angola()}, {"AI", countries::anguilla()}, {"AQ", countries::antarctica()}, {"AG", countries::antigua_and_barbuda()}, {"AR", countries::argentina()}, {"AM", countries::armenia()}, {"AW", countries::aruba()}, {"AU", countries::australia()}, {"AT", countries::austria()}, {"AZ", countries::azerbaijan()}, {"BS", countries::bahamas()}, {"BH", countries::bahrain()}, {"BD", countries::bangladesh()}, {"BB", countries::barbados()}, {"BY", countries::belarus()}, {"BE", countries::belgium()}, {"BZ", countries::belize()}, {"BJ", countries::benin()}, {"BM", countries::bermuda()}, {"BT", countries::bhutan()}, {"BO", countries::bolivia()}, {"BQ", countries::bonaire_sint_eustatius_and_saba()}, {"BA", countries::bosnia_and_herzegovina()}, {"BW", countries::botswana()}, {"BV", countries::bouvet_island()}, {"BR", countries::brazil()}, {"IO", countries::british_indian_ocean_territory()}, {"BN", countries::brunei_darussalam()}, {"BG", countries::bulgaria()}, {"BF", countries::burkina_faso()}, {"BI", countries::burundi()}, {"CV", countries::cabo_verde()}, {"KH", countries::cambodia()}, {"CM", countries::cameroon()}, {"CA", countries::canada()}, {"KY", countries::cayman_islands()}, {"CF", countries::central_african_republic()}, {"TD", countries::chad()}, {"CL", countries::chile()}, {"CN", countries::china()}, {"CX", countries::christmas_island()}, {"CC", countries::cocos_keeling_islands()}, {"CO", countries::colombia()}, {"KM", countries::comoros()}, {"CG", countries::congo()}, {"CD", countries::democratic_republic_of_the_congo()}, {"CK", countries::cook_islands()}, {"CR", countries::costa_rica()}, {"CI", countries::cote_d_ivoire()}, {"HR", countries::croatia()}, {"CU", countries::cuba()}, {"CW", countries::curacao()}, {"CY", countries::cyprus()}, {"CZ", countries::czechia()}, {"DK", countries::denmark()}, {"DJ", countries::djibouti()}, {"DM", countries::dominica()}, {"DO", countries::dominican_republic()}, {"EC", countries::ecuador()}, {"EG", countries::egypt()}, {"SV", countries::el_salvador()}, {"GQ", countries::equatorial_guinea()}, {"ER", countries::eritrea()}, {"EE", countries::estonia()}, {"SZ", countries::eswatini()}, {"ET", countries::ethiopia()}, {"FK", countries::falkland_islands()}, {"FO", countries::faroe_islands()}, {"FJ", countries::fiji()}, {"FI", countries::finland()}, {"FR", countries::france()}, {"GF", countries::french_guiana()}, {"PF", countries::french_polynesia()}, {"TF", countries::french_southern_territories()}, {"GA", countries::gabon()}, {"GM", countries::gambia()}, {"GE", countries::georgia()}, {"DE", countries::germany()}, {"GH", countries::ghana()}, {"GI", countries::gibraltar()}, {"GR", countries::greece()}, {"GL", countries::greenland()}, {"GD", countries::grenada()}, {"GP", countries::guadeloupe()}, {"GU", countries::guam()}, {"GT", countries::guatemala()}, {"GG", countries::guernsey()}, {"GN", countries::guinea()}, {"GW", countries::guinea_bissau()}, {"GY", countries::guyana()}, {"HT", countries::haiti()}, {"HM", countries::heard_island_and_mcdonald_islands()}, {"VA", countries::holy_see()}, {"HN", countries::honduras()}, {"HK", countries::hong_kong()}, {"HU", countries::hungary()}, {"IS", countries::iceland()}, {"IN", countries::india()}, {"ID", countries::indonesia()}, {"IR", countries::iran()}, {"IQ", countries::iraq()}, {"IE", countries::ireland()}, {"IM", countries::isle_of_man()}, {"IL", countries::israel()}, {"IT", countries::italy()}, {"JM", countries::jamaica()}, {"JP", countries::japan()}, {"JE", countries::jersey()}, {"JO", countries::jordan()}, {"KZ", countries::kazakhstan()}, {"KE", countries::kenya()}, {"KI", countries::kiribati()}, {"KP", countries::north_korea()}, {"KR", countries::south_korea()}, {"KW", countries::kuwait()}, {"KG", countries::kyrgyzstan()}, {"LA", countries::lao_people_s_democratic_republic()}, {"LV", countries::latvia()}, {"LB", countries::lebanon()}, {"LS", countries::lesotho()}, {"LR", countries::liberia()}, {"LY", countries::libya()}, {"LI", countries::liechtenstein()}, {"LT", countries::lithuania()}, {"LU", countries::luxembourg()}, {"MO", countries::macao()}, {"MG", countries::madagascar()}, {"MW", countries::malawi()}, {"MY", countries::malaysia()}, {"MV", countries::maldives()}, {"ML", countries::mali()}, {"MT", countries::malta()}, {"MH", countries::marshall_islands()}, {"MQ", countries::martinique()}, {"MR", countries::mauritania()}, {"MU", countries::mauritius()}, {"YT", countries::mayotte()}, {"MX", countries::mexico()}, {"FM", countries::federated_states_of_micronesia()}, {"MD", countries::moldova()}, {"MC", countries::monaco()}, {"MN", countries::mongolia()}, {"ME", countries::montenegro()}, {"MS", countries::montserrat()}, {"MA", countries::morocco()}, {"MZ", countries::mozambique()}, {"MM", countries::myanmar()}, {"NA", countries::namibia()}, {"NR", countries::nauru()}, {"NP", countries::nepal()}, {"NL", countries::netherlands()}, {"NC", countries::new_caledonia()}, {"NZ", countries::new_zealand()}, {"NI", countries::nicaragua()}, {"NE", countries::niger()}, {"NG", countries::nigeria()}, {"NU", countries::niue()}, {"NF", countries::norfolk_island()}, {"MK", countries::north_macedonia()}, {"MP", countries::northern_mariana_islands()}, {"NO", countries::norway()}, {"OM", countries::oman()}, {"PK", countries::pakistan()}, {"PW", countries::palau()}, {"PS", countries::state_of_palestine()}, {"PA", countries::panama()}, {"PG", countries::papua_new_guinea()}, {"PY", countries::paraguay()}, {"PE", countries::peru()}, {"PH", countries::philippines()}, {"PN", countries::pitcairn()}, {"PL", countries::poland()}, {"PT", countries::portugal()}, {"PR", countries::puerto_rico()}, {"QA", countries::qatar()}, {"RE", countries::reunion()}, {"RO", countries::romania()}, {"RU", countries::russian_federation()}, {"RW", countries::rwanda()}, {"BL", countries::saint_barthelemy()}, {"SH", countries::saint_helena_ascension_and_tristan_da_cunha()}, {"KN", countries::saint_kitts_and_nevis()}, {"LC", countries::saint_lucia()}, {"MF", countries::saint_martin_french_part()}, {"PM", countries::saint_pierre_and_miquelon()}, {"VC", countries::saint_vincent_and_the_grenadines()}, {"WS", countries::samoa()}, {"SM", countries::san_marino()}, {"ST", countries::sao_tome_and_principe()}, {"SA", countries::saudi_arabia()}, {"SN", countries::senegal()}, {"RS", countries::serbia()}, {"SC", countries::seychelles()}, {"SL", countries::sierra_leone()}, {"SG", countries::singapore()}, {"SX", countries::sint_maarten_dutch_part()}, {"SK", countries::slovakia()}, {"SI", countries::slovenia()}, {"SB", countries::solomon_islands()}, {"SO", countries::somalia()}, {"ZA", countries::south_africa()}, {"GS", countries::south_georgia_and_the_south_sandwich_islands()}, {"SS", countries::south_sudan()}, {"ES", countries::spain()}, {"LK", countries::sri_lanka()}, {"SD", countries::sudan()}, {"SR", countries::suriname()}, {"SJ", countries::svalbard_and_jan_mayen()}, {"SE", countries::sweden()}, {"CH", countries::switzerland()}, {"SY", countries::syrian_arab_republic()}, {"TW", countries::taiwan_china()}, {"TJ", countries::tajikistan()}, {"TZ", countries::tanzania()}, {"TH", countries::thailand()}, {"TL", countries::timor_leste()}, {"TG", countries::togo()}, {"TK", countries::tokelau()}, {"TO", countries::tonga()}, {"TT", countries::trinidad_and_tobago()}, {"TN", countries::tunisia()}, {"TR", countries::turkey()}, {"TM", countries::turkmenistan()}, {"TC", countries::turks_and_caicos_islands()}, {"TV", countries::tuvalu()}, {"UG", countries::uganda()}, {"UA", countries::ukraine()}, {"AE", countries::united_arab_emirates()}, {"GB", countries::united_kingdom_of_great_britain_and_northern_ireland()}, {"US", countries::united_states_of_america()}, {"UM", countries::united_states_minor_outlying_islands()}, {"UY", countries::uruguay()}, {"UZ", countries::uzbekistan()}, {"VU", countries::vanuatu()}, {"VE", countries::venezuela()}, {"VN", countries::viet_nam()}, {"VG", countries::british_virgin_islands()}, {"VI", countries::united_states_virgin_islands()}, {"WF", countries::wallis_and_futuna()}, {"EH", countries::western_sahara()}, {"YE", countries::yemen()}, {"ZM", countries::zambia()}, {"ZW", countries::zimbabwe()}};
  return countries[strings::to_upper(alpha_2_code)];
}

country country::from_alpha_3_code(const std::string& alpha_3_code) {
  static map<string, country> countries {{"AFG", countries::afghanistan()}, {"ALA", countries::aland_islands()}, {"ALB", countries::albania()}, {"DZA", countries::algeria()}, {"ASM", countries::american_samoa()}, {"AND", countries::andorra()}, {"AGO", countries::angola()}, {"AIA", countries::anguilla()}, {"ATA", countries::antarctica()}, {"ATG", countries::antigua_and_barbuda()}, {"ARG", countries::argentina()}, {"ARM", countries::armenia()}, {"ABW", countries::aruba()}, {"AUS", countries::australia()}, {"AUT", countries::austria()}, {"AZE", countries::azerbaijan()}, {"BHS", countries::bahamas()}, {"BHR", countries::bahrain()}, {"BGD", countries::bangladesh()}, {"BRB", countries::barbados()}, {"BLR", countries::belarus()}, {"BEL", countries::belgium()}, {"BLZ", countries::belize()}, {"BEN", countries::benin()}, {"BMU", countries::bermuda()}, {"BTN", countries::bhutan()}, {"BOL", countries::bolivia()}, {"BES", countries::bonaire_sint_eustatius_and_saba()}, {"BIH", countries::bosnia_and_herzegovina()}, {"BWA", countries::botswana()}, {"BVT", countries::bouvet_island()}, {"BRA", countries::brazil()}, {"IOT", countries::british_indian_ocean_territory()}, {"BRN", countries::brunei_darussalam()}, {"BGR", countries::bulgaria()}, {"BFA", countries::burkina_faso()}, {"BDI", countries::burundi()}, {"CPV", countries::cabo_verde()}, {"KHM", countries::cambodia()}, {"CMR", countries::cameroon()}, {"CAN", countries::canada()}, {"CYM", countries::cayman_islands()}, {"CAF", countries::central_african_republic()}, {"TCD", countries::chad()}, {"CHL", countries::chile()}, {"CHN", countries::china()}, {"CXR", countries::christmas_island()}, {"CCK", countries::cocos_keeling_islands()}, {"COL", countries::colombia()}, {"COM", countries::comoros()}, {"COG", countries::congo()}, {"COD", countries::democratic_republic_of_the_congo()}, {"COK", countries::cook_islands()}, {"CRI", countries::costa_rica()}, {"CIV", countries::cote_d_ivoire()}, {"HRV", countries::croatia()}, {"CUB", countries::cuba()}, {"CUW", countries::curacao()}, {"CYP", countries::cyprus()}, {"CZE", countries::czechia()}, {"DNK", countries::denmark()}, {"DJI", countries::djibouti()}, {"DMA", countries::dominica()}, {"DOM", countries::dominican_republic()}, {"ECU", countries::ecuador()}, {"EGY", countries::egypt()}, {"SLV", countries::el_salvador()}, {"GNQ", countries::equatorial_guinea()}, {"ERI", countries::eritrea()}, {"EST", countries::estonia()}, {"SWZ", countries::eswatini()}, {"ETH", countries::ethiopia()}, {"FLK", countries::falkland_islands()}, {"FRO", countries::faroe_islands()}, {"FJI", countries::fiji()}, {"FIN", countries::finland()}, {"FRA", countries::france()}, {"GUF", countries::french_guiana()}, {"PYF", countries::french_polynesia()}, {"ATF", countries::french_southern_territories()}, {"GAB", countries::gabon()}, {"GMB", countries::gambia()}, {"GEO", countries::georgia()}, {"DEU", countries::germany()}, {"GHA", countries::ghana()}, {"GIB", countries::gibraltar()}, {"GRC", countries::greece()}, {"GRL", countries::greenland()}, {"GRD", countries::grenada()}, {"GLP", countries::guadeloupe()}, {"GUM", countries::guam()}, {"GTM", countries::guatemala()}, {"GGY", countries::guernsey()}, {"GIN", countries::guinea()}, {"GNB", countries::guinea_bissau()}, {"GUY", countries::guyana()}, {"HTI", countries::haiti()}, {"HMD", countries::heard_island_and_mcdonald_islands()}, {"VAT", countries::holy_see()}, {"HND", countries::honduras()}, {"HKG", countries::hong_kong()}, {"HUN", countries::hungary()}, {"ISL", countries::iceland()}, {"IND", countries::india()}, {"IDN", countries::indonesia()}, {"IRN", countries::iran()}, {"IRQ", countries::iraq()}, {"IRL", countries::ireland()}, {"IMN", countries::isle_of_man()}, {"ISR", countries::israel()}, {"ITA", countries::italy()}, {"JAM", countries::jamaica()}, {"JPN", countries::japan()}, {"JEY", countries::jersey()}, {"JOR", countries::jordan()}, {"KAZ", countries::kazakhstan()}, {"KEN", countries::kenya()}, {"KIR", countries::kiribati()}, {"PRK", countries::north_korea()}, {"KOR", countries::south_korea()}, {"KWT", countries::kuwait()}, {"KGZ", countries::kyrgyzstan()}, {"LAO", countries::lao_people_s_democratic_republic()}, {"LVA", countries::latvia()}, {"LBN", countries::lebanon()}, {"LSO", countries::lesotho()}, {"LBR", countries::liberia()}, {"LBY", countries::libya()}, {"LIE", countries::liechtenstein()}, {"LTU", countries::lithuania()}, {"LUX", countries::luxembourg()}, {"MAC", countries::macao()}, {"MDG", countries::madagascar()}, {"MWI", countries::malawi()}, {"MYS", countries::malaysia()}, {"MDV", countries::maldives()}, {"MLI", countries::mali()}, {"MLT", countries::malta()}, {"MHL", countries::marshall_islands()}, {"MTQ", countries::martinique()}, {"MRT", countries::mauritania()}, {"MUS", countries::mauritius()}, {"MYT", countries::mayotte()}, {"MEX", countries::mexico()}, {"FSM", countries::federated_states_of_micronesia()}, {"MDA", countries::moldova()}, {"MCO", countries::monaco()}, {"MNG", countries::mongolia()}, {"MNE", countries::montenegro()}, {"MSR", countries::montserrat()}, {"MAR", countries::morocco()}, {"MOZ", countries::mozambique()}, {"MMR", countries::myanmar()}, {"NAM", countries::namibia()}, {"NRU", countries::nauru()}, {"NPL", countries::nepal()}, {"NLD", countries::netherlands()}, {"NCL", countries::new_caledonia()}, {"NZL", countries::new_zealand()}, {"NIC", countries::nicaragua()}, {"NER", countries::niger()}, {"NGA", countries::nigeria()}, {"NIU", countries::niue()}, {"NFK", countries::norfolk_island()}, {"MKD", countries::north_macedonia()}, {"MNP", countries::northern_mariana_islands()}, {"NOR", countries::norway()}, {"OMN", countries::oman()}, {"PAK", countries::pakistan()}, {"PLW", countries::palau()}, {"PSE", countries::state_of_palestine()}, {"PAN", countries::panama()}, {"PNG", countries::papua_new_guinea()}, {"PRY", countries::paraguay()}, {"PER", countries::peru()}, {"PHL", countries::philippines()}, {"PCN", countries::pitcairn()}, {"POL", countries::poland()}, {"PRT", countries::portugal()}, {"PRI", countries::puerto_rico()}, {"QAT", countries::qatar()}, {"REU", countries::reunion()}, {"ROU", countries::romania()}, {"RUS", countries::russian_federation()}, {"RWA", countries::rwanda()}, {"BLM", countries::saint_barthelemy()}, {"SHN", countries::saint_helena_ascension_and_tristan_da_cunha()}, {"KNA", countries::saint_kitts_and_nevis()}, {"LCA", countries::saint_lucia()}, {"MAF", countries::saint_martin_french_part()}, {"SPM", countries::saint_pierre_and_miquelon()}, {"VCT", countries::saint_vincent_and_the_grenadines()}, {"WSM", countries::samoa()}, {"SMR", countries::san_marino()}, {"STP", countries::sao_tome_and_principe()}, {"SAU", countries::saudi_arabia()}, {"SEN", countries::senegal()}, {"SRB", countries::serbia()}, {"SYC", countries::seychelles()}, {"SLE", countries::sierra_leone()}, {"SGP", countries::singapore()}, {"SXM", countries::sint_maarten_dutch_part()}, {"SVK", countries::slovakia()}, {"SVN", countries::slovenia()}, {"SLB", countries::solomon_islands()}, {"SOM", countries::somalia()}, {"ZAF", countries::south_africa()}, {"SGS", countries::south_georgia_and_the_south_sandwich_islands()}, {"SSD", countries::south_sudan()}, {"ESP", countries::spain()}, {"LKA", countries::sri_lanka()}, {"SDN", countries::sudan()}, {"SUR", countries::suriname()}, {"SJM", countries::svalbard_and_jan_mayen()}, {"SWE", countries::sweden()}, {"CHE", countries::switzerland()}, {"SYR", countries::syrian_arab_republic()}, {"TWN", countries::taiwan_china()}, {"TJK", countries::tajikistan()}, {"TZA", countries::tanzania()}, {"THA", countries::thailand()}, {"TLS", countries::timor_leste()}, {"TGO", countries::togo()}, {"TKL", countries::tokelau()}, {"TON", countries::tonga()}, {"TTO", countries::trinidad_and_tobago()}, {"TUN", countries::tunisia()}, {"TUR", countries::turkey()}, {"TKM", countries::turkmenistan()}, {"TCA", countries::turks_and_caicos_islands()}, {"TUV", countries::tuvalu()}, {"UGA", countries::uganda()}, {"UKR", countries::ukraine()}, {"ARE", countries::united_arab_emirates()}, {"GBR", countries::united_kingdom_of_great_britain_and_northern_ireland()}, {"USA", countries::united_states_of_america()}, {"UMI", countries::united_states_minor_outlying_islands()}, {"URY", countries::uruguay()}, {"UZB", countries::uzbekistan()}, {"VUT", countries::vanuatu()}, {"VEN", countries::venezuela()}, {"VNM", countries::viet_nam()}, {"VGB", countries::british_virgin_islands()}, {"VIR", countries::united_states_virgin_islands()}, {"WLF", countries::wallis_and_futuna()}, {"ESH", countries::western_sahara()}, {"YEM", countries::yemen()}, {"ZMB", countries::zambia()}, {"ZWE", countries::zimbabwe()}};
  return countries[strings::to_upper(alpha_3_code)];
}

country country::from_numeric_code(int numeric_code) {
  static map<int, country> countries {{4, countries::afghanistan()}, {248, countries::aland_islands()}, {8, countries::albania()}, {12, countries::algeria()}, {16, countries::american_samoa()}, {20, countries::andorra()}, {24, countries::angola()}, {660, countries::anguilla()}, {10, countries::antarctica()}, {28, countries::antigua_and_barbuda()}, {32, countries::argentina()}, {51, countries::armenia()}, {533, countries::aruba()}, {36, countries::australia()}, {40, countries::austria()}, {31, countries::azerbaijan()}, {44, countries::bahamas()}, {48, countries::bahrain()}, {50, countries::bangladesh()}, {52, countries::barbados()}, {112, countries::belarus()}, {56, countries::belgium()}, {84, countries::belize()}, {204, countries::benin()}, {60, countries::bermuda()}, {64, countries::bhutan()}, {68, countries::bolivia()}, {535, countries::bonaire_sint_eustatius_and_saba()}, {70, countries::bosnia_and_herzegovina()}, {72, countries::botswana()}, {74, countries::bouvet_island()}, {76, countries::brazil()}, {86, countries::british_indian_ocean_territory()}, {96, countries::brunei_darussalam()}, {100, countries::bulgaria()}, {854, countries::burkina_faso()}, {108, countries::burundi()}, {132, countries::cabo_verde()}, {116, countries::cambodia()}, {120, countries::cameroon()}, {124, countries::canada()}, {136, countries::cayman_islands()}, {140, countries::central_african_republic()}, {148, countries::chad()}, {152, countries::chile()}, {156, countries::china()}, {162, countries::christmas_island()}, {166, countries::cocos_keeling_islands()}, {170, countries::colombia()}, {174, countries::comoros()}, {178, countries::congo()}, {180, countries::democratic_republic_of_the_congo()}, {184, countries::cook_islands()}, {188, countries::costa_rica()}, {384, countries::cote_d_ivoire()}, {191, countries::croatia()}, {192, countries::cuba()}, {531, countries::curacao()}, {196, countries::cyprus()}, {203, countries::czechia()}, {208, countries::denmark()}, {262, countries::djibouti()}, {212, countries::dominica()}, {214, countries::dominican_republic()}, {218, countries::ecuador()}, {818, countries::egypt()}, {222, countries::el_salvador()}, {226, countries::equatorial_guinea()}, {232, countries::eritrea()}, {233, countries::estonia()}, {748, countries::eswatini()}, {231, countries::ethiopia()}, {238, countries::falkland_islands()}, {234, countries::faroe_islands()}, {242, countries::fiji()}, {246, countries::finland()}, {250, countries::france()}, {254, countries::french_guiana()}, {258, countries::french_polynesia()}, {260, countries::french_southern_territories()}, {266, countries::gabon()}, {270, countries::gambia()}, {268, countries::georgia()}, {276, countries::germany()}, {288, countries::ghana()}, {292, countries::gibraltar()}, {300, countries::greece()}, {304, countries::greenland()}, {308, countries::grenada()}, {312, countries::guadeloupe()}, {316, countries::guam()}, {320, countries::guatemala()}, {831, countries::guernsey()}, {324, countries::guinea()}, {624, countries::guinea_bissau()}, {328, countries::guyana()}, {332, countries::haiti()}, {334, countries::heard_island_and_mcdonald_islands()}, {336, countries::holy_see()}, {340, countries::honduras()}, {344, countries::hong_kong()}, {348, countries::hungary()}, {352, countries::iceland()}, {356, countries::india()}, {360, countries::indonesia()}, {364, countries::iran ()}, {368, countries::iraq()}, {372, countries::ireland()}, {833, countries::isle_of_man()}, {376, countries::israel()}, {380, countries::italy()}, {388, countries::jamaica()}, {392, countries::japan()}, {832, countries::jersey()}, {400, countries::jordan()}, {398, countries::kazakhstan()}, {404, countries::kenya()}, {296, countries::kiribati()}, {408, countries::north_korea()}, {410, countries::south_korea()}, {414, countries::kuwait()}, {417, countries::kyrgyzstan()}, {418, countries::lao_people_s_democratic_republic()}, {428, countries::latvia()}, {422, countries::lebanon()}, {426, countries::lesotho()}, {430, countries::liberia()}, {434, countries::libya()}, {438, countries::liechtenstein()}, {440, countries::lithuania()}, {442, countries::luxembourg()}, {446, countries::macao()}, {450, countries::madagascar()}, {454, countries::malawi()}, {458, countries::malaysia()}, {462, countries::maldives()}, {466, countries::mali()}, {470, countries::malta()}, {584, countries::marshall_islands()}, {474, countries::martinique()}, {478, countries::mauritania()}, {480, countries::mauritius()}, {175, countries::mayotte()}, {484, countries::mexico()}, {583, countries::federated_states_of_micronesia()}, {498, countries::moldova()}, {492, countries::monaco()}, {496, countries::mongolia()}, {499, countries::montenegro()}, {500, countries::montserrat()}, {504, countries::morocco()}, {508, countries::mozambique()}, {104, countries::myanmar()}, {516, countries::namibia()}, {520, countries::nauru()}, {524, countries::nepal()}, {528, countries::netherlands()}, {540, countries::new_caledonia()}, {554, countries::new_zealand()}, {558, countries::nicaragua()}, {562, countries::niger()}, {566, countries::nigeria()}, {570, countries::niue()}, {574, countries::norfolk_island()}, {807, countries::north_macedonia()}, {580, countries::northern_mariana_islands()}, {578, countries::norway()}, {512, countries::oman()}, {586, countries::pakistan()}, {585, countries::palau()}, {275, countries::state_of_palestine()}, {591, countries::panama()}, {598, countries::papua_new_guinea()}, {600, countries::paraguay()}, {604, countries::peru()}, {608, countries::philippines()}, {612, countries::pitcairn()}, {616, countries::poland()}, {620, countries::portugal()}, {630, countries::puerto_rico()}, {634, countries::qatar()}, {638, countries::reunion()}, {642, countries::romania()}, {643, countries::russian_federation()}, {646, countries::rwanda()}, {652, countries::saint_barthelemy()}, {654, countries::saint_helena_ascension_and_tristan_da_cunha()}, {659, countries::saint_kitts_and_nevis()}, {662, countries::saint_lucia()}, {663, countries::saint_martin_french_part()}, {666, countries::saint_pierre_and_miquelon()}, {670, countries::saint_vincent_and_the_grenadines()}, {882, countries::samoa()}, {674, countries::san_marino()}, {678, countries::sao_tome_and_principe()}, {682, countries::saudi_arabia()}, {686, countries::senegal()}, {688, countries::serbia()}, {690, countries::seychelles()}, {694, countries::sierra_leone()}, {702, countries::singapore()}, {534, countries::sint_maarten_dutch_part()}, {703, countries::slovakia()}, {705, countries::slovenia()}, {90, countries::solomon_islands()}, {706, countries::somalia()}, {710, countries::south_africa()}, {239, countries::south_georgia_and_the_south_sandwich_islands()}, {728, countries::south_sudan()}, {724, countries::spain()}, {144, countries::sri_lanka()}, {729, countries::sudan()}, {740, countries::suriname()}, {744, countries::svalbard_and_jan_mayen()}, {752, countries::sweden()}, {756, countries::switzerland()}, {760, countries::syrian_arab_republic()}, {158, countries::taiwan_china()}, {762, countries::tajikistan()}, {834, countries::tanzania()}, {764, countries::thailand()}, {626, countries::timor_leste()}, {768, countries::togo()}, {772, countries::tokelau()}, {776, countries::tonga()}, {780, countries::trinidad_and_tobago()}, {788, countries::tunisia()}, {792, countries::turkey()}, {795, countries::turkmenistan()}, {796, countries::turks_and_caicos_islands()}, {798, countries::tuvalu()}, {800, countries::uganda()}, {804, countries::ukraine()}, {784, countries::united_arab_emirates()}, {826, countries::united_kingdom_of_great_britain_and_northern_ireland()}, {840, countries::united_states_of_america()}, {581, countries::united_states_minor_outlying_islands()}, {858, countries::uruguay()}, {860, countries::uzbekistan()}, {548, countries::vanuatu()}, {862, countries::venezuela()}, {704, countries::viet_nam()}, {92, countries::british_virgin_islands()}, {850, countries::united_states_virgin_islands()}, {876, countries::wallis_and_futuna()}, {732, countries::western_sahara()}, {887, countries::yemen()}, {894, countries::zambia()}, {716, countries::zimbabwe()}};
  return countries[numeric_code];
}

std::string country::to_string() const {
  if (*this == empty()) return "country [empty]";
  return strings::format("country [name={}, alpha_2_code={}, alpha_3_code={}, numeric_code={}]", name(), alpha_2_code(), alpha_3_code(), numeric_code());
}

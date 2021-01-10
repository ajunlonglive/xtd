/// @file
/// @brief Contains doygen main page.

/// @mainpage xtd. - Reference Guide Documentation
///
/// @section FeaturesSection Features
///   * a collection of native C++ classes libraries, to complete std;
///   * written in efficient, modern C++17;
///   * and highly portable and available on many different platforms (Windows, macOS, Linux, iOS and android);///
/// For more information see <a href="https://gammasoft71.wixsite.com/xtdpro">website</a> (or <a href="https://github.com/gammasoft71/xtd/tree/master/docs/home.md">documentations</a>) and <a href="https://codedocs.xyz/gammasoft71/xtd/">Reference Guide</a>).
///
/// @section ExamplesSection Examples
/// The classic first application 'Hello World'.
///
/// src/hello_world_console.cpp:
/// @code
/// #include <xtd/xtd>
///
/// using namespace xtd;
///
/// int main() {
///   console::background_color(console_color::blue);
///   console::foreground_color(console_color::white);
///   console::write_line("Hello, World!");
/// }
/// @endcode
///
/// src/hello_worlds_forms.cpp:
/// @code
/// #include <xtd/xtd>
///
/// using namespace xtd::forms;
///
/// int main() {
///   button button1;
///   button1.text("Click me");
///   button1.location({10, 10});
///   button1.click += [] {
///     messageBox::show("Hello, World!");
///   };
///
///   form form1;
///   form1.text("Hello world (message_box)");
///   form.controls().push_back(button1);
///
///   application::run(form1);
/// }
/// @endcode
///
/// src/hello_worlds_tunit.cpp:
/// @code
/// #include <xtd/xtd>
/// #include <string>
///
/// using namespace std;
/// using namespace xtd::tunit;
///
/// namespace unit_tests {
///   class test_class_(hello_world_test) {
///   public:
///     void test_method_(create_string_from_literal) {
///       string s = "Hello, World!";
///       assert::are_equal("Hello, World!", s);
///     }
///
///     void test_method_(create_string_from_chars) {
///       string s = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
///       assert::are_equal("Hello, World!", s);
///     }
///   };
/// }
///
/// int main(int argc, char* argv[]) {
///   return console_unit_test(argv, argc).run();
/// }
/// @endcode
///
/// For more examples see <a href="https://github.com/gammasoft71/xtd/tree/master/examples/">examples</a>.
///
/// @section DownloadSection Download and install
/// Before running examples you must download and install xtd. To download and install it read <a href="https://github.com/gammasoft71/xtd/tree/master/docs/downloads.md">Downloads.md</a> file.

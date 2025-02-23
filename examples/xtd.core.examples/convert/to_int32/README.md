# to_int32

Shows how to use [xtd::convert::to_int32](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1convert.html#a4d52bf96c567e100f5aba3eca94abe2b) method.

# Sources

[src/to_int32.cpp](src/to_int32.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Convert unsigned int to int :
-----------------------------
static_cast<int32_t>(value) = 42
as<int32_t>(value)          = 42
convert::to_int32(value)    = 42

Convert float to int :
----------------------
static_cast<int32_t>(float_value) = 42
as<int32_t>(float_value)          = 43
convert::to_int32(float_value)    = 43

Convert any to int :
--------------------
any_cast<int32_t>(any_value) = 42
as<int32_t>(any_value)       = 42
convert::to_int32(any_value) = 42

Convert string to int :
-----------------------
parse<int32_t>(string_value))   = 42
as<int32_t>(string_value)       = 42
convert::to_int32(string_value) = 42

Convert hexa string to int :
----------------------------
parse<int32_t>(string_hex_value, number_styles::hex_number) = 42
as<int32_t>(string_hex_value, 16)                           = 42
convert::to_int32(string_hex_value, 16))                    = 42

Convert unsigned int to int with overflow :
-------------------------------------------
static_cast<int32_t>(overflow_value) = -2147483648
(ERROR) as : Overflow exception
(ERROR) convert::to_int32 : Overflow exception
```

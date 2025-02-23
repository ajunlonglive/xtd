#include "../../../include/xtd/reflection/assembly_trademark_attribute.h"

using namespace std;
using namespace xtd;
using namespace xtd::reflection;

assembly_trademark_attribute::assembly_trademark_attribute(const ustring& trademark) : trademark_(trademark) {
}

assembly_trademark_attribute::assembly_trademark_attribute(const ustring& trademark, const object& executing_assembly) : trademark_(trademark) {
  __assembly_trademark_attribute__() = make_shared<xtd::reflection::assembly_trademark_attribute>(trademark);
}

shared_ptr<object> assembly_trademark_attribute::get_type_id() const {
  return xtd::guid::new_guid().memberwise_clone<xtd::guid>();
}

shared_ptr<xtd::reflection::assembly_trademark_attribute>& __assembly_trademark_attribute__() {
  static shared_ptr<xtd::reflection::assembly_trademark_attribute> trademark;
  return trademark;
}

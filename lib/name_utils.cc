#include <string>

#include "absl/strings/str_cat.h"
#include "google/protobuf/text_format.h"
#include "lib/name_utils.h"

namespace lib {

std::string GetNameFromNameProto(const lib::Name& name_proto) {
  return absl::StrCat(name_proto.first_name(), " ", name_proto.last_name());
}
std::string GetFirstNameFromNameProto(const lib::Name& name_proto) {
  return name_proto.first_name();
}
std::string GetLastNameFromNameProto(const lib::Name& name_proto) {
  return name_proto.last_name();
}

Name ConvertBinaryProto(const std::string& name_binary_proto) {
  Name result;
  result.ParseFromString(name_binary_proto);
  return result;
}

Name ConvertTextProto(const std::string& name_text_proto) {
  Name result;
  google::protobuf::TextFormat::ParseFromString(name_text_proto, &result);
  return result;
}

}  // namespace lib
#ifndef NAME_UTILS_FOO_H_
#define NAME_UTILS_FOO_H_

#include <string>

#include "lib/name.pb.h"

namespace lib {

std::string GetNameFromNameProto(const lib::Name& name_proto);
std::string GetFirstNameFromNameProto(const lib::Name& name_proto);
std::string GetLastNameFromNameProto(const lib::Name& name_proto);

Name ConvertBinaryProto(const std::string& name_binary_proto);
Name ConvertTextProto(const std::string& name_text_proto);

}  // namespace lib

// namespace lib

#endif  // NAME_UTILS_FOO_H_
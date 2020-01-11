#include <iostream>

#include "lib/name.pb.h"
#include "lib/name_utils.h"

int main(int argc, char** argv) {
  lib::Name name;
  name.set_first_name("Chuck");
  name.set_last_name("Norris");
  std::cout << name.DebugString();

  std::cout << "Name's combined name is: " << lib::GetNameFromNameProto(name)
            << std::endl;

  lib::Name name2 = lib::ConvertTextProto(R"(
      first_name: "hello"
      last_name: "world"
  )");
  std::cout << name2.DebugString();
}
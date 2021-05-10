/// file: dev_test.cpp
/// date: 2021-05-10


#include <rapidjson/document.h> 

#include "jsonfront/base.h"
#include "jsonfront/front4rapidjson.h"


int main(int argc, char** argv) {
  jsonfront::Front4RapidJSON rapidjson_front("../data/json_file_demo.json");
  rapidjson_front.print();

  rapidjson::Document tmp = rapidjson_front.get_core();
  std::string test = jsonfront::Front4RapidJSON::to_string(tmp);
  printf("dbg %s \n", test.c_str());
  
  jsonfront::Front4RapidJSON rapidjson_front1(&tmp);
  rapidjson_front1.print();

  jsonfront::Front4RapidJSON rapidjson_front2(tmp);
  rapidjson_front2.print();
  return 0;
}

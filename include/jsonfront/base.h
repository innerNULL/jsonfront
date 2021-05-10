/// file: base.h
/// date: 2021-05-10


#ifndef JSONFRONT_BASE_H_
#define JSONFRONT_BASE_H_


#include <thread>
#include <mutex>

#include <rapidjson/document.h>


namespace jsonfront {


template<typename JSON_CORE>
class JSONBase {
 protected:
  std::mutex mutex_;
  JSON_CORE core_;

 public:
  JSONBase() {}

  //JSONBase(const std::string& json_str) {}
  //JSONBase(const std::string& json_file) {} 
  //JSONBase(const JSON_CORE* source_json_obj) {}

  //JSON_CORE get_core() { return this->core_; }

  static std::string to_string(); 

  static void doc_assign(JSON_CORE* to, JSON_CORE* from) {};

  virtual void load_from_file(const std::string& json_file_path) {}

  virtual void check() {};

  virtual std::string get_string() = 0;

  virtual void print() = 0;

  virtual JSON_CORE get_core() = 0;  
};


} // namespace jsonfront


#endif



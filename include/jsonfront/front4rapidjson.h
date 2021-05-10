/// file: front4rapidjson.h
/// date: 2021-05-10


#ifndef JSONFRONT_FRONT$REPIDJSON_H_
#define JSONFRONT_FRONT$REPIDJSON_H_

#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

#include "./base.h"


namespace jsonfront {   


class Front4RapidJSON : public JSONBase<rapidjson::Document> {
 public:
  Front4RapidJSON() {
    this->core_.SetObject();  
  }

  Front4RapidJSON(const std::string& json_file) {
    FILE* json_fp = fopen(json_file.c_str(), "r"); 
    char readBuffer[65536];

    rapidjson::FileReadStream json_in_stream(json_fp, readBuffer, sizeof(readBuffer));
    this->core_.ParseStream(json_in_stream);
  }

  Front4RapidJSON(rapidjson::Document* source_json_obj) {
    this->core_.SetObject(); 
    doc_assign(&(this->core_), source_json_obj);
  }

  static void doc_assign(rapidjson::Document* target_json_obj, rapidjson::Document* source_json_obj) {
    rapidjson::Document::AllocatorType& target_allocator = source_json_obj->GetAllocator();
    
    for (auto iter = source_json_obj->MemberBegin(); iter != source_json_obj->MemberEnd(); ++iter) {
      rapidjson::Value key = rapidjson::Value(iter->name, target_allocator);
      rapidjson::Value val = rapidjson::Value(iter->value, target_allocator);
      target_json_obj->AddMember(key, val, target_allocator);
    }
  }

  Front4RapidJSON(rapidjson::Document& source_json_obj) : Front4RapidJSON(&source_json_obj) {}

  void print() { 
    printf("%s\n", this->get_string().c_str()); 
  }

  static std::string to_string(rapidjson::Document& source_json_obj) {
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    source_json_obj.Accept(writer);
    return buffer.GetString();
  }

  std::string get_string() {
    return to_string(this->core_);
  }
 
  rapidjson::Document get_core() {
    rapidjson::Document doc;
    doc.SetObject();
    doc_assign(&doc, &(this->core_));
    return doc;
  } 
};


} // namespace jsonfront 


#endif 

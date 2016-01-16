/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef fileservice_TYPES_H
#define fileservice_TYPES_H

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>




struct Status {
  enum type {
    FAILED = 0,
    SUCCESSFUL = 1
  };
};

extern const std::map<int, const char*> _Status_VALUES_TO_NAMES;

typedef std::string UserID;

typedef int64_t Timestamp;

typedef struct _SystemException__isset {
  _SystemException__isset() : message(false) {}
  bool message;
} _SystemException__isset;

class SystemException : public ::apache::thrift::TException {
 public:

  static const char* ascii_fingerprint; // = "66E694018C17E5B65A59AE8F55CCA3CD";
  static const uint8_t binary_fingerprint[16]; // = {0x66,0xE6,0x94,0x01,0x8C,0x17,0xE5,0xB6,0x5A,0x59,0xAE,0x8F,0x55,0xCC,0xA3,0xCD};

  SystemException() : message() {
  }

  virtual ~SystemException() throw() {}

  std::string message;

  _SystemException__isset __isset;

  void __set_message(const std::string& val) {
    message = val;
    __isset.message = true;
  }

  bool operator == (const SystemException & rhs) const
  {
    if (__isset.message != rhs.__isset.message)
      return false;
    else if (__isset.message && !(message == rhs.message))
      return false;
    return true;
  }
  bool operator != (const SystemException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SystemException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(SystemException &a, SystemException &b);


class StatusReport {
 public:

  static const char* ascii_fingerprint; // = "8BBB3D0C3B370CB38F2D1340BB79F0AA";
  static const uint8_t binary_fingerprint[16]; // = {0x8B,0xBB,0x3D,0x0C,0x3B,0x37,0x0C,0xB3,0x8F,0x2D,0x13,0x40,0xBB,0x79,0xF0,0xAA};

  StatusReport() : status((Status::type)0) {
  }

  virtual ~StatusReport() throw() {}

  Status::type status;

  void __set_status(const Status::type val) {
    status = val;
  }

  bool operator == (const StatusReport & rhs) const
  {
    if (!(status == rhs.status))
      return false;
    return true;
  }
  bool operator != (const StatusReport &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const StatusReport & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(StatusReport &a, StatusReport &b);

typedef struct _RFileMetadata__isset {
  _RFileMetadata__isset() : filename(false), created(false), updated(false), deleted(false), version(false), owner(false), contentLength(false), contentHash(false) {}
  bool filename;
  bool created;
  bool updated;
  bool deleted;
  bool version;
  bool owner;
  bool contentLength;
  bool contentHash;
} _RFileMetadata__isset;

class RFileMetadata {
 public:

  static const char* ascii_fingerprint; // = "AE509EADC6F5C652FAA107524F293698";
  static const uint8_t binary_fingerprint[16]; // = {0xAE,0x50,0x9E,0xAD,0xC6,0xF5,0xC6,0x52,0xFA,0xA1,0x07,0x52,0x4F,0x29,0x36,0x98};

  RFileMetadata() : filename(), created(0), updated(0), deleted(0), version(0), owner(), contentLength(0), contentHash() {
  }

  virtual ~RFileMetadata() throw() {}

  std::string filename;
  Timestamp created;
  Timestamp updated;
  Timestamp deleted;
  int32_t version;
  UserID owner;
  int32_t contentLength;
  std::string contentHash;

  _RFileMetadata__isset __isset;

  void __set_filename(const std::string& val) {
    filename = val;
    __isset.filename = true;
  }

  void __set_created(const Timestamp val) {
    created = val;
    __isset.created = true;
  }

  void __set_updated(const Timestamp val) {
    updated = val;
    __isset.updated = true;
  }

  void __set_deleted(const Timestamp val) {
    deleted = val;
    __isset.deleted = true;
  }

  void __set_version(const int32_t val) {
    version = val;
    __isset.version = true;
  }

  void __set_owner(const UserID& val) {
    owner = val;
    __isset.owner = true;
  }

  void __set_contentLength(const int32_t val) {
    contentLength = val;
    __isset.contentLength = true;
  }

  void __set_contentHash(const std::string& val) {
    contentHash = val;
    __isset.contentHash = true;
  }

  bool operator == (const RFileMetadata & rhs) const
  {
    if (__isset.filename != rhs.__isset.filename)
      return false;
    else if (__isset.filename && !(filename == rhs.filename))
      return false;
    if (__isset.created != rhs.__isset.created)
      return false;
    else if (__isset.created && !(created == rhs.created))
      return false;
    if (__isset.updated != rhs.__isset.updated)
      return false;
    else if (__isset.updated && !(updated == rhs.updated))
      return false;
    if (__isset.deleted != rhs.__isset.deleted)
      return false;
    else if (__isset.deleted && !(deleted == rhs.deleted))
      return false;
    if (__isset.version != rhs.__isset.version)
      return false;
    else if (__isset.version && !(version == rhs.version))
      return false;
    if (__isset.owner != rhs.__isset.owner)
      return false;
    else if (__isset.owner && !(owner == rhs.owner))
      return false;
    if (__isset.contentLength != rhs.__isset.contentLength)
      return false;
    else if (__isset.contentLength && !(contentLength == rhs.contentLength))
      return false;
    if (__isset.contentHash != rhs.__isset.contentHash)
      return false;
    else if (__isset.contentHash && !(contentHash == rhs.contentHash))
      return false;
    return true;
  }
  bool operator != (const RFileMetadata &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RFileMetadata & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(RFileMetadata &a, RFileMetadata &b);

typedef struct _RFile__isset {
  _RFile__isset() : meta(false), content(false) {}
  bool meta;
  bool content;
} _RFile__isset;

class RFile {
 public:

  static const char* ascii_fingerprint; // = "C073435743C38E100878E0BBF30AE795";
  static const uint8_t binary_fingerprint[16]; // = {0xC0,0x73,0x43,0x57,0x43,0xC3,0x8E,0x10,0x08,0x78,0xE0,0xBB,0xF3,0x0A,0xE7,0x95};

  RFile() : content() {
  }

  virtual ~RFile() throw() {}

  RFileMetadata meta;
  std::string content;

  _RFile__isset __isset;

  void __set_meta(const RFileMetadata& val) {
    meta = val;
    __isset.meta = true;
  }

  void __set_content(const std::string& val) {
    content = val;
    __isset.content = true;
  }

  bool operator == (const RFile & rhs) const
  {
    if (__isset.meta != rhs.__isset.meta)
      return false;
    else if (__isset.meta && !(meta == rhs.meta))
      return false;
    if (__isset.content != rhs.__isset.content)
      return false;
    else if (__isset.content && !(content == rhs.content))
      return false;
    return true;
  }
  bool operator != (const RFile &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const RFile & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

void swap(RFile &a, RFile &b);



#endif

/**
 * Autogenerated by Thrift Compiler (1.0.0-dev)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef DHTNode_H
#define DHTNode_H

#include <thrift/TDispatchProcessor.h>
#include "stable_chord_types.h"



class DHTNodeIf {
 public:
  virtual ~DHTNodeIf() {}
  virtual void findSucc(NodeID& _return, const std::string& key) = 0;
  virtual void findPred(NodeID& _return, const std::string& key) = 0;
  virtual void getNodeSucc(NodeID& _return) = 0;
  virtual void getNodePred(NodeID& _return) = 0;
  virtual void getFingertable(std::vector<NodeID> & _return) = 0;
  virtual void join(const NodeID& nodeId) = 0;
  virtual void stabilize() = 0;
  virtual void notify(const NodeID& nodeId) = 0;
  virtual void fixFingers() = 0;
};

class DHTNodeIfFactory {
 public:
  typedef DHTNodeIf Handler;

  virtual ~DHTNodeIfFactory() {}

  virtual DHTNodeIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(DHTNodeIf* /* handler */) = 0;
};

class DHTNodeIfSingletonFactory : virtual public DHTNodeIfFactory {
 public:
  DHTNodeIfSingletonFactory(const boost::shared_ptr<DHTNodeIf>& iface) : iface_(iface) {}
  virtual ~DHTNodeIfSingletonFactory() {}

  virtual DHTNodeIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(DHTNodeIf* /* handler */) {}

 protected:
  boost::shared_ptr<DHTNodeIf> iface_;
};

class DHTNodeNull : virtual public DHTNodeIf {
 public:
  virtual ~DHTNodeNull() {}
  void findSucc(NodeID& /* _return */, const std::string& /* key */) {
    return;
  }
  void findPred(NodeID& /* _return */, const std::string& /* key */) {
    return;
  }
  void getNodeSucc(NodeID& /* _return */) {
    return;
  }
  void getNodePred(NodeID& /* _return */) {
    return;
  }
  void getFingertable(std::vector<NodeID> & /* _return */) {
    return;
  }
  void join(const NodeID& /* nodeId */) {
    return;
  }
  void stabilize() {
    return;
  }
  void notify(const NodeID& /* nodeId */) {
    return;
  }
  void fixFingers() {
    return;
  }
};

typedef struct _DHTNode_findSucc_args__isset {
  _DHTNode_findSucc_args__isset() : key(false) {}
  bool key;
} _DHTNode_findSucc_args__isset;

class DHTNode_findSucc_args {
 public:

  DHTNode_findSucc_args() : key() {
  }

  virtual ~DHTNode_findSucc_args() throw() {}

  std::string key;

  _DHTNode_findSucc_args__isset __isset;

  void __set_key(const std::string& val) {
    key = val;
  }

  bool operator == (const DHTNode_findSucc_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const DHTNode_findSucc_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_findSucc_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DHTNode_findSucc_pargs {
 public:


  virtual ~DHTNode_findSucc_pargs() throw() {}

  const std::string* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_findSucc_result__isset {
  _DHTNode_findSucc_result__isset() : success(false), systemException(false) {}
  bool success;
  bool systemException;
} _DHTNode_findSucc_result__isset;

class DHTNode_findSucc_result {
 public:

  DHTNode_findSucc_result() {
  }

  virtual ~DHTNode_findSucc_result() throw() {}

  NodeID success;
  SystemException systemException;

  _DHTNode_findSucc_result__isset __isset;

  void __set_success(const NodeID& val) {
    success = val;
  }

  void __set_systemException(const SystemException& val) {
    systemException = val;
  }

  bool operator == (const DHTNode_findSucc_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(systemException == rhs.systemException))
      return false;
    return true;
  }
  bool operator != (const DHTNode_findSucc_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_findSucc_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_findSucc_presult__isset {
  _DHTNode_findSucc_presult__isset() : success(false), systemException(false) {}
  bool success;
  bool systemException;
} _DHTNode_findSucc_presult__isset;

class DHTNode_findSucc_presult {
 public:


  virtual ~DHTNode_findSucc_presult() throw() {}

  NodeID* success;
  SystemException systemException;

  _DHTNode_findSucc_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DHTNode_findPred_args__isset {
  _DHTNode_findPred_args__isset() : key(false) {}
  bool key;
} _DHTNode_findPred_args__isset;

class DHTNode_findPred_args {
 public:

  DHTNode_findPred_args() : key() {
  }

  virtual ~DHTNode_findPred_args() throw() {}

  std::string key;

  _DHTNode_findPred_args__isset __isset;

  void __set_key(const std::string& val) {
    key = val;
  }

  bool operator == (const DHTNode_findPred_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const DHTNode_findPred_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_findPred_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DHTNode_findPred_pargs {
 public:


  virtual ~DHTNode_findPred_pargs() throw() {}

  const std::string* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_findPred_result__isset {
  _DHTNode_findPred_result__isset() : success(false), systemException(false) {}
  bool success;
  bool systemException;
} _DHTNode_findPred_result__isset;

class DHTNode_findPred_result {
 public:

  DHTNode_findPred_result() {
  }

  virtual ~DHTNode_findPred_result() throw() {}

  NodeID success;
  SystemException systemException;

  _DHTNode_findPred_result__isset __isset;

  void __set_success(const NodeID& val) {
    success = val;
  }

  void __set_systemException(const SystemException& val) {
    systemException = val;
  }

  bool operator == (const DHTNode_findPred_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(systemException == rhs.systemException))
      return false;
    return true;
  }
  bool operator != (const DHTNode_findPred_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_findPred_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_findPred_presult__isset {
  _DHTNode_findPred_presult__isset() : success(false), systemException(false) {}
  bool success;
  bool systemException;
} _DHTNode_findPred_presult__isset;

class DHTNode_findPred_presult {
 public:


  virtual ~DHTNode_findPred_presult() throw() {}

  NodeID* success;
  SystemException systemException;

  _DHTNode_findPred_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DHTNode_getNodeSucc_args {
 public:

  DHTNode_getNodeSucc_args() {
  }

  virtual ~DHTNode_getNodeSucc_args() throw() {}


  bool operator == (const DHTNode_getNodeSucc_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DHTNode_getNodeSucc_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_getNodeSucc_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DHTNode_getNodeSucc_pargs {
 public:


  virtual ~DHTNode_getNodeSucc_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_getNodeSucc_result__isset {
  _DHTNode_getNodeSucc_result__isset() : success(false), systemException(false) {}
  bool success;
  bool systemException;
} _DHTNode_getNodeSucc_result__isset;

class DHTNode_getNodeSucc_result {
 public:

  DHTNode_getNodeSucc_result() {
  }

  virtual ~DHTNode_getNodeSucc_result() throw() {}

  NodeID success;
  SystemException systemException;

  _DHTNode_getNodeSucc_result__isset __isset;

  void __set_success(const NodeID& val) {
    success = val;
  }

  void __set_systemException(const SystemException& val) {
    systemException = val;
  }

  bool operator == (const DHTNode_getNodeSucc_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(systemException == rhs.systemException))
      return false;
    return true;
  }
  bool operator != (const DHTNode_getNodeSucc_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_getNodeSucc_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_getNodeSucc_presult__isset {
  _DHTNode_getNodeSucc_presult__isset() : success(false), systemException(false) {}
  bool success;
  bool systemException;
} _DHTNode_getNodeSucc_presult__isset;

class DHTNode_getNodeSucc_presult {
 public:


  virtual ~DHTNode_getNodeSucc_presult() throw() {}

  NodeID* success;
  SystemException systemException;

  _DHTNode_getNodeSucc_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DHTNode_getNodePred_args {
 public:

  DHTNode_getNodePred_args() {
  }

  virtual ~DHTNode_getNodePred_args() throw() {}


  bool operator == (const DHTNode_getNodePred_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DHTNode_getNodePred_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_getNodePred_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DHTNode_getNodePred_pargs {
 public:


  virtual ~DHTNode_getNodePred_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_getNodePred_result__isset {
  _DHTNode_getNodePred_result__isset() : success(false), systemException(false) {}
  bool success;
  bool systemException;
} _DHTNode_getNodePred_result__isset;

class DHTNode_getNodePred_result {
 public:

  DHTNode_getNodePred_result() {
  }

  virtual ~DHTNode_getNodePred_result() throw() {}

  NodeID success;
  SystemException systemException;

  _DHTNode_getNodePred_result__isset __isset;

  void __set_success(const NodeID& val) {
    success = val;
  }

  void __set_systemException(const SystemException& val) {
    systemException = val;
  }

  bool operator == (const DHTNode_getNodePred_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(systemException == rhs.systemException))
      return false;
    return true;
  }
  bool operator != (const DHTNode_getNodePred_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_getNodePred_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_getNodePred_presult__isset {
  _DHTNode_getNodePred_presult__isset() : success(false), systemException(false) {}
  bool success;
  bool systemException;
} _DHTNode_getNodePred_presult__isset;

class DHTNode_getNodePred_presult {
 public:


  virtual ~DHTNode_getNodePred_presult() throw() {}

  NodeID* success;
  SystemException systemException;

  _DHTNode_getNodePred_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DHTNode_getFingertable_args {
 public:

  DHTNode_getFingertable_args() {
  }

  virtual ~DHTNode_getFingertable_args() throw() {}


  bool operator == (const DHTNode_getFingertable_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DHTNode_getFingertable_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_getFingertable_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DHTNode_getFingertable_pargs {
 public:


  virtual ~DHTNode_getFingertable_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_getFingertable_result__isset {
  _DHTNode_getFingertable_result__isset() : success(false), systemException(false) {}
  bool success;
  bool systemException;
} _DHTNode_getFingertable_result__isset;

class DHTNode_getFingertable_result {
 public:

  DHTNode_getFingertable_result() {
  }

  virtual ~DHTNode_getFingertable_result() throw() {}

  std::vector<NodeID>  success;
  SystemException systemException;

  _DHTNode_getFingertable_result__isset __isset;

  void __set_success(const std::vector<NodeID> & val) {
    success = val;
  }

  void __set_systemException(const SystemException& val) {
    systemException = val;
  }

  bool operator == (const DHTNode_getFingertable_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(systemException == rhs.systemException))
      return false;
    return true;
  }
  bool operator != (const DHTNode_getFingertable_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_getFingertable_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_getFingertable_presult__isset {
  _DHTNode_getFingertable_presult__isset() : success(false), systemException(false) {}
  bool success;
  bool systemException;
} _DHTNode_getFingertable_presult__isset;

class DHTNode_getFingertable_presult {
 public:


  virtual ~DHTNode_getFingertable_presult() throw() {}

  std::vector<NodeID> * success;
  SystemException systemException;

  _DHTNode_getFingertable_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DHTNode_join_args__isset {
  _DHTNode_join_args__isset() : nodeId(false) {}
  bool nodeId;
} _DHTNode_join_args__isset;

class DHTNode_join_args {
 public:

  DHTNode_join_args() {
  }

  virtual ~DHTNode_join_args() throw() {}

  NodeID nodeId;

  _DHTNode_join_args__isset __isset;

  void __set_nodeId(const NodeID& val) {
    nodeId = val;
  }

  bool operator == (const DHTNode_join_args & rhs) const
  {
    if (!(nodeId == rhs.nodeId))
      return false;
    return true;
  }
  bool operator != (const DHTNode_join_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_join_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DHTNode_join_pargs {
 public:


  virtual ~DHTNode_join_pargs() throw() {}

  const NodeID* nodeId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_join_result__isset {
  _DHTNode_join_result__isset() : systemException(false) {}
  bool systemException;
} _DHTNode_join_result__isset;

class DHTNode_join_result {
 public:

  DHTNode_join_result() {
  }

  virtual ~DHTNode_join_result() throw() {}

  SystemException systemException;

  _DHTNode_join_result__isset __isset;

  void __set_systemException(const SystemException& val) {
    systemException = val;
  }

  bool operator == (const DHTNode_join_result & rhs) const
  {
    if (!(systemException == rhs.systemException))
      return false;
    return true;
  }
  bool operator != (const DHTNode_join_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_join_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_join_presult__isset {
  _DHTNode_join_presult__isset() : systemException(false) {}
  bool systemException;
} _DHTNode_join_presult__isset;

class DHTNode_join_presult {
 public:


  virtual ~DHTNode_join_presult() throw() {}

  SystemException systemException;

  _DHTNode_join_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DHTNode_stabilize_args {
 public:

  DHTNode_stabilize_args() {
  }

  virtual ~DHTNode_stabilize_args() throw() {}


  bool operator == (const DHTNode_stabilize_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DHTNode_stabilize_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_stabilize_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DHTNode_stabilize_pargs {
 public:


  virtual ~DHTNode_stabilize_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_stabilize_result__isset {
  _DHTNode_stabilize_result__isset() : systemException(false) {}
  bool systemException;
} _DHTNode_stabilize_result__isset;

class DHTNode_stabilize_result {
 public:

  DHTNode_stabilize_result() {
  }

  virtual ~DHTNode_stabilize_result() throw() {}

  SystemException systemException;

  _DHTNode_stabilize_result__isset __isset;

  void __set_systemException(const SystemException& val) {
    systemException = val;
  }

  bool operator == (const DHTNode_stabilize_result & rhs) const
  {
    if (!(systemException == rhs.systemException))
      return false;
    return true;
  }
  bool operator != (const DHTNode_stabilize_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_stabilize_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_stabilize_presult__isset {
  _DHTNode_stabilize_presult__isset() : systemException(false) {}
  bool systemException;
} _DHTNode_stabilize_presult__isset;

class DHTNode_stabilize_presult {
 public:


  virtual ~DHTNode_stabilize_presult() throw() {}

  SystemException systemException;

  _DHTNode_stabilize_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DHTNode_notify_args__isset {
  _DHTNode_notify_args__isset() : nodeId(false) {}
  bool nodeId;
} _DHTNode_notify_args__isset;

class DHTNode_notify_args {
 public:

  DHTNode_notify_args() {
  }

  virtual ~DHTNode_notify_args() throw() {}

  NodeID nodeId;

  _DHTNode_notify_args__isset __isset;

  void __set_nodeId(const NodeID& val) {
    nodeId = val;
  }

  bool operator == (const DHTNode_notify_args & rhs) const
  {
    if (!(nodeId == rhs.nodeId))
      return false;
    return true;
  }
  bool operator != (const DHTNode_notify_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_notify_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DHTNode_notify_pargs {
 public:


  virtual ~DHTNode_notify_pargs() throw() {}

  const NodeID* nodeId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_notify_result__isset {
  _DHTNode_notify_result__isset() : systemException(false) {}
  bool systemException;
} _DHTNode_notify_result__isset;

class DHTNode_notify_result {
 public:

  DHTNode_notify_result() {
  }

  virtual ~DHTNode_notify_result() throw() {}

  SystemException systemException;

  _DHTNode_notify_result__isset __isset;

  void __set_systemException(const SystemException& val) {
    systemException = val;
  }

  bool operator == (const DHTNode_notify_result & rhs) const
  {
    if (!(systemException == rhs.systemException))
      return false;
    return true;
  }
  bool operator != (const DHTNode_notify_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_notify_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_notify_presult__isset {
  _DHTNode_notify_presult__isset() : systemException(false) {}
  bool systemException;
} _DHTNode_notify_presult__isset;

class DHTNode_notify_presult {
 public:


  virtual ~DHTNode_notify_presult() throw() {}

  SystemException systemException;

  _DHTNode_notify_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DHTNode_fixFingers_args {
 public:

  DHTNode_fixFingers_args() {
  }

  virtual ~DHTNode_fixFingers_args() throw() {}


  bool operator == (const DHTNode_fixFingers_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DHTNode_fixFingers_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_fixFingers_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DHTNode_fixFingers_pargs {
 public:


  virtual ~DHTNode_fixFingers_pargs() throw() {}


  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_fixFingers_result__isset {
  _DHTNode_fixFingers_result__isset() : systemException(false) {}
  bool systemException;
} _DHTNode_fixFingers_result__isset;

class DHTNode_fixFingers_result {
 public:

  DHTNode_fixFingers_result() {
  }

  virtual ~DHTNode_fixFingers_result() throw() {}

  SystemException systemException;

  _DHTNode_fixFingers_result__isset __isset;

  void __set_systemException(const SystemException& val) {
    systemException = val;
  }

  bool operator == (const DHTNode_fixFingers_result & rhs) const
  {
    if (!(systemException == rhs.systemException))
      return false;
    return true;
  }
  bool operator != (const DHTNode_fixFingers_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DHTNode_fixFingers_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DHTNode_fixFingers_presult__isset {
  _DHTNode_fixFingers_presult__isset() : systemException(false) {}
  bool systemException;
} _DHTNode_fixFingers_presult__isset;

class DHTNode_fixFingers_presult {
 public:


  virtual ~DHTNode_fixFingers_presult() throw() {}

  SystemException systemException;

  _DHTNode_fixFingers_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class DHTNodeClient : virtual public DHTNodeIf {
 public:
  DHTNodeClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  DHTNodeClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void findSucc(NodeID& _return, const std::string& key);
  void send_findSucc(const std::string& key);
  void recv_findSucc(NodeID& _return);
  void findPred(NodeID& _return, const std::string& key);
  void send_findPred(const std::string& key);
  void recv_findPred(NodeID& _return);
  void getNodeSucc(NodeID& _return);
  void send_getNodeSucc();
  void recv_getNodeSucc(NodeID& _return);
  void getNodePred(NodeID& _return);
  void send_getNodePred();
  void recv_getNodePred(NodeID& _return);
  void getFingertable(std::vector<NodeID> & _return);
  void send_getFingertable();
  void recv_getFingertable(std::vector<NodeID> & _return);
  void join(const NodeID& nodeId);
  void send_join(const NodeID& nodeId);
  void recv_join();
  void stabilize();
  void send_stabilize();
  void recv_stabilize();
  void notify(const NodeID& nodeId);
  void send_notify(const NodeID& nodeId);
  void recv_notify();
  void fixFingers();
  void send_fixFingers();
  void recv_fixFingers();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class DHTNodeProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<DHTNodeIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (DHTNodeProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_findSucc(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_findPred(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getNodeSucc(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getNodePred(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getFingertable(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_join(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_stabilize(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_notify(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_fixFingers(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  DHTNodeProcessor(boost::shared_ptr<DHTNodeIf> iface) :
    iface_(iface) {
    processMap_["findSucc"] = &DHTNodeProcessor::process_findSucc;
    processMap_["findPred"] = &DHTNodeProcessor::process_findPred;
    processMap_["getNodeSucc"] = &DHTNodeProcessor::process_getNodeSucc;
    processMap_["getNodePred"] = &DHTNodeProcessor::process_getNodePred;
    processMap_["getFingertable"] = &DHTNodeProcessor::process_getFingertable;
    processMap_["join"] = &DHTNodeProcessor::process_join;
    processMap_["stabilize"] = &DHTNodeProcessor::process_stabilize;
    processMap_["notify"] = &DHTNodeProcessor::process_notify;
    processMap_["fixFingers"] = &DHTNodeProcessor::process_fixFingers;
  }

  virtual ~DHTNodeProcessor() {}
};

class DHTNodeProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  DHTNodeProcessorFactory(const ::boost::shared_ptr< DHTNodeIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< DHTNodeIfFactory > handlerFactory_;
};

class DHTNodeMultiface : virtual public DHTNodeIf {
 public:
  DHTNodeMultiface(std::vector<boost::shared_ptr<DHTNodeIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~DHTNodeMultiface() {}
 protected:
  std::vector<boost::shared_ptr<DHTNodeIf> > ifaces_;
  DHTNodeMultiface() {}
  void add(boost::shared_ptr<DHTNodeIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void findSucc(NodeID& _return, const std::string& key) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->findSucc(_return, key);
    }
    ifaces_[i]->findSucc(_return, key);
    return;
  }

  void findPred(NodeID& _return, const std::string& key) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->findPred(_return, key);
    }
    ifaces_[i]->findPred(_return, key);
    return;
  }

  void getNodeSucc(NodeID& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getNodeSucc(_return);
    }
    ifaces_[i]->getNodeSucc(_return);
    return;
  }

  void getNodePred(NodeID& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getNodePred(_return);
    }
    ifaces_[i]->getNodePred(_return);
    return;
  }

  void getFingertable(std::vector<NodeID> & _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getFingertable(_return);
    }
    ifaces_[i]->getFingertable(_return);
    return;
  }

  void join(const NodeID& nodeId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->join(nodeId);
    }
    ifaces_[i]->join(nodeId);
  }

  void stabilize() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->stabilize();
    }
    ifaces_[i]->stabilize();
  }

  void notify(const NodeID& nodeId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->notify(nodeId);
    }
    ifaces_[i]->notify(nodeId);
  }

  void fixFingers() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->fixFingers();
    }
    ifaces_[i]->fixFingers();
  }

};



#endif

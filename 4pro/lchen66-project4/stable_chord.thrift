typedef string UserID
typedef i64 Timestamp

exception SystemException {
  1: optional string message
}

struct NodeID {
  1: string id;
  2: string ip;
  3: i32 port;
  4: optional i32 count;
}

service DHTNode {

  NodeID findSucc(1: string key) throws (1: SystemException systemException),
  NodeID findPred(1: string key) throws (1: SystemException systemException),
  NodeID getNodeSucc() throws (1: SystemException systemException),
  NodeID getNodePred() throws (1: SystemException systemException),
  
  list<NodeID> getFingertable() throws (1: SystemException systemException),

  void join(1: NodeID nodeId) throws (1: SystemException systemException),
  void stabilize() throws (1: SystemException systemException),
  
  void notify(1: NodeID nodeId) throws (1: SystemException systemException),
  void fixFingers() throws (1: SystemException systemException),

}

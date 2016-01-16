typedef string UserID
typedef i64 Timestamp

exception SystemException {
  1: optional string message
}

struct RFileMetadata {
  1: optional string filename;
  2: optional Timestamp created;
  3: optional Timestamp updated;
  4: optional Timestamp deleted;
  5: optional i32 version;
  6: optional UserID owner;
  7: optional i32 contentLength;
  8: optional string contentHash;
}

struct RFile {
  1: optional RFileMetadata meta;
  2: optional string content;
}

struct NodeID {
  1: string id;
  2: string ip;
  3: i32 port;
  4: optional i32 count;
}

service FileStore {
  void writeFile(1: RFile rFile)
    throws (1: SystemException systemException),
  
  RFile readFile(1: string filename, 2: UserID owner)
    throws (1: SystemException systemException),

  void deleteFile(1: string filename, 2: UserID owner)
    throws (1: SystemException systemException),

  NodeID findSucc(1: string key) throws (1: SystemException systemException),
  NodeID findPred(1: string key) throws (1: SystemException systemException),
  NodeID getNodeSucc() throws (1: SystemException systemException),
  void setNodePred(1: NodeID nodeId) throws (1: SystemException systemException),

  void updateFinger(1: i32 idx, 2: NodeID nodeId) throws (1: SystemException systemException),
  list<NodeID> getFingertable() throws (1: SystemException systemException),

  list<RFile> pullUnownedFiles() throws (1: SystemException systemException),
  void pushUnownedFiles(1: list<RFile> files) throws (1: SystemException systemException),

  void join(1: NodeID nodeId) throws (1: SystemException systemException),
  void remove() throws (1: SystemException systemException),

}

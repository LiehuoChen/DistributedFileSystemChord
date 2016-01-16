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
}

service FileStore {
  void writeFile(1: RFile rFile)
    throws (1: SystemException systemException),
  
  RFile readFile(1: string filename, 2: UserID owner)
    throws (1: SystemException systemException),

  void deleteFile(1: string filename, 2: UserID owner)
    throws (1: SystemException systemException),

  void setFingertable(1: list<NodeID> node_list),
  
  NodeID findSucc(1: string key) throws (1: SystemException systemException),
  NodeID findPred(1: string key) throws (1: SystemException systemException),
  NodeID getNodeSucc() throws (1: SystemException systemException),

}

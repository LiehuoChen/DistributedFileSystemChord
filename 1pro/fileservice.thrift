typedef string UserID
typedef i64 Timestamp

exception SystemException {
  1: optional string message
}

enum Status {
  FAILED = 0;
  SUCCESSFUL = 1;
}

struct StatusReport {
  1: required Status status;
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

service FileStore {
  list<RFileMetadata> listOwnedFiles(1: UserID user)
    throws (1: SystemException systemException),
      
  StatusReport writeFile(1: RFile rFile)
    throws (1: SystemException systemException),
  
  RFile readFile(1: string filename, 2: UserID owner)
    throws (1: SystemException systemException),

  StatusReport deleteFile(1: string filename, 2: UserID owner)
    throws (1: SystemException systemException),
}

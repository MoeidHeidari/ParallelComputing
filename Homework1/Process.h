//
// Created by Moeid Heidari on 3/16/20.
//

#include <unistd.h>
#include <stdio.h>
#include <ostream>
#include<iostream>

#ifndef HOMWWORK1_PROCESS_H
#define HOMWWORK1_PROCESS_H


class Process{

private:
    pid_t m_Process_Id=0;
    pid_t m_Parent_Process_Id=0;
    uid_t m_User_Id=0;
    gid_t m_Group_Id=0;
public:
    pid_t getMProcessId() const;

    void setMProcessId(pid_t mProcessId);

    uid_t getMUserId() const;

    void setMUserId(uid_t mUserId);

    gid_t getMGroupId() const;

    void setMGroupId(gid_t mGroupId);

    pid_t getMParentProcessId() const;

    void setMParentProcessId(pid_t mParentProcessId);

    Process(pid_t mProcessId, uid_t mUserId, gid_t mGroupId,pid_t mParentProcessId);

    Process();

    virtual ~Process();

    bool operator==(const Process &rhs) const;

    bool operator!=(const Process &rhs) const;

    bool operator<(const Process &rhs) const;

    bool operator>(const Process &rhs) const;

    bool operator<=(const Process &rhs) const;

    bool operator>=(const Process &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Process &process);

    Process* createNewChild();
    void printProcess(void);


};


#endif //HOMWWORK1_PROCESS_H

//
// Created by Moeid Heidari on 3/16/20.
//

#include "Process.h"

pid_t Process::getMProcessId() const {
    return m_Process_Id;
}

void Process::setMProcessId(pid_t mProcessId) {
    m_Process_Id = mProcessId;
}

uid_t Process::getMUserId() const {
    return m_User_Id;
}

void Process::setMUserId(uid_t mUserId) {
    m_User_Id = mUserId;
}

gid_t Process::getMGroupId() const {
    return m_Group_Id;
}

void Process::setMGroupId(gid_t mGroupId) {
    m_Group_Id = mGroupId;
}

Process::Process(pid_t mProcessId, uid_t mUserId, gid_t mGroupId,pid_t mParentProcessId) : m_Process_Id(mProcessId), m_User_Id(mUserId),
                                                                    m_Group_Id(mGroupId),m_Parent_Process_Id(mParentProcessId) {

}

std::ostream &operator<<(std::ostream &os, const Process &process) {
    os << "m_Process_Id: " << process.m_Process_Id << " m_User_Id: " << process.m_User_Id << " m_Group_Id: "
       << process.m_Group_Id << "m_Parent_Process_Id"<<process.m_Parent_Process_Id;
    return os;
}

bool Process::operator<(const Process &rhs) const {
    if (m_Process_Id < rhs.m_Process_Id)
        return true;
    if (rhs.m_Process_Id < m_Process_Id)
        return false;
    if (m_User_Id < rhs.m_User_Id)
        return true;
    if (rhs.m_User_Id < m_User_Id)
        return false;
    if (rhs.m_Parent_Process_Id < m_Parent_Process_Id)
        return false;
    return m_Group_Id < rhs.m_Group_Id;
}

bool Process::operator>(const Process &rhs) const {
    return rhs < *this;
}

bool Process::operator<=(const Process &rhs) const {
    return !(rhs < *this);
}

bool Process::operator>=(const Process &rhs) const {
    return !(*this < rhs);
}

Process::Process()
{
    m_Process_Id = fork();
    m_User_Id=getuid();
    m_Group_Id=getgid();
    m_Parent_Process_Id=getppid();
    this->printProcess();
}


bool Process::operator==(const Process &rhs) const {
    return m_Process_Id == rhs.m_Process_Id &&
           m_User_Id == rhs.m_User_Id &&
           m_Group_Id == rhs.m_Group_Id &&
           m_Parent_Process_Id==rhs.m_Parent_Process_Id;

}

bool Process::operator!=(const Process &rhs) const {
    return !(rhs == *this);
}

Process *Process::createNewChild() {
    Process *process;
    try {
        process=new Process();

    }catch (const char* message)
    {
        throw "Wrong process Id";
    }


    return process;
}

Process::~Process() {

}

pid_t Process::getMParentProcessId() const {
    return m_Parent_Process_Id;
}

void Process::setMParentProcessId(pid_t mParentProcessId) {
    m_Parent_Process_Id = mParentProcessId;
}

void Process::printProcess(void)
{
    std::cout<<"processId:"<<this->getMProcessId()<<std::endl;
    std::cout<<"parentProcessId:"<<this->getMParentProcessId()<<std::endl;
    std::cout<<"userId:"<<this->getMUserId()<<std::endl;
    std::cout<<"groupId:"<<this->getMGroupId()<<std::endl;
}

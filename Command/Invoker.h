#ifndef INVOKER_H
#define INVOKER_H
#include "Command.h"
#include <vector>
#include <queue>
class Invoker {
    
private:
    std :: queue<Command*> commandQueue;
public:
    void addCommand(Command* c) { commandQueue.push(c); }

    void processCommands() {
        while (!commandQueue.empty()) {
            Command* cmd = commandQueue.front();
            commandQueue.pop();
            cmd->execute();
        }
    }
};

#endif

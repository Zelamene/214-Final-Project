#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <iostream>

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() { std :: cout << "(Undo not implemented)\n"; }
    virtual ~Command() = default;
};

#endif
#ifndef SIMPLEPLATFORMER_COMMANDQUEUE_H
#define SIMPLEPLATFORMER_COMMANDQUEUE_H

#include <vector>
#include "ScoreManager.h"

enum class Command
{
    PickUpCollectable,
};

class CommandQueue
{
public:
    static std::vector<Command> commands;

    static void Dispatch(Command command);

    static void Process();
};

#endif //SIMPLEPLATFORMER_COMMANDQUEUE_H

#include "CommandQueue.h"

std::vector<Command> CommandQueue::commands;

void CommandQueue::Dispatch(Command command)
{
    CommandQueue::commands.push_back(command);
}

void CommandQueue::Process()
{
    for (auto &command: CommandQueue::commands)
    {
        switch (command)
        {
            case Command::PickUpCollectable:
                ScoreManager::GetInstance().AddScore(10);
                break;
        }
    }

    CommandQueue::commands.clear();
}

#include "Utilities.h"

bool Utilities::isValidPaper(const std::vector<paper> &papers, const std::string &paperCode)
{
    for (const auto &paper : papers)
    {
        if (paper.getPaperCode() == paperCode)
            return true;
    }
    return false;
}
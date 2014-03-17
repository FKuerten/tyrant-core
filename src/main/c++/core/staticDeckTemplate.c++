#include "staticDeckTemplate.h++"

namespace Tyrant {
    namespace Core {

        StaticDeckTemplate::StaticDeckTemplate()
        {}

        StaticDeckTemplate::~StaticDeckTemplate() {}

        unsigned int
        StaticDeckTemplate::getCommanderId() const
        {
            return this->commanderId;
        }

        bool
        StaticDeckTemplate::equals2(DeckTemplate const & rhs) const
        {
            if (StaticDeckTemplate const * rhs2 =
                dynamic_cast<StaticDeckTemplate const *>
                    (&rhs)
               )
            {
                return this->equals2(*rhs2);
            } else {
                return false;
            }
        }

        bool
        StaticDeckTemplate::equals2(StaticDeckTemplate const & rhs) const
        {
            return DeckTemplate::equals2(rhs)
                && this->commanderId == rhs.commanderId;
        }

    }
}


#include "deckTemplate.h++"

namespace Tyrant {
    namespace Core {

        DeckTemplate::DeckTemplate()
        {}

        DeckTemplate::~DeckTemplate() {}

        bool
        DeckTemplate::equals(DeckTemplate const & rhs) const
        {
            // Same object
            if (this == &rhs) {
                return true;
            }
            if (typeid(*this) == typeid(rhs)) {
                return this->equals2(rhs);
            }
            return false;
        }

        bool
        DeckTemplate::equals2(DeckTemplate const & rhs) const
        {
            return true;
        }

        bool
        operator==(DeckTemplate const & lhs, DeckTemplate const & rhs)
        {
            return lhs.equals(rhs);
        }

        bool
        operator!=(DeckTemplate const & lhs, DeckTemplate const & rhs)
        {
            return !(lhs == rhs);
        }

        size_t
        hash_value
            (Tyrant::Core::DeckTemplate const & deck
            )
        {
            return deck.hashCode();
        }

    }
}

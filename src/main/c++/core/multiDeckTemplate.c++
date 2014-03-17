#include "multiDeckTemplate.h++"
#include <sstream>
#include <boost/functional/hash.hpp>

namespace Tyrant {
    namespace Core {

        MultiDeckTemplate::MultiDeckTemplate(
            std::multiset<DeckTemplate::Ptr> const & decks
            )
        : decks(decks)
        {
        }

        MultiDeckTemplate::operator std::string() const
        {
            std::stringstream ssString;
            for(DeckTemplate::Ptr const & deck: this->decks) {
                ssString << '{';
                ssString << static_cast<std::string>(*deck);
                ssString << '}';
                ssString << ';';
            }
            return ssString.str();
        }

        std::multiset<DeckTemplate::Ptr> const &
        MultiDeckTemplate::getDecks() const
        {
            return this->decks;
        }

        CREATE_VISITOR_METHOD(MultiDeckTemplate)

        bool
        MultiDeckTemplate::equals2(DeckTemplate const & rhs) const
        {
            if (MultiDeckTemplate const * rhs2 =
                dynamic_cast<MultiDeckTemplate const *>
                    (&rhs)
               )
            {
                return this->equals2(*rhs2);
            } else {
                return false;
            }
        }

        bool
        MultiDeckTemplate::equals2(MultiDeckTemplate const & rhs) const
        {
            return DeckTemplate::equals2(rhs)
                && this->decks == rhs.decks;
        }

        size_t
        MultiDeckTemplate::hashCode() const
        {
            size_t result = 0;
            boost::hash_range(result, this->decks.begin(), this->decks.end());
            return result;
        }

    }
}

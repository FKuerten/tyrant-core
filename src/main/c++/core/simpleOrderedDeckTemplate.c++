#include "simpleOrderedDeckTemplate.h++"
#include <errorHandling/assert.h++>
#include <iterator>
#include <boost/functional/hash.hpp>

namespace Tyrant {
    namespace Core {

        SimpleOrderedDeckTemplate::SimpleOrderedDeckTemplate(unsigned int commanderId, std::vector<unsigned int> const & cardIds)
        : StaticDeckTemplate()
        {
            this->commanderId = commanderId;
            for(unsigned int cardId : cardIds) {
                this->cards.push_back(cardId);
            }
        }

        SimpleOrderedDeckTemplate::SimpleOrderedDeckTemplate(std::list<unsigned int> const & ids)
        : StaticDeckTemplate()
        {
            std::list<unsigned int>::const_iterator iter = ids.begin();
            unsigned int const commanderId = *iter;
            this->commanderId = commanderId;
            for(iter++ ;iter != ids.end(); iter++) {
                unsigned int cardId = *iter;
                this->cards.push_back(cardId);
            }
        }

        SimpleOrderedDeckTemplate::operator std::string() const
        {
            std::stringstream ssString;
            ssString << "ORDERED_IDS:";
            ssString << this->commanderId;
            for(unsigned int cardId : this->cards) {
                ssString << ",";
                ssString << cardId;
            }
            return ssString.str();
        }

        CREATE_VISITOR_METHOD(SimpleOrderedDeckTemplate)

        Tyrant::Core::StaticDeckTemplate::Ptr
        SimpleOrderedDeckTemplate::withCommander(unsigned int commanderId) const
        {
            SimpleOrderedDeckTemplate::Ptr copy(new SimpleOrderedDeckTemplate(*this));
            copy->commanderId = commanderId;
            return copy;
        }

        size_t
        SimpleOrderedDeckTemplate::getNumberOfNonCommanderCards() const
        {
            return this->cards.size();
        }

        unsigned int
        SimpleOrderedDeckTemplate::getCardIdAtIndex(size_t index) const
        {
            return this->cards[index];
        }

        Tyrant::Core::StaticDeckTemplate::Ptr
        SimpleOrderedDeckTemplate::withCard(unsigned int cardId) const
        {
            SimpleOrderedDeckTemplate::Ptr copy(new SimpleOrderedDeckTemplate(*this));
            copy->cards.push_back(cardId);
            return copy;
        }

        Tyrant::Core::StaticDeckTemplate::Ptr
        SimpleOrderedDeckTemplate::withCardAtIndex(unsigned int cardId, size_t index) const
        {
            SimpleOrderedDeckTemplate::Ptr copy(new SimpleOrderedDeckTemplate(*this));
            ListType::iterator iter = copy->cards.begin();
            std::advance(iter, index);
            copy->cards.insert(iter,cardId);
            return copy;
        }

        Tyrant::Core::StaticDeckTemplate::Ptr
        SimpleOrderedDeckTemplate::withoutCardAtIndex(size_t index) const
        {
            SimpleOrderedDeckTemplate::Ptr copy(new SimpleOrderedDeckTemplate(*this));
            ListType::iterator iter = copy->cards.begin();
            std::advance(iter, index);
            copy->cards.erase(iter);
            return copy;
        }

        Tyrant::Core::StaticDeckTemplate::Ptr
        SimpleOrderedDeckTemplate::withSwappedCards(size_t i, size_t j) const
        {
            assertLE(static_cast<size_t>(0u),i);
            assertLE(static_cast<size_t>(0u),j);
            assertLT(i, this->cards.size());
            assertLT(j, this->cards.size());
            SimpleOrderedDeckTemplate::Ptr copy(new SimpleOrderedDeckTemplate(*this));
            copy->cards[i] = this->cards[j];
            copy->cards[j] = this->cards[i];
            return copy;
        }

        Tyrant::Core::StaticDeckTemplate::Ptr
        SimpleOrderedDeckTemplate::withReplacedCardAtIndex(unsigned int cardId, size_t index) const
        {
            SimpleOrderedDeckTemplate::Ptr copy(new SimpleOrderedDeckTemplate(*this));
            copy->cards[index] = cardId;
            return copy;
        }

        bool
        operator< (SimpleOrderedDeckTemplate const & a
                  ,SimpleOrderedDeckTemplate const & b
                  )
        {
            if (a.commanderId < b.commanderId) {
                return true;
            } else if (a.commanderId > b.commanderId) {
                return false;
            } else {
                assertEQ(a.commanderId, b.commanderId);
                return a.cards < b.cards;
            }
        }

        bool
        SimpleOrderedDeckTemplate::equals2(StaticDeckTemplate const & rhs) const
        {
            if (SimpleOrderedDeckTemplate const * rhs2 =
                dynamic_cast<SimpleOrderedDeckTemplate const *>
                    (&rhs)
               )
            {
                return this->equals2(*rhs2);
            } else {
                return false;
            }
        }

        bool
        SimpleOrderedDeckTemplate::equals2(SimpleOrderedDeckTemplate const & rhs) const
        {
            return StaticDeckTemplate::equals2(rhs)
                && this->cards == rhs.cards;
        }

        size_t
        SimpleOrderedDeckTemplate::hashCode() const
        {
            size_t result = 0;
            boost::hash_combine(result, this->commanderId);
            boost::hash_range(result, this->cards.begin(), this->cards.end());
            return result;
        }

    }
}

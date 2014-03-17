#include "questDeckTemplate.h++"
#include <boost/lexical_cast.hpp>
#include <boost/functional/hash.hpp>

namespace Tyrant {
    namespace Core {

        QuestDeckTemplate::QuestDeckTemplate(unsigned int questId)
        : questId(questId)
        {
        }

        QuestDeckTemplate::operator std::string() const
        {
            return "QUESTID:" + boost::lexical_cast<std::string>(this->questId);
        }

        CREATE_VISITOR_METHOD(QuestDeckTemplate)

        bool
        QuestDeckTemplate::equals2(DeckTemplate const & rhs) const
        {
            if (QuestDeckTemplate const * rhs2 =
                dynamic_cast<QuestDeckTemplate const *>
                    (&rhs)
               )
            {
                return this->equals2(*rhs2);
            } else {
                return false;
            }
        }

        bool
        QuestDeckTemplate::equals2(QuestDeckTemplate const & rhs) const
        {
            return DeckTemplate::equals2(rhs)
                && this->questId == rhs.questId;
        }

        size_t
        QuestDeckTemplate::hashCode() const
        {
            size_t result = 0;
            boost::hash_combine(result, this->questId);
            return result;
        }

    }
}

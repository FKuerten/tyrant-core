#include "raidDeckTemplate.h++"
#include <boost/lexical_cast.hpp>
#include <boost/functional/hash.hpp>

namespace Tyrant {
    namespace Core {

        RaidDeckTemplate::RaidDeckTemplate(unsigned int raidId)
        : raidId(raidId)
        {
        }

        RaidDeckTemplate::operator std::string() const
        {
            return "RAIDID:" + boost::lexical_cast<std::string>(this->raidId);
        }

        CREATE_VISITOR_METHOD(RaidDeckTemplate)

        bool
        RaidDeckTemplate::equals2(DeckTemplate const & rhs) const
        {
            if (RaidDeckTemplate const * rhs2 =
                dynamic_cast<RaidDeckTemplate const *>
                    (&rhs)
               )
            {
                return this->equals2(*rhs2);
            } else {
                return false;
            }
        }

        bool
        RaidDeckTemplate::equals2(RaidDeckTemplate const & rhs) const
        {
            return DeckTemplate::equals2(rhs)
                && this->raidId == rhs.raidId;
        }

        size_t
        RaidDeckTemplate::hashCode() const
        {
            size_t result = 0;
            boost::hash_combine(result, this->raidId);
            return result;
        }
    }
}

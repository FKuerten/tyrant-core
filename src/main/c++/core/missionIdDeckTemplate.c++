#include "missionIdDeckTemplate.h++"
#include <boost/lexical_cast.hpp>
#include <boost/functional/hash.hpp>

namespace Tyrant {
    namespace Core {

        MissionIdDeckTemplate::MissionIdDeckTemplate(unsigned int missionId)
        : missionId(missionId)
        {
        }

        MissionIdDeckTemplate::operator std::string() const
        {
            return "MISSIONID:" + boost::lexical_cast<std::string>(this->missionId);
        }

        CREATE_VISITOR_METHOD(MissionIdDeckTemplate)

        bool
        MissionIdDeckTemplate::equals2(DeckTemplate const & rhs) const
        {
            if (MissionIdDeckTemplate const * rhs2 =
                dynamic_cast<MissionIdDeckTemplate const *>
                    (&rhs)
               )
            {
                return this->equals2(*rhs2);
            } else {
                return false;
            }
        }

        bool
        MissionIdDeckTemplate::equals2(MissionIdDeckTemplate const & rhs) const
        {
            return DeckTemplate::equals2(rhs)
                && this->missionId == rhs.missionId;
        }

        size_t
        MissionIdDeckTemplate::hashCode() const
        {
            size_t result = 0;
            boost::hash_combine(result, this->missionId);
            return result;
        }

    }
}

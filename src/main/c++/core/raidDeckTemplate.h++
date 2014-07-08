#ifndef TYRANT_CORE_RAIDDECKTEMPLATE_HPP
    #define TYRANT_CORE_RAIDDECKTEMPLATE_HPP

#include <memory>
#include "deckTemplate.h++"

namespace Tyrant {
    namespace Core {

        class RaidDeckTemplate : public DeckTemplate {
        public:
            typedef std::shared_ptr<RaidDeckTemplate> Ptr;
            CREATE_VISITOR_INTERFACE(RaidDeckTemplate);

        protected:
            virtual bool equals2(DeckTemplate const & rhs) const;
            virtual bool equals2(RaidDeckTemplate const & rhs) const;
            virtual size_t hashCode() const;

        public:
            unsigned int raidId;

        public:
            RaidDeckTemplate(unsigned int raidId);
            operator std::string() const;

            virtual void accept(Praetorian::Basics::Visitor::AcyclicVisitor & visitor) const;
        };
    }
}


#endif

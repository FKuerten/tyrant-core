#ifndef TYRANT_CORE_QUESTDECKTEMPLATE_HPP
    #define TYRANT_CORE_QUESTDECKTEMPLATE_HPP

#include <memory>
#include "deckTemplate.h++"

namespace Tyrant {
    namespace Core {

        class QuestDeckTemplate : public DeckTemplate {
        public:
            typedef std::shared_ptr<QuestDeckTemplate> Ptr;
            CREATE_VISITOR_INTERFACE(QuestDeckTemplate);
        public:
            unsigned int questId;

        protected:
            virtual bool equals2(DeckTemplate const & rhs) const;
            virtual bool equals2(QuestDeckTemplate const & rhs) const;
            virtual size_t hashCode() const;

        public:
            QuestDeckTemplate(unsigned int questId);
            operator std::string() const;

            virtual void accept(Praetorian::Basics::Visitor::AcyclicVisitor & visitor) const;
        };
    }
}


#endif

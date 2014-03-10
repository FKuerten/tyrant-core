#ifndef TYRANT_CORE_MULTIDECKTEMPLATE_HPP
    #define TYRANT_CORE_MULTIDECKTEMPLATE_HPP

    #include <memory>
    #include <set>
    #include "deckTemplate.h++"

    namespace Tyrant {
        namespace Core {

            class MultiDeckTemplate : public DeckTemplate {
                public:
                    typedef std::shared_ptr<MultiDeckTemplate> Ptr;
                    typedef std::shared_ptr<MultiDeckTemplate const> ConstPtr;
                    CREATE_VISITOR_INTERFACE(MultiDeckTemplate);
                private:
                    std::multiset<DeckTemplate::Ptr> decks;
                public:
                    MultiDeckTemplate(std::multiset<DeckTemplate::Ptr> const & decks);
                    virtual operator std::string() const;

                    virtual void accept(Praetorian::Basics::Visitor::AcyclicVisitor & visitor) const;

                    std::multiset<DeckTemplate::Ptr> const & getDecks() const;

            };

        }
    }
#endif


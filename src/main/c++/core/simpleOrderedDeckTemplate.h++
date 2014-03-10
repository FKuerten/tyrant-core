#ifndef TYRANT_CACHE_CLI_SIMPLEORDEREDDECKTEMPLATE_HPP
    #define TYRANT_CACHE_CLI_SIMPLEORDEREDDECKTEMPLATE_HPP

    #include <memory>
    #include <list>
    #include <vector>
    #include "staticDeckTemplate.h++"
    #include <visitor/acyclicVisitor.h++>

    namespace Tyrant {
        namespace Core {

            class SimpleOrderedDeckTemplate : public StaticDeckTemplate {
                public:
                    typedef std::shared_ptr<SimpleOrderedDeckTemplate> Ptr;
                    CREATE_VISITOR_INTERFACE(SimpleOrderedDeckTemplate);
                public:
                    std::list<unsigned int> cards;
                public:
                    SimpleOrderedDeckTemplate(unsigned int commanderId, std::vector<unsigned int> const & cardIds);
                    SimpleOrderedDeckTemplate(std::list<unsigned int> const & ids);
                    virtual operator std::string() const;

                    virtual void accept(Praetorian::Basics::Visitor::AcyclicVisitor & visitor) const;

                    virtual unsigned int getNumberOfNonCommanderCards() const;
                    virtual unsigned int getCardIdAtIndex(unsigned int index) const;
                    virtual StaticDeckTemplate::Ptr withCommander(unsigned int commanderId) const;
                    virtual StaticDeckTemplate::Ptr withoutCardAtIndex(unsigned int index) const;
                    virtual StaticDeckTemplate::Ptr withSwappedCards(size_t i, size_t j) const;
                    virtual StaticDeckTemplate::Ptr withCard(unsigned int cardId) const;
                    virtual StaticDeckTemplate::Ptr withCardAtIndex(unsigned int cardId , size_t index) const;
                    virtual StaticDeckTemplate::Ptr withReplacedCardAtIndex(unsigned int cardId, size_t index) const;

                    friend bool operator< (SimpleOrderedDeckTemplate const & a, SimpleOrderedDeckTemplate const & b);
            };

            bool operator< (SimpleOrderedDeckTemplate const & a, SimpleOrderedDeckTemplate const & b);
        }
    }

#endif
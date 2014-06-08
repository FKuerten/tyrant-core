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
                private: // type
                    typedef std::vector<unsigned int> ListType;

                public:
                    typedef std::shared_ptr<SimpleOrderedDeckTemplate> Ptr;
                    CREATE_VISITOR_INTERFACE(SimpleOrderedDeckTemplate);
                public:
                    ListType cards;

                protected:
                    virtual bool equals2(StaticDeckTemplate const & rhs) const;
                    virtual bool equals2(SimpleOrderedDeckTemplate const & rhs) const;
                    virtual size_t hashCode() const;

                public:
                    SimpleOrderedDeckTemplate(unsigned int commanderId, std::vector<unsigned int> const & cardIds);
                    SimpleOrderedDeckTemplate(std::list<unsigned int> const & ids);
                    virtual operator std::string() const;

                    virtual void accept(Praetorian::Basics::Visitor::AcyclicVisitor & visitor) const;

                    virtual size_t getNumberOfNonCommanderCards() const;
                    virtual unsigned int getCardIdAtIndex(size_t index) const;
                    virtual StaticDeckTemplate::Ptr withCommander(unsigned int commanderId) const;
                    virtual StaticDeckTemplate::Ptr withoutCardAtIndex(size_t index) const;
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

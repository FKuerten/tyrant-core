#ifndef TYRANT_CACHE_CORE_AUTODECKTEMPLATE_HPP
    #define TYRANT_CACHE_CORE_AUTODECKTEMPLATE_HPP

    #include <memory>
    #include <set>
    #include <list>
    #include <vector>
    #include "staticDeckTemplate.h++"

    namespace Tyrant {
        namespace Core {

            class AutoDeckTemplate : public StaticDeckTemplate {
                public:
                    typedef std::shared_ptr<AutoDeckTemplate> Ptr;
                    CREATE_VISITOR_INTERFACE(AutoDeckTemplate);
                public:
                    std::multiset<unsigned int> cards;

                protected:
                    virtual bool equals2(StaticDeckTemplate const & rhs) const;
                    virtual bool equals2(AutoDeckTemplate const & rhs) const;
                    virtual size_t hashCode() const;

                public:
                    AutoDeckTemplate(unsigned int commanderId, std::vector<unsigned int> const & cardIds);
                    AutoDeckTemplate(std::list<unsigned int> const & ids);
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

                    friend bool operator< (AutoDeckTemplate const & a, AutoDeckTemplate const & b);
            };

            bool operator< (AutoDeckTemplate const & a, AutoDeckTemplate const & b);

        }
    }
#endif

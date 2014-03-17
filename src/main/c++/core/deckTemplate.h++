#ifndef TYRANT_CACHE_CORE_DECKTEMPLATE_HPP
    #define TYRANT_CACHE_CORE_DECKTEMPLATE_HPP

    #include <string>
    #include <memory>
    #include <visitor/acyclicVisitor.h++>
    #include <boost/functional/hash_fwd.hpp>

    namespace Tyrant {
        namespace Core {

            class DeckTemplate {
                public:
                    typedef std::shared_ptr<DeckTemplate> Ptr;
                    typedef std::shared_ptr<DeckTemplate const> ConstPtr;

                protected:
                    DeckTemplate();

                    bool equals(DeckTemplate const & rhs) const;
                    virtual bool equals2(DeckTemplate const & rhs) const = 0;
                    virtual size_t hashCode() const = 0;

                public:
                    virtual ~DeckTemplate();
                    virtual operator std::string() const = 0;

                    /**
                     * Visitor stuff.
                     * We use the acyclic visitor pattern.
                     */
                    virtual void accept(Praetorian::Basics::Visitor::AcyclicVisitor & visitor) const = 0;


                friend bool operator==(DeckTemplate const &, DeckTemplate const &);
                friend class std::hash<DeckTemplate>;
                friend size_t hash_value(DeckTemplate const &);
            };

            bool operator==(DeckTemplate const & a, DeckTemplate const & b);
            bool operator!=(DeckTemplate const & a, DeckTemplate const & b);

            size_t hash_value
                (Tyrant::Core::DeckTemplate const & deck
                );
        }
    }

    namespace std {
        template<>
        struct hash<Tyrant::Core::DeckTemplate> {
            inline size_t operator()
                (Tyrant::Core::DeckTemplate const & deck
                ) const
            {
                return deck.hashCode();
            }
        };
    }

#endif

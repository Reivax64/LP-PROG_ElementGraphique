#ifndef ELEMENTACTIVABLE_H
#define ELEMENTACTIVABLE_H


class ElementActivable
{
    public:
        ElementActivable();
        ElementActivable(bool);
        ElementActivable(const ElementActivable&);
        virtual ~ElementActivable();

        virtual ElementActivable& operator=(const ElementActivable&);
        virtual bool operator==(const ElementActivable&);

        bool isActivated() const;
        void SetisActivated(bool);
        virtual void afficher();

    protected:

    private:
        bool m_isActivated;
};

#endif // ELEMENTACTIVABLE_H

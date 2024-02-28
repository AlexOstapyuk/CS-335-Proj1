/*
 Alex Ostapyuk
 CS 335
 Project 1
 */


#include "Book.hpp"

    // write and document all methods in this file.
    Book::Book()
    {
        setTitle("");
        setAuthor("");
        setISBN(0);
        setIcon(nullptr);
        setPrice(0);
        setKeywords({});
        setBlurb("");
    }

    Book::~Book()
    {
        delete[] icon_;
    }

    Book::Book(const Book& rhs)
    {
        setTitle(rhs.getTitle());
        setAuthor(rhs.getAuthor());
        setISBN(rhs.getISBN());
        //setIcon(rhs.getIcon());

       const int* rhsIcon=rhs.getIcon();
       if(rhsIcon!= nullptr){
           icon_=new int(*rhsIcon);
       }else{
           icon_=nullptr;
       }
        setPrice(rhs.getPrice());
        setKeywords(rhs.getKeywords());
        setBlurb(rhs.getBlurb());
    }

    Book& Book::operator=(const Book& rhs)
    {
        if(this!=&rhs){
            delete[] icon_;
            setTitle(rhs.getTitle());
            setAuthor(rhs.getAuthor());
            setISBN(rhs.getISBN());
            const int* rhsIcon=rhs.getIcon();
            if(rhsIcon!= nullptr){
                icon_=new int(*rhsIcon);
            }else{
                icon_=nullptr;
            }
            setPrice(rhs.getPrice());
            setKeywords(rhs.getKeywords());
            setBlurb(rhs.getBlurb());
        }
        return *this;
    }
//move constructor
    Book::Book(Book&& rhs)
    {
    title_=std::move(rhs.title_);
    author_ = std::move(rhs.author_);
    ISBN_ = rhs.ISBN_;
    icon_ = rhs.icon_;
    price_ = rhs.price_;
    keywords_ = std::move(rhs.keywords_);
    blurb_ = std::move(rhs.blurb_);
    rhs.setTitle("");
    rhs.setAuthor("");
    rhs.setISBN(0);
    rhs.setIcon(nullptr);
    rhs.setPrice(0);
    rhs.setKeywords({});
    rhs.setBlurb("");

    }

    Book& Book::operator=(Book&& rhs)
    {
        if(this!=&rhs){
            delete[] icon_;
            title_=std::move(rhs.title_);
            author_ = std::move(rhs.author_);
            ISBN_ =rhs.ISBN_;
            icon_ = rhs.icon_;
            price_ = rhs.price_;
            keywords_ = std::move(rhs.keywords_);
            blurb_ = std::move(rhs.blurb_);
            rhs.setTitle("");
            rhs.setAuthor("");
            rhs.setISBN(0);
            rhs.setIcon(nullptr);
            rhs.setPrice(0);
            rhs.setKeywords({});
            rhs.setBlurb("");
        }
        return *this;
    }

    const std::string& Book::getTitle() const
    {
        return title_;
    }

    void Book::setTitle(const std::string& title)
    {
        title_ = title;
    }

    const std::string& Book::getAuthor() const
    {
        return author_;
    }

    void Book::setAuthor(const std::string& author)
    {
        author_ = author;
    }

    long long int Book::getISBN() const
    {
        return ISBN_;
    }

    void Book::setISBN(long long int ISBN)
    {
        ISBN_ = ISBN;
    }

    const int* Book::getIcon() const
    {
        return icon_;
    }

    void Book::setIcon(int* icon)
    {
        //delete[] icon_;

        if(icon != nullptr){
            icon_ = icon;
        }
        else{
            icon_ = nullptr;
        }
    }

    float Book::getPrice() const
    {
        return price_;
    }

    void Book::setPrice(float price)
    {
        price_ = price;
    }

    const std::vector<std::string>& Book::getKeywords() const
    {
        return keywords_;
    }

    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
        keywords_ = keywords;
    }

    const std::string& Book::getBlurb() const
    {
        return blurb_;
    }

    void Book::setBlurb(const std::string& blurb)
    {
        blurb_ = blurb;
    }

    void Book::print() const
    {
        std::cout << "Title: " << getTitle() << "\nAuthor: " << getAuthor() << "\nISBN: " << getISBN() << std::endl;
        const int* icon= getIcon();
        std::cout<< "Icon: ";
//        while(icon != nullptr){
//            std::cout << *icon << " ";
//            ++icon;
//        }
std::cout<<"/////////////////";
//        for(int i=0;i<80;i++){
//            std::cout<<icon_[i]<<" ";
//        }
        std::cout<<*icon<<std::endl;
        icon++;
        std::cout<<*icon<<std::endl;
        std::cout<<"///////////////////";
        std:: cout<< "\nPrice: $" << std::setprecision(4) << getPrice() << "\n";
        const std::vector<std::string>& keywords=getKeywords();
        std::cout<< "Keywords: ";
//        for(const auto& keyword: keywords ){
//            std::cout << keyword << ", ";
//        }
        for(int i=0; i<keywords.size(); i++){
            if(i != keywords.size()-1){
                std::cout << keywords[i] << ", ";
            }
            else{
                std::cout << keywords[i];
            }
        }
        std::cout << "\nBlurb: " << getBlurb() << std::endl << std::endl;
    }
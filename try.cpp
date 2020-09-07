#include <list>
#include <iostream>
#include <string>


class My {

    private:
    std::list < std::pair<std::string, std::string> > _container;

    public:
    My() {
        std::cout << "My created." << std::endl;
        this->containerManager();
    }

    virtual ~My() {
        std::cout << "My destroyed." << std::endl;
    }

    void containerManager() {
        std::cout << "Size of _container = " << this->_container.size() << std::endl;
        this->containerAddElement(std::pair<std::string, std::string>("John", "Gray"));
        this->containerAddElement(std::pair<std::string, std::string>("William", "Blue"));
        this->containerAddElement(std::pair<std::string, std::string>("Charles", "Green"));
        std::cout << "Size of _container = " << this->_container.size() << std::endl << std::endl;
        this->containerDisplayElements();
        this->containerUseFirstElement();
        this->containerDisplayElements();
        this->containerUseFirstElement();
        this->containerDisplayElements();
    }

    void containerAddElement(std::pair<std::string, std::string> myPair) {
        std::cout << "Adding \"" << myPair.first << "\" and \"" << myPair.second << "\" in _container." << std::endl;
        this->_container.push_back(std::pair<std::string, std::string>(myPair.first, myPair.second));
    }

    void containerDisplayElements() {
        int k;
        std::list < std::pair<std::string, std::string > >::iterator it;

        k = 0;
        for (it = _container.begin(); it != _container.end(); ++it) {
            std::cout << "*it " << k << " = " << (*it).first << " - " << (*it).second << std::endl;
            ++k;
        }
        std::cout << "First element in _container = " << this->_container.front().first << " - " << this->_container.front().second << std::endl << std::endl;
    }

    void containerUseFirstElement() {
        std::cout << "Pop!" << std::endl;
        this->_container.pop_front();
    }
};


int main() {
    My *my = new My();

    delete my;

    while (1337);
    return 0;
}
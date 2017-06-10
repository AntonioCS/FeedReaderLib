#ifndef XMLNODE_H
#define XMLNODE_H

#include <string>
#include <functional> //function
#include <iostream>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <iostream>

namespace AcsFeedReader {

    class XMLNode {
        xmlNodePtr nptr = nullptr;
    public:
        class Iterator;
        /*
        class Iterator {
            XMLNode &mEle;
        public:

            Iterator(XMLNode ele) : mEle(ele) {
                std::cout << "CHAMADO!!!\n";
            }

            Iterator &operator++() {
                mEle = mEle.getNext();
                return *this;
            }

            XMLNode &operator*() {
                return mEle;
            }

            bool operator==(const Iterator &other) {
                return (mEle == other.mEle);
            }

            bool operator!=(const Iterator &other) {
                return !this->operator==(other);

            }
        };
*/
        
        XMLNode(const xmlNodePtr n) : nptr(n) {
        }

        //copy constructor

        XMLNode(const XMLNode &orig) : nptr(orig.nptr) {
        }

        ~XMLNode() {
        }

        std::string getContent() const noexcept;

        void iterateChildren(std::function<bool(XMLNode&) > func) const noexcept;

        operator bool() const {//user-defined conversion operator
            return !isNull();
        }

        bool isNull() const noexcept {
            return (nptr == nullptr);
        }

        bool isBlank() const noexcept {
            //http://www.xmlsoft.org/html/libxml-tree.html#xmlIsBlankNode
            return (xmlIsBlankNode(nptr) == 1);
        }

        std::string getName() const noexcept {
            return nptr ? std::string(reinterpret_cast<const char*> (nptr->name)) : std::string{};
        }

        XMLNode getChildrenNode() const noexcept {
            return {nptr->xmlChildrenNode};
        }

        XMLNode getNext() const noexcept {
            return {(nptr->next)};
        }

        Iterator begin() {
            return Iterator(getChildrenNode());
        }

        Iterator end() {
            return Iterator(nullptr);
        }
    };

}
#endif /* XMLNODE_H */


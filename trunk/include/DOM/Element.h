// This file is part of XmlPlus package
// 
// Copyright (C)   2010   Satya Prakash Tripathi
//
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include "DOM/DOMCommonInc.h"
#include "DOM/Node.h"

namespace DOM
{
  class Element : public Node 
  {
  protected:
    const DOMStringPtr        _tagName;

    // buffer used at DOM statful building, eg. reading xml file, to accumalate
    // fragments of text
    DOMString                 _textBufferOnDocBuild;
    bool                      _isCDATA;

  public:

    Element(
        DOMString* tagName,
        DOMString* nsURI=NULL,
        DOMString* nsPrefix=NULL,
        Document* ownerDocument=NULL,
        Node* parentNode=NULL,
        Node* prevSibling=NULL,
        Node* nextSibling=NULL
        );

    virtual ~Element() {}
    
    virtual const DOMString* getTagName() const {
      return _tagName;
    }

    inline void resetTextBufferOnDocBuild() {
      _textBufferOnDocBuild = "";
    }
    inline void addTextBufferOnDocBuild(DOMString str) {
      _textBufferOnDocBuild += str;
    }
    inline DOMString getTextBufferOnDocBuild() {
      return _textBufferOnDocBuild;
    }

    inline bool markTextBufferAsCDATA() {
      _isCDATA = true;
    }
    inline bool unmarkTextBufferAsCDATA() {
      _isCDATA = false;
    }
    inline bool isTextBufferCDATA() {
      return _isCDATA;
    }

    virtual const DOMString* getAttribute(DOMString* name);
    virtual void setAttribute(DOMString* name,
                              DOMString* value); // throws();
    virtual void removeAttribute(DOMString* name); // throws();
    virtual AttributeP getAttributeNode(DOMString* name);
    virtual AttributeP setAttributeNode(Attribute* newAttr); // throws();
    virtual AttributeP removeAttributeNode(AttributeP oldAttr); // throws();
    virtual NodeList* getElementsByTagName(DOMString* name);

        // Introduced in DOM Level 2:
    virtual const DOMString* getAttributeNS(DOMString* namespaceURI,
                                     DOMString* localName);
    virtual void setAttributeNS(DOMString* namespaceURI,
                                DOMString* qualifiedName,
                                DOMString* value); // throws();
    virtual void removeAttributeNS(DOMString* namespaceURI,
                                   DOMString* localName); // throws();
    virtual AttributeP getAttributeNodeNS(DOMString* namespaceURI,
                                            DOMString* localName);
    virtual AttributeP setAttributeNodeNS(AttributeP newAttr); // throws();
    virtual NodeList*  getElementsByTagNameNS(DOMString* namespaceURI,
                                              DOMString* localName);
    virtual bool hasAttribute(DOMString* name);
    virtual bool hasAttributeNS(DOMString* namespaceURI,
                                DOMString* localName);

  };

}

#endif
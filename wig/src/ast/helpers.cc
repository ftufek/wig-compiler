#include "helpers.h"

using namespace std;

namespace ast {

Base *wrapAround(string name, map<string, string> *attrs,
                      List *exp){
    Base *opening = new HtmlTag(name, attrs);
    Base *closing = new HtmlTag(name,
                                     emptyMap(),
                                     true);
    exp->getList()->push_front(opening);
    exp->getList()->push_back(closing);
    return exp;
}


Base *wrapHtml(List *exp){
    return wrapAround("html", emptyMap(), exp);
}

map<string, string> *emptyMap(){
    return new map<string, string>;
}

map<string, string> *initMap(string key, string val){
    map<string, string> *a = emptyMap();
    a->insert(pair<string, string>(key, val));
    return a;
}

map<string, string> *mergeMap(map<string, string> *m1,
                              map<string, string> *m2){
    m1->insert(m2->begin(), m2->end());
    return m1;
}

List *initList(Base *e){
    List *l = new List();
    l->getList()->push_front(e);
    return l;
}

List *addBack(List *list, Base *exp){
    list->getList()->push_back(exp);
    return list;
}

}
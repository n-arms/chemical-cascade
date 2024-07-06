#ifndef system_h
#define system_h

#include <functional>
#include <iostream>
#include "entity_list.h"

template<typename Query>
void run(Query query, std::function<void(typename Query::Result)> perEntity, entity_list &el) {
  for (auto entity : el.entities) {
    if (query.matches(el, entity)) {
      perEntity(query.use(el, entity));
    }  
  }
}

#endif
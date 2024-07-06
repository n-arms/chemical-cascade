#ifndef all_h
#define all_h

#include "entity.h"
#include "entity_list.h"

template<typename First, typename... Rest>
struct all {
  using Result = std::tuple<First, Rest...>;

  bool matches(entity_list &el, entity e) {
    return matches_all(*this, el, e);
  }

  Result use(entity_list &el, entity e) {
    return use_all(*this, el, e);
  }
};

template<typename First, typename Second, typename... Rest>
bool matches_all(all<First, Second, Rest...> query, entity_list &el, entity e) {
  all<Second, Rest...> rest;
  auto first = e.has_component(el.component_id<First>());
  return first && matches_all<Second, Rest...>(rest, el, e);
}

template<typename First>
bool matches_all(all<First> query, entity_list &el, entity e) {
  auto first = e.has_component(el.component_id<First>());
  return first;
}

template<typename First, typename Second, typename... Rest>
std::tuple<First, Second, Rest...> use_all(all<First, Second, Rest...> query, entity_list &el, entity e) {
  all<Second, Rest...> rest_query;
  std::tuple<Second, Rest...> rest = use_all(rest_query, el, e);
  auto maybeComponent = el.get<First>(e.id);
  if (!maybeComponent.has_value()) {
    std::cout << "Query `matches_all` function is wrong" << std::endl;
    exit(1);
  }
  First component = *maybeComponent;
  return std::tuple_cat(std::make_tuple(component), rest);
}

template<typename First>
std::tuple<First> use_all(all<First> query, entity_list &el, entity e) {
  auto maybeComponent = el.get<First>(e.id);
  if (!maybeComponent.has_value()) {
    std::cout << "Query `matches_all` function is wrong" << std::endl;
    exit(1);
  }
  First component = *maybeComponent;
  return std::make_tuple(component);
}

#endif
#include "Filter.h"
#include "../Exceptions.h"

#include <utility>
#include <sstream>

std::string add_alias(const std::string& alias, std::string fieldName) {
    if (alias.empty()) {
        return fieldName;
    } else {
        return alias + "." + add_alias("", fieldName);
    }
}

ANDFilter::ANDFilter(std::vector<std::shared_ptr<Filter>> filters) : filters(std::move(filters)) { }

std::string ANDFilter::getRepresentation(std::string alias) {
    std::stringstream ss;

    for (int i = 0; i < filters.size(); i++) {
        ss << filters[i]->getRepresentation(alias);
        if (i < filters.size() - 1) {
            ss << " AND ";
        }
    }

    return ss.str();
}

CompareFilter::CompareFilter(std::string  fieldName, std::string  value, std::string compare_operator)
: fieldName(std::move(fieldName)), value(std::move(value)), compare_operator(std::move(compare_operator)) { }

std::string CompareFilter::getRepresentation(std::string alias = "") {
    return add_alias(alias, fieldName) + " " + compare_operator + " " + value;
}

BetweenFilter::BetweenFilter(std::string  fieldName, int min, int max) : fieldName(std::move(fieldName)), min(min), max(max) {}

std::string BetweenFilter::getRepresentation(std::string alias) {
    std::stringstream ss;
    ss << add_alias(alias, fieldName) << " BETWEEN " << min << " AND " << max;
    return ss.str();
}

NOTFilter::NOTFilter(std::string fieldName, shared_ptr<Filter> filter)
: fieldName(std::move(fieldName)), filter(std::move(filter)) {}

std::string NOTFilter::getRepresentation(std::string alias) {
    return add_alias(alias, fieldName) + " NOT " + filter->getRepresentation(alias);
}

IsNotNullFilter::IsNotNullFilter(std::string fieldName) : fieldName(std::move(fieldName)) { }

std::string IsNotNullFilter::getRepresentation(std::string alias) {
    return add_alias(alias, fieldName) + " IS NOT NULL";
}

NotLikeFilter::NotLikeFilter(std::string fieldName, std::string value)
: fieldName(std::move(fieldName)), value(std::move(value)) { }

std::string NotLikeFilter::getRepresentation(std::string alias) {
    return add_alias(alias, fieldName) + " NOT LIKE " + value;
}

NotInFilter::NotInFilter(std::string fieldName, std::string value)
: fieldName(std::move(fieldName)), value(std::move(value)) { }

std::string NotInFilter::getRepresentation(std::string alias) {
    return add_alias(alias, fieldName) + " NOT IN " + value;
}

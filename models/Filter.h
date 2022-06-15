#pragma once

#include <string>
#include <vector>
#include <memory>

class Filter {
public:
    virtual std::string getRepresentation(std::string alias) = 0;
};

class ANDFilter : public Filter {
public:
    explicit ANDFilter(std::vector<std::shared_ptr<Filter>>  filters);
    std::string getRepresentation(std::string alias) override;
private:
    std::vector<std::shared_ptr<Filter>> filters;
};

class ORFilter : public Filter {
public:
    explicit ORFilter(std::vector<std::shared_ptr<Filter>>  filters);
    std::string getRepresentation(std::string alias) override;
private:
    std::vector<std::shared_ptr<Filter>> filters;
};

class CompareFilter : public Filter {
public:
    CompareFilter(std::string  fieldName, std::string  value, std::string compare_operator);
    std::string getRepresentation(std::string alias) override;
private:
    std::string fieldName;
    std::string value;
    std::string compare_operator;
};

class BetweenFilter : public Filter {
public:
    BetweenFilter(std::string  fieldName, int min, int max);
    std::string getRepresentation(std::string alias) override;
private:
    std::string fieldName;
    int min;
    int max;
};

class NOTFilter : public Filter {
public:
    NOTFilter(std::string fieldName, std::shared_ptr<Filter> filter);
    std::string getRepresentation(std::string alias) override;
private:
    std::string fieldName;
    std::shared_ptr<Filter> filter;
};

class IsNotNullFilter : public Filter {
public :
    explicit IsNotNullFilter(std::string fieldName);
    std::string getRepresentation(std::string alias) override;
private:
    std::string fieldName;
};

class NotLikeFilter : public Filter {
public :
    explicit NotLikeFilter(std::string fieldName, std::string value);
    std::string getRepresentation(std::string alias) override;
private:
    std::string fieldName;
    std::string value;
};

class NotInFilter : public Filter {
public :
    explicit NotInFilter(std::string fieldName, std::string value);
    std::string getRepresentation(std::string alias) override;
private:
    std::string fieldName;
    std::string value;
};



#include <iostream>
#include "DBWorker.h"
#include "Exceptions.h"
#include "models/DwellingManager.h"
#include "models/PersonInQueueManager.h"
#include "models/QueueDwelling.h"

using namespace std;


int testDBWorker() {
    cout << "Test DBWorker" << endl;
    string sql = "SELECT * from person;";
    DBWorker *worker = DBWorker::getInstance();
    auto result = worker->execute(sql);
    for (auto &row: result) {
        for (auto &col: row) {
            cout << col << " ";
        }
        cout << endl;
    }

    result.clear();
    vector<vector<string> >().swap(result);

    sql = "INSERT INTO person (name, birth_date, sex) VALUES ('Test Name', '1980-05-31', 'Female');";
    result = worker->execute(sql);
    for (auto &row: result) {
        for (auto &col: row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << "inserted row" << endl;

    result.clear();
    vector<vector<string> >().swap(result);

    string maxID = worker->execute("SELECT max(id) FROM person;")[0][0];

    sql = "DELETE FROM person WHERE id = " + maxID + ";";
    result = worker->execute(sql);
    for (auto &row: result) {
        for (auto &col: row) {
            cout << col << " ";
        }
        cout << endl;
    }

    cout << "deleted row" << endl;


    result.clear();
    vector<vector<string> >().swap(result);


    cout << "\n\n\n\n";

    return 0;
}

int testDwellingManager() {
    cout << "Test DwellingManager" << "\n\n";

    cout << "getList()" << endl;
    for (auto dwelling: DwellingManager().getList()) {
        cout << dwelling->pk << " " << dwelling->address << " " << dwelling->rooms << endl;
    }
    cout << "\n\n\n\n";
    return 0;
}

int testPersonInQueueManager() {
    PersonInQueueManager personInQueueManager;
    cout << "Test PersonInQueueManager" << "\n\n";

    cout << "getList()" << endl;
    for (auto i: personInQueueManager.getList()) {
        cout << i->person->name << i->dwelling  << endl;
    }
    cout << endl;

    cout << "get()" << endl;
    PersonInQueue* a = personInQueueManager.get(personInQueueManager.getList()[0]->pk);
    cout << a->person->name << " " << a->dwelling << " " << a->person->birthDate->toRepresentation() << endl;
    cout << endl;

    cout << "save()" << endl;
    Person* p = PersonManager().get(2);
    Dwelling* d = DwellingManager().get(1);
    auto* pq = new PersonInQueue(new Date(2022, 06, 01), p, true, d);
    pq = pq->save();
    if (!PersonInQueueManager().get(p->pk)->pk) {
        throw Exception("PersonInQueue not created");
    }
    cout << "saved " << pq->person->name << " " << pq->dwelling->address << " "
    << pq->person->birthDate->toRepresentation() << endl;
    cout << endl;

    cout << "remove()" << endl;
    PersonInQueueManager().get(2)->remove();
    try {
        PersonInQueueManager().get(2);
    } catch (Exception &e) {
        cout << "removed successfully" << endl;
    }
    cout << endl;

    cout << "\n\n\n\n";
    return 0;
}

int filterTest() {
    PersonInQueueManager personInQueueManager;

    /*
    personInQueueManager.filterTest(new ANDFilter(vector<std::shared_ptr<Filter>>{
        make_shared<BetweenFilter>("Age", 3, 5),
        make_shared<CompareFilter>("Price", "40", "< "),
        make_shared<CompareFilter>("Price", "10", ">"),
        make_shared<IsNotNullFilter>("name"),
        make_shared<NOTFilter>("temperature", make_shared<BetweenFilter>("", 10, 30)),
        make_shared<NotLikeFilter>("House", "o%"),
        make_shared<NotInFilter>("City", "('Kharkiv', 'Lviv', 'Kyiv')")
    }));
    */

    vector<PersonInQueue*> personInQueue = personInQueueManager.filter(new ANDFilter(vector<std::shared_ptr<Filter>>{
            make_shared<CompareFilter>("added_date", "'2022-05-01'", ">"),
    }));

    for (auto p : personInQueue) {
        std::cout << p->pk << " " << p->dateAdded->toRepresentation() << " " << std::endl;
    }

    return 0;
}

int testDate() {
    Date date(2020, 1, 29);
    stringstream ss;

    ss.clear();
    Date date1(1, 9, 3);

    date -= date1;
    ss << date;
    cout << ss.str();
    return 0;
}

int testQueueDwelling() {
    QueueDwelling queueDwelling;

    for (const auto& person : queueDwelling) {
        cout << person.dateAdded->toRepresentation() << endl;
    }

    return 0;
}

int runTests() {
    /*
    testDBWorker();
    testDwellingManager();
    testPersonInQueueManager();
    filterTest();
    testQueueDwelling();
     */
    testDate();


    return 0;
}

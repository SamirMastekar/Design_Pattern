#include <iostream>
#include <thread>
#include <mutex>

//Simple Class
class Logger {
    static int count;
public:
    Logger() {
        count++;
        std::cout << "New Instance is created:- " << count << std::endl;
    }
    void LogMessage(std::string msg) {
        std::cout << msg << std::endl;
    }
};

int Logger::count = 0;

int main1() {
    Logger* obj1 = new Logger();
    obj1->LogMessage("Samir");

    Logger* obj2 = new Logger();
    obj2->LogMessage("Pratiksha");

    return 0;
}


//Singleton Class, but it will fail in Multi-threading
class Log {
    static int cnt;
    static Log *logInstance;
public:
    Log() {
        cnt++;
        std::cout << "New Instance is created:- " << cnt << std::endl;
    }

    static Log* GetInstance() {
        if (logInstance == NULL)
            logInstance = new Log();
        return logInstance;
    }

    void GetLogMessage(std::string msg) {
        std::cout << msg << std::endl;
    }
};

Log* Log::logInstance = NULL;
int Log::cnt = 0;

int main2() {
    Log* obj1 = Log::GetInstance();
    obj1->GetLogMessage("Samir");

    Log* obj2 = Log::GetInstance();
    obj2->GetLogMessage("Pratikasha");

    return 0;
}


class LogInMultiThread {
    static int cnCount;
    static LogInMultiThread* logInst;
    static std::mutex mtx;
public:
    LogInMultiThread() {
        cnCount++;
        std::cout << "New Instance is created:- " << cnCount << std::endl;
    }

    /*To avoid copying of object and assigning one object to another
      we can delete the copy constructor and assignment operator */

    LogInMultiThread(const LogInMultiThread& obj) = delete;
    LogInMultiThread operator =(const LogInMultiThread obj) = delete;

    static LogInMultiThread* GetInstance() {
        //mtx.lock();                  // Log are expensive, we can use lock when instance of class is NULL
        //if (logInst == NULL)
        //    logInst = new LogInMultiThread();
        //mtx.unlock();

        if (logInst == NULL) {
            mtx.lock();
            if (logInst == NULL)
                logInst = new LogInMultiThread();
            mtx.unlock();
        }
        return logInst;
    }

    void GetLogMessage(std::string msg) {
        std::cout << msg << std::endl;
    }
};

void UserLog1() {
    LogInMultiThread* obj1 = LogInMultiThread::GetInstance();
    obj1->GetLogMessage("I am user 1");
}

void UserLog2() {
    LogInMultiThread* obj1 = LogInMultiThread::GetInstance();
    obj1->GetLogMessage("I am user 2");
}


LogInMultiThread* LogInMultiThread::logInst = NULL;
std::mutex LogInMultiThread::mtx;
int LogInMultiThread::cnCount = 0;

int main() {
    std::thread t1(UserLog1);
    std::thread t2(UserLog2);

    t1.join();
    t2.join();

    LogInMultiThread obj1;
    LogInMultiThread obj2;
    //obj2 = obj1;    // Copy will not possible due to delete of Copy Constructor and assignment operator
    return 0;
}

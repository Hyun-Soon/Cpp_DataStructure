#include <string>
#include <iostream>
#include <unordered_map>

struct URLService
{
    using ActualURL = std::string;
    using TinyURL = std::string;

private:
    std::unordered_map<TinyURL, ActualURL> data;

public:
    std::pair<bool, ActualURL> lookup(const TinyURL& url) const
    {
        auto it = data.find(url);
        if (it == data.end())
        {
            return std::make_pair(false, std::string());
        }
        else
        {
            return std::make_pair(true, it->second);
        }
    }

    bool registerURL(const ActualURL& actualURL, const TinyURL& tinyURL)
    {
        auto found = lookup(tinyURL).first;
        if (found)
        {
            return false;
        }

        data[tinyURL] = actualURL;
        return true;
    }

    bool deregisterURL(const TinyURL& tinyURL)
    {
        auto found = lookup(tinyURL).first;
        if (found)
        {
            data.erase(tinyURL);
            return true;
        }

        return false;
    }

    void printURLs() const
    {
        for (const auto& entry : data)
        {
            std::cout << entry.first << " -> " << entry.second << std::endl;
        }
        std::cout << std::endl;
    }
    
};

int main()
{
    URLService service;

    if (service.registerURL("https://www.giilbut.co.kr/book/view?bookcode=BN002245", "https://py_dojang"))
    {
        std::cout << "https://py_dojang 등록" << std::endl;
    }
    else
    {
        std::cout << "https://py_dojang 등록 실패" << std::endl;
    }

    auto cppBook = service.lookup("https://cpp_dojang");
    if (cppBook.first)
    {
        std::cout << "https://cpp_dojang 원본 URL : " << cppBook.second << std::endl;
    }
    else
    {
        std::cout << "https://cpp_dojang 원본 URL을 찾을 수 없습니다." << std::endl;
    }

    if (service.deregisterURL("https://c_dojang"))
    {
        std::cout << "c_dojang 책 URL 등록 해제" << std::endl;
    }
    else
    {
        std::cout << "c_dojang 책 URL 등록 해제 실패" << std::endl;
    }
    
    std::cout << "등록된 URL 리스트 : " << std::endl;
    service.printURLs();
}
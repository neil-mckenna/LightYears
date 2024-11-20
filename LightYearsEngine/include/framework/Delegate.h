#pragma once

#include <functional>
#include "framework/Core.h"
#include "framework/Object.h"

using namespace std;

namespace ly
{
    class Object;

    template<typename... Args>
    class Delegate
    {
    public:
        template<typename ClassName>
        void BindAction(shared<Object> obj, void(ClassName::* callback)(Args...))
        {
            LOG("Bind Action Called");
            // Store the shared_ptr, which will automatically manage the lifetime
            function<bool(Args...)> callbackFunc = [obj, callback](Args... args)->bool
                {
                    // No need to check for expired here; shared_ptr manages lifetime
                    (static_cast<ClassName*>(obj.get())->*callback)(args...);
                    LOG("True");
                    return true;
                };

            m_Callbacks.push_back(callbackFunc);
        }

        void Broadcast(Args... args) {
            LOG("Broadcast Called");
            LOG("Callback Count: %d", (int)m_Callbacks.size());

            for (auto iter = m_Callbacks.begin(); iter != m_Callbacks.end();) {
                if ((*iter)(args...)) {
                    ++iter;
                }
                else {
                    iter = m_Callbacks.erase(iter);
                }
            }
        }


    private:
        vector<function<bool(Args...)>> m_Callbacks;
    };




}
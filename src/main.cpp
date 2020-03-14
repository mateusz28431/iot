#include <iostream>
#include <mosquitto.h>
#include <thread>

int main()
{
    mosquitto_lib_init();
    mosquitto* mqtt = mosquitto_new("client_01", true, nullptr);

    int result = mosquitto_connect(mqtt, "192.168.1.1", 8883, 10);

    if(MOSQ_ERR_SUCCESS == result)
    {
        std::cout << "Mqtt client successfully contected to broker" << std::endl;
    }

    int msgId = 0;

    while(result == MOSQ_ERR_SUCCESS)
    {
        std::string msg(std::string("Message ") + std::to_string(msgId++));
        std::cout << "Sending message: "<<  msg << std::endl;
        result = mosquitto_publish(mqtt, nullptr, "test_topic", msg.size(), msg.c_str(), 0, false);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    mosquitto_destroy(mqtt);
    return 0;
}
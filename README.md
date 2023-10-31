# Slave_Read_Master_Dsplay
Interfacing Microcontrollers for Temperature Monitoring

The project involves the integration of two microcontrollers, namely the Master and the Slave, to facilitate temperature monitoring using an LM35 sensor. The Slave microcontroller is responsible for reading the temperature values from the LM35 sensor at regular intervals, while the Master microcontroller controls the overall operation and displays the temperature readings on its LCD screen.

The Slave microcontroller is equipped with an LM35 sensor, which is a precision temperature sensor capable of accurately measuring ambient temperature. The Slave microcontroller reads the temperature value from the LM35 sensor continuously. It then waits for an interrupt signal from the Master microcontroller.

On the other hand, the Master microcontroller initiates the communication by sending an interrupt signal every 5 seconds to the Slave microcontroller. Upon receiving the interrupt signal, the Slave microcontroller responds by transmitting the temperature reading it obtained from the LM35 sensor to the Master microcontroller.

The Master microcontroller, upon receiving the temperature value from the Slave, processes the data and displays the temperature reading on its LCD screen. The LCD screen serves as a user interface, providing a convenient and easily readable display of the current temperature.

This project demonstrates the intercommunication between two microcontrollers to achieve temperature monitoring functionality. By leveraging the LM35 sensor and the interrupt-based communication mechanism, the system ensures regular and accurate temperature readings. The LCD display on the Master microcontroller enhances user interaction and enables real-time temperature monitoring in a user-friendly manner.

Overall, the project showcases the capability of microcontrollers to collaborate and exchange data, enabling efficient and precise temperature monitoring in various applications such as environmental control systems, industrial processes, or home automation systems.

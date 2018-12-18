#pragma once

#include <functional>
#include <string>
#include <boost/asio.hpp>
#include<boost/bind.hpp>
#include <boost/thread.hpp>

using boost::asio::ip::tcp;

namespace CraftWorld {
	/**
	 * Used to connect to, and exchange data with, a Server.
	 */
	class Client {
			/**
			 * The socket used to transmit data.
			 */
			tcp::socket socket_;
			bool write = true;
                        int ID;

		public:
			/**
			 * Creates a new Client.
			 * @param host The host of the Server to connect to.
			 * @param port The port of the Server to connect to.
			 */
			Client(const std::string& host, const int& port, int ID);

			/**
			 * Receives data and keeps looping.
			 */
			void readLoop(const std::function<void(const std::string&)>& dataHandler);

			/**
			 * Writes data and keeps looping.
			 */
			void writeLoop();

			/**
			 * Starts communication with the Server.
			 * @param dataHandler The function that will handle incoming data.
			 */
			void run(const std::function<void(const std::string&)>& dataHandler);
	};
}

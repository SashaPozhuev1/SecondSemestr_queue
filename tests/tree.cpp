#include <catch.hpp>
#include <sstream>
#include <cassert>

#include "queue.hpp"

TEST_CASE("creating queue")
{
	queue_t<int> queue;
	REQUIRE( queue.heads() == nullptr);
	REQUIRE( queue.tails() == nullptr);
}

TEST_CASE("push queue")
{
	std::string input{ "1 2 3 \n" };
	
	queue_t<int> queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	
	std::ostringstream ostream;
	queue.print(ostream);
	REQUIRE( input == ostream.str() );
}


TEST_CASE("pop queue")
{
	queue_t<double> queue;
	queue.push(1.1);
	queue.push(2.2);
	queue.push(3.3);
	
	REQUIRE( queue.pop() == 1.1 );
	REQUIRE( queue.pop() == 2.2 );
	REQUIRE( queue.pop() == 3.3 );
}

TEST_CASE("error queue")
{
	queue_t<double> queue;
	queue.push(1.1);
	queue.push(2.2);
	queue.push(3.3);
	
	queue.pop();
	queue.pop();
	queue.pop();
	
	 REQUIRE_THROWS_AS( queue.pop(), std::logic_error );
}

TEST_CASE(" = queue")
{
	std::string input{ "1 2 3 \n" };
	queue_t<double> queue1;
	queue_t<double> queue2;
	
	queue1.push(1);
	queue1.push(2);
	queue1.push(3);
	
	queue2.push(3);
	
	queue2 = queue1;
	
	std::ostringstream ostream;
	queue2.print(ostream);
	REQUIRE( input == ostream.str() );
}

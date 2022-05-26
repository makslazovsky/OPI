#include "pch.h"
#include "CppUnitTest.h"
#include "../main-project/data_subscription.h"
#include "../main-project/processing.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
	data_subscription* build_subscription(int start_hour, int start_minute, int start_sec, int finish_hour, int finish_minute, int finish_sec)
		{
			data_subscription* subscription = new data_subscription;
			subscription->start.hour = start_hour;
			subscription->start.minute = start_minute;
			subscription->start.sec = start_sec;
			subscription->finish.hour = finish_hour;
			subscription->finish.minute = finish_minute;
			subscription->finish.sec = finish_sec;
			*subscription->reader.first_name = *"h";
			*subscription->reader.last_name = *"h";
			*subscription->reader.middle_name = *"h";
			*subscription->club = *"h";

			return subscription;
		}

		//       
		void delete_subscription(data_subscription* array[], int size)
		{
			for (int i = 0; i < size; i++)
			{
				delete array[i];
			}
		}
		TEST_CLASS(unittestproject)
	{
	public:
		
			TEST_METHOD(TestMethod1) //     
			{
				data_subscription* subscriptions[3];
				subscriptions[0] = build_subscription(1, 5, 15, 2, 5, 15); // 1:00:00 
				subscriptions[1] = build_subscription(10, 25, 25, 15, 25, 25); // 5:00:00 
				subscriptions[2] = build_subscription(3, 4, 5, 6, 7, 8); // 3:03:03 
				Assert::AreEqual(*"1:00:00", process(subscriptions, 3));
				delete_subscription(subscriptions, 3);
			}

			TEST_METHOD(TestMethod2) //        
			{
				data_subscription* subscriptions[3];
				subscriptions[0] = build_subscription(5, 5, 5, 6, 7, 8); // 1:2:3 
				subscriptions[1] = build_subscription(11, 12, 3, 19, 13, 4); // 8:1:1 
				subscriptions[2] = build_subscription(3, 2, 1, 11, 15, 17); // 8:13:16 
				Assert::AreEqual(*"1:02:03", process(subscriptions, 3));
				delete_subscription(subscriptions, 3);
			}

			TEST_METHOD(TestMethod3) //         
			{
				data_subscription* subscriptions[3];
				subscriptions[0] = build_subscription(1, 1, 1, 2, 2, 2); // 1:1:1 
				subscriptions[1] = build_subscription(2, 3, 4, 5, 6, 7); // 3:3:3 
				subscriptions[2] = build_subscription(13, 14, 11, 16, 23, 27); // 3:9:16
				Assert::AreEqual(*"1:01:01", process(subscriptions, 3));
				delete_subscription(subscriptions, 3);
			}

	};
}

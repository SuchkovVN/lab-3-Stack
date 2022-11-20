#include <gtest.h>
#include <iostream>

int main(int argc, char **argv)
{
  try
  {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }
  catch (const char* s)
  {
    std::cout << s;
  }
    
}

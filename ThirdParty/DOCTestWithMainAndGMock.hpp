// https://github.com/matepek/catch2-with-gmock

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#include "gmock/gmock.h"

int main(int argc, char** argv)
{
    ::testing::InitGoogleMock(&argc, argv);

    struct Listener : public testing::EmptyTestEventListener
    {
        void OnTestPartResult(const testing::TestPartResult& result) override
        {
            const char* filename = "unknown";
            int linenumber = 0;

            if (result.file_name() != nullptr)
                filename = result.file_name();

            if (result.line_number() != -1)
                linenumber = result.line_number();

            if (result.nonfatally_failed())
            {
                DOCTEST_ADD_FAIL_CHECK_AT(filename, linenumber, result.message());
            }
            else if (result.fatally_failed())
            {
                DOCTEST_ADD_FAIL_AT(filename, linenumber, result.message());
            }
        }
    };

    auto& listeners = ::testing::UnitTest::GetInstance()->listeners();

    listeners.Append(new Listener);

    delete listeners.Release(listeners.default_result_printer());

    doctest::Context context;

    context.applyCommandLine(argc, argv);

    return context.run();
}
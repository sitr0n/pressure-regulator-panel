#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../presentationmodel.h"
//#include <presentationmodel.h>
#include <memory>
#include <vector>
#include <QDebug>

class MockItems
{
public: MOCK_METHOD1(refresh, void(int item));
};

using ::testing::_;
using ::testing::Return;
using ::testing::AtLeast;

TEST(PresentationModel, testInitialize)
{
    auto model = std::make_shared<PresentationModel>();
    bool wasEdited = false;
    model->initialize(Action([&wasEdited]{
        wasEdited = true;
        return true;
    }));

    ASSERT_TRUE(model->setupPending());
    model->QThread::start();
    model->wait();
    ASSERT_EQ(wasEdited, true);
}

TEST(PresentationModel, testSubscribe)
{
    auto items = std::make_shared<MockItems>();
    auto model = std::make_shared<PresentationModel>();

    for (const auto& item : {1, 2, 3}) {
        for (const auto& result : {false, true}) {
            model->subscribe(Action([item, result, &items]{
                items->refresh(item);
                return result;
            }));
        }
        EXPECT_CALL(*items, refresh(item)).Times(AtLeast(1));
    }

    ASSERT_TRUE(model->eventsPending());
    model->QThread::start();
    ASSERT_FALSE(model->wait(20));
}

TEST(PresentationModel, testDispatchPreStart)
{
    auto items = std::make_shared<MockItems>();
    auto model = std::make_shared<PresentationModel>();

    for (auto item : {1, 2, 3}) {
        model->dispatch(Action([item, &items]{
            items->refresh(item);
            return true;
        }));
        EXPECT_CALL(*items, refresh(item)).Times(1);
    }
    ASSERT_TRUE(model->eventsPending());
    model->QThread::start();
    ASSERT_TRUE(model->wait());
}

TEST(PresentationModel, testDispatchPostStart)
{
    auto items = std::make_shared<MockItems>();
    auto model = std::make_shared<PresentationModel>();
    model->subscribe(Action([]{
        return bool{}; // Keep model running
    }));
    model->QThread::start();
    for (auto item : {1, 2, 3}) {
        model->dispatch(Action([item, &items]{
            items->refresh(item);
            return true;
        }));
        EXPECT_CALL(*items, refresh(item)).Times(1);
    }
    ASSERT_FALSE(model->wait(10));
}

TEST(PresentationModel, testTeardown)
{
    auto items = std::make_shared<MockItems>();
    auto model = std::make_shared<PresentationModel>();

    for (auto item : {1, 2, 3}) {
        model->teardown(Action([item, &items]{
            items->refresh(item);
            return true;
        }));
        EXPECT_CALL(*items, refresh(item)).Times(1);
    }
    ASSERT_TRUE(model->teardownPending());
    model->QThread::start();
    ASSERT_TRUE(model->wait());
}

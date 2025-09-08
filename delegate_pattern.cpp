// Delegate interface
class ButtonDelegate {
public:
    virtual void onButtonTap() = 0;
    virtual ~ButtonDelegate() = default;
};

// Class that uses the delegate
class Button {
    ButtonDelegate* delegate;
public:
    Button(ButtonDelegate* d) : delegate(d) {}
    void tap() {
        if (delegate) delegate->onButtonTap();
    }
};

// Implementation of the delegate
class MyHandler : public ButtonDelegate {
public:
    void onButtonTap() override {
        std::cout << "Button tapped!" << std::endl;
    }
};

// Usage
int main() {
    MyHandler handler;
    Button button(&handler);
    button.tap();
    return 0;
}
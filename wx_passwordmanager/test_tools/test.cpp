#include <iostream>
#include <cassert>
#include "passwordManager.hpp"

void testPasswordManager() {
    PasswordManager manager("admin", "password123", "encryption_key");

    // Test Authenticate function
    assert(manager.authenticate("admin", "password123"));
    assert(!manager.authenticate("admin", "wrong_password"));
    assert(!manager.authenticate("wrong_username", "password123"));

    // Test AddPassword and GetPasswordInfo functions
    manager.addPassword("Website A", "userA", "https://www.websiteA.com", "", "passwordA");
    manager.addPassword("Website B", "userB", "https://www.websiteB.com", "", "passwordB");
    manager.addPassword("Website C", "userC", "https://www.websiteC.com", "", "passwordC");

    auto infoA = manager.getPasswordInfo("Website A");
    assert(infoA.title == "Website A");
    assert(infoA.username == "userA");
    assert(infoA.url == "https://www.websiteA.com");
    assert(infoA.note.empty());
    assert(infoA.password == "passwordA");

    auto infoB = manager.getPasswordInfo("Website B");
    assert(infoB.title == "Website B");
    assert(infoB.username == "userB");
    assert(infoB.url == "https://www.websiteB.com");
    assert(infoB.note.empty());
    assert(infoB.password == "passwordB");

    auto infoC = manager.getPasswordInfo("Website C");
    assert(infoC.title == "Website C");
    assert(infoC.username == "userC");
    assert(infoC.url == "https://www.websiteC.com");
    assert(infoC.note.empty());
    assert(infoC.password == "passwordC");

    // Test RemovePassword function
    manager.removePassword("Website B");
    assert(manager.getPasswordInfo("Website B").title.empty());

    // Test GenerateRandomPassword function
    std::string randomPassword = manager.generateRandomPassword(10, true, true, true);
    assert(randomPassword.length() == 10);

    // Test ShowPassword function
    manager.showPassword("Website A");
    manager.showPassword("Website B"); // Should not display anything since it was removed

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testPasswordManager();
    return 0;
}

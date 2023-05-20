#ifndef PASSWORDMANAGER_HPP
#define PASSWORDMANAGER_HPP

#include <iostream>
#include <unordered_map>
#include <string>
#include <random>
#include <fstream>
#include <sstream>
#include "cryptopp/aes.h"
#include "cryptopp/modes.h"
#include "cryptopp/filters.h"
#include "cryptopp/hex.h"

class PasswordManager
{private:
    std::string username;
    std::string password;

    // Private constructor and destructor to prevent direct instantiation and deletion
    PasswordManager(const std::string& username, const std::string& password);

public:
    PasswordManager(); // Standardkonstruktor hinzufügen
    ~PasswordManager(); //

    struct PasswordInfo
    {
        std::string title;
        std::string username;
        std::string url;
        std::string note;
        std::string password;

        // Konstruktor für PasswordInfo
        PasswordInfo(const std::string& title, const std::string& username, const std::string& url, const std::string& note, const std::string& password)
            : title(title), username(username), url(url), note(note), password(password) {}


        PasswordInfo() = default;

        // Setter functions
        void setTitle(const std::string& newTitle)
        {
            title = newTitle;
        }
        void setUsername(const std::string& newUsername)
        {
            username = newUsername;
        }
        void setURL(const std::string& newURL)
        {
            url = newURL;
        }
        void setNote(const std::string& newNote)
        {
            note = newNote;
        }
        void setPassword(const std::string& newPassword)
        {
            password = newPassword;
        }
        void setCredentials(const std::string& newUsername, const std::string& newPassword)
        {
            username = newUsername;
            password = newPassword;
        }

        // Getter functions
        std::string getTitle() const
        {
            return title;
        }
        std::string getUsername() const
        {
            return username;
        }
        std::string getURL() const
        {
            return url;
        }
        std::string getNote() const
        {
            return note;
        }
        std::string getPassword() const
        {
            return password;
        }
    };

    std::unordered_map<std::string, PasswordInfo> passwords;
    std::random_device rd;
    std::mt19937 gen;

    std::string encryptData(const std::string& data);
    std::string decryptData(const std::string& encryptedData);

    static PasswordManager& getInstance(const std::string& username, const std::string& password);
    static std::string loginfile;
    static void setLoginFile(const std::string& filename)
    {
        loginfile = filename;
    }

    static std::string getLoginFile()
    {
        return loginfile;
    }

    void addPassword(const std::string& title, const std::string& username, const std::string& url, const std::string& note, const std::string& password);
    void removePassword(const std::string& title);

    PasswordInfo getPasswordInfo(const std::string& title);

    std::string generateRandomPassword(int length, bool includeLetters, bool includeNumbers, bool includeSpecialChars);

    void showPassword(const std::string& searchQuery);
    void saveDataToFile(const std::string& filename);
    void loadDataFromFile(const std::string& filename);
    void loadAuthenticationCredentialsFromFile(const std::string& filename);

    std::unordered_map<std::string, PasswordInfo> getAllPasswords() const;


    void updateAuthenticationCredentials(const std::string& newUsername, const std::string& newPassword);
    bool authenticate(const std::string& username, const std::string& password);



};

#endif // PASSWORDMANAGER_HPP

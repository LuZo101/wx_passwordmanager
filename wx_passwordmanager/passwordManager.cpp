#include "passwordManager.hpp"
#include "cryptopp/aes.h"
#include "cryptopp/modes.h"
#include "cryptopp/filters.h"
#include "fstream"
#include "string"

std::string PasswordManager::loginfile;

PasswordManager::PasswordManager(const std::string& username, const std::string& password)
    : username(username), password(password)
{
        passwords = getAllPasswords();
}

PasswordManager::PasswordManager() {}

PasswordManager::~PasswordManager()
{
    // Cleanup code, if necessary
}

PasswordManager& PasswordManager::getInstance(const std::string& username, const std::string& password)
{
    static PasswordManager passwordManager(username, password);
    return passwordManager;
}

std::unordered_map<std::string, PasswordManager::PasswordInfo> PasswordManager::getAllPasswords() const
{
    return passwords;
}

void PasswordManager::addPassword(const std::string& title, const std::string& username, const std::string& url, const std::string& note, const std::string& password)
{
    PasswordInfo info;
    info.title = title;
    info.username = username;
    info.url = url;
    info.note = note;
    info.password = password;
    passwords[title] = info;
}

void PasswordManager::removePassword(const std::string& title)
{
    auto it = passwords.find(title);
    if (it != passwords.end())
    {
        passwords.erase(it);
    }
}

PasswordManager::PasswordInfo PasswordManager::getPasswordInfo(const std::string& title)
{
    if (passwords.find(title) != passwords.end())
    {
        return passwords[title];
    }
    return {};
}

std::string PasswordManager::generateRandomPassword(int length, bool includeLetters, bool includeNumbers, bool includeSpecialChars)
{
    std::string characters = "";
    if (includeLetters)
    {
        characters += "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    if (includeNumbers)
    {
        characters += "0123456789";
    }
    if (includeSpecialChars)
    {
        characters += "!@#$%^&*()";
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, characters.size() - 1);
    std::string password = "";
    for (int i = 0; i < length; ++i)
    {
        password += characters[distribution(gen)];
    }
    return password;
}

void PasswordManager::showPassword(const std::string& searchQuery)
{
    for (const auto& password : passwords)
    {
        if (password.second.title == searchQuery || password.second.url == searchQuery)
        {
            std::cout << "Title: " << password.second.title << std::endl;
            std::cout << "Username: " << password.second.username << std::endl;
            std::cout << "URL: " << password.second.url << std::endl;
            std::cout << "Note: " << password.second.note << std::endl;
            std::cout << "Password: " << password.second.password << std::endl;
            return;
        }
    }
    std::cout << "Password not found." << std::endl;
}

std::string PasswordManager::encryptData(const std::string& data)
{
    std::string encryptedData = data;
    // Implementiere die Verschlüsselung mit CryptoPP (AES, Modes, Filters)
    // ...

    return encryptedData;
}

std::string PasswordManager::decryptData(const std::string& encryptedData)
{
    std::string decryptedData = encryptedData;
    // Implementiere die Entschlüsselung mit CryptoPP (AES, Modes, Filters)
    // ...

    return decryptedData;
}


void PasswordManager::saveDataToFile(const std::string& filename)
{
    std::ofstream file(filename, std::ios::out | std::ios::binary);
    if (!file)
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Schreiben der Anzahl der Passwörter in die Datei
    size_t numPasswords = passwords.size();
    file.write(reinterpret_cast<const char*>(&numPasswords), sizeof(numPasswords));

    // Schreiben jedes Passworts in die Datei
    for (const auto& entry : passwords)
    {
        const PasswordInfo& info = entry.second;

        // Schreiben der Länge des Titels und des Titels in die Datei
        size_t titleLength = info.title.size();
        file.write(reinterpret_cast<const char*>(&titleLength), sizeof(titleLength));
        file.write(info.title.c_str(), titleLength);

        // Schreiben der Länge des Benutzernamens und des Benutzernamens in die Datei
        size_t usernameLength = info.username.size();
        file.write(reinterpret_cast<const char*>(&usernameLength), sizeof(usernameLength));
        file.write(info.username.c_str(), usernameLength);

        // Schreiben der Länge der URL und der URL in die Datei
        size_t urlLength = info.url.size();
        file.write(reinterpret_cast<const char*>(&urlLength), sizeof(urlLength));
        file.write(info.url.c_str(), urlLength);

        // Schreiben der Länge der Notiz und der Notiz in die Datei
        size_t noteLength = info.note.size();
        file.write(reinterpret_cast<const char*>(&noteLength), sizeof(noteLength));
        file.write(info.note.c_str(), noteLength);

        // Schreiben der Länge des Passworts und des Passworts in die Datei
        size_t passwordLength = info.password.size();
        file.write(reinterpret_cast<const char*>(&passwordLength), sizeof(passwordLength));
        file.write(info.password.c_str(), passwordLength);
    }

    file.close();
}


void PasswordManager::loadAuthenticationCredentialsFromFile(const std::string& filename)
{
    std::ifstream file(loginfile);
    if (!file)
    {
        std::cerr << "Error opening credentials file." << std::endl;
        return;
    }

    std::getline(file, username);
    std::getline(file, password);

    file.close();
}
void PasswordManager::loadDataFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    // Leeren des bestehenden Inhalts von passwords
    passwords.clear();

    std::string line;
    int lineCount = 0;
    while (std::getline(file, line))
    {
        if (lineCount < 2) // Erste zwei Zeilen überspringen
        {
            lineCount++;
            continue;
        }

        std::string title, username, url, note, password;
        size_t startPos = 0;
        size_t delimiterPos = line.find('|', startPos);

        // Extrahieren der einzelnen Felder
        title = line.substr(startPos, delimiterPos - startPos);
        startPos = delimiterPos + 2; // Länge des Trennzeichens berücksichtigen

        delimiterPos = line.find('|', startPos);
        username = line.substr(startPos, delimiterPos - startPos);
        startPos = delimiterPos + 2;

        delimiterPos = line.find('|', startPos);
        url = line.substr(startPos, delimiterPos - startPos);
        startPos = delimiterPos + 2;

        delimiterPos = line.find('|', startPos);
        note = line.substr(startPos, delimiterPos - startPos);
        startPos = delimiterPos + 2;

        password = line.substr(startPos);

        PasswordInfo passwordInfo;
        passwordInfo.setTitle(title);
        passwordInfo.setUsername(username);
        passwordInfo.setURL(url);
        passwordInfo.setNote(note);
        passwordInfo.setPassword(password);
        passwords[title] = passwordInfo;
    }

    file.close();
}




bool PasswordManager::authenticate(const std::string& enteredUsername, const std::string& enteredPassword)
{
    // Lade die Authentifizierungsdaten aus der Datei
    loadAuthenticationCredentialsFromFile(loginfile);

    // Überprüfe, ob das eingegebene Benutzername-Passwort-Paar mit den gespeicherten Daten übereinstimmt
    return (enteredUsername == username && enteredPassword == password);
}



void PasswordManager::updateAuthenticationCredentials(const std::string& newUsername, const std::string& newPassword)
{
    // Aktualisiere die Authentifizierungsdaten des PasswordManagers
    this->username = newUsername;
    this->password = newPassword;
}

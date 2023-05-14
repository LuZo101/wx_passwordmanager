#include <iostream>
#include <fstream>

void generateSampleData(std::ofstream& file) {
    file << "Google,Gmail,https://www.gmail.com/,Primary email account,myGmailPassword" << std::endl;
    file << "Facebook,myUsername,https://www.facebook.com/,Social media platform,myFacebookPassword" << std::endl;
    file << "Amazon,myUsername,https://www.amazon.com/,Online shopping,myAmazonPassword" << std::endl;
    file << "Netflix,myUsername,https://www.netflix.com/,Streaming platform,myNetflixPassword" << std::endl;
    file << "LinkedIn,myUsername,https://www.linkedin.com/,Professional networking,myLinkedInPassword" << std::endl;
    file << "Twitter,myUsername,https://www.twitter.com/,Microblogging platform,myTwitterPassword" << std::endl;
    file << "GitHub,myUsername,https://www.github.com/,Version control platform,myGitHubPassword" << std::endl;
    file << "Dropbox,myUsername,https://www.dropbox.com/,Cloud storage service,myDropboxPassword" << std::endl;
    file << "Instagram,myUsername,https://www.instagram.com/,Photo sharing platform,myInstagramPassword" << std::endl;
    file << "Microsoft,myUsername,https://www.microsoft.com/,Technology company,myMicrosoftPassword" << std::endl;
}

int main() {
    std::ofstream file("database.txt", std::ios::app); // Open the file in append mode

    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    generateSampleData(file);

    file.close();

    std::cout << "Sample data generated successfully." << std::endl;

    return 0;
}


#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <chrono>
#include <windows.h>
#include <thread>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "transpose.h"
#include "caeser.h"
#include <filesystem>
#include <cctype>
namespace fs = std::filesystem;
using namespace std;
#define RESET "\033[0m"
#define BLUE1 "\033[34m"
#define BLUE2 "\033[94m"
#define PURPLE1 "\033[35m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define BOLD "\033[1m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define GREEN "\033[0;32m"
#define GREY    "\033[90m"
// formatting -> Hush
// ascii help -> MTT
// fing bug -> Cosine
//  main function build -> Hush + Riae
//  input validations -> Narihito
// file handling -> Riae

void enableANSI();
bool isFileLocked(const string& filename);
void mainPage_cipherChoice();
void printLogo_X(bool first);
void printLogo_Y(bool first);
void printLogo_C(bool first);                                                          // Hush
void printKeyLogo();                                                         // Hush
void encryptX(vector<string> &texti, int x[]);                               // Hush --
void decryptX(vector<string> &texti, int x[]);                               // Hush --
void display_mode(string text, vector<string> ini);                          // Hush --
void for_condofzeroupfront(vector<int> &de, int expectedLen);                // Hush + Riae
void addHeader(vector<string> &ciphertext, int shuffleOrder);                // Cosine --
int shuffl(vector<string> &names, vector<string> &new_name);                 // Riae --
int formulaX(int n);                                                         // Narihito --
int xor_addition(int a, int b);                                              // Narihito --
int extractHeader(string &text, vector<int> &header, bool &ext);             // Cosine --
int vec_to_int(const vector<int> &v);                                        // Cosine
int formulaY(int n);                                                         // Narihito --
int formulaYverse(int n);                                                    // Narihito --
int findMax(const vector<int> &d_header, int seg);                           // John Lay --
vector<string> splitRandom(const string &input, int parts, char c, int max); // John Lay--
string exportFile(const string &filename);                                   // Riae --
string docxToTxt(string docxFile, string textfile);
void txtToDocx(string text, string docxFile);
void txtPrint();
void txtIIllustrate();
void docx();
void pause();


int main()
{
    enableANSI();
    while (true)
    {
        this_thread::sleep_for(chrono::seconds(1));
        SetConsoleOutputCP(CP_UTF8); // Work Ascii Art for both terminal and exe file
        cout << PURPLE1 << R"(
                                _____                                                                            _____ 
                               ( ___ )                                                                          ( ___ )
                                |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | 
                                |   | ███████╗ ██████╗ ██████╗ ███╗   ███╗██╗   ██╗██╗      █████╗      ██╗  ██╗ |   | 
                                |   | ██╔════╝██╔═══██╗██╔══██╗████╗ ████║██║   ██║██║     ██╔══██╗     ╚██╗██╔╝ |   | 
                                |   | █████╗  ██║   ██║██████╔╝██╔████╔██║██║   ██║██║     ███████║█████╗╚███╔╝  |   | 
                                |   | ██╔══╝  ██║   ██║██╔══██╗██║╚██╔╝██║██║   ██║██║     ██╔══██║╚════╝██╔██╗  |   | 
                                |   | ██║     ╚██████╔╝██║  ██║██║ ╚═╝ ██║╚██████╔╝███████╗██║  ██║     ██╔╝ ██╗ |   | 
                                |   | ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝     ╚═╝  ╚═╝ |   | 
                                |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| 
                               (_____)                                                                          (_____)
     )";
        cout << RESET;
        mainPage_cipherChoice();
        char cipherchoice;
        string cippherchoice;
        string c = "CHOICE: ";
        bool vv;
        do
        {
            vv = true;
            cout << string(65, ' ');
            cout << PURPLE1;
            for (char ch : c)
            {
                cout << ch;
                this_thread::sleep_for(chrono::milliseconds(55));
            }
            cin >> cippherchoice;
            if (cippherchoice.size() != 1 || !isdigit(cippherchoice[0]) || cippherchoice[0] < '1' || cippherchoice[0] > '4')
            {
                cout << string(52, ' ') << RED << "Invalid choice. Please enter 1, 2, 3 or 4 only." << RESET << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                vv = false;
                continue;
            }
            cipherchoice = cippherchoice[0] - '0';
            break;
        } while (!vv);
        system("cls");
        // cout << "\033[2J\033[1;1H"; // clear + move cursor to top-left
        if (cipherchoice == 1)
        {

            printLogo_X(true);
            do
            {
                string check[3];
                int x[3];
                int xkey[3];
                string text, filename;
                string choiceStr;
                string displaychoice, docxFile, txtFile;
                char display_choice;
                char choice, confirmFile;
                int choose_File = 0;
                bool validchoice = true;
                bool display_bool = false;
                bool ext = true;
                cout << "\n\n\n";
                cout << string(62, ' ') << YELLOW << "(E)ncrypt, (D)ecrypt, or (Q)uit? \n"
                     << PURPLE1;
                cout << string(78, ' ');
                cin >> choiceStr;
                cin.ignore();
                cout << RESET;
                try
                {
                    if (choiceStr.size() != 1 ||
                        (tolower(choiceStr[0]) != 'e' && tolower(choiceStr[0]) != 'd' && tolower(choiceStr[0]) != 'q'))
                    {
                        cout << string(52, ' ') << RED "Invalid choice. Please enter E, D, or Q.\n"
                             << RESET;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }

                    choice = tolower(choiceStr[0]);
                }
                catch (exception &e)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                if (tolower(choice) == 'q')
                {
                    cout << string (52,' ') << PURPLE1 << "Exiting The Program" << RESET;
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        this_thread::sleep_for(chrono::milliseconds(300));
                    }
                    cout << endl;
                    cout << string (52,' ') << PURPLE1 << "Thank You For Using" << RESET;
                    break;
                }
                // ("cls");
                system("cls");
                printLogo_X(false);
                // cout << "\033[2J\033[1;1H"; // for terminal
                bool validconfirm = true;
                do{
                    
                    cout << "\n\n"
                     << string(52, ' ') << CYAN << "Do you want to import a file for encryption(y or n): " << PURPLE1;
                    cin >> confirmFile;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    confirmFile = tolower(confirmFile);
                    if(confirmFile != 'y'&&confirmFile != 'n'){
                        cout<<RED<<"Please enter only y for (yes) and n for (no)!"<<endl;
                        validconfirm = false;
                    }
                    else{
                        validconfirm = true;
                    }
                }while(!validconfirm);
                cout << RESET;

                // cout << "\033[2J\033[1;1H";
                while (true)
                {
                    try
                    {
                        if(tolower(confirmFile) == 'n')
                        {
                            cout << "\n\n"
                             << string(52, ' ') << CYAN << "Do you want to see how the process works step by step?\n";
                            cout << "\n"
                             << string(52, ' ') << "Press (Y)es or (N)o: " << PURPLE1;
                            cin >> displaychoice;
                            cin.ignore();
                        }
                        else
                        {
                            display_bool = false;
                            system("cls");
                            break;
                        }
                        cout << RESET;
                        system("cls");
                        if (displaychoice.size() != 1 || (tolower(displaychoice[0]) != 'y' && tolower(displaychoice[0]) != 'n'))
                        {
                            cout << string(52, ' ') << RED << "Invalid choice. Please enter Y or N and make sure to input appropriate length.\n"
                                 << RESET;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }

                        display_choice = tolower(displaychoice[0]);
                        if ((display_choice) == 'y')
                            display_bool = true;
                        break;
                    }
                    catch (exception &e)
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        continue;
                    }
                }
                printLogo_X(false);
                printKeyLogo();
                cout << string(52, ' ') << CYAN << "PLease Enter your Key no more than 9 characters\n" << RESET;
                for (int i = 0; i < 3; i++)
                {
                    while (true)
                    {

                        cout << string(52, ' ') << YELLOW << "Enter Key " << i + 1 << " 🔑 : " << PURPLE1;
                        cin >> check[i];
                        cin.ignore();
                        cout << RESET;
                        cout << "\n\n";
                        bool validchoice = true;
                        for (char c : check[i])
                        {
                            if (!isdigit(c))
                            {
                                validchoice = false;
                                break;
                            }
                        }

                        if (!validchoice)
                        {
                            cout << string(52, ' ') << RED << "Please enter The Number And No String Included.\n"
                                 << RESET;
                            continue;
                        }
                        try
                        {
                            x[i] = stoi(check[i]); // change to stoll
                            xkey[i] = xor_addition(x[i], formulaX(x[i]));
                            break;
                        }
                        catch (exception &e)
                        {
                            cout << string(52, ' ') << RED << "Omg!! Please Enter Appropriate Number.\n"
                                 << RESET;
                        }
                    }
                }
                if (tolower(choice) == 'e')
                {
                    if (tolower(confirmFile) == 'y')
                    {
                        system("cls");
                        txtPrint();
                            cout<<endl;
                        do
                        {
                            
                            bool correct_option = true;
                            cout<<string(52,' ')<<YELLOW<<"Our program currently supports txt and docx only."<<endl;
                            cout<<string(52,' ')<<YELLOW<<"Choose "<<"1"<<YELLOW<<" for TXT file and choose "<<"2"<<YELLOW<<" for DOCX file: "<<PURPLE1;
                            if(!(cin>>choose_File))
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                system("cls");
                                choose_File = 0;
                                correct_option = false;
                            }
                            if(correct_option)
                            {
                                system("cls");
                                cin.ignore();
                            }
                            cout<<"\n\n";
                            txtPrint();
                            cout<<endl;
                            cout<<string(52,' ')<<RED<<"Invalid input. Please enter 1 or 2 only."<<RESET<<endl;
                        }while (choose_File != 1 && choose_File != 2);
                        system("cls");
                        
                        if (choose_File == 1)
                        {
                            txtIIllustrate();
                            bool fileexist = true;
                            do
                            {
                                fileexist = true;
                                cout<<"\n\n";
                                cout << string(52, ' ') << YELLOW << "Enter the text file: " << PURPLE1;
                                getline(cin, txtFile);
                                if (txtFile.size() < 4 || !fs::exists(txtFile) || txtFile.substr(txtFile.size() - 4) != ".txt")

                                {
                                    fileexist = false;
                                    cout << string(52, ' ') << RED << "Sorry the file you specified is not in your system.\n";
                                    cout <<string(52,' ')<<RED<< "Please make sure that the file is in your system.\n";
                                    cout<<string(52,' ')<<RED<< "Please make sure to include the correct file path and extension of the file.\n";
                                }

                            } while (!fileexist);
                            text = exportFile(txtFile);

                            cout << RESET; // reseting color
                        }
                        if (choose_File == 2)
                        {
                            docx();
                            bool fileexist = true;
                            do
                            {
                                fileexist = true;
                                cout<<"\n\n";
                                cout << string(52, ' ') << YELLOW << "Enter the docx file: ";
                                getline(cin, docxFile);
                                if(isFileLocked(docxFile)){
                                    cout<<"Sorry the file is used in another application, please close it first.\n";
                                    fileexist = false;
                                    if (!isFileLocked(docxFile)&&docxFile.size() < 5 || !fs::exists(docxFile) || docxFile.substr(docxFile.size()-5) != ".docx")
                                    {
                                        fileexist = false;
                                        cout << string(52, ' ') << RED << "Sorry the file you specified is not in your system.\n";
                                        cout <<string(52,' ')<<RED<< "Please make sure that the file is in your system.\n";
                                        cout<<string(52,' ')<<RED<< "Please make sure to include the correct file path and extension of the file.\n";
                                    }
                                }

                            } while (!fileexist||isFileLocked(docxFile));
                            text = docxToTxt(docxFile, "temp.txt");
                            cout << RESET;
                        }
                    }
                    else
                    {
                        do
                        {
                            cout << string(52, ' ') << CYAN << "Enter your plaintext More than 2 letters:  " << PURPLE1;
                            getline(cin >> ws, text);
                        }while(text.length() <= 2);
                    }
                    cout << RESET;
                    int segment_number = 0;
                    int max = -1;
                    vector<string> texti = splitRandom(text, segment_number, 'e', max); // 1

                    if (display_bool)
                    {
                        
                        pause();
                        system("cls");
                        printLogo_X(false);
                        display_mode("segmented text", texti);
                        // cout << string(56,' ')<< "↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n";}
                        cout << endl;
                        // 2
                    }
                    encryptX(texti, xkey);
                    if (display_bool)
                    {
                        pause();
                        display_mode("encrypted text without unshuffle", texti);
                        // cout << string(56,' ')<< "↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n";}
                        cout << endl;

                        // 3
                    }
                    vector<string> in_text;
                    int shuffleOrder = shuffl(texti, in_text);
                    if (display_bool)
                    {
                        pause();
                        display_mode("shuffled text", in_text);
                        cout << string(56,' ')<< "↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n";
                        cout << endl;
                    }
                    addHeader(in_text, shuffleOrder);

                    cout << string(52, ' ') << YELLOW << "Encrypting the text";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        this_thread::sleep_for(chrono::milliseconds(500));
                    }
                    cout << endl
                         << endl;
                    if (tolower(confirmFile) == 'n')
                    {
                        cout << string(52, ' ') << CYAN << "Encrypted text is ";
                        cout << PURPLE1 << "\"";
                    }
                    string text_file;
                    for (const string &seg : in_text)
                    {
                        text_file += seg;
                    }
                    if (choose_File == 1)
                    {
                        ofstream outfile(txtFile);
                        if (!outfile.is_open())
                        {
                            cerr << "Error opening file.";
                            return 1;
                        }
                        outfile << text_file;
                        cout << string(52, ' ') << CYAN // GREEN//
                             << "\"File encrypted successfully.";
                    }
                    else if (choose_File == 2)
                    {
                        string tempfile = "temp.txt";
                        ofstream out(tempfile);
                        if (!out.is_open())
                        {
                            cerr << "Error parsing docx to txt.";
                            return 1;
                        }
                        out << text_file;
                        out.close();
                        txtToDocx(tempfile, docxFile);
                        cout << string(52, ' ') << "File encrypted successfully\n";
                    }

                    else
                    {
                        cout << text_file;
                    }
                    cout << "\"\n"
                         << RESET;
                }
                else if (tolower(choice) == 'd')
                {
                    if (tolower(confirmFile) == 'y')
                    {
                        system("cls");
                        txtPrint();
                        cout<<endl;
                        do
                        {
                            
                            bool correct_option = true;
                            cout<<string(52,' ')<<YELLOW<<"Our program currently supports txt and docx only."<<endl;
                            cout<<string(52,' ')<<CYAN<<"Choose 1 for TXT file and choose 2 for DOCX file: "<<PURPLE1;
                            if(!(cin>>choose_File))
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                system("cls");
                                choose_File = 0;
                                correct_option = false;
                            }
                            if(correct_option)
                            {
                                
                                system("cls");
                                cin.ignore();
                                
                            }
                            cout<<"\n\n";
                            txtPrint();
                            cout<<endl;
                            cout<<string(52,' ')<<RED<<"Invalid input. Please enter 1 or 2 only."<<RESET<<endl;
                        }while (choose_File != 1 && choose_File != 2);
                        system("cls");
                        if (choose_File == 1)
                        {
                            txtIIllustrate();
                            cout<<"\n\n";
                            bool fileexist = true;
                            do
                            {
                                fileexist = true;
                                cout << string(52, ' ') << CYAN << "Enter the text file: " << PURPLE1;
                                getline(cin, txtFile);
                                cout << RESET;
                                if (txtFile.size() < 4 || !fs::exists(txtFile) || txtFile.substr(txtFile.size() - 4) != ".txt")
                                {
                                    fileexist = false;
                                    cout << string(52, ' ') << RED << "Sorry the file you specified is not in your system.\n";
                                    cout <<string(52,' ')<<RED<< "Please make sure that the file is in your system.\n";
                                    cout<<string(52,' ')<<RED<< "Please make sure to include the correct file path and extension of the file.\n";
                                }
                            } while (!fileexist);
                            text = exportFile(txtFile);
                        }
                        if (choose_File == 2)
                        {
                            docx();
                            cout<<"\n\n";
                            bool fileexist = true;
                            do
                            {
                                fileexist = true;
                                cout << string(52, ' ') << YELLOW << "Enter the docx file: " << PURPLE1;
                                getline(cin, docxFile);
                                if(isFileLocked(docxFile)){
                                    cout<<"Sorry the file is used in another application, please close it first.\n";
                                    fileexist = false;
                                }
                                if (docxFile.size() < 5 || !fs::exists(docxFile) || docxFile.substr(docxFile.size()-5) != ".docx")
                                {
                                    fileexist = false;
                                    cout << string(52, ' ') << RED << "Sorry the file you specified is not in your system.\n";
                                    cout <<string(52,' ')<<RED<< "Please make sure that the file is in your system.\n";
                                    cout<<string(52,' ')<<RED<< "Please make sure to include the correct file path and extension of the file.\n";
                                }

                            } while (!fileexist);
                            text = docxToTxt(docxFile, "temp.txt");
                        }
                    }
                    else
                    {
                        cout << string(52, ' ') << CYAN << "Enter your ciphertext: " << PURPLE1;
                        getline(cin >> ws, text);
                    }
                    cout << RESET;
                    vector<int> ex_header;
                    int decrypted_header = extractHeader(text, ex_header, ext);
                    if (!ext)
                        continue; // 1 ko sai

                    vector<int> decrypted_header_vector;
                    string str_form = to_string(decrypted_header);
                    for (char ch : str_form)
                        decrypted_header_vector.push_back(ch - '0');

                    int provisionalSegs = (int)decrypted_header_vector.size();
                    /*for (int num: decrypted_header_vector)
                    {
                        cout << num << endl;
                    }*/
                    // uncomment for finding bugs
                    int maxVal = *max_element(decrypted_header_vector.begin(), decrypted_header_vector.end());
                    int expectedSegs = maxVal + 1;

                    for_condofzeroupfront(decrypted_header_vector, expectedSegs);

                    int segment_number = (int)decrypted_header_vector.size();
                    int max = findMax(decrypted_header_vector, segment_number);

                    vector<string> texti = splitRandom(text, segment_number, 'd', max); // 2 mtt
                    if (display_bool)
                    { 
                        pause();
                        system("cls");
                        printLogo_X(false);
                        display_mode("segmented text", texti);
                    }
                    vector<string> in_text(segment_number);

                    for (int i = 0; i < segment_number; i++) // 3
                    {
                        int originalIndex = decrypted_header_vector[i];
                        if (originalIndex < 0 || originalIndex >= segment_number)
                        {
                            cerr << "\n[Error] Corrupt header/permutation.\n";
                            return 1;
                        }
                        in_text[originalIndex] = texti[i];
                    }
                    if (display_bool)
                    {
                        pause();
                        display_mode("ordered text", in_text);
                    }
                    decryptX(in_text, xkey); // 4
                    if (display_bool)
                    {
                        pause();
                        display_mode("segmented decrypted text", in_text);
                    }   
                    cout << string (52, ' ')<< YELLOW << "Decrypting the text";

                    /*for (const string &hi: texti)
                        cout << hi << endl;
                    cout << endl;
                    for (const string &seg : in_text)
                        cout << seg << endl;*/
                    // decomment it if you want to find bugs
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        this_thread::sleep_for(chrono::milliseconds(500));
                    }
                    cout << endl;
                    if (tolower(confirmFile) == 'n')
                    {
                        cout << string (52, ' ') << CYAN << "Decrypted text is ";
                        cout << PURPLE1 << "\"";
                    }
                    string text_file;
                    for (const string &seg : in_text)
                    {
                        text_file += seg;
                    }
                    if (choose_File == 1)
                    {
                        ofstream outfile(txtFile);
                        if (!outfile.is_open())
                        {
                            cerr << "Error opening file.";
                            return 1;
                        }
                        outfile << text_file;
                        cout << string(52, ' ') << PURPLE1 // GREEN
                             << "\"File decrypted successfully.";
                    }
                    else if (choose_File == 2)
                    {
                        string tempfile = "temp.txt";
                        ofstream out(tempfile);
                        if (!out.is_open())
                        {
                            cerr << "Error parsing docx to txt.";
                            return 1;
                        }
                        out << text_file;
                        out.close();
                        txtToDocx(tempfile, docxFile);
                        cout << string(52, ' ') << "File decrypted successfully\n";
                    }
                    else
                    {
                        cout << text_file;
                        cout << "\"\n"
                             << RESET;
                    }
                }
            } while (true);
        }
        if (cipherchoice == 2)
        {
            printLogo_Y(true);
            string txt, rshift, cshift, chhoice;
            
            
            char choose;
            int rows = 0, cols = 0, rowShift = 0, colShift = 0;

            do
            {
                cout << string(52, ' ') << YELLOW << "(E)ncrypt, (D)ecrypt, or (Q)uit? " << PURPLE1;
                getline(cin >> ws, chhoice);
                cout << RESET;

                if (chhoice.empty() || chhoice.size() != 1 ||
                    (tolower(chhoice[0]) != 'e' && tolower(chhoice[0]) != 'd' && tolower(chhoice[0]) != 'q'))
                {
                    cout << string(52, ' ') << RED << "Invalid choice. Please enter E, D, or Q." << RESET << endl;
                    continue;
                }
                choose = tolower(chhoice[0]);
                if (choose == 'q')
                    break;
                
                cout << string(52, ' ') << YELLOW << "Enter the text: " << PURPLE1;
                getline(cin >> ws, txt);
                

                txt.erase(remove(txt.begin(), txt.end(), ' '), txt.end());
                int textLength = txt.size();

                // Get rows and columns
                while (true)
                {
                    string temp;
                    cout << string(52, ' ') << YELLOW << "Enter the number of rows: " << PURPLE1;
                    cin >> temp;
                    cin.ignore();
                    cout << RESET;
                    if (!isvalid(temp) || !isNumber(temp))
                    {
                        cout << string(52, ' ') << RED << "Invalid input." << RESET << endl;
                        continue;
                    }
                    try{
                    rows = stoi(temp);
                    }
                    catch(exception &e)
                    {
                        cout << string(52, ' ') << RED <<"Plese Enter Appropriate Number." << endl;
                        continue;
                    }
                    cout << string(52, ' ') << YELLOW << "Enter the number of columns: " << PURPLE1;
                    cin >> temp;
                    cin.ignore();
                    cout << RESET;
                    if (!isvalid(temp) || !isNumber(temp))
                    {
                        cout << string(52, ' ') << RED << "Invalid input." << RESET << endl;
                        continue;
                    }
                    try{
                    cols = stoi(temp);
                    }
                    catch(exception &e)
                    {
                       cout << string(52, ' ') << RED <<"Plese Enter Appropriate Number." << endl;
                        continue;
                    }
                    if (rows * cols < textLength)
                    {
                        cout << string(52, ' ') << RED << "Rows x Columns too small." << RESET << endl;
                        continue;
                    }
                    else if (rows * cols > textLength)
                    {
                        cout << string(52, ' ') << YELLOW << "Note: Text will be padded with 'X' to fit the grid." << RESET << endl;
                    }
                    break;
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                // Show original grid
                vector<vector<char>> originalGrid = fillGrid(txt, rows, cols);
                showGrid(originalGrid, rows, cols, "Original Grid");

                cout << string(52, ' ') << YELLOW << "Note: For downshift/rightshift, no need to use (+)." << RESET << endl;

                // Get row shift
                while (true)
                {
                    cout << string(52, ' ') << YELLOW << "How many rows do you want to shift (- up / + down): " << PURPLE1;
                    cin >> rshift;
                    cin.ignore();
                    cout << RESET;
                    if (!isvalid(rshift) || !isNumber(rshift))
                    {
                        cout << string(52, ' ') << RED << "Invalid row shift." << RESET << endl;
                        continue;
                    }
                    try{
                    rowShift = stoi(rshift);
                    break;
                    }
                    catch(exception &e)
                    {
                        cout << "Please enter the appropriate number";
                        continue;
                    }
                }

                // Get column shift
                while (true)
                {
                    cout << string(52, ' ') << YELLOW << "How many columns do you want to shift (- left / + right): " << PURPLE1;
                    cin >> cshift;
                    cin.ignore();
                    cout << RESET;
                    if (!isvalid(cshift) || !isNumber(cshift))
                    {
                        cout << string(52, ' ') << RED << "Invalid column shift." << RESET << endl;
                        continue;
                    }
                    try{
                    colShift = stoi(cshift);
                    break;
                    }
                    catch(exception &e)
                    {
                        cout << string(52, ' ') << RED << "Please enter the appropriate number" << endl;
                        continue;
                    }
                }

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (choose == 'e')
                {
                    vector<vector<char>> grid = fillGrid(txt, rows, cols);
                    vector<vector<char>> shiftedGrid = shiftGrid(grid, rows, cols, rowShift, colShift);
                    showGrid(shiftedGrid, rows, cols, "Shifted Grid");

                    string cipher = transposeEncrypt(shiftedGrid, rows, cols);
                    cout << string(52, ' ') << YELLOW << "Cipher text: " << PURPLE1 << cipher << RESET << "\n\n";
                }
                else if (choose == 'd')
                {
                    vector<vector<char>> cipherGrid = fillGrid(txt, rows, cols);
                    showGrid(cipherGrid, rows, cols, "Cipher Grid");

                    string plain = transposeDecrypt(txt, rows, cols, rowShift, colShift);

                    vector<vector<char>> decryptedGrid = fillGrid(plain, rows, cols);
                    showGrid(decryptedGrid, rows, cols, "Decrypted Grid");

                    while (!plain.empty() && plain.back() == 'X')
                        plain.pop_back();
                    
                    
                    cout << string(52, ' ') << YELLOW << "Plain text: " << PURPLE1 << plain << RESET << "\n\n";
                    
                }

            } while (true);

            cout << string(52, ' ') << YELLOW << "Thank You!" << RESET << endl;
        }
        if (cipherchoice == 3)
        {
            printLogo_C(true);
            while (true)
            {
                string choiceStr;
                char choice;

                cout << string(52, ' ') << YELLOW << "(E)ncrypt, (D)ecrypt, or (Q)uit? " << PURPLE1;
                getline(cin >> ws, choiceStr);
                cout << RESET;

                if (choiceStr.empty() ||
                    choiceStr.size() != 1 ||
                    (tolower(choiceStr[0]) != 'e' &&
                     tolower(choiceStr[0]) != 'd' &&
                     tolower(choiceStr[0]) != 'q'))
                {
                    cout << string(52, ' ') << RED << "Invalid choice. Please enter E, D, or X." << RESET << endl;
                    continue;
                }

                choice = tolower(choiceStr[0]);

                if (choice == 'q')
                {
                    system("cls");
                    cout << string(52, ' ') << YELLOW << "Thank You" << RESET << endl;
                    cout << string(52, ' ') << PURPLE1 << "Exiting The Program";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        this_thread::sleep_for(chrono::milliseconds(300));
                    }

                    break;
                }

                system("cls");
                printLogo_C(false);
                // Input message
                string message;
                while (true)
                {
                    cout << string(52, ' ') << YELLOW << "Enter the text: " << PURPLE1;
                    getline(cin >> ws, message);
                    cout << RESET;
                    if (!message.empty())
                        break;
                    cout << string(52, ' ') << RED << "Message cannot be empty! Please enter again." << RESET << endl;
                }

                // Input shift
                string shiftInput;
                int s_input;
                while (true)
                {
                   
                    cout << string(52, ' ') << YELLOW << "Enter shift value: " << PURPLE1;
                    getline( cin >> ws, shiftInput);
                    cout << RESET;
                    if (!isvalid(shiftInput) || !isNumber(shiftInput))
                    {
                        cout << string(52, ' ') << RED << "Please Enter Appropriate Number." << RESET << endl;
                        continue;
                    }
                    try{
                    s_input = stoi(shiftInput);
                    break;
                    }
                    catch(exception &e)
                    {
                        cout << string(52, ' ') << RED << "Please Enter Appropriate Number." << endl;
                        continue;
                    }
            }
                int shift_mod = (stoi(shiftInput) % 26 + 26) % 26;
                
                if (choice == 'e')
                {
                    cout << string(52, ' ') << GREEN << "Encrypted text: \"" << encryptCaesar(message, shift_mod) << "\"" << RESET << endl;
                }
                else
                {
                    cout << string(52, ' ') << GREEN << "Decrypted text: \"" << decryptCaesar(message, shift_mod) << "\"" << RESET << endl;
                }
            }
        }
        if (cipherchoice == 4)
        {
            cout << string(52, ' ') << YELLOW << "Quitting The Program";
            for (int i = 0; i < 3; i++)
            {
                cout << YELLOW << ".";
                this_thread::sleep_for(chrono::seconds(1));
            }
            cout << RESET;
            break;
        }
        cout << endl;
        char enter;
        do
        {
            cout << string(52,' ') << CYAN << "Press Enter to Return to the Main Screen...";
            enter = cin.get();
        } while (enter != '\n');
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");
    }
}  

int vec_to_int(const vector<int> &v)
{
    ostringstream oss;
    for (int d : v)
        oss << d;
    return stoi(oss.str());
}

void encryptX(vector<string> &texti, int x[])
{
    const int MIN_ASCII = 32; // ' '
    const int RANGE = 95;     // 126 - 32 + 1

    for (int i = 0; i < (int)texti.size(); i++)
    {
        for (int j = 0; j < (int)texti[i].size(); j++)
        {
            unsigned char ch = texti[i][j];
            if (ch >= MIN_ASCII && ch <= 126)
            {
                int shift = (x[i % 3]+(2*i)) % RANGE;
                if (shift == 0) shift = 3;
                int off = (ch - MIN_ASCII + shift) % RANGE;
                texti[i][j] = char(MIN_ASCII + off);
            }
        }
    }
}

void decryptX(vector<string> &texti, int x[])
{
    const int MIN_ASCII = 32;
    const int RANGE = 95;

    for (int i = 0; i < (int)texti.size(); i++)
    {
        for (int j = 0; j < (int)texti[i].size(); j++)
        {
            unsigned char ch = texti[i][j];
            if (ch >= MIN_ASCII && ch <= 126)
            {
                int shift = (x[i % 3]+(2*i)) % RANGE;
                if (shift == 0) shift = 3;
                int off = (ch - MIN_ASCII - shift) % RANGE;
                if (off < 0)
                    off += RANGE;
                texti[i][j] = char(MIN_ASCII + off);
            }
        }
    }
}

int shuffl(vector<string> &names, vector<string> &new_name)
{
    random_device rd;
    mt19937 gen(rd());
    vector<int> idx(names.size());
    for (int i = 0; i < (int)names.size(); i++)
        idx[i] = i;
    shuffle(idx.begin(), idx.end(), gen);

    new_name.reserve(names.size() + 1);
    for (int k : idx)
        new_name.push_back(names[k]);

    return vec_to_int(idx);
}

int formulaX(int n) { return ((5LL * ((n * 7LL) + 3LL)) % 997LL) + 1LL; }
int formulaY(int n) { return (5 * ((n * 7) + 3)) + 1; }
int formulaYverse(int n) { return (n - 16) / 35; }
int xor_addition(int a, int b) { return a ^ b; }

void addHeader(vector<string> &ciphertext, int shuffleOrder)
{
    int enc = formulaY(shuffleOrder);
    string encStr = to_string(enc);
    string header = to_string((int)encStr.size()) + encStr;
    ciphertext.insert(ciphertext.begin(), header);
}

vector<string> splitRandom(const string &input, int parts, char c, int max)
{
    vector<string> result;
    if (input.empty())
        return result;

    if (c == 'e')
    {
        mt19937 rng(static_cast<unsigned>(time(nullptr)));
        uniform_int_distribution<int> dist(3, 5);
        parts = dist(rng);
    }
    if (parts <= 0)
        parts = 1;
    if ((size_t)parts > input.size())
        parts = (int)input.size();

    int n = (int)input.size();
    int segLen = n / parts;
    int extra = n % parts;
    int start = 0;

    if (c == 'e')
    {
        for (int i = 0; i < parts; i++)
        {
            int len = segLen + ((i == parts - 1) ? extra : 0);
            result.push_back(input.substr(start, len));
            start += len;
        }
    }
    else if (c == 'd')
    {
        for (int i = 0; i < parts; i++)
        {
            int len = segLen + ((i == max) ? extra : 0);
            result.push_back(input.substr(start, len));
            start += len;
        }
    }
    return result;
}

int extractHeader(string &text, vector<int> &header, bool &ext)
{
    if (text.empty() || !isdigit((unsigned char)text[0]))
    {
        cout << "\n"
             << string(52, ' ') << RED << "[Error] Missing header length.\n";
        ext = false;
        return -1;
    }
    int lenDigits = text[0] - '0';
    text.erase(0, 1);

    if ((int)text.size() < lenDigits)
    {
        cout << "\n"
             << string(52, ' ') << RED << "[Error] Truncated header payload.\n";
        ext = false;
        return -1;
    }

    for (int i = 0; i < lenDigits; i++)
    {
        if (!isdigit((unsigned char)text[i]))
        {
            cout << "\n"
                 << string(52, ' ') << RED << "[Error] Non-digit in header payload.\n";
            ext = false;
            return -1;
        }
        header.push_back(text[i] - '0');
    }
    text.erase(0, lenDigits);

    int encVal = vec_to_int(header);
    return formulaYverse(encVal);
}

void for_condofzeroupfront(vector<int> &de, int expectedLen)
{
    while ((int)de.size() < expectedLen)
        de.insert(de.begin(), 0);
}

int findMax(const vector<int> &d_header, int seg)
{
    if (d_header.empty())
        return -1;
    int idx = 0, maxVal = d_header[0];
    for (int i = 1; i < seg; i++)
    {
        if (d_header[i] > maxVal)
        {
            maxVal = d_header[i];
            idx = i;
        }
    }
    return idx;
}

void display_mode(string text, vector<string> ini)
{
    cout << "\n"
         << string(52, ' ') << YELLOW << text;
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    cout << endl
         << endl;
    for (string tex : ini)
    {
        cout << string(56, ' ') << PURPLE1 << "╔══";
        for (char cha : tex)
            cout << "═";
        cout << "══╗\n";
        cout << string(56, ' ') << PURPLE1 << "║  " << tex << "  ║\n";
        cout << string(56, ' ') << PURPLE1 << "╚══";
        for (char cha : tex)
            cout << "═";
        cout << "══╝\n";
        cout << string(56, ' ');
        for (char cha : tex)
            cout << "-";
        for (int i = 0; i < 4; i++)
            cout << "-";
        cout << "--";
        cout << endl;
    }
    cout << "\n"
         << RESET;
}
string exportFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file.";
        return "";
    }
    string line;
    string lines;
    while (getline(file, line))
    {
        lines += line;
    }
    return lines;
}

void mainPage_cipherChoice()
{
    vector<string> logo1 = {
        "        ",
        "██╗  ██╗",
        "╚██╗██╔╝",
        " ╚███╔╝ ",
        " ██╔██╗ ",
        "██╔╝ ██╗",
        "╚═╝  ╚═╝",
    };

    vector<string> logo2 = {
        "                         ",
        "███╗    ████████╗    ███╗",
        "██╔╝    ╚══██╔══╝    ╚██║",
        "██║        ██║        ██║",
        "██║        ██║        ██║",
        "███╗       ██║       ███║",
        "╚══╝       ╚═╝       ╚══╝"};

    vector<string> logo3 = {
        "         ",
        " ██████╗ ",
        "██╔════╝ ",
        "██║      ",
        "██║      ",
        "╚██████╗ ",
        " ╚═╝╚══╝ "};

    // Print the logos side by side

    for (int i = 0; i < 7; i++)
    { // 6 lines in each logo
        cout << "                                        " << YELLOW << logo1[i]
             << "               " << logo2[i] << "               " << logo3[i] << RESET << endl;
        this_thread::sleep_for(chrono::milliseconds(230));
    }
    this_thread::sleep_for(chrono::milliseconds(500));
    // Print the menu items aligned under each logo
    cout << PURPLE1 << "                            ╔══════════════════════╗" << "         "
         << "╔══════════════════════╗" << "           "
         << "╔══════════════════════╗" << endl;
    cout << CYAN
         << "                            ║   [1] FormuLa - X    ║" << "         "
         << "║ [2] Transpose Cipher ║" << "           "
         << "║ [3] Caesar Cipher    ║" << endl;
    cout << PURPLE1
         << "                            ╚══════════════════════╝" << "         "
         << "╚══════════════════════╝" << "           "
         << "╚══════════════════════╝" << RESET << endl;
    cout << "\n\n\n";
    string tt = "\t\t\t\tWELCOME TO OUR FORMULA-X CIPHER BOX. YOU CAN CHOOSE ONE OF THE THREE OPTIONS PROVIDED ABOVE.";
    cout << CYAN;
    for (int j = 0; j < tt.length(); j++)
    {
        cout << tt[j];
        this_thread::sleep_for(chrono::milliseconds(20));
    }
    cout << RESET;
    cout << GREY << "\n\t\t\t\t\t\t\t  Tip:FORMULA-X IS THE MOST SECURE AMONG THEM ALL.\n";
    // approximate
    cout << string(58, ' ') << CYAN << "----------------------------------------------" << RESET << endl;

    cout << string(58 + 5, ' ');
    cout << YELLOW << BOLD << "What Cipher are you choosing?" << RESET;
    cout << "\n\n";
    int ch;

    cout << string(65, ' ') << "╔════════════════════╗\n";
    cout << string(65, ' ') << "║   CIPHER BOX MENU  ║\n";
    cout << string(65, ' ') << "╠════════════════════╣\n";
    cout << string(65, ' ') << "║ [1] FormuLa - X    ║\n";
    cout << string(65, ' ') << "║ [2] Transpose      ║\n";
    cout << string(65, ' ') << "║ [3] Caesar Caesar  ║\n";
    cout << string(65, ' ') << "║ [4] Quit           ║\n";
    cout << string(65, ' ') << "╚════════════════════╝\n";
    
}

string docxToTxt(string docxFile, string textfile)
{
    string tempfile = "temp.txt";
    string pythonScriptToText = "docxtotxt.py";
    string command = "python \"" + pythonScriptToText + "\" \"" + docxFile + "\" \"" + textfile + "\"";
    int result = system(command.c_str());
    if (result != 0)
    {
        cerr << "Error parsing docx to txt.";
        return "";
    }
    string line, content;
    ifstream infile(textfile);
    if (!infile.is_open())
    {
        cerr << "Error opening temporary text file.";
        return "";
    }
    while (getline(infile, line))
    {
        content += line;
    }
    infile.close();
    remove(textfile.c_str());
    return content;
}
void txtToDocx(string text, string docxFile)
{
    string pythonScriptToDocx = "txt_to_docx.py";
    string command = "python \"" + pythonScriptToDocx + "\" \"" + text + "\" \"" + docxFile + "\"";
    int result = system(command.c_str());
    if (result != 0)
    {
        cerr << "Error converting txt to docx.";
        return;
    }
    cout << string (52, ' ') << "File converted to docx successfully.\n";
}
void printLogo_X(bool first)
{
    /*cout << PURPLE1 << R"(hehe
                                                                        ██╗  ██╗
                                                                        ╚██╗██╔╝
                                                                         ╚███╔╝
                                                                         ██╔██╗
                                                                        ██╔╝ ██╗
                                                                        ╚═╝  ╚═╝)";
        cout << RESET;*/
    vector<string> logo_x = {
        "██╗  ██╗",
        "╚██╗██╔╝",
        " ╚███╔╝ ",
        " ██╔██╗ ",
        "██╔╝ ██╗",
        "╚═╝  ╚═╝",
    };
    if (first)
    {   
        for (int i = 0; i < 6; i++)
        { // 6 lines in each logo
            cout << "\t\t\t\t\t\t\t\t\t  " << PURPLE1 << logo_x[i] << endl;
            this_thread::sleep_for(chrono::milliseconds(250));
        }
        cout << RESET;
    }
    else if(!first)
    {
         for (int i = 0; i < 6; i++)
        { // 6 lines in each logo
            cout << "\t\t\t\t\t\t\t\t\t  " << PURPLE1 << logo_x[i] << endl;
        }
        cout << RESET;
    }
}
int getTerminalWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return 80; // default width if something goes wrong
}

void printKeyLogo()
{
    cout << CYAN << R"(
                                                                                                                                                                                                                                                                                                                              
                                        :=+******+=:.                                                
                                    -=-:...   ..-:==:                                              
                                    .-*===+-:...-===*#=.                                             
                                    -=--==*#****##*==-==:                                            
                                    ++-:+**=:...-+*+:-=*-                                            
                                    *+=+=.-******=.-++:*=                                            
                                    **...=#*******=...:***********************************+-         
                                    **. .**.    .**....=-.                              .:=+         
                                    **. .**      **....--..                  .....   ....--*         
                                    **. .**      **....-+********************************++*         
                                    **. .**.    .**....-+****************+=:... ..-+*+:...**         
                                    **...=#*******+...:******************##*=:. .-***#+...**         
                                    *#.:.:=******=:...-*=                .-+*=...+*:.**...**         
                                    *#:..:........::.:=*-                  :+**+*#+. +#*+**+         
                                    =##=..:::..::::.:+#+:                  .-+***+:. :+***+:         
                                    :-*#*=........-+*#+:.                     .:.      .:.           
                                    -+#%######%##%*=:                                              
                                        :+********+-.   
                                        
                                        
)";
}

void printLogo_Y(bool first)
{
    vector<string> logo_y = {
        "███╗    ████████╗    ███╗",
        "██╔╝    ╚══██╔══╝    ╚██║",
        "██║        ██║        ██║",
        "██║        ██║        ██║",
        "███╗       ██║       ███║",
        "╚══╝       ╚═╝       ╚══╝"};
    if (first)
    {    for (int i = 0; i < 6; i++)
        { // 6 lines in each logo
            cout << "\t\t\t\t\t\t\t\t  " << PURPLE1 << logo_y[i] << endl;
            this_thread::sleep_for(chrono::milliseconds(250));
        }
        cout << RESET;
    }    
    else if(!first)
    {
        for (int i = 0; i < 6; i++)
    { // 6 lines in each logo
        cout << "\t\t\t\t\t\t\t\t  " << PURPLE1 << logo_y[i] << endl;
    }
    cout << RESET;
    }
}

void printLogo_C(bool first)
{
    vector<string> logo_C = {
        " ██████╗ ",
        "██╔════╝ ",
        "██║      ",
        "██║      ",
        "╚██████╗ ",
        " ╚═╝╚══╝ "};
    if (first)    
    {   
        for (int i = 0; i < 6; i++)
        { // 6 lines in each logo
            cout << "\t\t\t\t\t\t\t\t  " << PURPLE1 << logo_C[i] << endl;
            
            this_thread::sleep_for(chrono::milliseconds(250));
        }
        cout << RESET;
    }
    else if (!first)
    {
        for (int i = 0; i < 6; i++)
        { // 6 lines in each logo
            cout << "\t\t\t\t\t\t\t\t  " << PURPLE1 << logo_C[i] << endl;
            
        }
        cout << RESET;
    }
}
void enableANSI()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
        return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
        return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
void txtPrint()
{
    vector<string> logo = {
        "████████╗██╗░░██╗████████╗",
        "╚══██╔══╝╚██╗██╔╝╚══██╔══╝",
        "░░░██║░░░░╚███╔╝░░░░██║░░░",
        "░░░██║░░░░██╔██╗░░░░██║░░░",
        "░░░██║░░░██╔╝╚██╗░░░██║░░░",
        "░░░╚═╝░░░╚═╝░░╚═╝░░░╚═╝░░░"
    };
    vector<string> logo1 = {
       
    "██████╗░░█████╗░░█████╗░██╗░░██╗",
    "██╔══██╗██╔══██╗██╔══██╗╚██╗██╔╝",
    "██║░░██║██║░░██║██║░░╚═╝░╚███╔╝░",
    "██║░░██║██║░░██║██║░░██╗░██╔██╗░",
    "██████╔╝╚█████╔╝╚█████╔╝██╔╝╚██╗",
    "╚═════╝░░╚════╝░░╚════╝░╚═╝░░╚═╝",
    };

    for(int i=0;i<logo.size();i++)
    {
        cout<<string(35, ' ')<<GREY<<logo[i] << string(10, ' ')<<CYAN<<logo1[i]<<RESET<<endl;
    }
}
void txtIIllustrate()
{
    vector<string> logo = {
        "████████╗██╗░░██╗████████╗",
        "╚══██╔══╝╚██╗██╔╝╚══██╔══╝",
        "░░░██║░░░░╚███╔╝░░░░██║░░░",
        "░░░██║░░░░██╔██╗░░░░██║░░░",
        "░░░██║░░░██╔╝╚██╗░░░██║░░░",
        "░░░╚═╝░░░╚═╝░░╚═╝░░░╚═╝░░░"
    };
    for(auto& line: logo){
        cout<<string(52, ' ')<<GREY<<line<<RESET<<endl;
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}
void docx()
{
    vector<string> logo = {
       
    "██████╗░░█████╗░░█████╗░██╗░░██╗",
    "██╔══██╗██╔══██╗██╔══██╗╚██╗██╔╝",
    "██║░░██║██║░░██║██║░░╚═╝░╚███╔╝░",
    "██║░░██║██║░░██║██║░░██╗░██╔██╗░",
    "██████╔╝╚█████╔╝╚█████╔╝██╔╝╚██╗",
    "╚═════╝░░╚════╝░░╚════╝░╚═╝░░╚═╝",
    };
    for(auto& line: logo)
    {
        cout<<string(52, ' ')<<CYAN<<line<<RESET<<endl;
        this_thread::sleep_for(chrono::milliseconds(150));
    }
}

void pause()
{
    
    char enter;
    do
    {
        cout << string(52,' ') << GREY << "Press Enter to continue....";
        enter = cin.get();
    } while (enter != '\n');
    
}
bool isFileLocked(const string& filename){
    HANDLE hFILE = CreateFileA(
        filename.c_str(),
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
    if(hFILE == INVALID_HANDLE_VALUE){
        return true;
    }
    CloseHandle(hFILE);
    return false;
    
}
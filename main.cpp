#include <iostream>

#include "TeamManagement.h"
#include "PlayerManagement.h"
#include "BestX1.h"

using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\n==========================================" << endl;
        cout << "          CRICKET MANAGEMENT" << endl;
        cout << "==========================================" << endl;

        cout << "1. Team Management" << endl;
        cout << "2. Player Management" << endl;
        cout << "3. Predict Best X1" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int teamChoice;

                do
                {
                    cout << "\n========== TEAM MANAGEMENT ==========" << endl;
                    cout << "1. Add Team" << endl;
                    cout << "2. Display Teams" << endl;
                    cout << "3. Search Team" << endl;
                    cout << "4. Update Team" << endl;
                    cout << "5. Delete Team" << endl;
                    cout << "0. Back" << endl;

                    cout << "Enter your choice: ";
                    cin >> teamChoice;

                    switch(teamChoice)
                    {
                        case 1:
                            addTeam();
                            break;

                        case 2:
                            displayTeams();
                            break;

                        case 3:
                            searchTeam();
                            break;

                        case 4:
                            updateTeam();
                            break;

                        case 5:
                            deleteTeam();
                            break;

                        case 0:
                            break;

                        default:
                            cout << "Invalid choice." << endl;
                    }

                } while(teamChoice != 0);

                break;
            }

            case 2:
            {
                int playerChoice;

                do
                {
                    cout << "\n========= PLAYER MANAGEMENT =========" << endl;
                    cout << "1. Add Player" << endl;
                    cout << "2. Display Players" << endl;
                    cout << "3. Search Player" << endl;
                    cout << "4. Delete Player" << endl;
                    cout << "5. Display Players in Team wise";
                    cout << "0. Back" << endl;

                    cout << "Enter your choice: ";
                    cin >> playerChoice;

                    switch(playerChoice)
                    {
                        case 1:
                            addPlayer();
                            break;

                        case 2:
                            displayPlayers();
                            break;

                        case 3:
                            searchPlayer();
                            break;

                        case 4:
                            deletePlayer();
                            break;
                        case 5:
                            displayPlayersByTeam();
                            break;

                        case 0:
                            break;

                        default:
                            cout << "Invalid choice." << endl;
                    }

                } while(playerChoice != 0);

                break;
            }
            case 3:
                    int teamID;
                    cout << "Enter the Team ID : ";
                    cin >> teamID;
                    predictBestX1(teamID);
                    break;

            case 0:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice." << endl;
        }

    } while(choice != 0);

    return 0;
}
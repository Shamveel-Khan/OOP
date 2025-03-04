#include <iostream>
#include <string>

using namespace std;

class Ball {
private:
    int x, y;
public:
    Ball(int initialX = 0, int initialY = 0) : x(initialX), y(initialY) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void move(int dx, int dy) { x += dx; y += dy; }
    void getPosition(int& outX, int& outY) const { outX = x; outY = y; }
};

class Robot {
private:
    string name;
    int hits;
public:
    Robot(const string& robotName) : name(robotName), hits(0) {}
    void hitBall(int& ballX, int& ballY, const string& direction) {
        if (direction == "up") ballY += 1;
        else if (direction == "down") ballY -= 1;
        else if (direction == "left") ballX -= 1;
        else if (direction == "right") ballX += 1;
        hits++;
    }
    string getName() const { return name; }
    int getHits() const { return hits; }
};

class Goal {
private:
    int x, y;
public:
    Goal(int goalX = 3, int goalY = 3) : x(goalX), y(goalY) {}
    bool isGoalReached(int ballX, int ballY) const { return ballX == x && ballY == y; }
    int getX() const { return x; }
    int getY() const { return y; }
};

class Team {
private:
    string teamName;
    Robot* robot;
public:
    Team(const string& name, Robot* r) : teamName(name), robot(r) {}
    string getTeamName() const { return teamName; }
    Robot* getRobot() const { return robot; }
};

class Game {
private:
    Team* teamOne;
    Team* teamTwo;
    Ball ball;
    Goal goal;
public:
    Game(Team* t1, Team* t2) : teamOne(t1), teamTwo(t2), ball(0, 0), goal(3, 3) {}
    void play(Team* team) {
        Robot* robot = team->getRobot();
        cout << "Team " << team->getTeamName() << " is playing." << endl;
        while (!goal.isGoalReached(ball.getX(), ball.getY())) {
            string direction;
            if (ball.getX() < goal.getX()) direction = "right";
            else if (ball.getX() > goal.getX()) direction = "left";
            else if (ball.getY() < goal.getY()) direction = "up";
            else direction = "down";
            int ballX = ball.getX(), ballY = ball.getY();
            robot->hitBall(ballX, ballY, direction);
            ball.move(ballX - ball.getX(), ballY - ball.getY());
            cout << "Robot " << robot->getName() << " hit the ball " << direction << ". Ball position: (" << ball.getX() << ", " << ball.getY() << ")" << endl;
        }
        cout << "Team " << team->getTeamName() << " reached the goal in " << robot->getHits() << " hits!" << endl;
        ball = Ball(0, 0);
    }
    void startGame() {
        cout << "Game started!" << endl;
        cout << "Goal position: (" << goal.getX() << ", " << goal.getY() << ")" << endl;
        play(teamOne);
        play(teamTwo);
        declareWinner();
    }
    void declareWinner() {
        Robot* robotOne = teamOne->getRobot();
        Robot* robotTwo = teamTwo->getRobot();
        cout << "\nGame Results:" << endl;
        cout << "Team " << teamOne->getTeamName() << " took " << robotOne->getHits() << " hits." << endl;
        cout << "Team " << teamTwo->getTeamName() << " took " << robotTwo->getHits() << " hits." << endl;
        if (robotOne->getHits() < robotTwo->getHits()) cout << "Team " << teamOne->getTeamName() << " wins!" << endl;
        else if (robotTwo->getHits() < robotOne->getHits()) cout << "Team " << teamTwo->getTeamName() << " wins!" << endl;
        else cout << "It's a tie!" << endl;
    }
};

int main() {
    cout<<"\nSHAMVEEL KHAN\n24K-0962\n";
    cout << "\n===== Football Game Simulation =====" << endl;
    cout << "\nCreating robots..." << endl;
    Robot* robotA = new Robot("Striker-1");
    Robot* robotB = new Robot("Kicker-2");
    cout << "Created robot: " << robotA->getName() << endl;
    cout << "Created robot: " << robotB->getName() << endl;
    cout << "\nForming teams..." << endl;
    Team* teamA = new Team("Red Dragons", robotA);
    Team* teamB = new Team("Blue Eagles", robotB);
    cout << "Team " << teamA->getTeamName() << " formed with robot " << teamA->getRobot()->getName() << endl;
    cout << "Team " << teamB->getTeamName() << " formed with robot " << teamB->getRobot()->getName() << endl;
    cout << "\n===== Starting the Actual Game =====" << endl;
    Game game(teamA, teamB);
    game.startGame();
    cout << "\nCleaning up resources..." << endl;
    delete robotA;
    delete robotB;
    delete teamA;
    delete teamB;
    cout << "Resources cleaned up successfully." << endl;
    return 0;
}

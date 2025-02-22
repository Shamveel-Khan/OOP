#include <iostream>
#include <string>

class Ball {
private:
    int x;
    int y;

public:
    Ball(int initialX = 0, int initialY = 0) : x(initialX), y(initialY) {}

    int getX() const { return x; }
    int getY() const { return y; }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void getPosition(int& outX, int& outY) const {
        outX = x;
        outY = y;
    }
};

class Robot {
private:
    std::string name;
    int hits;

public:
    Robot(const std::string& robotName) : name(robotName), hits(0) {}

    void hitBall(int& ballX, int& ballY, const std::string& direction) {
        if (direction == "up") {
            ballY += 1;
        } else if (direction == "down") {
            ballY -= 1;
        } else if (direction == "left") {
            ballX -= 1;
        } else if (direction == "right") {
            ballX += 1;
        }
        hits++;
    }

    std::string getName() const { return name; }
    int getHits() const { return hits; }
};

class Goal {
private:
    int x;
    int y;

public:
    Goal(int goalX = 3, int goalY = 3) : x(goalX), y(goalY) {}

    bool isGoalReached(int ballX, int ballY) const {
        return (ballX == x && ballY == y);
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

class Team {
private:
    std::string teamName;
    Robot* robot; 

public:
    Team(const std::string& name, Robot* r) : teamName(name), robot(r) {}

    std::string getTeamName() const { return teamName; }
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
        std::cout << "Team " << team->getTeamName() << " is playing." << std::endl;

        while (!goal.isGoalReached(ball.getX(), ball.getY())) {
            std::string direction;
            if (ball.getX() < goal.getX()) {
                direction = "right";
            } else if (ball.getX() > goal.getX()) {
                direction = "left";
            } else if (ball.getY() < goal.getY()) {
                direction = "up";
            } else {
                direction = "down";
            }

            int ballX = ball.getX();
            int ballY = ball.getY();
            robot->hitBall(ballX, ballY, direction);
            ball.move(ballX - ball.getX(), ballY - ball.getY());

            std::cout << "Robot " << robot->getName() << " hit the ball " << direction 
                      << ". Ball position: (" << ball.getX() << ", " << ball.getY() << ")" << std::endl;
        }

        std::cout << "Team " << team->getTeamName() << " reached the goal in " 
                  << robot->getHits() << " hits!" << std::endl;
        ball = Ball(0, 0);
    }

    void startGame() {
        std::cout << "Game started!" << std::endl;
        std::cout << "Goal position: (" << goal.getX() << ", " << goal.getY() << ")" << std::endl;
        play(teamOne);
        play(teamTwo);
        declareWinner();
    }

    void declareWinner() {
        Robot* robotOne = teamOne->getRobot();
        Robot* robotTwo = teamTwo->getRobot();

        std::cout << "\nGame Results:" << std::endl;
        std::cout << "Team " << teamOne->getTeamName() << " took " << robotOne->getHits() << " hits." << std::endl;
        std::cout << "Team " << teamTwo->getTeamName() << " took " << robotTwo->getHits() << " hits." << std::endl;

        if (robotOne->getHits() < robotTwo->getHits()) {
            std::cout << "Team " << teamOne->getTeamName() << " wins!" << std::endl;
        } else if (robotTwo->getHits() < robotOne->getHits()) {
            std::cout << "Team " << teamTwo->getTeamName() << " wins!" << std::endl;
        } else {
            std::cout << "It's a tie!" << std::endl;
        }
    }
};

int main() {       
    cout<<"\nShamveel Khan\n24k-0962\n";   
    std::cout << "\n===== Football Game Simulation =====" << std::endl;
        
    std::cout << "\nCreating robots..." << std::endl;
    Robot* robotA = new Robot("Striker-1");
    Robot* robotB = new Robot("Kicker-2");
    std::cout << "Created robot: " << robotA->getName() << std::endl;
    std::cout << "Created robot: " << robotB->getName() << std::endl;
    
    std::cout << "\nForming teams..." << std::endl;
    Team* teamA = new Team("Red Dragons", robotA);
    Team* teamB = new Team("Blue Eagles", robotB);
    std::cout << "Team " << teamA->getTeamName() << " formed with robot " << teamA->getRobot()->getName() << std::endl;
    std::cout << "Team " << teamB->getTeamName() << " formed with robot " << teamB->getRobot()->getName() << std::endl;
    
    std::cout << "\nTesting Ball functionality..." << std::endl;
    Ball testBall(1, 1);
    std::cout << "Initial ball position: (" << testBall.getX() << ", " << testBall.getY() << ")" << std::endl;
    testBall.move(2, 1);
    std::cout << "After move(2, 1), position: (" << testBall.getX() << ", " << testBall.getY() << ")" << std::endl;
    int ballX, ballY;
    testBall.getPosition(ballX, ballY);
    std::cout << "Retrieved position using getPosition(): (" << ballX << ", " << ballY << ")" << std::endl;
    
    std::cout << "\nTesting Robot's hitBall functionality..." << std::endl;
    int demoX = 0, demoY = 0;
    std::cout << "Initial position: (" << demoX << ", " << demoY << ")" << std::endl;
    robotA->hitBall(demoX, demoY, "right");
    std::cout << "After hitting right: (" << demoX << ", " << demoY << "), hits: " << robotA->getHits() << std::endl;
    robotA->hitBall(demoX, demoY, "up");
    std::cout << "After hitting up: (" << demoX << ", " << demoY << "), hits: " << robotA->getHits() << std::endl;
    
    std::cout << "\nTesting Goal functionality..." << std::endl;
    Goal testGoal(3, 3);
    std::cout << "Goal position: (" << testGoal.getX() << ", " << testGoal.getY() << ")" << std::endl;
    std::cout << "Is goal reached at (1, 1)? " << (testGoal.isGoalReached(1, 1) ? "Yes" : "No") << std::endl;
    std::cout << "Is goal reached at (3, 3)? " << (testGoal.isGoalReached(3, 3) ? "Yes" : "No") << std::endl;
    
    std::cout << "\n===== Starting the Actual Game =====" << std::endl;
    Game game(teamA, teamB);
    game.startGame();
    
    std::cout << "\nCleaning up resources..." << std::endl;
    delete robotA;
    delete robotB;
    delete teamA;
    delete teamB;
    std::cout << "Resources cleaned up successfully." << std::endl;
    
    return 0;
}

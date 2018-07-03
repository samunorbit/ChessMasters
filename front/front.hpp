#include <SFML/Graphics.hpp>
using namespace sf;

class tabuleiro
{
private:
    int starting_board[8][8] =
    {
        {-2,-3,-4,-5,-6,-4,-3,-2},
        {-1,-1,-1,-1,-1,-1,-1,-1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {2, 3, 4, 5, 6, 4, 3, 2}
    };

    int board[8][8];
    RenderWindow window;
    double x=0,y=0;
    Texture t1,t2[12];
    Sprite pecas, fundo;
    const int tamanho_peca=45;

    void copia_matrix8x8(int m1[8][8],int m2[8][8])
    {
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                m2[i][j]=m1[i][j];
            }
        }
    }

public:
    tabuleiro()
    {
        window.create(VideoMode(800,800),"XADREZ");
        for(int i=0; i<6; i++)
        {
            t2[i].loadFromFile("images2/sprites.png",IntRect(tamanho_peca*i,0,tamanho_peca+tamanho_peca*i,45));
        }

        for(int i=0; i<6; i++)
        {
            t2[i+6].loadFromFile("images2/sprites.png",IntRect(tamanho_peca*i,tamanho_peca,45+tamanho_peca*i,45+tamanho_peca));
        }
        pecas.setTexture(t2[0]);
        pecas.scale(Vector2f(100/tamanho_peca +0.25,100/tamanho_peca +0.25));
        t1.loadFromFile("images2/board2.png");
        fundo.setTexture(t1);
        copia_matrix8x8(starting_board,board);
    }

    bool desenha_tabuleiro()
    {
        int x,y;
        if(window.isOpen())
        {
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed)
                {
                    window.close();
                    return false;
                }
                if (e.type == Event::KeyPressed)
                {

                    if(e.key.code == Keyboard::Escape)
                    {
                        window.close();
                        return false;
                    }
                }

            }
            window.clear();
            window.draw(fundo);

            y=0;
            for(int i=0; i<8; i++)
            {
                x=0;
                for(int j=0; j<8; j++)
                {
                    if(board[i][j]!=0)
                    {
                        pecas.setPosition(x,y);

                        if(board[i][j]==1)
                        {
                            pecas.setTexture(t2[5]);
                        }
                        if(board[i][j]==-1)
                        {
                            pecas.setTexture(t2[11]);
                        }
                        if(board[i][j]==2)
                        {
                            pecas.setTexture(t2[4]);
                        }
                        if(board[i][j]==-2)
                        {
                            pecas.setTexture(t2[10]);
                        }
                        if(board[i][j]==3)
                        {
                            pecas.setTexture(t2[3]);
                        }
                        if(board[i][j]==-3)
                        {
                            pecas.setTexture(t2[9]);
                        }
                        if(board[i][j]==4)
                        {
                            pecas.setTexture(t2[2]);
                        }
                        if(board[i][j]==-4)
                        {
                            pecas.setTexture(t2[8]);
                        }
                        if(board[i][j]==5)
                        {
                            pecas.setTexture(t2[1]);
                        }
                        if(board[i][j]==-5)
                        {
                            pecas.setTexture(t2[7]);
                        }
                        if(board[i][j]==6)
                        {
                            pecas.setTexture(t2[0]);
                        }
                        if(board[i][j]==-6)
                        {
                            pecas.setTexture(t2[6]);
                        }
                        window.draw(pecas);
                    }
                    x+=100;
                }
                y+=100;
            }
            window.display();
            return true;
        }
        return false;
    }

    void setboard(int newboard[8][8])
    {
        copia_matrix8x8(newboard,board);
    }
};

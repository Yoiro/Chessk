#ifndef PIECE_H
#define PIECE_H

#include <QObject>


#include <memory>
#include <set>
#include <typeinfo>
#include <iosfwd>


class Piece : public QObject
{
    Q_OBJECT

    friend class ::board::Board; //Voir pour le lien avec le jeu -> ::chessk::board::Board

public:

    using Position_t = config::BoardConfig::Position_t;
    using Suit_t = config::BoardConfig::SuitClass_t;
    using Class_t = config::BoardConfig::PieceClass_t;

    /**
     * The ::board::Board in wich the Piece exist.
     *
     */
        board::Board & board;

private:
        Position_t p;
        Suit_t s;
        Class_t c;
        std::size_t m=0;


public:
        //Position of the piece
        Position_t const &pos = p;

        //The display of the piece (Gold or Green)
        Suit_t const &suit = s;

        /**
        * The display class of the piece
        * This cannot be used to determine what kind of piece this is, as this value is
        * only for display purposes and may not match the actual type
        */
        Class_t const &pclass = c;

        //The number of moves this piece has made
        std::size_t const &moves = m;

        /**
        * Construct onto a board the given position with the given suit and class
        * \param b The chesspp::board::Board on which this piece is to live, must outlive
        * this instance.
        * \param pos The initial position of this piece.
        * \param s The display suit of the piece.
        * \param pc The display class of the piece.
        */
        Piece(board::Board &b, Position_t const &pos, Suit_t const &s, Class_t const &pc);
        virtual ~Piece() = default;

        //Update movement information , Should not be overriden or shadowed by deriving classes.

        void makeTrajectory()
        {
            addCapturable(pos);
            calcTajectory();
        }


protected:
    /**
     * \brief
     * Called by `makeTrajectory()` to calculate movement information.
     *
     * Implementations should call `addTrajectory()`, `addCapturing()`, and
     * `addCapturable()`, as well as their `remove` counterparts if necessary. By
     * default, `addCapturable()` is called with the current position of the piece
     * before this member function is called.
     */
    virtual void calcTrajectory() = 0;

    /**
     * \brief
     * Mark a position as a valid position to move to without capturing.
     *
     * \param tile The position to mark.
     */
    void addTrajectory(Position_t const &tile);
    /**
     * \brief
     * Unmark a position as a valid position to move to without capturing.
     *
     * \param tile The position to unmark.
     */
    void removeTrajectory(Position_t const &tile);

    /**
     * \brief
     * Mark a position as a valid position to move to when capturing.
     *
     * \param tile The position to mark.
     */
    void addCapturing(Position_t const &tile);
    /**
     * \brief
     * Unmark a position as a valid position to move to when capturing.
     *
     * \param tile The position to unmark.
     */
    void removeCapturing(Position_t const &tile);

    /**
     * \brief
     * Mark a position as a valid position to capture this piece from.
     *
     * \param tile The position to mark.
     */
    void addCapturable(Position_t const &tile);
    /**
     * \brief
     * Unmark a position as a valid position to capture this piece from.
     *
     * \param tile The position to mark.
     */
    void removeCapturable(Position_t const &tile);

private:
    /**
     * \brief
     * Called when another piece moves on the same board.
     *
     * \param m The position of the piece that moved.
     */
    virtual void tick(Position_t const &m)
    {
    }

    /**
     * \brief
     * The chesspp::board::Board calls this to change the position of the piece.
     *
     * \param to The new position of the piece.
     */
    void move(Position_t const &to)
    {
        Position_t from = pos;
        p = to;
        moveUpdate(from, to);
        ++m;
    }

    /**
     * \brief
     * Called after this piece has moved.
     *
     * \note
     * The value of `moves` is not updated until after this member function returns.
     *
     * \param from The old position of the piece.
     * \param to The current position of the piece.
     */
    virtual void moveUpdate(Position_t const &from, Position_t const &to)
    {
    }

public:
    /**
     * \brief
     * Outputs a basic human-readable description of this piece to an output stream.
     *
     * \param os The stream to which to describe this piece.
     * \param p The piece to describe.
     */
    friend std::ostream &operator<<(std::ostream &os, Piece const &p);

    explicit Piece(QObject *parent = nullptr);

signals:

public slots:



};

#endif // PIECE_H

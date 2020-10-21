
class Ops
{
    private:
        int id;

    public:
        Ops()
        {
            this->id = 111;
        }

        int get_id()
        {
            return this->id;
        }
};

typedef struct
{
    int id;
} Entity;

Entity create_entity(int id)
{
    Entity ent;
    ent.id = id;
    return ent;
}
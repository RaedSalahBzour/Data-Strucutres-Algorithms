#include <iostream>
#include <list>
#include <vector>
struct Edge
{
    int DestenationVertexId;
    int Weight;
    Edge(int id,int w):DestenationVertexId(id),Weight(w){}
    void setDestenationVertexId(int id) { DestenationVertexId = id; }
    int getDestenationVertexId() const { return DestenationVertexId; }
    void setWeight(int w) { Weight = w; }
    int getWeight() const { return Weight; }
};
struct Vertex
{
    int id;
    std::string name;
    std::list<Edge>edgeList;
    Vertex() :id(0),name("") {}
    Vertex(int i, std::string n) :id(i), name(n){}
    void setId(int i) { id= i; }
    int getId() const { return id; }
    void setName(std::string n) { name = n; }
    std::string getName() const { return name; }
    std::list<Edge> getEdgeList()
    {
        return edgeList;
    }
    void printEdgeList()
    {
        for (auto it = edgeList.begin();it != edgeList.end();it++)
        {
            std::cout <<"[" << it->getDestenationVertexId() << " : " << it->getWeight()<<"] ";
        }
    }
    
};
struct Graph
{
    std::vector<Vertex>vertices;
    Graph() = default;
    void addVertex(Vertex newVertex)
    {
        if (isVertexExist(newVertex.getId()))
        {
            std::cout << "already exist" << std::endl;
            return;
        }
        vertices.push_back(newVertex);
    }
    bool isVertexExist(int id)const
    {
        for (const Vertex& vertex : vertices)
        {
            if (vertex.getId() == id)
                return true;
        }
        return false;
    }
    Vertex* getVertexById(int id)
    {
        for (Vertex& v : vertices)
        {
            if (v.getId() == id)
                return &v;
        }
         return nullptr;
    }
    void addEdgeFromToById(int fromId, int toId, int w)
    {
        if (isVertexExist(fromId)&&isVertexExist(toId))
        {
            if (isEdgeExist(fromId,toId))
            {
                std::cout << "edge already exist" << std::endl;
                return;
            }
            else
            {
                Vertex* v1 = getVertexById(fromId);
                if (v1)
                {
                    v1->edgeList.emplace_back(toId,w);
                }
            }
        }
        else
        {
            std::cout << "one or more vertices was not found" << std::endl;
        }
    }
    bool isEdgeExist(int v1Id, int v2Id)
    {
         Vertex* v = getVertexById(v1Id);
         if (!v)
             return false;
         for (const Edge& e : v->getEdgeList())
         {
             if (e.getDestenationVertexId() == v2Id)
             {
                 return true;
             }
         }return false;
    }
    void printGraph()
    {
        for (int i{};i < vertices.size();i++)
        {
            Vertex temp;
            temp = vertices.at(i);
            std::cout << temp.getId() << " : " << temp.getName() << "->";
            temp.printEdgeList();
            std::cout << std::endl;
        }
    }
    void updateEdge(int sourceId, int destenationId, int newWeight)
    {
        if (!isEdgeExist(sourceId, destenationId))
        {
            std::cout << "edge doesn't exist" << std::endl;
            return;
        }
        for (Vertex& v : vertices)
        {
            if (v.getId() == sourceId)
            {
                for (Edge& e : v.getEdgeList())
                {
                    if (e.getDestenationVertexId() == destenationId)
                    {
                        e.setWeight(newWeight);
                        return;
                    }
                }
                std::cout << "edge not found";
                return;
            }
        }
        std::cout << "Source vertex not found" << std::endl;
    }
    void deleteEdge(int sourceId, int destenationId)
    {
        if (!isEdgeExist(sourceId, destenationId))
        {
            std::cout << "edge doesn't exist" << std::endl;
            return;
        }
        for (Vertex& v : vertices)
        {
            if (v.getId() == sourceId)
            {
                for (auto it=v.edgeList.begin();it!=v.edgeList.end();it++)
                {
                    if (it->getDestenationVertexId() == destenationId)
                    {
                        v.edgeList.erase(it);
                        return;
                    }
                }
                std::cout << "edge not found";
                return;
            }
        }
        std::cout << "Source vertex not found" << std::endl;
    }
    void deleteVertexById(int id)
    {
        if (!isVertexExist(id))
        {
            std::cout << "vertex was not found";
            return;
        }
        for (Vertex& v : vertices)
        {
           
                v.edgeList.remove_if([id](const Edge& edge)
                    {
                        return edge.getDestenationVertexId() == id;
                    });
                
            
        }
        vertices.erase(
            std::remove_if(vertices.begin(), vertices.end(), [id](const Vertex& v)
                {
                    return v.getId() == id;
                }),
            vertices.end()
        );
    }
    void updateVertex(int vId,std::string n)
    {
        if (!isVertexExist(vId))
        {
            std::cout << "vertex was not found" << std::endl;
            return;
        }
        for (Vertex& v:vertices)
        {
            if (v.getId() == vId)
            {
                v.setName(n);
                return;
            }
        }
        std::cout << "vertex was not found" << std::endl;
    }
};
int main()
{
    Graph g;
    Vertex v1;
    v1.setId(1);
    v1.setName("jenin");
    Vertex v2;
    v2.setId(2);
    v2.setName("ramallah");
    Vertex v3;
    v3.setId(3);
    v3.setName("nablus");
    g.addVertex(v1);
    g.addVertex(v2);
    g.addVertex(v3);
    g.addEdgeFromToById(v1.getId(), v2.getId(),30);
    g.addEdgeFromToById(v1.getId(), v3.getId(),15);
    g.addEdgeFromToById(v3.getId(), v1.getId(),20);
    g.addEdgeFromToById(v2.getId(), v3.getId(),15);
    g.printGraph();
    std::cin.get();
}
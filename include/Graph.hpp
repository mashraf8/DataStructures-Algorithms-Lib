#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream> // Using Basic Things Like cout And cin
#include <typeinfo> // Allows Dynamic Type Identification At Runtime
#include "LinkedList.hpp"
#include "Trees.hpp"

using namespace std;
namespace DataStrcture
{
    template <typename T>
    class Graph
    {
    private:
        class GraphNode
        {
        public:
            class CostNode
            {
            public:
                T data_cost;
                double cost_cost;
                T data_parent;
                CostNode()
                {
                    data_cost = T();
                    cost_cost = -1;
                    data_parent = T();
                }
                CostNode(T data_, double cost_)
                {
                    data_cost = data_;
                    cost_cost = cost_;
                    data_parent = T();
                }
            };
            T data;
            DoublyLinkedList<T> children;
            DoublyLinkedList<T> parent;
            DoublyLinkedList<double> cost;
            bool isvisited = false;
            typename GraphNode::CostNode cost_arr;
            DoublyLinkedList<T> node_path;
            GraphNode()
            {
                data = T();
            }
            GraphNode(T item) :cost_arr(item, -1)
            {

                data = item;
            }
            bool operator ==(GraphNode& other)
            {
                return data == other.data;
            }
            bool operator !=(GraphNode& other)
            {
                return data != other.data;
            }
            bool operator <(GraphNode& other)
            {
                return data < other.data;
            }
            bool operator >(GraphNode& other)
            {
                return data > other.data;

            }
            bool operator <=(GraphNode& other)
            {
                return data <= other.data;
            }
            bool operator >=(GraphNode& other)
            {
                return data >= other.data;
            }
        };
    public:
        AVLTree<GraphNode>* _items;
        Graph()
        {
            _items = new AVLTree<GraphNode>();
        }
        ~Graph()
        {
            _items->Clear();
        }
        void Insert(T value)
        {
            GraphNode* gr_node = new GraphNode(value);
            if (_items->SearchBool(*gr_node))
            {
                return;
            }
            else
            {
                _items->Insert(*gr_node);
            }
        }
        void Delete(T value)
        {
            GraphNode* select_node = SearchNode(value);
            if (select_node == NULL)
            {
                return;
            }
            else
            {
                DeleteChildFromParents(&select_node->parent, select_node);
                DeleteParentFromChilds(&select_node->children, select_node);
                select_node->children.Clear();
                select_node->parent.Clear();
                select_node->cost.Clear();
            }
        }
        void Update(T old_value, T new_value)
        {
            GraphNode* old_select_node = SearchNode(old_value);
            GraphNode* new_select_node = SearchNode(new_value);
            if (old_select_node == NULL || new_select_node != NULL || old_value == new_value)
            {
                return;
            }
            else
            {
                Insert(new_value);
                new_select_node = SearchNode(new_value);
                DoublyLinkedList<T>* parent = new DoublyLinkedList<T>();
                for (int i = 0; i < old_select_node->children.Count(); i++)
                {
                    InsertEdge(new_select_node->data, old_select_node->children.SelectBackward(i), old_select_node->cost.SelectBackward(i));
                }
                for (int i = 0; i < old_select_node->parent.Count(); i++)
                {
                    int index = SearchNode(old_select_node->parent.SelectBackward(i))->children.SelectIndexByValue(old_select_node->data);
                    InsertEdge(old_select_node->parent.SelectBackward(i), new_select_node->data, SearchNode(old_select_node->parent.SelectBackward(i))->cost.SelectForward(index));
                }
                Delete(old_select_node->data);
            }
        }
        void InsertEdge(T from, T to, double cost)
        {
            GraphNode* gr_from = SearchNode(from);
            GraphNode* gr_to = SearchNode(to);
            if (gr_from == NULL || gr_to == NULL || cost < 0)
            {
                return;
            }
            else
            {
                int index_to = gr_from->children.SelectIndexByValue(gr_to->data);
                if (index_to == -1)
                {
                    gr_from->children.InsertFirst(gr_to->data);
                    gr_from->cost.InsertFirst(cost);
                    gr_to->parent.InsertFirst(gr_from->data);
                }
                else
                {
                    return;
                }

            }
        }
        void DeleteEdge(T from, T to)
        {
            GraphNode* gr_from = SearchNode(from);
            GraphNode* gr_to = SearchNode(to);
            if (gr_from == NULL || gr_to == NULL)
            {
                return;
            }
            else
            {
                int index_child = -1;
                int index_parent = -1;
                index_child = gr_from->children.SelectIndexByValue(gr_to->data);
                index_parent = gr_to->parent.SelectIndexByValue(gr_from->data);
                if (index_child == -1)
                {
                    return;
                }
                else
                {
                    gr_from->children.DeleteByIndex(index_child);
                    gr_from->cost.DeleteByIndex(index_child);
                    gr_to->parent.DeleteByIndex(index_parent);
                }


            }
        }
        void UpdateCost(T from, T to, double new_cost)
        {
            GraphNode* gr_from = SearchNode(from);
            GraphNode* gr_to = SearchNode(to);
            if (gr_from == NULL || gr_to == NULL || new_cost < 0)
            {
                return;
            }
            else
            {
                int index_child = -1;
                index_child = gr_from->children.SelectIndexByValue(gr_to->data);
                if (index_child == -1)
                {
                    return;
                }
                else
                {
                    gr_from->cost.Update(index_child, new_cost);
                }


            }
        }
        GraphNode* SearchNode(T value)
        {
            GraphNode* gr_node = new GraphNode(value);
            if (!_items->SearchBool(*gr_node))
            {
                return NULL;
            }
            return SelectNode(gr_node);
        }
        void PrintGraphByDFS(T value)
        {
            GraphNode* select_node = SearchNode(value);
            if (select_node == NULL)
            {
                return;
            }
            else
            {
                PrintGraph(select_node);
                ResetStatus(select_node);
            }
        }
        void ShortPathForAll(T value)
        {
            GraphNode* select_node = SearchNode(value);
            if (select_node == NULL)
            {
                return;
            }
            else
            {
                AllShortPath(select_node);
                PrintPathForNode(select_node);
                ResetStatus(select_node);
            }
        }
        double CostForShortPath(T from, T to)
        {
            GraphNode* from_select_node = SearchNode(from);
            GraphNode* to_select_node = SearchNode(to);
            double ret = -1;
            if (from_select_node == NULL || to_select_node == NULL)
            {
                return -1;
            }
            else
            {
                ShortPathFromTo(from_select_node, to_select_node);
                ret = to_select_node->cost_arr.cost_cost;
                ResetStatus(from_select_node);
                return ret;
            }
        }
        DoublyLinkedList<T>* AllItemPathForShortPath(T from, T to)
        {
            GraphNode* from_select_node = SearchNode(from);
            GraphNode* to_select_node = SearchNode(to);
            DoublyLinkedList<T>* ret = NULL;
            if (from_select_node == NULL || to_select_node == NULL)
            {
                return NULL;
            }
            else
            {
                ShortPathFromTo(from_select_node, to_select_node);
                ret = new DoublyLinkedList<T>();
                for (int i = 0; i < to_select_node->node_path.Count(); i++)
                {
                    ret->InsertFirst(to_select_node->node_path.SelectBackward(i));
                }
                ResetStatus(from_select_node);
                return ret;
            }
        }
        void Clear()
        {
            _items->Clear();
        }

    private:
        GraphNode* SelectNode(GraphNode* value)
        {
            GraphNode* gr_node = &(_items->SearchNode(*value)->_data);
            return gr_node;

        }
        void DeleteChildFromParents(DoublyLinkedList<T>* parents, GraphNode* select_node)
        {
            GraphNode* parent_node;
            int index = -1;
            int i = 0;
            for (i = 0; i < parents->Count(); i++)
            {
                parent_node = SearchNode((*parents).SelectForward(i));
                index = parent_node->children.SelectIndexByValue(select_node->data);
                parent_node->children.DeleteByIndex(index);
                parent_node->cost.DeleteByIndex(index);
            }
        }
        void DeleteParentFromChilds(DoublyLinkedList<T>* childs, GraphNode* select_node)
        {
            GraphNode* child_node;
            int index = -1;
            int i = 0;
            for (i = 0; i < childs->Count(); i++)
            {
                child_node = SearchNode((*childs).SelectForward(i));
                index = child_node->parent.SelectIndexByValue(select_node->data);
                child_node->parent.DeleteByIndex(index);
            }
        }
        void PrintGraph(GraphNode* select_node, int level = 0)
        {
            if (!select_node)
            {
                return;
            }

            if (select_node->isvisited)
            {
                return;
            }

            select_node->isvisited = true;
            for (int i = 0; i < level; i++)
            {
                cout << "  ";
            }
            cout << " Node: " << select_node->data << "\n";

            for (int i = 0; i < select_node->children.Count(); i++)
            {
                GraphNode* child = SearchNode(select_node->children.SelectBackward(i));
                double edge_cost = select_node->cost.SelectBackward(i);
                for (int j = 0; j < level + 1; j++) std::cout << "  ";
                cout << "-> Child: " << child->data << " (Cost: " << edge_cost << ")\n";
                PrintGraph(child, level + 2);

            }
        }
        void ResetStatus(GraphNode* select_node)
        {
            if (!select_node)
            {
                return;
            }
            if (!select_node->isvisited)
            {
                return;
            }
            select_node->isvisited = false;
            select_node->cost_arr.cost_cost = -1;
            select_node->cost_arr.data_parent = T();
            select_node->node_path.Clear();

            for (int i = 0; i < select_node->children.Count(); i++)
            {
                GraphNode* child = SearchNode(select_node->children.SelectForward(i));
                ResetStatus(child);
            }
        }
        void AllShortPath(GraphNode* select_node)
        {
            DoublyLinkedList<typename GraphNode::CostNode>* lin = new DoublyLinkedList<typename GraphNode::CostNode>();
            select_node->cost_arr.cost_cost = 0;
            select_node->isvisited = true;
            select_node->node_path.InsertFirst(select_node->data);
            lin->InsertFirst(select_node->cost_arr);
            GraphNode* currentNode = new GraphNode();
            GraphNode* lastNode = new GraphNode();
            GraphNode* child = new GraphNode();
            double cost_child;
            while (!lin->Isembty())
            {
                currentNode = SearchNode(lin->SelectBackward(0).data_cost);
                lin->DeleteAtEnd();
                lastNode = SearchNode(currentNode->cost_arr.data_parent);
                currentNode->isvisited = true;
                if (currentNode->data != select_node->data)
                {
                    currentNode->cost_arr.cost_cost = lastNode->cost_arr.cost_cost + lastNode->cost.SelectForward(lastNode->children.SelectIndexByValue(currentNode->data));
                    for (int i = 0; i < lastNode->node_path.Count(); i++)
                    {
                        currentNode->node_path.InsertFirst(lastNode->node_path.SelectBackward(i));
                    }
                    currentNode->node_path.InsertFirst(currentNode->data);
                }
                for (int i = 0; i < currentNode->children.Count(); i++)
                {

                    child = SearchNode(currentNode->children.SelectForward(i));

                    if (child->isvisited)
                    {
                        continue;
                    }
                    cost_child = currentNode->cost_arr.cost_cost + currentNode->cost.SelectForward(i);

                    if (InsertInLinkedList(lin, child->cost_arr.data_cost, cost_child, currentNode->data))
                    {
                        child->cost_arr.cost_cost = currentNode->cost_arr.cost_cost + currentNode->cost.SelectForward(currentNode->children.SelectIndexByValue(child->data));
                        child->cost_arr.data_parent = currentNode->data;
                    }



                }



            }




        }
        void ShortPathFromTo(GraphNode* from_select_node, GraphNode* to_select_node)
        {
            DoublyLinkedList<typename GraphNode::CostNode>* lin = new DoublyLinkedList<typename GraphNode::CostNode>();
            from_select_node->cost_arr.cost_cost = 0;
            from_select_node->isvisited = true;
            from_select_node->node_path.InsertFirst(from_select_node->data);
            lin->InsertFirst(from_select_node->cost_arr);
            GraphNode* currentNode = new GraphNode();
            GraphNode* lastNode = new GraphNode();
            GraphNode* child = new GraphNode();
            double cost_child;
            while (!lin->Isembty())
            {
                currentNode = SearchNode(lin->SelectBackward(0).data_cost);
                lin->DeleteAtEnd();
                lastNode = SearchNode(currentNode->cost_arr.data_parent);
                currentNode->isvisited = true;
                if (currentNode->data != from_select_node->data)
                {
                    currentNode->cost_arr.cost_cost = lastNode->cost_arr.cost_cost + lastNode->cost.SelectForward(lastNode->children.SelectIndexByValue(currentNode->data));
                    for (int i = 0; i < lastNode->node_path.Count(); i++)
                    {
                        currentNode->node_path.InsertFirst(lastNode->node_path.SelectBackward(i));
                    }
                    currentNode->node_path.InsertFirst(currentNode->data);
                }
                if (currentNode->data == to_select_node->data)
                {
                    break;
                }
                for (int i = 0; i < currentNode->children.Count(); i++)
                {

                    child = SearchNode(currentNode->children.SelectForward(i));

                    if (child->isvisited)
                    {
                        continue;
                    }
                    cost_child = currentNode->cost_arr.cost_cost + currentNode->cost.SelectForward(i);

                    if (InsertInLinkedList(lin, child->cost_arr.data_cost, cost_child, currentNode->data))
                    {
                        child->cost_arr.cost_cost = currentNode->cost_arr.cost_cost + currentNode->cost.SelectForward(currentNode->children.SelectIndexByValue(child->data));
                        child->cost_arr.data_parent = currentNode->data;
                    }



                }



            }

        }
        bool InsertInLinkedList(DoublyLinkedList<typename GraphNode::CostNode>* lin, T _da, double co, T pa_da)
        {
            if (lin->Isembty())
            {
                typename GraphNode::CostNode cost_node;
                cost_node.data_cost = _da;
                cost_node.cost_cost = co;
                cost_node.data_parent = pa_da;
                lin->InsertFirst(cost_node);
                return true;
            }
            else
            {
                int ind = -1;
                for (int i = 0; i < lin->Count(); i++)
                {
                    if (lin->SelectByIndex(i)->data_cost == _da)
                    {
                        ind = i;
                        break;
                    }
                }

                if (ind != -1)
                {
                    if (lin->SelectByIndex(ind)->cost_cost > co)
                    {
                        lin->DeleteByIndex(ind);
                        InsertWithSortMin(lin, _da, co, pa_da);
                        return true;
                    }
                    return false;
                }
                else
                {
                    InsertWithSortMin(lin, _da, co, pa_da);
                    return true;
                }
            }


        }
        void InsertWithSortMin(DoublyLinkedList<typename GraphNode::CostNode>* lin, T _da, double co, T pa_da)
        {
            int index = 0;
            for (index = 0; index < lin->Count(); ++index)
            {
                if (co > lin->SelectByIndex(index)->cost_cost)
                {
                    break;
                }
            }
            typename GraphNode::CostNode cost_node;
            cost_node.data_cost = _da;
            cost_node.cost_cost = co;
            cost_node.data_parent = pa_da;
            lin->InsertByIndex(index, cost_node);
        }
        void PrintPathForNode(GraphNode* select_node)
        {
            if (!select_node)
            {
                return;
            }

            if (select_node->cost_arr.cost_cost == -1)
            {
                return;
            }
            cout << select_node->data << ": ";
            cout << "Total Cost: " << select_node->cost_arr.cost_cost << " ";
            select_node->node_path.DisplayBackward();
            cout << "\n";
            select_node->cost_arr.cost_cost = -1;
            for (int i = 0; i < select_node->children.Count(); i++)
            {
                GraphNode* child = SearchNode(select_node->children.SelectBackward(i));
                PrintPathForNode(child);
            }
        }



    };
}

#endif
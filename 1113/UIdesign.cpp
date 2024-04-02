#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct polygon{
    int id;
    int R = 0;
    int G = 0;
    int B = 0;
    string type;
};

struct group{
    int id;
    int count = 0;
    int list[103];
};

int findPolygon(polygon polygonlist[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (polygonlist[i].id == id) {
            return i;
        }
    }
    return -1;
}

int findGroup(group grouplist[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (grouplist[i].id == id) {
            return i;
        }
    }
    return -1;
}

bool _normal(polygon left, polygon right) {
    return left.id < right.id;
}

bool _gray(polygon left, polygon right) {
    double leftsum = left.R * 0.299 + left.G * 0.587 + left.B * 0.114;
    double rightsum = right.R * 0.299 + right.G * 0.587 + right.B * 0.114;
    return leftsum == rightsum ? left.id < right.id : leftsum < rightsum;
}

int main () {
    polygon polygonlist[103];
    int polygonCount = 0;
    group grouplist[103];
    int groupCount = 0;
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string order;
        cin >> order;
        if (order == "Add") {
            string type;
            string id;
            cin >> type >> id;
            polygon *po = new polygon;
            po->type = type;
            po->id = stoi(id.substr(1));
            polygonlist[polygonCount] =  *po;
            polygonCount++;
        } else if (order == "Group") {
            int number = 0;
            cin >> number;
            group *grp = new group;
            grp->count = number;
            for (int j = 0; j < number; j++) {
                string temp;
                cin >> temp;
                grp->list[j] = stoi(temp.substr(1));
            }
            string id;
            cin >> id;
            grp->id = stoi(id.substr(1));
            grouplist[groupCount] = *grp;
            groupCount++;
        } else if (order == "Set") {
            string who;
            cin >> who;
            int R, G, B;
            cin >> R >> G >> B;
            if (who.substr(0, 1) == "P") {
                int pos = findPolygon(polygonlist, polygonCount, stoi(who.substr(1)));
                polygon *tochange = polygonlist + pos;
                if (tochange->type == "normal") {
                    tochange->R = R;
                    tochange->G = G;
                    tochange->B = B;
                } else if (tochange->type == "single") {
                    tochange->R = R;
                    tochange->G = 0;
                    tochange->B = 0;
                } else {
                    tochange->R = 255 - R;
                    tochange->G = 255 - G;
                    tochange->B = 255 - B;
                }
            } else {
                int Grpos = findGroup(grouplist, groupCount, stoi(who.substr(1)));
                group thisGroup = grouplist[Grpos];
                for (int i = 0; i < thisGroup.count; i++) {
                    int pos = findPolygon(polygonlist, polygonCount, thisGroup.list[i]);
                    polygon *tochange = polygonlist + pos;
                    if (tochange->type == "normal") {
                        tochange->R = R;
                        tochange->G = G;
                        tochange->B = B;
                    } else if (tochange->type == "single") {
                        tochange->R = R;
                        tochange->G = 0;
                        tochange->B = 0;
                    } else {
                        tochange->R = 255 - R;
                        tochange->G = 255 - G;
                        tochange->B = 255 - B;
                    }
                }
            }
        }
    }
    string order;
    cin >> order;
    if (order == "Normal") {
        sort(polygonlist, polygonlist + polygonCount, _normal);
    } else {
        sort(polygonlist, polygonlist + polygonCount, _gray);
    }
    for (int i = 0; i < polygonCount; i++) {
        cout << "P" << polygonlist[i].id << " " << polygonlist[i].R << " " << polygonlist[i].G << " " << polygonlist[i].B << endl;
    }
}
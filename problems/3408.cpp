#define P pair<int,int>
#define F first
#define S second

class TaskManager {
    static const int MAXN = 100005;
    set<P> top_tasks;
    set<P> user_tasks[MAXN];
    int taskid2user[MAXN];
    int taskid2priority[MAXN];
public:
    void print(){
        for(auto it=top_tasks.begin();it!=top_tasks.end();it++)
            cout<<'('<<it->F<<','<<it->S<<')'<<' ';
        cout<<'\n';
        for(int i=1;i<=7;i++){
            cout<<"i="<<i<<' ';
            for(auto it=user_tasks[i].begin();it!=user_tasks[i].end();it++)
                cout<<'('<<it->F<<','<<it->S<<')'<<' ';
            cout<<'\n';
        }
    }

    TaskManager(vector<vector<int>>& tasks) {
        for(int i=0;i<MAXN;i++)
            taskid2user[i] = -1;
        for(auto x:tasks){
            user_tasks[ x[0] ].insert({-x[2],-x[1]});
            taskid2user[ x[1] ] = x[0];
            taskid2priority[ x[1] ] = x[2];
        }
        for(int i=0;i<MAXN;i++){
            if( !user_tasks[i].empty() ){
                top_tasks.insert( *user_tasks[i].begin() );
            }
        }
        //print();
    }
    
    void add(int userId, int taskId, int priority) {
        if( user_tasks[userId].empty() ){
            user_tasks[ userId ].insert({-priority,-taskId});
            taskid2user[ taskId ] = userId;
            taskid2priority[ taskId ] = priority;
            top_tasks.insert( *user_tasks[userId].begin() );
            //print();
            return;
        }
        int top_priority = user_tasks[userId].begin()->F;
        int top_taskId = user_tasks[userId].begin()->S;

        user_tasks[ userId ].insert({-priority,-taskId});
        taskid2user[ taskId ] = userId;
        taskid2priority[ taskId ] = priority;

        if( user_tasks[userId].begin()->S != top_taskId ){
            top_tasks.erase({top_priority,top_taskId});
            top_tasks.insert( *user_tasks[userId].begin() );
        }
        //print();
    }
    
    void edit(int taskId, int newPriority) {
        int user = taskid2user[taskId];

        int top_priority = user_tasks[user].begin()->F;
        int top_taskId = user_tasks[user].begin()->S;
        top_tasks.erase({top_priority,top_taskId});

        user_tasks[user].erase({-taskid2priority[taskId],-taskId});
        user_tasks[user].insert({-newPriority,-taskId});
        taskid2priority[ taskId ] = newPriority;
        top_tasks.insert( *user_tasks[user].begin() );
        //print();
    }
    
    void rmv(int taskId) {
        int user = taskid2user[taskId];
        int priority = taskid2priority[taskId];

        if( -user_tasks[user].begin()->S == taskId ){
            top_tasks.erase({-priority,-taskId});
            user_tasks[user].erase({-priority,-taskId});
            if( !user_tasks[user].empty() )
                top_tasks.insert( *user_tasks[user].begin() );
            //print();
            return;
        }
        user_tasks[user].erase({-priority,-taskId});
        //print();
    }
    
    int execTop() {
        if( top_tasks.empty() )
            return -1;
        int priority = -top_tasks.begin()->F;
        int taskId = -top_tasks.begin()->S;
        top_tasks.erase({-priority,-taskId});
        int user = taskid2user[taskId];
        user_tasks[user].erase({-priority,-taskId});
        if( !user_tasks[user].empty() )
            top_tasks.insert( *user_tasks[user].begin() );
        //print();
        return user;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

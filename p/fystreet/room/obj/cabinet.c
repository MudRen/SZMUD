inherit ITEM;
 
int to_put(string arg);
int to_get(string arg);
 
void create()
{
        set_name("木柜", ({"wooden cabinet", "mu gui", "cabinet"}));
        set_weight(200000);
        if(clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 0);
                set("size", 3);
                set("long", "这是一个非常普通的一般木柜，可以用来放东西。\n");
        }
        setup();
}

void init()
{
        if(strsrch(base_name(environment()), this_player()->query("id"))) {
                add_action("to_put", "put");
                add_action("to_get", "get");
                set("owner", this_player()->query("id"));
                set("stores", this_player()->store_list());
        }
}

string long()
{
        string list, *stores = query("stores");
        int num = sizeof(stores);
        if(num == 0 || this_player()->query("id") != query("owner"))
                return query("long");
        list = query("name") + "中目前一共有" + chinese_number(num) + "件物品：\n";
        for(int i = 0; i < num; i++) list += "  " + stores[i] + "\n";
        return query("long") + list;
}

int to_get(string arg)
{
        string obj, cabinet_id, *list, *temp_list, *stores = query("stores");
        int list_s, temp_list_s, num = sizeof(stores);
        object user = this_player(), cabinet = this_object(), ob;
        mapping store;
        if(!arg) return 0;
        if(sscanf(arg, "%s from %s", obj, cabinet_id) != 2) return 0;
        if(present(cabinet_id, environment()) != cabinet) return 0;
        if(user->query("id") != query("owner")) {
                tell_object(user, "你盯着" + name() + "瞧了瞧，可以上了锁，看来这会你是做不成贼了。\n");
                return 1;
        }
        if(num == 0) {
                message_vision("$N在$n里面找了半天，结果$n里面什么也没有。\n", user, cabinet);
                return 1;
        }
        for(int i = 0 ;i < num ;i++) {
                store = user->store_info(i);
                if(strsrch(query("stores")[i], obj)) {
                        ob = new(store["path"]);
                        if(store["data"]) {
                                list = keys(store["data"]);
                                list_s = sizeof(list);
                                for(int j = 0; j < list_s; j++)
                                        ob->set(list[i], store["data"][list[i]]);
                        }
                        if(store["temp_data"]) {
                                temp_list = keys(store["temp_data"]);
                                temp_list_s = sizeof(temp_list);
                                for(int j = 0; j < temp_list_s; j++)
                                        ob->set_temp(temp_list[i], store["temp_data"][temp_list[i]]);
                        }
                        user->del_store(i);
                        message_vision("$N从$n里面拿出" + ob->short() + "。\n", user, cabinet);
                        ob->move(user);
                        set("stores", user->store_list());
                        return 1;
                }
        }
        message_vision("$N在$n里面找了半天，没有找到$N要的东西。\n", user, cabinet);
        return 1;
}

int to_put(string arg)
{
        object store, user = this_player(), cabinet = this_object();
        string put_id, cabinet_id;
        mapping info = ([]);
        if(!arg) return 0;
        if(sscanf(arg, "%s in %s", put_id, cabinet_id) != 2) return 0;
        if(present(cabinet_id, environment()) != cabinet) return 0;
        if(user->query("id") != query("owner")) {
                tell_object(user, "你盯着" + name() + "瞧了瞧，可以上了锁，看来这会你是做不成好人了。\n");
                return 1;
        }       
        if(sizeof(user->store_list()) == query("size")) {
                tell_object(user, this_object()->name() + "已经装满了。\n");
                return 1;
        }
        if(!objectp(store = present(put_id, user))) {
                tell_object(user,"你身上没有这样物品。\n");
                return 1;
        }
        if(strsrch(base_name(store), "/clone/unique")) {
                message_vision("$N正要把" + store->name() + "放到$n里面，突然" + store->name() + "像受了强力似的越空而起。\n", user, cabinet);
                message_vision("$N掉到地上了。\n", store);
                store->move(environment());
                message_vision("看来这$N冶游灵性，不原埋没了自己的光彩。", cabinet);
                return 1;
        }
        info += (["data" : store->query_entire_dbase()]);
        info += (["temp_data" : store->query_entire_temp_dbase()]);
        info["name"] = store->name();
        info["id"] = store->query("id");
        info["path"] = base_name(store);
        user->add_store(info);
        message_vision("$N把" + store->short() + "放到$n里面了。\n", user, cabinet);
        destruct(store);
        set("stores", user->store_list());
        return 1;
}


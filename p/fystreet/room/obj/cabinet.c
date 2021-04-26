inherit ITEM;
 
int to_put(string arg);
int to_get(string arg);
 
void create()
{
        set_name("ľ��", ({"wooden cabinet", "mu gui", "cabinet"}));
        set_weight(200000);
        if(clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("size", 3);
                set("long", "����һ���ǳ���ͨ��һ��ľ�񣬿��������Ŷ�����\n");
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
        list = query("name") + "��Ŀǰһ����" + chinese_number(num) + "����Ʒ��\n";
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
                tell_object(user, "�㶢��" + name() + "�����ƣ���������������������������������ˡ�\n");
                return 1;
        }
        if(num == 0) {
                message_vision("$N��$n�������˰��죬���$n����ʲôҲû�С�\n", user, cabinet);
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
                        message_vision("$N��$n�����ó�" + ob->short() + "��\n", user, cabinet);
                        ob->move(user);
                        set("stores", user->store_list());
                        return 1;
                }
        }
        message_vision("$N��$n�������˰��죬û���ҵ�$NҪ�Ķ�����\n", user, cabinet);
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
                tell_object(user, "�㶢��" + name() + "�����ƣ�����������������������������ɺ����ˡ�\n");
                return 1;
        }       
        if(sizeof(user->store_list()) == query("size")) {
                tell_object(user, this_object()->name() + "�Ѿ�װ���ˡ�\n");
                return 1;
        }
        if(!objectp(store = present(put_id, user))) {
                tell_object(user,"������û��������Ʒ��\n");
                return 1;
        }
        if(strsrch(base_name(store), "/clone/unique")) {
                message_vision("$N��Ҫ��" + store->name() + "�ŵ�$n���棬ͻȻ" + store->name() + "������ǿ���Ƶ�Խ�ն���\n", user, cabinet);
                message_vision("$N���������ˡ�\n", store);
                store->move(environment());
                message_vision("������$Nұ�����ԣ���ԭ��û���Լ��Ĺ�ʡ�", cabinet);
                return 1;
        }
        info += (["data" : store->query_entire_dbase()]);
        info += (["temp_data" : store->query_entire_temp_dbase()]);
        info["name"] = store->name();
        info["id"] = store->query("id");
        info["path"] = base_name(store);
        user->add_store(info);
        message_vision("$N��" + store->short() + "�ŵ�$n�����ˡ�\n", user, cabinet);
        destruct(store);
        set("stores", user->store_list());
        return 1;
}


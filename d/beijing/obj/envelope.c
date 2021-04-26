//Cracked by Roath
inherit ITEM;

int do_write(string);
string do_look(string);
string do_seal(string);
string do_open(string);
string do_tear(string);

void create()
{
    set_name("�ŷ�", ({"envelope", "xin feng", "feng"}));
    set_weight(30);
    set_max_encumbrance(100);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "һֻ��ͨ���ŷ⡣\n");
	set("unit", "ֻ");
	set("material", "paper");
	set("value", 50);
	set("sealed", 0);
	set("opened", 0);
    }
}

int init()
{
    add_action("do_write", "write");
    add_action("do_look",  "look");
    add_action("do_seal",  "seal");
    add_action("do_open",  "open");
    add_action("do_tear",  "tear");
}

int is_container() {return 1;}

int reject(object ob)
{
    object me = this_object();

    if (me->query("sealed")) {
	if (me->query("opened")) {
	    notify_fail("�ŷ��Ѿ����ˣ�û����װ�����ˡ�\n");
	}else{
	    notify_fail("�ŷ�����أ���ô����װ������\n");
	}
	return 1;
    }
    if (ob->query("material") != "paper") {
	notify_fail("�ŷ���ֻ��װֽ��\n");
	return 1;
    }
    if (sizeof(all_inventory(me)) >= 3) {
	notify_fail("�ŷ����Ѿ������˶�����\n");
	return 1;
    }
    return 0;
}


int do_write(string arg)
{
    object me = this_object(), player = this_player();

    if (arg != "envelope" && arg != "xin feng" && arg != "feng") return 0;
    if (player->is_busy())
	return notify_fail("����æ���ء�\n");
    if (me->query("content"))
	return notify_fail("�ŷ����Ѿ�д�����֣����Ҳ����ط��±ʡ�\n");

    message_vision("$N���ŷ���д������������\n", player);

    me->set("writer", player->query("name"));
    write("�ŷ��Ͽ���д�ü��У�д������ . ��ʾ������\n");
    write("����������������������������������������������������\n");
    input_to("get_msg");
    return 1;
}

int get_msg(string msg)
{
    object me = this_object();
    string old_content = me->query("content");

    if (msg == ".") {
	write("\n");
	return 1;
    }

    if (old_content) 
	me->set("content", old_content + msg + "\n");
    else 
	me->set("content", msg+"\n");
    input_to("get_msg");
    return 1;
}

int do_tear(string arg)
{
    object me = this_object(), player=this_player();
    object *inv;

    if (arg != "envelope" && arg != "xin feng" && arg != "feng") return 0;
    message_vision("$Nһ�ѽ��ŷ�˺��ϡ�á�\n", player);
    destruct(me);
    return 1;
}

int do_open(string arg)
{
    object me = this_object(), player=this_player();
    object *inv;

    if (arg != "envelope" && arg != "xin feng" && arg != "feng") return 0;
    if (!me->query("sealed")) 
	return notify_fail("��ֻ�ŷ������û��������\n");
    if (me->query("opened")) 
	return notify_fail("��ֻ�ŷ��Ѿ���˺���ˡ�\n");
    me->set("opened", 1);
    message_vision("$N���ŷ�˺����\n", player);
    // set("value", 0);
    inv = all_inventory(me);
    if (sizeof(inv)) map_array(inv, "unlock", me);
    return 1;
}

int do_seal(string arg)
{
    object me = this_object(), player=this_player();
    object *inv;

    if (arg != "envelope" && arg != "xin feng" && arg != "feng") 
	return notify_fail("��Ҫ��ʲô��\n");
    if (me->query("sealed")) 
	return notify_fail("��ֻ�ŷ��Ѿ��Ƿ��ŵ��ˡ�\n");
    if (me->query("opened")) 
	return notify_fail("��ֻ�ŷ��Ѿ���˺���ˣ����޷��ٰ�����������\n");
    me->set("sealed", 1);
    message_vision("$NС������ذ��ŷ���Ͽڡ�\n", player);
    inv = all_inventory(me);
    if (sizeof(inv)) map_array(inv, "lock", me);
    return 1;
}

int do_look(string arg)
{
    object me = this_object(); 
    mixed *inv;

    if (arg != "envelope" && arg != "xin feng" && arg != "feng") return 0;

    if (me->query("sealed")) {
	if (me->query("opened") == 0) {
	    write("����һֻ���ŵ��ŷ�");
	}else {
	    write("����һֻ�����˵��ŷ�");
	}
    } else {
	write("����һֻո�µ��ŷ�");
    }

    if(! me->query("content")) {
	write("������ʲôҲûд��\n");
    }else{
	write("������д�ţ�\n\n");
	write(me->query("content")+"\n");
	write("\n���ּ������ƺ���"+me->query("writer")+"���ױʡ�\n");
    }

    if (!me->query("sealed") || me->query("opened")) {
	inv = all_inventory(me);
	if (sizeof(inv)) {
	    inv = map_array(inv, "inventory_look", this_object());
	    write("�����У�\n  "+implode(inv, "\n  ") +"\n");
	}
    }
    return 1;
}

void lock(object obj, int flag) { obj->set("no_get", 1); } 
void unlock(object obj, int flag) { obj->delete("no_get"); } 

string inventory_look(object obj, int flag)
{
    return "    " + obj->short();
}

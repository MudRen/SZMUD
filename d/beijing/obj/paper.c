//Cracked by Roath
inherit ITEM;

int do_write(string);
string do_look(string);
string do_tear(string);

void create()
{
    set_name("��ֽ", ({"paper"}));
    set_weight(30);
    if (clonep())
	set_default_object(__FILE__);
    else {
	set("long", "һ�Ÿմ������������ֽ��\n");
	set("unit", "��");
	set("material", "paper");
	set("value", 30);
	set("create_time", time());
	set("freshness", "�մ������������ֽ");
    }
    remove_call_out("aging");
    call_out("aging", 600);
}

int init()
{
    add_action("do_write", "write");
    add_action("do_look",  "look");
    add_action("do_tear",  "tear");
}

int do_tear(string arg)
{
    object me = this_object(), player = this_player();

    if (arg != "paper") return 0;
    if (player->is_busy()) return notify_fail("����æ���ء�\n");
    message_vision("$Nһ�ѽ�ֽ˺��ϡ�á�\n", player);
    destruct(me);
    return 1;
}

int do_write(string arg)
{
    object me = this_object(), player = this_player();

    if (arg != "paper") return 0;
    if (player->is_busy())
	return notify_fail("����æ���ء�\n");
    if (me->query("content"))
	return notify_fail("����ֽ���Ѿ�д�����֣����Ҳ����ط��±ʡ�\n");

    message_vision("$N��ֽ��д������������\n", player);

    me->set("writer", player->query("name"));
    write("ֽ�Ͽ���д�ü��У�д������ . ��ʾ������\n");
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

int do_look(string arg)
{
    object me = this_object();
    int age = time() - me->query("create_time");

    if (arg != "paper") return 0;

    if(! me->query("content")) {
	write("����һ��"+query("freshness")+"������ʲôҲûд��\n");
	return 1;
    }
    
    write("����һ��"+me->query("freshness")+"������" + 
	(age<36000?"д��":"��Լ�ɱ����Щ�ּ�") + "��\n\n");
    write(me->query("content")+"\n");
    write("\n���ּ������ƺ���"+me->query("writer")+"���ױʡ�\n");
    return 1;
}

int aging()
{
    int age;

    remove_call_out("aging");
    call_out("aging", 600);
    
    age = time() - query("create_time");
    if (age > 600 && age < 3600) {
	set("freshness", "������ֽ�����ֽ");
    }else if (age < 7200) {
	set("freshness", "ѩ�׵���ֽ");
    }else if (age < 21600) { // 5 hours
	set("freshness", "�е㷢�Ƶ���ֽ");
    }else if (age < 36000) { // 10 hours
	set("freshness", "�е㷢ù����ֽ");
    }else if (age < 72000) { // 20 hours
	set("freshness", "�Ѿ���ù����ֽ");
    }else if (age < 144000) { // 40 hours
	set("freshness", "��������Щ������ֽ");
    }else{
        message("vision", "һ��紵������"+query("name")+
		"��ɢ�����ˡ�\n", environment());
	destruct(this_object());
    }
    return 1;
}

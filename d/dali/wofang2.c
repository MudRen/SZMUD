// Code of ShenZhou
// wofang2.c

inherit ROOM;

void create()
{
	set("short", "�᷿");
	set("long", @LONG
���Ǵ����Ů�ӹ�Ա�����ң��佫�����¼���Ĺ�Ա���ڴ���Ϣ
˯������������ʰ�øɸɾ����Ĵ�����ǽ����һȦ��
LONG );

	set("exits", ([
		"west" : __DIR__"diziarea.c",
		]));

        set("sleep_room", 1);
        set("no_fight", 1);
        setup();
}

void init()
{
/*	object ob=this_player();

	if (!wizardp(ob) && ob->query("family/family_name") != "����μ�") {
		message_vision("һ������Ů�ͳ��˽����������µ�����$N�㲻�Ǵ�����ˣ���ô�����������ˣ������ȥ��\n",ob);
		if (!userp(ob)) {
			message_vision("һȺ��ʿ˵�žͷ�ӵ������$N�ҹ���ȥ��\n",ob);
			ob->unconcious();
		}
		remove_call_out("kickout");
		call_out("kickout", 1, ob);
	}
*/
	add_action("do_get", "get");
}
/*
int kickout(object ob)
{
	if (!present(ob,find_object("/d/dali/wofang2.c"))) {
		return 1;
	}
	message_vision("��ʿ�ǰ�$N�ҹ����˳�ȥ��\n",ob);
	ob->move("/d/dali/taihejie5");
	message("vision","ֻ����ƹ����һ����"+ob->query("name")+"�������ﱻ���ҹ����˳�����\n", environment(ob), ob);
	if (!userp(ob)) {
		ob->revive();
		ob->set("qi",ob->query("eff_qi"));
		ob->set("jing",ob->query("eff_jing"));
		ob->set("jingli",ob->query("max_jingli"));
	}
	return 1;
}
*/
int do_get(string arg)  
{
	string a,b,c;
	object obj;

	if ( arg && objectp(obj = present(arg, environment(this_player())))
        && obj->is_character() ) {
		write("�㲻�ܰᶯ��ҵ����塣\n");
		return 1;
	}
	if (!arg || sscanf(arg, "%s %s %s", a, b, c) != 3 )
		return 0;
	if ( b != "from" ) return 0;
	if ( objectp(obj = present(c, environment(this_player())))
        && obj->is_character() ) {
		write("�㲻�ܴ�˯���˵��������͵������\n");
		return 1;
	}
	return 0;
}

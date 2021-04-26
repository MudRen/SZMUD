// Code of ShenZhou
// Room: /d/shaolin/cjlou1.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "�ؾ����¥");
	set("long", @LONG
ǧ������������ִ��ԭ����֮ţ�����Դ�Ħ�������£�����
�˲ı����������в��ٸ�ɮ�������棬�㼯�����ճ���������
��������ʮ�����ա����־����������ڴˡ���¥���濪����ȷ��
ͨ�硣�м����������Ŵ���ܡ���������а������Թ��Ķ�����
λ��ɮ��ִ�������ڱ�Ŀ��˼��
LONG
	);

	set("exits", ([
		"down" : __DIR__"cjlou",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/hui-zhen" : 1,
		"d/shaolin/obj/wuji1" : 1,
		"d/shaolin/obj/wuji2" : 1,
		"d/shaolin/obj/wuji3" : 1,
	]));
	set("cost", 2);
	setup();
}

void init()
{
	add_action("do_hit","hit");
}

int do_hit(string arg)
{
	object ob, me = this_player();

	if ( arg == "huizhen" || arg == "zunzhe" || arg == "huizhen zunzhe" ) {
		ob = present("huizhen zunzhe", environment(me));
		ob->kill_ob(me);
		me->fight_ob(ob);
		tell_object(me,"��ͻȻ������ת��ڤڤ���ƺ��й������ڲ����������!\n");
        	me->unconcious();
	
		return 1;
	}

	return 0;
}

int valid_leave(object me, string dir)
{
	object *inv, obj;
	int i, found = 0;

	inv = all_inventory(me);
	for (i=0; i<sizeof(inv); i++) {
                if ( inv[i]->is_container() && present("shaolin wuji", inv[i]) ) found = 1;
		if ( inv[i]->is_character() ) {
			if ( present("shaolin wuji", inv[i]) ) found = 1;
			if ( obj=present("bu dai", inv[i]) && present("shaolin wuji", obj) ) found = 1;
		}
	}

	if ( present("huizhen zunzhe", environment(me)) && (present("shaolin wuji", me) || found) )
	{
		if (dir == "down" )
		{
			return notify_fail("����˵��: �书�ؼ�ֻ���ڲؾ�������ϰ������Я����� !\n");
		}
	}

	if ( present("huizhen zunzhe",me) )
		return notify_fail("��Ӵ�������Źմ�����аɣ�\n");

	return ::valid_leave(me, dir);
}

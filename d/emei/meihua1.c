// Code of ShenZhou
// Room: /d/emei/meihua1.c

inherit ROOM;

void create()
{
	set("short", "�ŵ���");
	set("long", @LONG
����һƬ���ܵ��ľ�֣�������ͦ���Σ�֦Ҷ����������������ӵ�𣬾�
˵��������֮�࣬Ҫ�ǲ���Ϥ���κ�������·��������һƬ�յأ���ֻ�ľ׮
�ų�÷��ģ����
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"meihua"+(random(7)+1),
		"northeast" : __DIR__"meihua"+(random(7)+1),
		"southeast" : __DIR__"meihua2",
		"southwest" : __DIR__"meihua"+(random(7)+1),
		"south"	    : __DIR__"bailong",
	]));

	set("outdoors", "emei");
	set("cost", 3);
	setup();
}

void init()
{
        object me, ob;
	mixed local;
	int t;

        local = localtime(time()*60);
        t = local[2]*60 + local[1];

        me = this_player();

        if( !userp(me) ) return;

        if ( me->query_temp("meihua/on")
	&&  (int)me->query_temp("meihua/count") == 7
        &&  (int)me->query_skill("dodge", 1) >= 30 
        &&  (int)me->query_skill("dodge", 1) <= 100  
	&&  t > 300 && t < 1260 )
        {
                me->receive_damage("jing", 25);
                me->receive_damage("jingli", 20);
                me->improve_skill("dodge", random(me->query("int")+me->query_int()));
		if ( me->query_skill("zhutian-bu",1) <= 120 )
			me->improve_skill("zhutian-bu", me->query_int());
        }
	me->delete_temp("meihua/count", 1);
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me = this_player();
        if ( !arg || (arg != "÷��׮" && arg != "down")) return command("jump "+arg);
        if ( me->query_temp("meihua/on") )
                if ( arg == "down" ) {
                        me->delete_temp("meihua/on");
                        message_vision("$Nһ���շ���׮�����£����ȵ�վ�ڵ��ϡ�\n", me);
                        return 1;
                } else
                        return notify_fail("���Ѿ�վ��÷��׮���ˣ�������С��ˤ��ȥ��\n");
        if ( arg == "down" ) return command("jump down");
	if ( me->query_skill("dodge", 1) < 30 ) {
		message_vision("$Nһ������Ҫ����÷��׮��������Ĳ����ߣ�ˤ�˸����ͷ��\n", me);
		me->receive_wound("qi", 20, me);
		return 0;
	} else
		message_vision("$Nһ��������÷��׮��\n", me);
	me->set_temp("meihua/on", 1);
	return 1;
}

int valid_leave(object me, string dir)
{

	if (dir == "southeast" ) me->add_temp("meihua/count", 1);
	else if ( dir == "south" ) me->delete_temp("meihua/on");
	else			 me->add_temp("meihua/count", -1);

	return ::valid_leave(me, dir);
}

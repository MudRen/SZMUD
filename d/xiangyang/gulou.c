// Code of ShenZhou
// Room: /d/xiangyang/gulou.c

inherit ROOM;

string look_drum();

void create()
{
	set("short", "��¥");
	set("long", @LONG
��������������������ļ�����ʾ���Ĺ�¥��ֱ�������ı���һֻ��ɫ�Ĵ�
��(drum)������վ�ż���ʿ���������㻹�ǲ�Ҫ��������¥�����ޱڣ���������
�������򱱸��ӣ����Կ����������ֵ��ڲ��������ɼ�����Ӫ��ʿ���ڲ�����
Ѳ�ߡ�������һ���ȹ�¥��һ��ĸ�¥��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"guloud",
]));
	set("outdoors", "xiangyang");
	set("item_desc",([
		"drum"		:	(: look_drum :),
	]));
	setup();
}

void init()
{
	add_action("do_hit", "hit");
	add_action("do_out", "out");
}

int do_hit(string arg)
{
	object me, killer;

	me = this_player();
	if ( !arg || ( arg != "drum" ) ) return notify_fail("��Ҫ��ʲ�᣿\n");

	if((int)me->query("qi") < 30)
	{
		killer = new(CLASS_D("shaolin") + "/qing-xiao");
		COMBAT_D->killer_reward(killer, me);
                me->die();
		destruct(killer);
		return 1;
	}
	else
		me->add("qi", -30);

	if ( random((int)me->query("str")) < 10 )
	{
		message_vision("$Nһ��С���õ��Լ�ͷ���ˡ�\n", me);
		//me->add("qi", -10 - me->query("qi"));
		me->unconcious();
	}
	else
	{
		mapping mine;

		mine = me->query_entire_dbase();
		message_vision("$N����һ�´�ģ����ˡ���������������������\n", me);
		write("������Ѹ�װ��������ը�죬��ͷ����һƬ��Ϳ��\n"
			"ȫ��ҡҡ��׹������֧���Ų����ڵ��ϡ�����һ��\n"
			"���������㣬�øϿ��뿪�����Ȼ��û���ˡ�\n");
		if ( mine["potential"] - mine["learned_points"] < 100 )
			mine["potential"] += 1;
	}
	return 1;
}

int do_out(string arg)
{
        object me, killer;

	int i, ging_cost, qi_cost;

        me = this_player();
        i = (int)me->query_skill("dodge", 0) + random(200);
        ging_cost = 600 / (int)me->query("int");
        qi_cost = 500 / (int)me->query("int");
        if(((int)me->query("jing") < ging_cost) || ((int)me->query("qi") < qi_cost))
                i = 0;

        message_vision("$N���ϴ�̨��һ������������ȥ��\n", me);
        me->move(__DIR__"gulou");
        message_vision("ֻ�����须��һ��$N����������������\n", me);
        if ( i < 50)
	{
		killer = new(CLASS_D("shaolin") + "/qing-wen");
		COMBAT_D->killer_reward(killer, me);
                me->die();
		destruct(killer);
	}
        else if( i < 125)
                me->unconcious();
        else {
                message_vision("$N�����ȵ�վ�ڵ��ϡ�\n", me);
                if( i > 175)
                        me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
                me->receive_damage("jing", ging_cost );
                me->receive_damage("qi", qi_cost );
        }

        return 1;
}






string look_drum()
{
	return
"������Ĺ���ͨ�죬���ɰ���ľ���ɡ���ͷ����ˮţƤ����һ�Ѵ�ͭ�����ڹ���\n"
"��Ե��������һȦ���գ���������Ϊ��λ����γɵġ�������ķ���һ��һ�˸�\n"
"�ļ����ϣ����ӵײ�����������鳡������ס���һ�¹�(hit)���ԡ�\n";
}

string look_out()
{
	return  "�����ǹ�¥����Ĵ�̨�����������ң����������ɽ����\n"
"�Լ��������Ƶ���ɽ�������̳��������۵ס���˵�ڴ˵�\n"
"������������ֱ�ӽ����������޴����洦��\n";
}


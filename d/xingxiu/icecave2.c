// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������棬�Ƕ����Ͻ��������ű�׶(icicle)�����̲��룬
��ϸ��һ�������±���������ǧ����̬�����ж��ڣ����ƽ��˹��
½��������硣�����и������ƺ���������ȥ(out)��
LONG
	);
	set("exits", ([
                "east" : __DIR__"icecave1",
        ]));
	set("bing_can", 3);
	set("cost", 2);
	set("icicle", 100);

	setup();
}
void init()
{
        add_action("do_flick", "flick");
        add_action("do_flick", "tan");
	add_action("do_out", "out");
}
int do_flick(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return 0;

        if (me->query_busy())
                return notify_fail("����æ���ء�\n");

	if (query("icicle") < 1)
		return notify_fail("����ı�׶�㶼�������ˡ�\n");

	if ( (int)me->query("jing") < 30 || (int)me->query("jingli") < 30)
                return notify_fail("��ľ����ܼ��С�\n");

        if( arg=="icicle")
        {
	me->receive_damage("jing", 15);	
	me->receive_damage("jingli", 15);
	add("icicle", -1);
        message_vision("$N���������ָ������һ����׶��\n", me);
	if (random(me->query_skill("feixing-shu", 1)) > 30){
	me->improve_skill("feixing-shu", me->query("int"));
	message_vision("$N���ɳ�ȥ�ı�׶ײ������һ����׶��ƹƹ�������졣\n", me);
	tell_object(me, "���ƺ�������һ�㰵���ļ��ܡ�\n");
	if (me->query_skill("feixing-shu", 1) > 100)
	me->receive_damage("jing", 15);
	if (me->query_skill("feixing-shu", 1) > 150)
        me->receive_damage("jing", 15);
	}
	if (query("icicle") < 1){
	remove_call_out("renew_up");
        call_out("renew_up", 300+random(200));
	}
	return 1;
	}
}
void renew_up()
{
	set("icicle", 100);
}
int do_out(string arg)
{
        object me;
	me = this_player();

	message_vision("$N���϶��ڴӿ��������˳�ȥ��\n", me);
        me->move(__DIR__"shanluan");
	message("vision", me->name() + "ˮ���ܵĲ�֪��ʲô�ط�����������\n",
                    environment(me), ({me}) );
	return 1;
}

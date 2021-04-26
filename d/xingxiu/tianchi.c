// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;
string look_cliff();
void create()
{
	set("short", "���");
	set("long", @LONG
��ɽ�ϰ�ѩ�����������ݺᣬ�������񡣴��СС�ı������
��������Ϊ�ֲ��������ڱ���Ͽ�������أ�ǡ��һ��޴��������
������⣬��˸ҫ�ۡ����˵�ɽɫ���⣬ɽ��ϰϰ������������ˮ�� 
ɽǰ���ͱ�(cliff)�Ͽ��м����ּ�����ʯ���֡�
LONG
	);
	set("exits", ([
                "westup" : __DIR__"shanluan",
                "southdown" : __DIR__"guozi",
        ]));
	set("item_desc",([
                "cliff"         :       (: look_cliff :),
        ]));
	set("cost", 7);
	set("bing_can", 7);
	set("resource/water",1);
	set("outdoors", "tianshan");

	setup();
}
string look_cliff()
{
        return
        "\n"
        "              ��    ѩ    ��    ��\n\n"
        "              ��    ��    ��    ��\n\n"
        "              ҫ    ��    ��    ��\n\n"
        "      ��      ��    ��    ��    ��\n"
	"      ��                          \n"
	"      ��      ��    ��    ��    ��\n"
	"      ��                          \n"
	"      ��      ��    ��    ��    ��\n"
	"      ��                          \n"
	"      ��      ��    ��    ��    ��\n";
}
void init()
{
        add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}
int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return notify_fail("��Ҫ���Ķ�����\n");

	if (me->query_busy())
                return notify_fail("����æ���ء�\n");

        if( arg=="cliff")
        {
	message_vision("$N�ֽŲ���˳���ͱ����嶥����ȥ��\n", me);
	me->start_busy(5);

	if (random(me->query_skill("dodge")) < 50){
	remove_call_out("drop_down");
        call_out("drop_down", 5, me);
	return 1;
	}
	
	message("vision", me->name()+"һ�������ʧ���������ˡ�\n", environment(me), ({me}) );
	remove_call_out("climb_up");
	call_out("climb_up", 5, me);
	return 1;
	}
}
void drop_down(object me)
{
	tell_object(me, "ͻȻ��һʧ�֣����ͱ��ϵ���������ƨ�����ص�ˤ�ڵ��ϡ�\n");
        message("vision", me->name() + "ͻȻһʧ�֣����ͱ��ϵ���С����ƨ�����ص�ˤ�ڵ��ϡ�\n",
                             environment(me), ({me}) );
	me->receive_damage("qi", 50, "���ͱ��ϵ�������ˤ����");
        me->receive_wound("qi",  50, "���ͱ���������ˤ����");
}
void climb_up(object me)
{
	tell_object(me, "������һ��������Ծ�𣬼�������䣬�Ѵ����˷嶥��\n");
	me->add("jingli", -50);
	me->move(__DIR__"lingshan");
        message("vision", me->name() + "���������ش���������������\n",
                             environment(me), ({me}) );
}


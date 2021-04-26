// Code of ShenZhou
// qiaobi0.c �ͱ���
// qfy July 13, 1996

inherit ROOM;

void create()
{
        set("short", "�ͱ���");
        set("long", @LONG
����һ��������ͱڣ�����һ�����磬��������ͱ�(cliff)�в����
Լ��ʮ���ɴ�������һ�������ɼ����Ĵ�ʯ������һ��ƽ̨(tai)��ʯ������
�̵����֡�
LONG
        );

	set("exits", ([
                "east" : __DIR__"xiaojing",
        ]));

	set("item_desc",([
	    "cliff" : 
	    "�ͱ���ÿ�����߱�����һ����̦����ʮ�Ա�ֱ���ж��ϣ�ԭ���ǹ���\n"
	    "��������֮���������վã����л��࣬���������̦��\n",
	    "tai" : "ƽ̨ʯ�Ͽ��š���ڣ���������֡�\n"
        ]));

	set("cost", 4);
        setup();
}

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	object me = this_player();

	if ( !arg )
	   return notify_fail( "ʲô��\n" );

	if ( arg != "up" ) 
	   return notify_fail( "��ֻ����������\n" );

	if ( (int)me->query_skill("dodge") <= 70 ) {
	   message_vision("$N����Ծ�𣬵��Ṧ���ã������ŵ�һ��С����\n", me);
	   return 1;
	}

	message_vision("$N����Ծ������̤�ڵ�һ��С��֮�У��������������׼�ڶ�\n", me);
	message_vision("����̦���˽�ȥ��$N����������������ʮ���ɡ�\n\n", me);
	message("vision",me->name()+"Խ��Խ�ߣ����ñ㿴�����ˡ�\n", environment(me), ({me}) );

	me->receive_damage("jingli", 7000/(int)me->query_skill("dodge"));
	write("��ֻ���������������������ӣ����Ǳ����������ɡ�\n\n");

	me->move(__DIR__"qiaobi1");

	return 1;
}

// Code of ShenZhou
// qiaobi1.c �ͱڣ�
// qfy July 13, 1996

inherit ROOM;

void create()
{
        set("short", "�ͱ�");
        set("long", @LONG
�������ͱ���������Ϣ��̧ͷһ������������ʮ���ɷ��ܵ����ͱ���
��ƽ̨�����ﲻ�������Ӧ�������������
LONG
        );

	set("cost", 6);
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

	if ( arg == "down" ) {
	   message_vision("$N���㲢�ã�С����������ͱ�����ȥ��\n", me);
	   me->move(__DIR__"qiaobi0");
	   message("vision", me->name()+"���ͱ�������������\n", environment(me), me);
	   write("��˫��̤��ʵ�أ����ɵ�͸��һ�ڴ�����\n");
	}
	else if ( arg == "up" ) {
	   if ( (int)me->query_skill("dodge") <= 100 ) {
	      	message_vision("$N����������Ծ�𣬵��Ṧ���δ�����ϲ���ƽ̨��\n", me);
	   	message_vision("���$N����ʧ��ˤ���ͱڣ����ܼ�ʱ����ʯ�ڣ��������˼����ˡ�\n", me);
	   	me->add("eff_qi", -5000/(int)me->query_skill("dodge"));
	   }
	   else {
		message_vision("$N����һ��������Ծ�𣬼�������䣬�Ѵ�����ƽ̨��\n", me);
		me->receive_damage("qi", 10000/(int)me->query_skill("dodge"));
		write("��ֻ�����������꣬�������٣���������Ϣһ��ɡ�\n\n");
		me->move(__DIR__"pingtai");
	   }
	}
	else return notify_fail( "��ֻ�����ϻ���������\n" );

	return 1;
}

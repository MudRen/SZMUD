// Code of ShenZhou
// /d/qilian/sulee
// Ryu, 10/28/96.
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "���պӶ���");
  set ("long", @LONG
��ˮ���Ŵ�Ȫ�ı��ӺӴ��µ����࣬ˮ�ƽ���������ɳɽ����Σ
ɽ���ˢ��һ��ɽ�¶ϲ㡣Ī�߿߾�������������ɳɽ�Ķϲ��ϡ���
����һ��С���֣���֦(shuzhi)֦Ҷ���Ǻ�ï�ܡ�
LONG);

	set("exits", ([
                "northeast" : __DIR__"loulan",
        ]));
	set("item_desc", ([
                "shuzhi" : "һЩ���Ǻܴ�׳����֦�����԰����ǿ�(chop)��������һ��ľ����\n"
        ]));
	set("mufa_count", 3);
	set("outdoors", "/d/qilian");
	set("cost", 2);
	setup();
}
void init()
{
   add_action("do_chop","chop");
   add_action("do_make","make");
}
int do_chop(string arg)
{
	object weapon, me = this_player();
	
	if( !arg || arg!="shuzhi" )
        return notify_fail("��Ҫ����ô��\n");
	
	if( !objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword"
	&& (string)weapon->query("skill_type") != "blade" )

	return notify_fail("���ֿ������²��аɣ�\n"); 
	
	if (query("mufa_count") < 1)
                return notify_fail("�������֦���������ˣ������ǳ�����ʱ�ٿ��ɡ�\n");

	me->receive_damage("jingli", 5);
	message_vision("$N�������еļһ�����Ͽ���һЩ��֦��\n", me);
	if ( random(10) >= 7) {
        write("�㿳�µ���֦�ƺ��㹻��(make)һ��ľ��(raft)�ˡ�\n");
        me->set_temp("marks/��", 1);
        }
        me->start_busy(10);
	return 1;
}
int do_make(string arg)
{
	object ob, me = this_player();

        if( !arg || arg!="raft" )
        return notify_fail("��Ҫ����ô��\n");

	if( !me->query_temp("marks/��") )	
	return notify_fail("��Ҫ����ô��\n");

	ob = new("/d/qilian/obj/raft");
        ob->move("/d/qilian/sulee");	
	write("���ÿ��µ���֦����һ��ľ����\n");
	me->delete_temp("marks/��");
	add("mufa_count", -1);
	return 1;
}

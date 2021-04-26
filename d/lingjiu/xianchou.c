//room: xianchou.c
inherit ROOM;
#include <ansi.h>;
void init();
int do_zou(string arg);

void create()
{
  set("short","�ɳ���");
  set("long",@LONG
����Ϳ쵽��翷�����ˣ�Խ�����ߣ�ɽ��Խ�ߣ�����������ߵİ�
��������Ũ������������ɽ��·������ɽ��û�߼�����������ǰ����һ��
ʯ�������顺�ɳ��š��������֣�������ɽ֮�����ɡ���ͷ��ɽ������ͻȻ
��ʧ�����㱳����һ��ɽ����ɽ��֮���������ƣ�������޷�������档
һ������(tiesuo)�������С�
LONG
     );
  set("outdoors", "lingjiu");
  set("exits",([
      "eastup" : __DIR__"dadao1",
//      "southdown" : __DIR__"jian",
     ]));
     set("objects",([
        "/kungfu/class/lingjiu/tbxuan" : 1,
        ]));
    set("item_desc",([
      "tiesuo" : "����ͨ������ġ������š�����Ҳ������߹�(zou)ȥ��\n" ,
     ]));
        set("cost", 3);
 setup();
// replace_program(ROOM);
}

void init()
{
	add_action("do_zou", "zou");
}

int do_zou(string arg)
{
	object me=this_player(), room;

	if(!arg || arg!="tiesuo")
		return notify_fail("��Ҫ��ʲô��\n");

	if( me->is_busy() )
		return notify_fail("( ����һ��������û����ɣ������ƶ���)\n");

        if( !me->query_skill("yueying-wubu", 1) > 0 && !me->query_skill("lingbo-weibu", 1) > 0 
		&& random((int)me->query_skill("dodge")) <= 30  ){
                me->receive_damage("qi", 50, "��ɽ���Ϲ�����ˤ����");
                me->receive_wound("qi",  50, "��ɽ���Ϲ�����ˤ����");
                message_vision(HIR"$Nһ��С�Ľ���һ����... ��...��\n"NOR, me);
                me->move(__DIR__"shanjiao");
                message("vision", HIR"ֻ��" + me->query("name")
                + "��µ��µ�ش�ɽ���Ϲ��������Ǳ�������\n"NOR, environment(me), me);
	tell_object(me, HIR"���ɽ���Ϲ�µ��µ�ع���������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
        return 1;
        }

	if(!( room = find_object(__DIR__"jian")) )
		room = load_object(__DIR__"jian");

	if(!objectp(room))
		return notify_fail("ERROR:not found 'xianchou.c' \n");
	message_vision("$N����������ƮȻ��ȥ��\n",me);
	message("vision","��ֻ��һ����ӰƮȻ������\n", room);
        me->move(room);
        return 1;
}
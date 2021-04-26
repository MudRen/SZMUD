// Code of ShenZhou
// ��̲ /d/shenlong/haitan
// aln 4 / 98

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��̲");
        set("long", @LONG
����������ľ�Դ䣬�����ĺ�̲��������ͷ������ѩ�׵�ϸɳ���Ĵ�һƬ
�ž���������һ�������������Ǵ󺣣�����·���һ��ɽ�壬��������������
ͷ�ĺ�̲��
LONG
        );

	set("exits", ([
		"east" : __DIR__"shanlu1",
		"south" : __DIR__"haitan",
                "west" : __DIR__"beach",
		"north" : __DIR__"haitan",
        ]));
	set("cost", 2);

        setup();
 //       replace_program(ROOM);
}

void init()
{
        object me = this_player();
        int damage;

        if( interactive(me = this_player()) 
        && !(me->query("sg/spy") || me->query("family/family_name") == "������")
        &&  random((int)me->query_skill("dodge")) < 80 ) {
                message_vision( HIR "$N����ǰͻȻ����һ���޵׵���Ԩ...$N����������֮�С�\n" NOR, me);
                message_vision( HIR "�����еĸְ�ͻȻð���������ĸ��룬�����������$N��������...\n" NOR, me);

                damage = 100000 / ( 100 + (int)me->query_skill("force"));
                me->receive_wound("qi", damage + random(damage), "��������");
                me->receive_damage("qi", damage + random(damage), "��������");

                me->apply_condition("snake_poison", 50 + random(50) +
                        me->query_condition("snake_poison"));
        }
}










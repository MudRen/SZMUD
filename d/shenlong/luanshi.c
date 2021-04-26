// Code of ShenZhou
// /d/shenlong/luanshi.c
// ALN   Sep / 97

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ʯ");
        set("long", @LONG
�������ʯ�ѣ��ƺ�������Ȼ���ɡ�һ�󺣷紵���������һ
�����£�����������������ϸ��һ�²�֪������Ȼ��
LONG
        );

        set("exits", ([
              "northeast" : __DIR__"jushi",
 //           "northwest" : __DIR__"shulin3",
              "southup" : __DIR__"houshan",
        ]));
        set("cost", 2);

        setup();
}

void init()
{
        object me = this_player();
        int damage;

        if( interactive(me = this_player()) 
        && !(me->query("sg/spy") || me->query("family/family_name") == "������")
        &&  random((int)me->query_skill("dodge")) < 80 ) {
                message_vision( HIR "$N����ǰͻȻ����һ���޵׵���Ԩ...$N����������֮�С�\n" NOR, me);
                message_vision( HIR "�����еĸְ�ͻȻð���������ĸ��룬����������$N��������...\n" NOR, me);

                damage = 100000 / ( 100 + (int)me->query_skill("force"));
                me->receive_wound("qi", damage + random(damage), "��������");
                me->receive_damage("qi", damage + random(damage), "��������");

                me->apply_condition("snake_poison", 50 + random(50) +
                        me->query_condition("snake_poison"));
        }
}


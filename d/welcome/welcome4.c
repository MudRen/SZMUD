 // welcome.c
// modified by lisser, 10/4/2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", HIC"�ӻ���"NOR);
        set ("long", "������һ��С���ӻ��꣬�����������ҵİڷ��ż���С���ӣ�����һ
Щ�ճ���Ʒ���������������"HIG"list"NOR"�����г��������"HIG"buy <��Ʒ��>"NOR"����
����������"HIY"eat <��Ʒ��>"NOR"��"HIY"drink <��Ʒ��>"NOR"�������Ի��ߺȶ�����
");

        set("exits", ([ /* sizeof() == 2 */
                "east" : __DIR__"welcome2",
                ]));

        set("objects", ([
                "/d/city/npc/xiaoer2" : 1,
                ]));

        set("valid_startroom", "1");
        set("no_fight", 1);

        setup();
}

void init()
{
        object me = this_player();        
        object wage;
        if(!me->query("wage"))
        {
                wage = new("/clone/money/silver");
                wage->set_amount(10);
                wage->move(me);
                me->set("wage",1);
        }

}


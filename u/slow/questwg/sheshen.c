// Code of ShenZhou
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

#include <ansi.h>

inherit ROOM;
int do_climb(string arg);
void create()
{
        set("short", HIG"������"NOR);
        set("long", @LONG
����һ�μ�խ���յ�ɽ�£�����������ƣ�����Ԩ���޵ס��粻С��
��һʧ�����ȥ��ֻ������ͷ���Ҳ�����
LONG
        );

        set("exits", ([ /* sizeof() == 1 */
          "eastdown" : "/d/huashan/canglong",

        ]));

        set("outdoors", "huashan");
        set("cost", 3);
        setup();
}
void init()
{
        add_action("do_climb","climb");

}
int do_climb(string arg)
{
        object me = this_player();

        if (arg!="up") 
        return notify_fail(HIG"�������û�취����\n"NOR);
                
        if (me->query_skill("dodge",1) < 360)
        return notify_fail(HIG"�����˰�����޽�չ�����ǻ�ȥ�����Ṧ�����ɡ�\n"NOR);
        
        if (me->query("jingli") < 2000)
        return notify_fail(HIG"�㾫�񲻺ã�����ЪЪ�����ɣ�С������С����\n"NOR);

        me->add("jingli",-500);

        message_vision(HIG"$N�ֽŲ��ã�ʹ���˳��̵�������������������\n"NOR,me);
        me->move("/u/slow/questwg/juding1");
}
                

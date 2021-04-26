// Code of ShenZhou
// Room: /d/heimuya/majiu.c
// fear 1999/12/08

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"���"NOR);
        set("long", @LONG
����ƽ���͵������ǣ����깩Ӧ���ʲ��ϡ�����
ֻҪס�꣬����Ǿͻ����ǣ����Ǻ����տ���������
ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź򵽿��������
·������жѷ������Ѳ��ϣ�������һ����ۡ�
LONG
        );

        set("objects", ([
                "/d/shaolin/npc/ma-fu" : 1,
                "/clone/horse/donkey" : 1,
                "/clone/horse/huangma" : 1,
                "/clone/horse/heima" : 1,
                "/clone/horse/hongma" : 1,
                "/d/shaolin/obj/caoliao" : 2,
        ]));

        set("exits", ([
                "east" : __DIR__"kedian",
                "south" : __DIR__"weststreet2",
        ]));

        set("resource/water",1);
        set("outdoors", "heimuya");
        set("cost",1);

        setup();
        replace_program(ROOM);
}

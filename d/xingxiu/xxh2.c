// Code of ShenZhou
// Room: /d/xingxiu/xxh2.c
// Jay 3/18/96

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺��ߡ�˵�Ǻ�����ʵ��Ƭ���������󣬵���ʮ���ն�
������������ͨ�����޺�������������������ܶ桪�����¶�   ��
���ڵ�ǽ��춷�ɳ�İ�ʴ͹����ƽ��ǽ��ǰ�ѻ��˺ܺ����ɳ��һЩ
«έ�ͺ�����֧֧�����¶��ͷ������������һ������(paizi)��
LONG
        );
        set("valid_startroom", 1);
        set("exits", ([
             "north" : __DIR__"riyuedong",
             "south" : __DIR__"xxh1",
             "northeast" : __DIR__"xxh3",
             "northwest" : __DIR__"xxh4",
        ]));

        set("item_desc", ([
                "paizi" : "���޺����أ����¶����졣\n",
        ]));

        //set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
       set("valid_startroom", 1);
        set("cost", 2);

        setup();

	call_other("/clone/board/xingxiu_b", "???");
        //"/clone/board/xingxiu_b"->foo();

}

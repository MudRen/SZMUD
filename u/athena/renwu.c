// Room��/u/athena/renwu.c

#include <room.h> 
inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
���������ݷ�������ļ���ݡ�����ɽ���в��˳��������ɧ�����ꡱ����ã
���ݴ�أ���ǧ���Ʊ�ã���Щ߳�彭����������ڶ���Ϊһ�����������ǽ��
�ϣ��򹤱ʣ���д�⣬���������ؿ���������硣
LONG
        );
        set("no_fight",1);
        set("exits", ([
                "east" : __DIR__"dating",
        ]));
        setup();
}


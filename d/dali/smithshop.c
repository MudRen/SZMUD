// Code of ShenZhou
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǵ�����ڷ��������ĵط�������ʢ������������
�������������Ȼ����Ʒ��һ�����������澫����������
�������������ˡ�
LONG
        );

set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dahejie",
]));

        set("objects", ([
                __DIR__"npc/ironsmith" :1,       
 ]));

set("cost", 1);

        setup();
}

int valid_leave(object me, string dir)
{
        if( present("iron smith", me) )
                return notify_fail("����մ����˰�Ʊ�����۸���ʵ�˰���\n");

        return ::valid_leave(me, dir);
}


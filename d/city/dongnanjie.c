// Code of ShenZhou
// Room: /city/dongnanjie.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
        set("short", "���Ͻ�");
        set("long", @LONG
������������ʯ���̳ɵģ�����û��ʲô�����˼ҡ�Ѳ��������Ҳ���ٵ���
����ֻ�м���������СŮ��������������ȥ������û���ϱ������������֣���Զ
�Ķ��������ͷ�ܶ����ö��ġ��ò����ģ���Χ��һ�����Ӵ���ߺ�ȡ��ϱ���һ
Щ��ˮ����̯�ӣ��������¿���С��ի��
LONG
        );
        set("outdoors", "city");

        set("fanhua",1);
        set("exits", ([
                "east" : __DIR__"xiangnanjie",
                "west" : __DIR__"nandajie2",
                "north" : __DIR__"xiaobaozhai",
                "south" : __DIR__"guopintan",
        ]));

        set("objects", ([
                __DIR__"npc/girl" : 2,
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

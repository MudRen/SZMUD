// Code of ShenZhou
// Room: /d/xingxiu/xxroad6.c

inherit ROOM;

void create()
{
        set("short", "ɽ��ƽ��");
        set("long", @LONG
ɽ��ƽ�أ����������̵�С�ݣ���Χ���˼���������ɽ����һ����Ȫ��
�ϱ�����С·��������������Ũ�ܵĻĲݣ�һֱ����ɽ�����
LONG
        );

        set("resource/water", 1);
        set("objects", ([
                __DIR__"npc/obj/yangrou.c" : 3]));


        set("exits", ([
  "westdown" : __DIR__"xxroad9",
  "south" : __DIR__"xxroad5",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 1);
        setup();
        replace_program(ROOM);
}

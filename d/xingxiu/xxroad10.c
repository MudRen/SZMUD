// Code of ShenZhou
// Room: /d/xingxiu/xxroad10.c

inherit ROOM;

void create()
{
        set("short", "ɽ���");
        set("long", @LONG
ɽ������˼������������ǻĲݿ�����ʯ��˷����ɱ�������ľ�������
�ϱ���ɽ��ĵأ������ߺ����������һ��ɽ����
LONG
        );

        set("resource/water", 1);
	set("bing_can", 3);

        set("exits", ([
  "northwest" : __DIR__"xxcave",
  "southup" : __DIR__"xxroad9",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 2);
        setup();
        replace_program(ROOM);
}

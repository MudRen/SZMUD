// Code of ShenZhou
// room: lianwuchang.c

inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
������һ�����䳡����������һЩľ׮(muzhuang)��ľ�ˡ�����
�����ڲ�ͣ�Ļ�����ϰ������Щ���Ӷ���������ʦ�������书��ÿ
�������ﶼҪ����һ�α��䣬�Լ����ڵ��书���ȡ�
LONG );

        set("exits", ([
                "north" : __DIR__"fanting",
                "east" : __DIR__"guangchang",
		"south" : __DIR__"bingqifang",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}

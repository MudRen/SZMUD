// Code of ShenZhou
// /d/emei/emroad6.c С·
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
�������������ڵ�һ�������ĵĻ���·��������ЩС���ݣ���������ġ�·
�����˺��٣�����ɫ�Ҵҵ���ǰ��·��������һ��С��ׯ������С�����������
ɽ�ˡ�
LONG
        );
        set("exits", ([
                "southeast" : "/d/wudang/wdroad5",
                "west" : __DIR__"emroad5",
                "north" : "/d/village/hsroad3",
                "south" : __DIR__"house1",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "emei");

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

//Cracked by shenzhou
// /d/sanbuguan/xroad1.c С·

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
                "southeast" : __DIR__"road6",
                "west" : __DIR__"xroad2",
                "north" : "/d/village/hsroad3",
                "south" : __DIR__"house1",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "sanbuguan");

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����������µ���ڣ�ӭ�������󺺰���ʯ�������������ֽ������̵�
�������ͼ�ơ�����һ����ʯ��·������ͨ���׵Ļ����š�
LONG
        );
        set("no_clean_up", 0);
        set("cost", 2);

        set("exits", ([
		"eastup" : __DIR__"tianls3.c",
        "out" : __DIR__"tianls13.c",		]));
setup();
replace_program(ROOM);
}


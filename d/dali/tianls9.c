//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "����̨");
        set("long", @LONG
����һ��������ĸ�̨��̨�ϳ��˼���������տ���Ұ����������ɮ����
��ڤ˼�������һ�������С������ϵ��ǰ벿�󾭣�ȴ��������������֮�
LONG
        );
       set("exits", ([
		"west" : __DIR__"tianls8.c",
        "east" : __DIR__"tianls7",
        "southeast" : __DIR__"tianls6",
        "northup" : __DIR__"tianls10",		]));

set("no_clean_up", 0);
        set("cost", 3);

setup();
}


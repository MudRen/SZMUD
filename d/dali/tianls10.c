//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "��ľ��");
        set("long", @LONG
���߹�һ����������һ��СԺ������ľ��ȫ����ľ��ɣ�����ľ����ľ�Ͼ�
��ȥƤ����Ȼ���ӣ���һ·�����Ľ�̻Եĵ��ý�Ȼ��ͬ��
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
		"enter" : __DIR__"tianls11.c",
        "southdown" : __DIR__"tianls9.c",
        "westdown" : __DIR__"tianls8",
		]));
	set("no_clean_up", 0);

	setup();
}

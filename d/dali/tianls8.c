//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "�껨Ժ");
        set("long", @LONG
����һ��������СԺ��Ժ�������͵����˼������񣬵����ò�ɫԲʯ�̳�һ
��С��������̤̤���У���ʯ�������ӣ�ǡ�����ʺ�һ�㡣
LONG
        );
      set("exits", ([
		"east" : __DIR__"tianls9.c",
        "eastup" : __DIR__"tianls10",
		]));
set("no_clean_up", 0);
        set("cost", 3);

setup();
}


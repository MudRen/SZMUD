// Code of ShenZhou
// Room: /d/beijing/guanshifang.c

inherit ROOM;

void create()
{
        set("short", "�����黭��");
	set("long", @LONG
�����Ǿ����黭���·����������˾�����ĸ����黭Ժ����Ʒ������Ǯ��
���������黭�ĵط���
LONG
	);
	set("no_clean_up", 0);
        set("exits", ([
          "east"  : __DIR__"fuchengdajie_n",
	]));
	set("cost", 2);

	setup();
}

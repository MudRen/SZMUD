// Code of ShenZhou
// Room: /d/mingjiao/shanqiu.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "Сɽ��");
	set("long", @LONG
��ͺͺ��ɽ��������Ҳ�Ѽ�һֻ��ʱ�к������µ���·����������
�ʼ�Ӳ����û����ˮ��ȥ���١�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"southeast" : __DIR__"shandao42",
	"northdown" : __DIR__"txiaochang",
	"southwest" : __DIR__"didao/didao",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
